程序说明：

1.IDE :项目采用vs2013 进行编译运行

2 .结构说明：
   2.1 文件全部在名称为demo的筛选器下的索引索引范围求解的筛选器中，
   2.2 文件的例子全部在main.cpp 中运行
   2.3 关于索引求解的小模块的主要用到的函数和代码介绍
         2.3.1 主要代码在Solution.cpp 和Solution.Head中。其中主要运用到的函数是
              std::vector < st_index_file*>CalculatePolicy(string startedDate, string endDate)；                  //用于返回函数返回一个存放了可能包含了年月日的容器
              st_index_file* sequentialSearch(vector <st_index_file> &array, int len, string value, int &indexs)  //用于顺序查找
              st_index_file* BinarySearch(vector <st_index_file> &array, int len, string value, int &indexs)      //用于进行二分查找
		 2.3.2
		     void addMonthData();   //用于产生相对应的测试月份数据
             void addWeekData();    //用于产生相对应的测试周数据
             void addDayData();     //用于产生相对应的测试天数据
3.使用只需调用st_index_file* sequentialSearch(vector <st_index_file> &array, int len, string value, int &indexs) 就可运行。详细代码见main 函数。
4.liunx 版本的主要文件是applicationT.cpp application.h  文件测试文件demo为mainThree.cpp。
    关于liunx版本，函数如下
              td::vector < st_index_file*>CalculatePolicy(string startedDate, string endDate)；                  //用于返回函数返回一个存放了可能包含了年月日的容器
              st_index_file* sequentialSearch(vector <st_index_file> &array, int len, string value, int &indexs)  //用于顺序查找
              //用于进行二分查找
              st_index_file* BinarySearchT(vector <st_index_file> *array, int len, string value, int &indexs)
             //对天进行处理
              bool dayProcessing(string strDate, string endDate, vector <st_index_file*> * index_Res, vector <st_index_file> *array_index_Day)         
             //对周进行处理
              bool weekProcessing(string strDate, string endDate, vector <st_index_file*> * index_Res, vector <st_index_file> *array_index_Week, vector <st_index_file> *array_index_Day)
             //对月进行处理
             bool MonthProcessing(string strDate, string endDate, vector <st_index_file*> * index_Res, vector <st_index_file> *array_index_Month, vector <st_index_file> *array_index_Week, vector <st_index_file> *array_index_Day)
             //改变日期向前加一或者减去一
             bool tranferDate(string &strDate, int flag, vector < st_index_file >  *array_index_Month)
		
             void addMonthData();   //用于产生相对应的测试月份数据
             void addWeekData();    //用于产生相对应的测试周数据
             void addDayData();     //用于产生相对应的测试天数据
3.使用只需调用st_index_file* sequentialSearch(vector <st_index_file> &array, int len, string value, int &indexs) 就可运行。详细代码见main 函数。 