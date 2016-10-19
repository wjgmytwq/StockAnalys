// StockAnalys.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//����K�߷�������
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

			//����
			KlINEArray::GetInstance()->StartAnalysis();
			StockDataArray::GetInstance()->PopFront();
			totalDay--;
		}
	}


	//�������Ʒ��������岻��
	//Analysis::KaipanZoushiAnalysis();

	//Ԥ�⣨���岻��
	//StockData tmpData;
	//StockDataArray::GetInstance()->PushFront(tmpData);
	//KlINEArray::GetInstance()->StartForecast();
	//StockDataArray::GetInstance()->PopFront();

	//��������������ϸ�嵥
	else if (commandType == 1)
	{
		unsigned int totalDay = 0xFFFFFF;
		if (argc >= 4)
		{
			totalDay = atoi(argv[3]);
		}
		KlINEArray::GetInstance()->StartBuyOrSale(totalDay);
	}

	//����Ԥ�����
	else if (commandType == 2)
	{
		//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("%s,%d\n",pathName,KlINEArray::GetInstance()->StartAnalysis(false));
		//Analysis::TrendAnalysis(true);

		//����
		//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	//������������
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

