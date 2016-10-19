#include "StdAfx.h"
#include "StockData.h"
#include <math.h>
#include "StockHeader.h"
#include<fstream>
//#include<stream>
using namespace std;

StockDataArray* StockDataArray::m_pStockDataArray = NULL;
const int AVERAGETRADECOUNTSDAYS = 5;

StockData::StockData(void)
{
	m_stockName = "";
	m_stockTime = 0;
	m_MiddlePrice = 0.0;
	m_KaiPanPrice = 0.0;
	m_ShouPanPrice = 0.0;
	m_HighPrice = 0.0;
	m_LowPrice = 0.0;
	m_ChengJiaoCounts = 0.0;
	m_KaiPanStatus = NONESTATUS;//开盘状态
	m_MA5 = 0.0;//5日均线
	m_MA10 = 0.0;//10日均线
	m_MA20 = 0.0;//20日均线
	m_MA60 = 0.0;//60日均线
	m_MA120 = 0.0;//120日均线
	m_MA250 = 0.0;//250日均线
	m_PA5 = 1.0;//量比（5日）
}

StockData::~StockData(void)
{

}

int StockData::GetYinYangLine()
{
	if (m_ShouPanPrice - m_KaiPanPrice > 0.0)
	{
		return 1;
	}
	else if (m_ShouPanPrice == m_KaiPanPrice)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
double StockData::GetEntityPercent()
{
	return (fabs(m_ShouPanPrice - m_KaiPanPrice)) / (m_KaiPanPrice);
}

double StockData::GetUpperShadowPercent()
{
	if (GetYinYangLine() >= 0)
	{
		return (fabs(m_HighPrice - m_ShouPanPrice)) / (m_KaiPanPrice);
	}
	else
	{
		return (fabs(m_HighPrice - m_KaiPanPrice)) / (m_KaiPanPrice);
	}
	
}
double StockData::GetLowerShadowPercent()
{
	if (GetYinYangLine() >= 0)
	{
		return (fabs(m_LowPrice - m_KaiPanPrice)) / (m_KaiPanPrice);
	}
	else
	{
		return (fabs(m_LowPrice - m_ShouPanPrice)) / (m_KaiPanPrice);
	}
}

double StockData::GetEntityHighPrice()
{
	if (GetYinYangLine() > 0.0)
	{
		return m_ShouPanPrice;
	}
	else
	{
		return m_KaiPanPrice;
	}
}
double StockData::GetEntityLowPrice()
{
	if (GetYinYangLine() < 0.0)
	{
		return m_ShouPanPrice;
	}
	else
	{
		return m_KaiPanPrice;
	}
}

bool StockData::isChuiTouXian()
{
	if(GetEntityPercent() < middlePercent && GetEntityPercent() > smallPercent && GetUpperShadowPercent() < smallPercent &&(GetLowerShadowPercent() > GetEntityPercent() * 2))
	{
		return true;
	}
	return false;
}
bool StockData::isDaoChuiTouXian()
{
	if(GetEntityPercent() < middlePercent && GetEntityPercent() > smallPercent && GetLowerShadowPercent() < smallPercent &&(GetUpperShadowPercent() > GetEntityPercent() * 2))
	{
		return true;
	}

	return false;
}
bool StockData::isDaYangXian()
{
	if (GetYinYangLine() > 0.0 && GetEntityPercent() > largePercent /*&& GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isDaYinXian()
{
	if (GetYinYangLine() < 0.0 && GetEntityPercent() > largePercent /*&& GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isZhongYangXian()
{
	if (GetYinYangLine() > 0.0 && GetEntityPercent() <= largePercent && GetEntityPercent() > middlePercent/* && GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isZhongYinXian()
{
	if (GetYinYangLine() < 0.0 && GetEntityPercent() <= largePercent && GetEntityPercent() > middlePercent /*&& GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isXiaoYangXian()
{
	if (GetYinYangLine() > 0.0 && GetEntityPercent() <= middlePercent /*&& GetEntityPercent() > smallPercent && GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isXiaoYinXian()
{
	if (GetYinYangLine() < 0.0 && GetEntityPercent() <= middlePercent /*&& GetEntityPercent() > smallPercent && GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() < middlePercent*/)
	{
		return true;
	}

	return false;
}
bool StockData::isShiZiXian()
{
	if (GetEntityPercent() < smallPercent && GetUpperShadowPercent() > smallPercent && GetUpperShadowPercent() < middlePercent && GetLowerShadowPercent() > smallPercent && GetLowerShadowPercent() < middlePercent)
	{
		return true;
	}
	return false;
}
bool StockData::isChangShiZiXian()
{
	if (GetEntityPercent() < smallPercent && GetUpperShadowPercent() >= middlePercent && GetLowerShadowPercent() >= middlePercent)
	{
		return true;
	}
	return false;
}
bool StockData::isLuoXuanJiang()
{
	if (GetEntityPercent() > microPercent && GetEntityPercent() < middlePercent && GetUpperShadowPercent() > smallPercent && GetLowerShadowPercent() > smallPercent)
	{
		return true;
	}
	return false;
}
bool StockData::isYiZiXian()
{
	if (GetEntityPercent() < microPercent &&  GetUpperShadowPercent() < microPercent && GetLowerShadowPercent() < microPercent)
	{
		return true;
	}
	return false;
}
bool StockData::isTZiXian()
{
	if (GetEntityPercent() < microPercent &&  GetUpperShadowPercent() < microPercent && GetLowerShadowPercent() > smallPercent)
	{
		return true;
	}
	return false;
}
bool StockData::isDaoTZiXian()
{
	if (GetEntityPercent() < microPercent &&  GetLowerShadowPercent() < microPercent && GetUpperShadowPercent() > smallPercent)
	{
		return true;
	}
	return false;
}

/*********************************************************************************************************/

StockDataArray::StockDataArray()
{
	m_dataArray.clear();

	////暂时伪造十个数据

	//StockData data086;
	//data086.SetStockName("曙光股份");
	//data086.SetStockTime(20160428);
	//data086.SetMiddlePrice(11.71);
	//data086.SetKaiPanPrice(11.85);
	//data086.SetShouPanPrice(11.40);
	//data086.SetHighPrice(11.85);
	//data086.SetLowPrice(11);
	//data086.SetChengJiaoCounts(42);
	//m_dataArray.push_back(data086);

	//StockData data087;
	//data087.SetStockName("曙光股份");
	//data087.SetStockTime(20160427);
	//data087.SetMiddlePrice(11.49);
	//data087.SetKaiPanPrice(11.50);
	//data087.SetShouPanPrice(11.71);
	//data087.SetHighPrice(12.08);
	//data087.SetLowPrice(11.42);
	//data087.SetChengJiaoCounts(42);
	//m_dataArray.push_back(data087);

	//StockData data088;
	//data088.SetStockName("曙光股份");
	//data088.SetStockTime(20160426);
	//data088.SetMiddlePrice(10.90);
	//data088.SetKaiPanPrice(10.92);
	//data088.SetShouPanPrice(11.49);
	//data088.SetHighPrice(11.77);
	//data088.SetLowPrice(10.91);
	//data088.SetChengJiaoCounts(31.77);
	//m_dataArray.push_back(data088);

	//StockData data089;
	//data089.SetStockName("曙光股份");
	//data089.SetStockTime(20160425);
	//data089.SetMiddlePrice(11.29);
	//data089.SetKaiPanPrice(11.20);
	//data089.SetShouPanPrice(10.90);
	//data089.SetHighPrice(11.20);
	//data089.SetLowPrice(10.70);
	//data089.SetChengJiaoCounts(21.92);
	//m_dataArray.push_back(data089);

	//StockData data090;
	//data090.SetStockName("曙光股份");
	//data090.SetStockTime(20160422);
	//data090.SetMiddlePrice(11.11);
	//data090.SetKaiPanPrice(11.13);
	//data090.SetShouPanPrice(11.29);
	//data090.SetHighPrice(11.31);
	//data090.SetLowPrice(10.78);
	//data090.SetChengJiaoCounts(26.32);
	//m_dataArray.push_back(data090);

	//StockData data091;
	//data091.SetStockName("曙光股份");
	//data091.SetStockTime(20160421);
	//data091.SetMiddlePrice(11.35);
	//data091.SetKaiPanPrice(11.21);
	//data091.SetShouPanPrice(11.11);
	//data091.SetHighPrice(11.59);
	//data091.SetLowPrice(11.05);
	//data091.SetChengJiaoCounts(30.01);
	//m_dataArray.push_back(data091);

	//StockData data092;
	//data092.SetStockName("曙光股份");
	//data092.SetStockTime(20160420);
	//data092.SetMiddlePrice(12.35);
	//data092.SetKaiPanPrice(12.40);
	//data092.SetShouPanPrice(11.35);
	//data092.SetHighPrice(12.50);
	//data092.SetLowPrice(11.17);
	//data092.SetChengJiaoCounts(48.85);
	//m_dataArray.push_back(data092);

	//StockData data093;
	//data093.SetStockName("曙光股份");
	//data093.SetStockTime(20160419);
	//data093.SetMiddlePrice(12.09);
	//data093.SetKaiPanPrice(12.16);
	//data093.SetShouPanPrice(12.35);
	//data093.SetHighPrice(12.40);
	//data093.SetLowPrice(12.06);
	//data093.SetChengJiaoCounts(44.70);
	//m_dataArray.push_back(data093);

	//StockData data094;
	//data094.SetStockName("曙光股份");
	//data094.SetStockTime(20160418);
	//data094.SetMiddlePrice(12.16);
	//data094.SetKaiPanPrice(12);
	//data094.SetShouPanPrice(12.09);
	//data094.SetHighPrice(12.20);
	//data094.SetLowPrice(11.78);
	//data094.SetChengJiaoCounts(30.21);
	//m_dataArray.push_back(data094);

	//StockData data095;
	//data095.SetStockName("曙光股份");
	//data095.SetStockTime(20160415);
	//data095.SetMiddlePrice(12.35);
	//data095.SetKaiPanPrice(12.27);
	//data095.SetShouPanPrice(12.16);
	//data095.SetHighPrice(12.28);
	//data095.SetLowPrice(12.06);
	//data095.SetChengJiaoCounts(28.38);
	//m_dataArray.push_back(data095);

	//StockData data096;
	//data096.SetStockName("曙光股份");
	//data096.SetStockTime(20160414);
	//data096.SetMiddlePrice(12.19);
	//data096.SetKaiPanPrice(12.01);
	//data096.SetShouPanPrice(12.35);
	//data096.SetHighPrice(12.44);
	//data096.SetLowPrice(11.79);
	//data096.SetChengJiaoCounts(63.98);
	//m_dataArray.push_back(data096);

	//StockData data097;
	//data097.SetStockName("曙光股份");
	//data097.SetStockTime(20160413);
	//data097.SetMiddlePrice(12.20);
	//data097.SetKaiPanPrice(12.15);
	//data097.SetShouPanPrice(12.19);
	//data097.SetHighPrice(12.45);
	//data097.SetLowPrice(12.09);
	//data097.SetChengJiaoCounts(46.81);
	//m_dataArray.push_back(data097);

	//StockData data098;
	//data098.SetStockName("曙光股份");
	//data098.SetStockTime(20160412);
	//data098.SetMiddlePrice(12.94);
	//data098.SetKaiPanPrice(12.66);
	//data098.SetShouPanPrice(12.20);
	//data098.SetHighPrice(12.73);
	//data098.SetLowPrice(12);
	//data098.SetChengJiaoCounts(57.10);
	//m_dataArray.push_back(data098);

	//StockData data099;
	//data099.SetStockName("曙光股份");
	//data099.SetStockTime(20160411);
	//data099.SetMiddlePrice(12.95);
	//data099.SetKaiPanPrice(12.95);
	//data099.SetShouPanPrice(12.94);
	//data099.SetHighPrice(13.15);
	//data099.SetLowPrice(12.63);
	//data099.SetChengJiaoCounts(55.59);
	//m_dataArray.push_back(data099);
}

void StockDataArray::Initialize(const char* path)
{
	LoadDataFromFile(path);
}

void StockDataArray::LoadDataFromFile(const char* path)
{
	fstream fin(path); //打开文件
	char ReadLine[1024] = {0};
	double lastShouPan = 0.0;
	while(fin.getline(ReadLine,1024)) //逐行读取，直到结束
	{
		//日期	    开盘	    最高	    最低	    收盘	    成交量	    成交额
		unsigned int tmpTime = 19700101;
		double tmpKaiPan = 0.0;
		double tmpZuiGao = 0.0;
		double tmpZuiDi = 0.0;
		double tmpShouPan = 0.0;
		double tmpChengjiaoLiang = 0.0;
		double tmpChengJiaoE = 0.0;



		if (7 == sscanf_s(ReadLine,"%u,%lf,%lf,%lf,%lf,%lf,%lf",&tmpTime,&tmpKaiPan,&tmpZuiGao,&tmpZuiDi,&tmpShouPan,&tmpChengjiaoLiang,&tmpChengJiaoE))
		{
			StockData data;
			data.SetStockTime(tmpTime);
			data.SetMiddlePrice(lastShouPan);
			data.SetKaiPanPrice(tmpKaiPan);
			data.SetHighPrice(tmpZuiGao);
			data.SetLowPrice(tmpZuiDi);
			data.SetShouPanPrice(tmpShouPan);
			data.SetChengJiaoCounts(tmpChengjiaoLiang);
			data.SetChengJiaoValue(tmpChengJiaoE);
			data.SetMA5(GetAverageMA(m_dataArray,data.GetShouPanPrice(),5));
			data.SetMA10(GetAverageMA(m_dataArray,data.GetShouPanPrice(),10));
			data.SetMA20(GetAverageMA(m_dataArray,data.GetShouPanPrice(),20));
			data.SetMA60(GetAverageMA(m_dataArray,data.GetShouPanPrice(),60));
			data.SetMA120(GetAverageMA(m_dataArray,data.GetShouPanPrice(),120));
			data.SetMA250(GetAverageMA(m_dataArray,data.GetShouPanPrice(),250));
			data.SetPA5(GetAveragePA(m_dataArray,data.GetShouPanPrice(),5));
			if (m_dataArray.size() > 0)
			{
				StockData lastData = m_dataArray.front();
				if (data.GetKaiPanPrice() < lastData.GetLowPrice())
				{
					data.SetKaiPanStatus(TIAOKONGDIKAI);
				}
				else if (data.GetKaiPanPrice() < lastData.GetShouPanPrice())
				{
					data.SetKaiPanStatus(DIKAI);
				}

				if (data.GetKaiPanPrice() > lastData.GetHighPrice())
				{
					data.SetKaiPanStatus(TIAOKONGGAOKAI);
				}
				else if (data.GetKaiPanPrice() > lastData.GetShouPanPrice())
				{
					data.SetKaiPanStatus(GAOKAI);
				}
			}
			lastShouPan = tmpShouPan;
			m_dataArray.push_front(data);
		}

		memset(ReadLine,0,1024);
	} 
	fin.close();
}

list<StockData> StockDataArray::GetLastNDaysData(unsigned int days)
{
	list<StockData> dataList;
	
	if (m_dataArray.size() < days)
	{
		return dataList;
	}

	list<StockData>::iterator iter;
	unsigned int i = 0;
	for (iter = m_dataArray.begin(); i < days && iter != m_dataArray.end();iter++,i++)
	{
		StockData data = *iter;
		dataList.push_front(data);
	}

	return dataList;
}

list<StockData>& StockDataArray::GetAllData()
{
	return m_dataArray;
}

StockData StockDataArray::GetDayAt(unsigned int day)
{
	StockData tmpData;
	list<StockData>::iterator iter;
	unsigned int i = 0;
	for (iter = m_dataArray.begin(); i < day -1 && iter != m_dataArray.end();iter++,i++)
	{
	}
	if (iter == m_dataArray.end())
	{
		return tmpData;
	}
	tmpData = *iter;
	return tmpData;
}

unsigned int StockDataArray::GetArraySize()
{
	return m_dataArray.size();
}

StockData StockDataArray::front()
{
	return m_dataArray.front();
}

void StockDataArray::PopFront()
{
	m_dataArray.pop_front();
}

void StockDataArray::PushFront(StockData data)
{
	m_dataArray.push_front(data);
}

double StockDataArray::GetAverageMA(list<StockData>& stockList,double shoupanjia, unsigned int days)//计算均线
{
	double result = 0.0;
	unsigned int realDays = 0;
	double totalCharge = 0.0;
	list<StockData>::iterator iter = stockList.begin();
	for (;realDays < days - 1 && realDays < stockList.size();realDays++,iter++)
	{
		totalCharge += iter->GetShouPanPrice();
	}

	totalCharge += shoupanjia;
	realDays += 1; 
	result = totalCharge / realDays;

	return result;
}

double StockDataArray::GetAveragePA(list<StockData>& stockList,double chengjiaoliang, unsigned int days)//计算量比
{
	double result = 1.0;
	unsigned int realDays = 0;
	double totalCharge = 0.0;
	list<StockData>::iterator iter = stockList.begin();
	for (;realDays < days && realDays < stockList.size();realDays++,iter++)
	{
		totalCharge += iter->GetChengJiaoCounts();
	}

	if (realDays > 0)
	{
		result = chengjiaoliang / (totalCharge / realDays);
	}

	return result;
}