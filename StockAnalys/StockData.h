#pragma once

#include "stdafx.h"
#include <list>

using namespace std;

enum KAIPANSTATUS
{
	NONESTATUS = 0,
	TIAOKONGDIKAI,
	DIKAI,
	GAOKAI,
	TIAOKONGGAOKAI
};



class StockData
{
public:
	StockData(void);
	~StockData(void);

public:
	void SetStockName(CString val){m_stockName = val;}
	CString GetStockName(){return m_stockName;}

	void SetStockTime(unsigned int val){m_stockTime = val;}
	unsigned int GetStockTime(){return m_stockTime;}

	void SetMiddlePrice(double val){m_MiddlePrice = val;}
	double GetMiddlePrice(){return m_MiddlePrice;}

	void SetKaiPanPrice(double val){m_KaiPanPrice = val;}
	double GetKaiPanPrice(){return m_KaiPanPrice;}

	void SetShouPanPrice(double val){m_ShouPanPrice = val;}
	double GetShouPanPrice(){return m_ShouPanPrice;}

	void SetHighPrice(double val){m_HighPrice = val;}
	double GetHighPrice(){return m_HighPrice;}

	void SetLowPrice(double val){m_LowPrice = val;}
	double GetLowPrice(){return m_LowPrice;}

	void SetChengJiaoCounts(double val){m_ChengJiaoCounts = val;}
	double GetChengJiaoCounts(){return m_ChengJiaoCounts;}

	void SetChengJiaoValue(double val){m_ChengJiaoValue = val;}
	double GetChengJiaoValue(){return m_ChengJiaoValue;}

	void SetKaiPanStatus(KAIPANSTATUS val){m_KaiPanStatus = val;}
	KAIPANSTATUS GetKaiPanStatus(){return m_KaiPanStatus;}

	void SetMA5(double val){m_MA5 = val;}
	double GetMA5(){return m_MA5;}

	void SetMA10(double val){m_MA10 = val;}
	double GetMA10(){return m_MA10;}

	void SetMA20(double val){m_MA20 = val;}
	double GetMA20(){return m_MA20;}

	void SetMA60(double val){m_MA60 = val;}
	double GetMA60(){return m_MA60;}

	void SetMA120(double val){m_MA120 = val;}
	double GetMA120(){return m_MA120;}

	void SetMA250(double val){m_MA250 = val;}
	double GetMA250(){return m_MA250;}

	void SetPA5(double val){m_PA5 = val;}
	double GetPA5(){return m_PA5;}

public:
	int GetYinYangLine();
	double GetEntityPercent();
	double GetUpperShadowPercent();
	double GetLowerShadowPercent();
	double GetEntityHighPrice();
	double GetEntityLowPrice();
	bool isChuiTouXian();
	bool isDaoChuiTouXian();
	bool isDaYangXian();
	bool isDaYinXian();
	bool isZhongYangXian();
	bool isZhongYinXian();
	bool isXiaoYangXian();
	bool isXiaoYinXian();
	bool isShiZiXian();
	bool isChangShiZiXian();
	bool isLuoXuanJiang();
	bool isYiZiXian();
	bool isTZiXian();
	bool isDaoTZiXian();

private:
	CString m_stockName;//����
	unsigned int m_stockTime;//ʱ��
	double m_MiddlePrice;//�м�۸����ռ�
	double m_KaiPanPrice;//���̼�
	double m_ShouPanPrice;//���̼�
	double m_HighPrice;//��߼�
	double m_LowPrice;//��ͼ�
	double m_ChengJiaoCounts;//�ɽ���
	double m_ChengJiaoValue;//�ɽ���
	KAIPANSTATUS m_KaiPanStatus;//����״̬
	double m_MA5;//5�վ���
	double m_MA10;//10�վ���
	double m_MA20;//20�վ���
	double m_MA60;//60�վ���
	double m_MA120;//120�վ���
	double m_MA250;//250�վ���
	double m_PA5;//���ȣ�5�գ�
};


class StockDataArray
{

public:
	static StockDataArray* GetInstance()
	{	if (m_pStockDataArray == NULL)
		{
			m_pStockDataArray = new StockDataArray();
		}
		return m_pStockDataArray;
	}

	list<StockData> GetLastNDaysData(unsigned int days);
	list<StockData>& GetAllData();
	StockData GetDayAt(unsigned int day);
	unsigned int GetArraySize();
	StockData front();
	void PopFront();
	void PushFront(StockData data);
	void Initialize(const char* path);


private:
	StockDataArray();
	void LoadDataFromFile(const char* path);
	double GetAverageMA(list<StockData>& stockList, double shoupanjia, unsigned int days);//�������
	double GetAveragePA(list<StockData>& stockList, double chengjiaoliang, unsigned int days);//��������

private:
	static StockDataArray* m_pStockDataArray;
	list<StockData> m_dataArray;
};

class BuyOrSaleStock
{
public:
	int stockType;
	StockData stockData;
};