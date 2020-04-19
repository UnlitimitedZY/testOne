#include "applicationT.h"

std::vector < st_index_file >  array_index_Day;
std::vector < st_index_file >  array_index_Week;
std::vector < st_index_file >  array_index_Month;
std::vector < st_index_file*>  index_Res;

//用于产生月份的数据
void addMonthData()
{
	st_index_file  indexMon;

	memcpy(indexMon.date_start, "2010-09-01 00:00:00", strlen("2010-10-01 00:00:00") + 1);
	memcpy(indexMon.date_end, "2010-09-28 00:00:00", strlen("2010-10-30 00:00:00") + 1);
	array_index_Month.push_back(indexMon);

	memcpy(indexMon.date_start, "2010-10-01 00:00:00", strlen("2010-10-01 00:00:00") + 1);
	memcpy(indexMon.date_end, "2010-10-28 00:00:00", strlen("2010-10-30 00:00:00") + 1);
	array_index_Month.push_back(indexMon);

	memcpy(indexMon.date_start, "2010-11-01 00:00:00", strlen("2010-10-01 00:00:00") + 1);
	memcpy(indexMon.date_end, "2010-11-28 00:00:00", strlen("2010-10-30 00:00:00") + 1);
	array_index_Month.push_back(indexMon);

	memcpy(indexMon.date_start, "2010-12-01 00:00:00", strlen("2010-12-01 00:00:00") + 1);
	memcpy(indexMon.date_end, "2010-12-28 00:00:00", strlen("2010-12-30 00:00:00") + 1);
	array_index_Month.push_back(indexMon);
}

//用于产生周的数据
void addWeekData()
{
	st_index_file  indexWeek;

	char weekStr[DATE_LEN]; int flag = 1;
	for (int i = 9; i < 13; i++)
	{
		flag = 1;
		for (int j = 1; j <= 28; j = j + 6)
		{
			if (flag)
			{
				if (flag != 1)     //第一次之后
				{
					j = j - 6 + 1;
					flag = 0;
				}
				else
					flag = 0;
				sprintf(weekStr, "2010-%02d-%02d 00:00:00", i, j);
				memcpy(indexWeek.date_start, weekStr, strlen(weekStr) + 1);
				//printf("start %s\n", weekStr);
			}
			else
			{
				flag = 2;
				sprintf(weekStr, "2010-%02d-%02d 00:00:00", i, j);
				memcpy(indexWeek.date_end, weekStr, strlen(weekStr) + 1);
				array_index_Week.push_back(indexWeek);
				//printf("end %s\n", weekStr);

			}

		}
	}

}
//
//用于产生每日的数据
void addDayData()
{
	st_index_file dayData;

	char dayNum[DATE_LEN];
	for (int i = 9; i < 13; i++)              //12月
	{
		for (int j = 1; j < 29; j++)           //1月
		{
			sprintf(dayNum, "2010-%02d-%02d 00:00:00", i, j);
			memcpy(dayData.date_start, dayNum, strlen(dayNum) + 1);
			memcpy(dayData.date_end, dayNum, strlen(dayNum) + 1);
			array_index_Day.push_back(dayData);

			printf("end %s\n", dayNum);
			printf("\n");
		}
	}
}

//测试demo
void testOne()
{
	char startDate[DATE_LEN] = "2010-11-12 12:20:00";        //日期在区域内 按照天进行排序
	char endDate[DATE_LEN] = "2010-11-16 11:00:00";
    CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n",i+1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
//测试demo
void testTwo()
{

	char startDate[DATE_LEN] = "2010-10-02 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-12-20 11:00:00";
	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
//测试demo
void testThree()
{

	char startDate[DATE_LEN] = "2010-09-10 12:20:00";        
	char endDate[DATE_LEN] = "2010-10-28 11:00:00";
	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void testFour()
{

	char startDate[DATE_LEN] = "2010-09-10 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-10-30 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void edageTest()
{
	char startDate[DATE_LEN] = "2010-09-27 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-10-02 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void edageTest2()
{
	char startDate[DATE_LEN] = "2010-09-28 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-12-01 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void testFive()
{

	char startDate[DATE_LEN] = "2010-09-10 00:00:00";        //跨月
	char endDate[DATE_LEN] = "2010-11-30 00:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void edgeTest()   
{
	char startDate[DATE_LEN] = "2010-09-28 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-12-01 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}

void edgeTestSameWeek()
{
	char startDate[DATE_LEN] = "2010-11-07 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-11-14 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}

void edgeTest4()
{
	char startDate[DATE_LEN] = "2010-09-02 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-12-03 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}

void edgeTest5()
{
	char startDate[DATE_LEN] = "2010-09-02 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-10.02 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void edgeTest6()
{
	char startDate[DATE_LEN] = "2010-09-28 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-11-02 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}
void edageTest7()
{
	char startDate[DATE_LEN] = "2010-10-27 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-12-02 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("u结果集中第%d个索引块是:\n", i + 1);
		printf("开始时间data_start%s\n", index_Res[i]->date_start);
		printf("结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	getchar();
}

void edageTest8()
{
	char startDate[DATE_LEN] = "2010-10-06 12:20:00";        //跨月
	char endDate[DATE_LEN] = "2010-10-16 11:00:00";

	CalculatePolicy(startDate, endDate, &array_index_Day, &array_index_Week, &array_index_Month, &index_Res);
	for (int i = 0; i < index_Res.size(); i++)
	{
		printf("u结果集中第%d个索引块是:\n", i + 1);
		printf("u开始时间data_start%s\n", index_Res[i]->date_start);
		printf("u结束时间data_start%s\n", index_Res[i]->date_end);
		printf("\n");
	}
	//getchar();
}

int main()
{

	// 为加载测试数据填充year month day 容器;
		addMonthData();
		addWeekData();
		addDayData();

		//edageTest();
		//edageTest2();
		//testOne();
		//edgeTestSameWeek();
		//edgeTest4();
		//edgeTest5();
		//edgeTest6();
		//edageTest7();
		edageTest8();

		//运行测试
		return true;
}