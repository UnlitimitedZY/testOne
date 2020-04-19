
#pragma once

#include <stdlib.h>
#include <iostream>
#include  <cmath>
#include <stdint.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>


#define  DATE_LEN    1000
//using namespace std;


typedef struct st_index_file
{
	int rows = 0;
	char date_start[DATE_LEN];  //2020-11-12 20:15:12
	char date_end[DATE_LEN];    //2020-11-13 20:15:12 
	char filepath[100];

}s_index_file;

extern std::vector < st_index_file >  array_index_Day;
extern std::vector < st_index_file >  array_index_Week;
extern std::vector < st_index_file >  array_index_Month;
extern std::vector < st_index_file*>  index_Res;


bool CalculatePolicy(std::string startedDate, std::string endDate, std::vector < st_index_file >  *array_index_Day, std::vector < st_index_file >*array_index_Week, std::vector < st_index_file >  *array_index_Month, std::vector < st_index_file*>  *index_Res);

