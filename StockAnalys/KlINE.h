#pragma once

//#include <Windows.h>
#include "stdafx.h"
#include <list>
using namespace std;

typedef int (*KLineAnalys)(bool status);

class KlINE
{
public:
	KlINE(void);
	~KlINE(void);

public:
	void SetKLineName(CString val){m_kLineName = val;}
	CString GetKLineName(){return m_kLineName;}


	void SetKLineDescription(CString val){m_kLineDescription = val;}
	CString GetKLineDescription(){return m_kLineDescription;}

	void SetKLineAnalysFun(KLineAnalys val){m_kLineAnalysFun = val;}

public:
		KLineAnalys m_kLineAnalysFun;

private:
	CString m_kLineName;
	CString m_kLineDescription;

};

class KlINEArray
{

public:
	static KlINEArray* GetInstance()
	{	if (m_pKLineArray == NULL)
		{
			m_pKLineArray = new KlINEArray();
		}
		return m_pKLineArray;
	}

	int StartAnalysis(bool bPrintf = true);
	void StartForecast();
	void StartBuyOrSale(unsigned int days = 0xFFFFFFFF,const char* pathName = "",int buyOrSaleType = 0,bool bPrintf = true);
private:
	KlINEArray();

public:
	static KlINEArray* m_pKLineArray;
private:
	list<KlINE> m_kLineArray;
};