// StockAnalys.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Analysis.h"
#include "KlINE.h"
#include "StockData.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char path[1024] = "d:\\htzq\\T0002\\export\\SH#600007.txt";
	char pathName[7] = {0};
	int commandType = 0;
	if (argc >= 2)
	{
		strcpy_s(path,argv[1]);
	}
	memcpy(pathName,path + (strlen(path) - 10),6);
	if (argc >= 3)
	{
		commandType = atoi(argv[2]);
	}

	StockDataArray::GetInstance()->Initialize(path);

	//commandType= 1;//test

	//根据K线分析走势
	if (commandType == 0)
	{
		unsigned int totalDay = 0xFFFFFF;
		if (argc >= 4)
		{
			totalDay = atoi(argv[3]);
		}

		while(StockDataArray::GetInstance()->GetArraySize() > 0 && totalDay > 0)
		{
			Analysis::TrendAnalysis(true);

			//分析
			KlINEArray::GetInstance()->StartAnalysis();
			StockDataArray::GetInstance()->PopFront();
			totalDay--;
		}
	}


	//开盘走势分析（意义不大）
	//Analysis::KaipanZoushiAnalysis();

	//预测（意义不大）
	//StockData tmpData;
	//StockDataArray::GetInstance()->PushFront(tmpData);
	//KlINEArray::GetInstance()->StartForecast();
	//StockDataArray::GetInstance()->PopFront();

	//进行买卖分析详细清单
	else if (commandType == 1)
	{
		unsigned int totalDay = 0xFFFFFF;
		if (argc >= 4)
		{
			totalDay = atoi(argv[3]);
		}
		KlINEArray::GetInstance()->StartBuyOrSale(totalDay);
	}

	//当天预测汇总
	else if (commandType == 2)
	{
		//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("%s,%d\n",pathName,KlINEArray::GetInstance()->StartAnalysis(false));
		//Analysis::TrendAnalysis(true);

		//分析
		//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	//进行买卖汇总
	else if (commandType == 3)
	{
		unsigned int totalDay = 0xFFFFFF;
		if (argc >= 4)
		{
			totalDay = atoi(argv[3]);
		}
		KlINEArray::GetInstance()->StartBuyOrSale(totalDay,pathName,0,false);
		KlINEArray::GetInstance()->StartBuyOrSale(totalDay,pathName,1,false);
	}


	//getchar();
	return 0;
}

