#include "applicationT.h"



//用于进行二分查找
st_index_file* BinarySearchT(std::vector <st_index_file> *array, int len, std::string value, int &indexs)
{
	if (array->empty() || len <= 0)
		return NULL;
	std::string strDate, endDate, compare;
	int low = 0;
	int high = len - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		strDate = array->at(mid).date_start;
		endDate = array->at(mid).date_end;
		if (strcmp(strDate.c_str(), value.c_str()) == 0 || strcmp(endDate.c_str(), value.c_str()) == 0 || (strcmp(value.c_str(), strDate.c_str()) >0 && strcmp(value.c_str(), endDate.c_str())<0))
		{

			indexs = mid;
			return &array->at(mid);
		}
		else if (strcmp(strDate.c_str(), value.c_str()) > 0)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;

		}
	}

	return NULL;
}

//对天进行处理
bool dayProcessing(std::string strDate, std::string endDate, std::vector <st_index_file*> * index_Res, std::vector <st_index_file> *array_index_Day)
{
	st_index_file * strIndex = NULL, *endIndex = NULL; int strNum = 0, endNum = 0, origin = 0, end = 0;

	strIndex = BinarySearchT(array_index_Day, array_index_Day->size(), strDate, strNum);
	endIndex = BinarySearchT(array_index_Day, array_index_Day->size(), endDate, endNum);

	if (!strIndex || !endIndex)
		return false;
	for (int i = strNum; i <= endNum; i++)
		index_Res->push_back(&array_index_Day->at(i));

	return true;
}

//对周进行处理
bool weekProcessing(std::string strDate, std::string endDate, std::vector <st_index_file*> * index_Res, std::vector <st_index_file> *array_index_Week, std::vector <st_index_file> *array_index_Month, std::vector <st_index_file> *array_index_Day)
{
	st_index_file * strIndex = NULL, *endIndex = NULL, *tempIndex = NULL; int strNum = 0, endNum = 0, origin = 0, end = 0, num =0,flag = 0,flagL = 0,flagR = 0;
	std::string tempStr, tepStrtT;
	strIndex = BinarySearchT(array_index_Week, array_index_Week->size(), strDate, strNum);
	endIndex = BinarySearchT(array_index_Week, array_index_Week->size(), endDate, endNum);

    if (!strIndex||!endIndex)    //找不到区间说明索引中并没有报错
	{
		return false;
	}

	origin = strNum + 1;
	end = endNum - 1;

	if (strcmp(strIndex->date_start, strDate.c_str()) == 0)
	{	origin = strNum; flagR = 1;}
	if (strcmp(endIndex->date_end, endDate.c_str()) == 0)
	{
		end = endNum; flagL = 1;
	}
	if (strcmp(endIndex->date_end, endDate.c_str()) == 0 && strcmp(strIndex->date_start, strDate.c_str()) == 0)   //是极端完整的月直接返回
	{
		origin = strNum;
		end = endNum;
		flag = 1;
	}
	if (endNum - strNum > 1 || flag == 1)
		//加入week容器
	{
		std::string temp;
		for (origin; origin <= end; origin++)
		{
			index_Res->push_back(&array_index_Week->at(origin));
		}
		if (flag == 1)
			return true;
	}
	if (strcmp(strDate.c_str(), strIndex->date_start) == 0 && strcmp(endDate.c_str(), endIndex->date_end) == 0)   //是几段完整的月直接返回
	{
		return true;
	}
	if (flagL == 1)                                                                                               //只有一个要查询的情况
	{
		dayProcessing(strDate, strIndex->date_end, index_Res, array_index_Day);
		return true;
	}
	if (flagR == 1)
	{
		dayProcessing(endIndex->date_start, endDate, index_Res, array_index_Day);
		return true;
	}

	if (strNum == endNum ||strcmp(strDate.c_str(), strIndex->date_start) == 0 || strcmp(strDate.c_str(), strIndex->date_start) > 0 && strcmp(endDate.c_str(), strIndex->date_end) == 0)
	{
		dayProcessing(strDate, endDate, index_Res, array_index_Day);
		return true;
	}

	dayProcessing(strDate, strIndex->date_end, index_Res, array_index_Day);
	dayProcessing(endIndex->date_start, endDate, index_Res, array_index_Day);

	return true;
}

//对月进行处理
bool MonthProcessing(std::string strDate, std::string endDate, std::vector <st_index_file*> * index_Res, std::vector <st_index_file> *array_index_Month, std::vector <st_index_file> *array_index_Week, std::vector <st_index_file> *array_index_Day)
{
	st_index_file * strIndex = NULL, *endIndex = NULL; int strNum, endNum, origin, end, flag = 0, flagL=0,flagR=0;

	strIndex = BinarySearchT(array_index_Month, array_index_Month->size(), strDate, strNum);
	endIndex = BinarySearchT(array_index_Month, array_index_Month->size(), endDate, endNum);


	if (endIndex == NULL || endIndex == NULL)                  //找不到区间则返回false
		return false;
    

	origin = strNum+1;
	end = endNum-1;

	if (strcmp(strIndex->date_start, strDate.c_str()) == 0)
	{	origin = strNum; flagR = 1;}
	if (strcmp(endIndex->date_end, endDate.c_str()) == 0)
	{
		end = endNum; flagL = 1;
	}
    if (strcmp(endIndex->date_end, endDate.c_str()) == 0 && strcmp(strIndex->date_start, strDate.c_str()) == 0)   //是极端完整的月直接返回
	{
		origin = strNum;
		end = endNum;
		flag = 1;
	}
	if (endNum-strNum>1 || flag ==1)
		//加入月容器
	{
		for (origin; origin <= end; origin++)
		{
			index_Res->push_back(&array_index_Month->at(origin));
		}
		if (flag == 1)
			return true;
	}
	if (strcmp(strDate.c_str(), strIndex->date_start) ==0 && strcmp(endDate.c_str(), endIndex->date_end) == 0)   //是几段完整的月直接返回
	{
		return true;
	}
	if (flagL ==1)                                                                                               //只有一个要查询的情况
	{
		weekProcessing(strDate, strIndex->date_end, index_Res, array_index_Week, array_index_Month, array_index_Day);
		return true;
	}
	if (flagR == 1)
	{
		weekProcessing(endIndex->date_start, endDate, index_Res, array_index_Week, array_index_Month, array_index_Day);
	}
	if (strcmp(strDate.substr(5, 2).c_str(), endDate.substr(5, 2).c_str())==0)
	{
		weekProcessing(strDate, endDate, index_Res, array_index_Week,array_index_Month, array_index_Day);
		return true;
	}

	weekProcessing(strDate, strIndex->date_end, index_Res, array_index_Week, array_index_Month, array_index_Day);
	weekProcessing(endIndex->date_start, endDate, index_Res, array_index_Week, array_index_Month, array_index_Day);

	return true;

}

//改变日期向前加一或者减去一
bool tranferDate(std::string &strDate, int flag, std::vector < st_index_file >  *array_index_Month)
{
	//天减去后大于开始日期   天加上后小于截止日期
    int	areaMonth = 0;
	st_index_file * index = BinarySearchT(array_index_Month, array_index_Month->size(), strDate, areaMonth);  //搜索月对应index
	if (!index)
		return false;
	std::string  tempEndDay = index->date_end;
	std::string  temStrDay = index->date_start;
	int aa = atoi(strDate.substr(8, 2).c_str()) + 1;
	int afds = atoi(tempEndDay.substr(8, 2).c_str());
	int fsdfdaf = aa <= afds;
	if (atoi(strDate.substr(8, 2).c_str()) + 1 <= atoi(tempEndDay.substr(8, 2).c_str()) && flag==1|| \
		atoi(strDate.substr(8, 2).c_str()) - 1 >= atoi(temStrDay.substr(8, 2).c_str())&&flag==2)  // 是小于这个月的情况
	{
		int newDay;
		char reStartDate[DATE_LEN];

		switch (flag)
		{
		case 1:                                                   //加一天
		{ newDay = atoi(strDate.substr(8, 2).c_str()) + 1;

		break; }
		case 2:                                                   //减去一天
		{newDay = atoi(strDate.substr(8, 2).c_str()) - 1;
		break; }
		default:
			break;
		}
		sprintf(reStartDate, "%d-%02d-%02d 00:00:00", atoi(strDate.substr(0, 4).c_str()), atoi(strDate.substr(5, 2).c_str()), newDay);
		strDate = reStartDate;
	}
	else                                                                                   //大于这个月最大day的情况 直接顺移
	{
		if (flag == 1)       //前日期点
		{
			strDate = array_index_Month->at(areaMonth + 1).date_start;
		}
		else if (flag == 2)  //后日期点
		{
			strDate = array_index_Month->at(areaMonth -1).date_end;

		}

	}
	return true;
}

//形参说明：两个参数格式输入日期.格式如下 yyyy-mm-dd hh-mm-ss
//例如：2010-11-12 12:20:00", "2010-11-18 11:00:00"
//函数返回一个存放了可能包含了年月日的容器。

bool CalculatePolicy(std::string startedDate, std::string endDate, std::vector < st_index_file >  *array_index_Day, std::vector < st_index_file >*array_index_Week, std::vector < st_index_file >  *array_index_Month, std::vector < st_index_file*>  *index_Res)
{
	st_index_file *indexarr = NULL, *index = NULL,*indexT = NULL;
	std::string starteDateCop, endDateCop;

	endDateCop = endDate;
	starteDateCop = startedDate;

	//起始天开始天搜索
	int startIndex = 1, endIndex = 0;

	sprintf(const_cast<char *>(starteDateCop.c_str()), "%d-%02d-%02d 00:00:00", atoi(startedDate.substr(0, 4).c_str()), atoi(startedDate.substr(5, 2).c_str()), atoi(startedDate.substr(8, 2).c_str()));
	index = BinarySearchT(array_index_Day, array_index_Day->size(), starteDateCop, startIndex);

	//结束天开始天搜索
	endIndex = 0;
	sprintf(const_cast<char *>(endDateCop.c_str()), "%d-%02d-%02d 00:00:00", atoi(endDate.substr(0, 4).c_str()), atoi(endDate.substr(5, 2).c_str()), atoi(endDate.substr(8, 2).c_str()));
    indexT = BinarySearchT(array_index_Day, array_index_Day->size(), endDateCop, endIndex);

	if (!index || !indexT)                         //找不到区域的时候
		return false;
     
	index_Res->push_back(index);                   //放入开始时间点作为头

	//开始和结束日期进行转换产生新的日期
	tranferDate(starteDateCop, 1, array_index_Month);
	tranferDate(endDateCop, 2, array_index_Month);

	MonthProcessing(starteDateCop, endDateCop, index_Res, array_index_Month, array_index_Week, array_index_Day);

	index_Res->push_back(indexT);
	return true;
}




