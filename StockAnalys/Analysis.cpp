#include "StdAfx.h"
#include "Analysis.h"
#include <list>
#include "StockData.h"
#include "StockHeader.h"
#include <math.h>

using namespace std;

#define  CHARGETYPE(K,M)  ((K)?true:(M))

int Analysis::TrendAnalysis(bool printLog)
{
	//取数据
	int days = 5;
	int result = ZOUSHI_UNKNOWN;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析

	list<StockData>::iterator beginIter = dataList.begin();
	list<StockData>::iterator endIter = dataList.end();
	double beginPrice = beginIter->GetKaiPanPrice();
	endIter--;
	double endPrice =endIter->GetShouPanPrice();
	if (printLog)
	{
		printf("-------------------------------------------------------------------\n");
		printf("今日日期：%d\n",endIter->GetStockTime());
	}


	double lastShoupan = beginIter->GetKaiPanPrice();
	double totalIncrease = 0.0;
	double maxPrice = 0.0;
	double minPrice = 9999.99;
	for (;beginIter != dataList.end();beginIter++)
	{
		totalIncrease += beginIter->GetShouPanPrice() - lastShoupan;
		lastShoupan = beginIter->GetShouPanPrice();

		if (maxPrice < beginIter->GetShouPanPrice())
		{
			maxPrice = beginIter->GetShouPanPrice();
		}
		if (minPrice > beginIter->GetShouPanPrice())
		{
			minPrice = beginIter->GetShouPanPrice();
		}
	}
	
	double increasePercent = (endPrice - beginPrice) / beginPrice;
	double shackPercent = (maxPrice - minPrice) / beginPrice;

	if (printLog)
	{
		printf("增幅百分比：%.2f%%\n平均增幅百分比：%.2f%%\n振幅百分比：%.2f%%\n振幅与增幅比:%.2f\n",increasePercent * 100,(increasePercent / days) * 100,shackPercent * 100,fabs(shackPercent / increasePercent));
	}
	
	if ((increasePercent / days) > 0.005)
	{
		if ((increasePercent / days) > 0.02)
		{
			result = ZOUSHI_HIGHUP;
			if (printLog)
			{
				printf("剧烈上升趋势！\n");
			}
		}
		else if (fabs(shackPercent / increasePercent) < 2.0)
		{
			result = ZOUSHI_LOWUP;
			
			if (printLog)
			{
				printf("稳步上升趋势！\n");
			}
		}
		else
		{
			result = ZOUSHI_ZHENDANGUP;
			
			if (printLog)
			{
				printf("震荡上升趋势！\n");
			}
		}

	}
	else if ((increasePercent / days) < -0.005)
	{
		if ((increasePercent / days) < -0.02)
		{
			result = ZOUSHI_HIGHDOWN;
			
			if (printLog)
			{
				printf("剧烈下降趋势！\n");
			}
		}
		else if (fabs(shackPercent / increasePercent) < 2.0)
		{
			result = ZOUSHI_LOWDOWN;
			
			if (printLog)
			{
				printf("稳步下降趋势！\n");
			}
		}
		else
		{
			result = ZOUSHI_ZHENGDANGDOWN;
			
			if (printLog)
			{
				printf("震荡下降趋势！\n");
			}
		}
	}
	else
	{
		if (fabs(shackPercent / increasePercent) < 2.0)
		{
			result = ZOUSHI_LOWHENGPAN;
			
			if (printLog)
			{
				printf("稳步横盘整理！\n");
			}
		}
		else
		{
			result = ZOUSHI_HIGHHENGPAN;

			if (printLog)
			{
				printf("震荡横盘整理！\n");
			}
		}
	}
	if (printLog)
	{
		printf("-------------------------------------------------------------------\n");
	}

	return result;
}

void Analysis::KaipanZoushiAnalysis()
{
	//取数据
	int days = 5;
	double result = 0.0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetAllData();
	if (dataList.size() == 0)
	{
		return;
	}

	list<StockData>::iterator iter;
	unsigned int total = 0;
	unsigned int tiaokongdikai = 0;
	unsigned int tiaokongdikai_xiaoyin = 0;
	unsigned int tiaokongdikai_xiaoyang = 0;
	unsigned int tiaokongdikai_zhongyin = 0;
	unsigned int tiaokongdikai_zhongyang = 0;
	unsigned int tiaokongdikai_dayin = 0;
	unsigned int tiaokongdikai_dayang = 0;
	unsigned int tiaokongdikai_other = 0;
	unsigned int dikai = 0;
	unsigned int dikai_xiaoyin = 0;
	unsigned int dikai_xiaoyang = 0;
	unsigned int dikai_zhongyin = 0;
	unsigned int dikai_zhongyang = 0;
	unsigned int dikai_dayin = 0;
	unsigned int dikai_dayang = 0;
	unsigned int dikai_other = 0;
	unsigned int gaokai = 0;
	unsigned int gaokai_xiaoyin = 0;
	unsigned int gaokai_xiaoyang = 0;
	unsigned int gaokai_zhongyin = 0;
	unsigned int gaokai_zhongyang = 0;
	unsigned int gaokai_dayin = 0;
	unsigned int gaokai_dayang = 0;
	unsigned int gaokai_other = 0;
	unsigned int tiaokonggaokai = 0;
	unsigned int tiaokonggaokai_xiaoyin = 0;
	unsigned int tiaokonggaokai_xiaoyang = 0;
	unsigned int tiaokonggaokai_zhongyin = 0;
	unsigned int tiaokonggaokai_zhongyang = 0;
	unsigned int tiaokonggaokai_dayin = 0;
	unsigned int tiaokonggaokai_dayang = 0;
	unsigned int tiaokonggaokai_other = 0;
	unsigned int otherkai = 0;
	unsigned int otherkai_xiaoyin = 0;
	unsigned int otherkai_xiaoyang = 0;
	unsigned int otherkai_zhongyin = 0;
	unsigned int otherkai_zhongyang = 0;
	unsigned int otherkai_dayin = 0;
	unsigned int otherkai_dayang = 0;
	unsigned int otherkai_other = 0;

	for (iter = dataList.begin(); iter != dataList.end();iter++)
	{
		total++;
		StockData data = *iter;
		if (data.GetKaiPanStatus() == TIAOKONGDIKAI)
		{
			tiaokongdikai++;
			if (data.isXiaoYangXian())
			{
				tiaokongdikai_xiaoyang++;
			}
			else if (data.isXiaoYinXian())
			{
				tiaokongdikai_xiaoyin++;
			}
			else if (data.isZhongYangXian())
			{
				tiaokongdikai_zhongyang++;
			}
			else if (data.isZhongYinXian())
			{
				tiaokongdikai_zhongyin++;
			}
			else if (data.isDaYangXian())
			{
				tiaokongdikai_dayang++;
			}
			else if (data.isDaYinXian())
			{
				tiaokongdikai_dayin++;
			}
			else
			{
				tiaokongdikai_other++;
			}
		}
		else if (data.GetKaiPanStatus() == DIKAI)
		{
			dikai++;
			if (data.isXiaoYangXian())
			{
				dikai_xiaoyang++;
			}
			else if (data.isXiaoYinXian())
			{
				dikai_xiaoyin++;
			}
			else if (data.isZhongYangXian())
			{
				dikai_zhongyang++;
			}
			else if (data.isZhongYinXian())
			{
				dikai_zhongyin++;
			}
			else if (data.isDaYangXian())
			{
				dikai_dayang++;
			}
			else if (data.isDaYinXian())
			{
				dikai_dayin++;
			}
			else
			{
				dikai_other++;
			}
		}
		else if (data.GetKaiPanStatus() == GAOKAI)
		{
			gaokai++;
			if (data.isXiaoYangXian())
			{
				gaokai_xiaoyang++;
			}
			else if (data.isXiaoYinXian())
			{
				gaokai_xiaoyin++;
			}
			else if (data.isZhongYangXian())
			{
				gaokai_zhongyang++;
			}
			else if (data.isZhongYinXian())
			{
				gaokai_zhongyin++;
			}
			else if (data.isDaYangXian())
			{
				gaokai_dayang++;
			}
			else if (data.isDaYinXian())
			{
				gaokai_dayin++;
			}
			else
			{
				gaokai_other++;
			}
		}
		else if (data.GetKaiPanStatus() == TIAOKONGGAOKAI)
		{
			tiaokonggaokai++;
			if (data.isXiaoYangXian())
			{
				tiaokonggaokai_xiaoyang++;
			}
			else if (data.isXiaoYinXian())
			{
				tiaokonggaokai_xiaoyin++;
			}
			else if (data.isZhongYangXian())
			{
				tiaokonggaokai_zhongyang++;
			}
			else if (data.isZhongYinXian())
			{
				tiaokonggaokai_zhongyin++;
			}
			else if (data.isDaYangXian())
			{
				tiaokonggaokai_dayang++;
			}
			else if (data.isDaYinXian())
			{
				tiaokonggaokai_dayin++;
			}
			else
			{
				tiaokonggaokai_other++;
			}
		}
		else
		{
			otherkai++;
			if (data.isXiaoYangXian())
			{
				otherkai_xiaoyang++;
			}
			else if (data.isXiaoYinXian())
			{
				otherkai_xiaoyin++;
			}
			else if (data.isZhongYangXian())
			{
				otherkai_zhongyang++;
			}
			else if (data.isZhongYinXian())
			{
				otherkai_zhongyin++;
			}
			else if (data.isDaYangXian())
			{
				otherkai_dayang++;
			}
			else if (data.isDaYinXian())
			{
				otherkai_dayin++;
			}
			else
			{
				otherkai_other++;
			}
		}
	}

	printf("*总数:%d\n",total);
	printf("*跳空低开：数量：%d  百分比：%.2f%%\n",tiaokongdikai,(tiaokongdikai * 100.0) / total);
	printf("*\t\t小阳：数量：%d  百分比：%.2f%%\n",tiaokongdikai_xiaoyang,(tiaokongdikai_xiaoyang * 100.0) / tiaokongdikai);
	printf("*\t\t中阳：数量：%d  百分比：%.2f%%\n",tiaokongdikai_zhongyang,(tiaokongdikai_zhongyang * 100.0) / tiaokongdikai);
	printf("*\t\t大阳：数量：%d  百分比：%.2f%%\n",tiaokongdikai_dayang,(tiaokongdikai_dayang * 100.0) / tiaokongdikai);
	printf("*\t\t小阴：数量：%d  百分比：%.2f%%\n",tiaokongdikai_xiaoyin,(tiaokongdikai_xiaoyin * 100.0) / tiaokongdikai);
	printf("*\t\t中阴：数量：%d  百分比：%.2f%%\n",tiaokongdikai_zhongyin,(tiaokongdikai_zhongyin * 100.0) / tiaokongdikai);
	printf("*\t\t大阴：数量：%d  百分比：%.2f%%\n",tiaokongdikai_dayin,(tiaokongdikai_dayin * 100.0) / tiaokongdikai);
	printf("*\t\t其它：数量：%d  百分比：%.2f%%\n",tiaokongdikai_other,(tiaokongdikai_other * 100.0) / tiaokongdikai);


	printf("*低    开：数量：%d  百分比：%.2f%%\n",dikai,(dikai * 100.0) / total);
	printf("*\t\t小阳：数量：%d  百分比：%.2f%%\n",dikai_xiaoyang,(dikai_xiaoyang * 100.0) / dikai);
	printf("*\t\t中阳：数量：%d  百分比：%.2f%%\n",dikai_zhongyang,(dikai_zhongyang * 100.0) / dikai);
	printf("*\t\t大阳：数量：%d  百分比：%.2f%%\n",dikai_dayang,(dikai_dayang * 100.0) / dikai);
	printf("*\t\t小阴：数量：%d  百分比：%.2f%%\n",dikai_xiaoyin,(dikai_xiaoyin * 100.0) / dikai);
	printf("*\t\t中阴：数量：%d  百分比：%.2f%%\n",dikai_zhongyin,(dikai_zhongyin * 100.0) / dikai);
	printf("*\t\t大阴：数量：%d  百分比：%.2f%%\n",dikai_dayin,(dikai_dayin * 100.0) / dikai);
	printf("*\t\t其它：数量：%d  百分比：%.2f%%\n",dikai_other,(dikai_other * 100.0) / dikai);

	printf("*高    开：数量：%d  百分比：%.2f%%\n",gaokai,(gaokai * 100.0) / total);
	printf("*\t\t小阳：数量：%d  百分比：%.2f%%\n",gaokai_xiaoyang,(gaokai_xiaoyang * 100.0) / gaokai);
	printf("*\t\t中阳：数量：%d  百分比：%.2f%%\n",gaokai_zhongyang,(gaokai_zhongyang * 100.0) / gaokai);
	printf("*\t\t大阳：数量：%d  百分比：%.2f%%\n",gaokai_dayang,(gaokai_dayang * 100.0) / gaokai);
	printf("*\t\t小阴：数量：%d  百分比：%.2f%%\n",gaokai_xiaoyin,(gaokai_xiaoyin * 100.0) / gaokai);
	printf("*\t\t中阴：数量：%d  百分比：%.2f%%\n",gaokai_zhongyin,(gaokai_zhongyin * 100.0) / gaokai);
	printf("*\t\t大阴：数量：%d  百分比：%.2f%%\n",gaokai_dayin,(gaokai_dayin * 100.0) / gaokai);
	printf("*\t\t其它：数量：%d  百分比：%.2f%%\n",gaokai_other,(gaokai_other * 100.0) / gaokai);

	printf("*跳空高开：数量：%d  百分比：%.2f%%\n",tiaokonggaokai,(tiaokonggaokai * 100.0) / total);
	printf("*\t\t小阳：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_xiaoyang,(tiaokonggaokai_xiaoyang * 100.0) / tiaokonggaokai);
	printf("*\t\t中阳：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_zhongyang,(tiaokonggaokai_zhongyang * 100.0) / tiaokonggaokai);
	printf("*\t\t大阳：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_dayang,(tiaokonggaokai_dayang * 100.0) / tiaokonggaokai);
	printf("*\t\t小阴：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_xiaoyin,(tiaokonggaokai_xiaoyin * 100.0) / tiaokonggaokai);
	printf("*\t\t中阴：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_zhongyin,(tiaokonggaokai_zhongyin * 100.0) / tiaokonggaokai);
	printf("*\t\t大阴：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_dayin,(tiaokonggaokai_dayin * 100.0) / tiaokonggaokai);
	printf("*\t\t其它：数量：%d  百分比：%.2f%%\n",tiaokonggaokai_other,(tiaokonggaokai_other * 100.0) / tiaokonggaokai);

	printf("*其    它：数量：%d  百分比：%.2f%%\n",otherkai,(otherkai * 100.0) / total);
	printf("*\t\t小阳：数量：%d  百分比：%.2f%%\n",otherkai_xiaoyang,(otherkai_xiaoyang * 100.0) / otherkai);
	printf("*\t\t中阳：数量：%d  百分比：%.2f%%\n",otherkai_zhongyang,(otherkai_zhongyang * 100.0) / otherkai);
	printf("*\t\t大阳：数量：%d  百分比：%.2f%%\n",otherkai_dayang,(otherkai_dayang * 100.0) / otherkai);
	printf("*\t\t小阴：数量：%d  百分比：%.2f%%\n",otherkai_xiaoyin,(otherkai_xiaoyin * 100.0) / otherkai);
	printf("*\t\t中阴：数量：%d  百分比：%.2f%%\n",otherkai_zhongyin,(otherkai_zhongyin * 100.0) / otherkai);
	printf("*\t\t大阴：数量：%d  百分比：%.2f%%\n",otherkai_dayin,(otherkai_dayin * 100.0) / otherkai);
	printf("*\t\t其它：数量：%d  百分比：%.2f%%\n",otherkai_other,(otherkai_other * 100.0) / otherkai);

}


int Analysis::KLineAnaly001(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//大阴 + 十字星 + 大阳
	if ((data1.isDaYinXian() || data2.isZhongYinXian())
		&&(data2.isShiZiXian() || data2.isChangShiZiXian())
		&& (CHARGETYPE(status,data3.isDaYangXian()) || CHARGETYPE(status,data3.isZhongYangXian()))
		)
	{
		//if (Analysis::TrendAnalysis() < 0.0)//在下降趋势中
		{
			//十字星的一字在另两根线的线的底部下方
			//if (data2.GetKaiPanPrice() < data1.GetShouPanPrice() && data2.GetShouPanPrice() < data1.GetShouPanPrice()
			//	&& data2.GetKaiPanPrice() < data3.GetKaiPanPrice() && data2.GetShouPanPrice() < data3.GetKaiPanPrice())
			{
				result = 1;
			}
		}
	}
	return result;
}

int Analysis::KLineAnaly002(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//大阴 + 小阴（小阳） + 大阳
	if ((data1.isDaYinXian() || data2.isZhongYinXian())
		&&(data2.isXiaoYangXian() || data2.isXiaoYinXian())
		&& (CHARGETYPE(status,data3.isDaYangXian()) || CHARGETYPE(status,data3.isZhongYangXian()))
		)
	{
		//if (Analysis::TrendAnalysis() < 0.0)//在下降趋势中
		{
			//十字星的一字在另两根线的线的底部下方
			//if (data2.GetKaiPanPrice() < data1.GetShouPanPrice() && data2.GetShouPanPrice() < data1.GetShouPanPrice()
			//	&& data2.GetKaiPanPrice() < data3.GetKaiPanPrice() && data2.GetShouPanPrice() < data3.GetKaiPanPrice())
			{
				result = 1;
			}
		}
	}
	return result;
}

int Analysis::KLineAnaly003(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阴  + 大阳
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() < 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() > 0))
		&& (CHARGETYPE(status,data2.GetKaiPanPrice() < data1.GetShouPanPrice()))
		&&(CHARGETYPE(status,fabs(data2.GetShouPanPrice() - data1.GetShouPanPrice()) / data1.GetShouPanPrice() < microPercent))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly004(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阴  + 大阳
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() < 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() > 0))
		&&(CHARGETYPE(status,data2.GetShouPanPrice() > (data1.GetShouPanPrice() + (data1.GetKaiPanPrice() - data1.GetShouPanPrice()) / 2)))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly005(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阴  + 大阳
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() < 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() > 0))
		&&(CHARGETYPE(status,data2.GetShouPanPrice() > data1.GetKaiPanPrice()))
		)
	{
		result = 1;;
	}
	return result;
}


int Analysis::KLineAnaly006(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();


	//倒锤线
	if (CHARGETYPE(status,data1.isDaoChuiTouXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp <= ZOUSHI_LOWDOWN)
		{
			result = 1;;
		}
	}
	return result;
}

int Analysis::KLineAnaly007(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();


	//锤线
	if (CHARGETYPE(status,data1.isChuiTouXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp <= ZOUSHI_LOWDOWN)
		{
			result = 1;;
		}
	}
	return result;
}

int Analysis::KLineAnaly008(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//最低价相同
	if ((CHARGETYPE(status,fabs(data1.GetLowPrice() - data2.GetLowPrice()) / data1.GetLowPrice() < microPercent))
		&& data1.GetUpperShadowPercent() < smallPercent
		&& CHARGETYPE(status,data2.GetUpperShadowPercent() < smallPercent)
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly009(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.isDaYangXian()) && CHARGETYPE(status,data1.isZhongYangXian())))
	{
		return result;
	}
	
	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.isXiaoYangXian() || data.isXiaoYinXian())
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			if (data.isDaYinXian() || data.isZhongYinXian())
			{
				int tmp = Analysis::TrendAnalysis(false);
				if (tmp <= ZOUSHI_LOWDOWN)
				{
					result = 1;
				}
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	//result = 1;;
	return result;
}

int Analysis::KLineAnaly010(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() > 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > smallPercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	StockData data2 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(data2.GetEntityPercent() < middlePercent && CHARGETYPE(status,data2.GetHighPrice() < data1.GetLowPrice())) )
	{
		return result;
	}

	dataList.push_back(data2);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetEntityPercent() < middlePercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			if (data.GetYinYangLine() < 0.0 && data.GetEntityPercent() > middlePercent)
			{
				result = 1;;
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly011(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();


	//最低价相同
	if ((data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() > smallPercent && data2.GetHighPrice() < data1.GetLowPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > smallPercent) && CHARGETYPE(status,data3.GetHighPrice() < data1.GetLowPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly012(bool status)
{
	//取数据
	int days = 5;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();


	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() < middlePercent)
		&&(data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() < middlePercent)
		&&(data3.GetYinYangLine() > 0.0 && data3.GetEntityPercent() < middlePercent)
		&&(data4.GetYinYangLine() > 0.0 && data4.GetEntityPercent() < middlePercent)
		&&(CHARGETYPE(status,data5.GetYinYangLine() > 0.0) && CHARGETYPE(status,data5.GetEntityPercent() < middlePercent))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly013(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();


	//
	if ((data2.GetYinYangLine() < 0.0 && data2.GetKaiPanPrice() < data1.GetShouPanPrice())
		&&(data3.GetYinYangLine() < 0.0 && data3.GetKaiPanPrice() < data2.GetShouPanPrice())
		&&(CHARGETYPE(status,data4.GetYinYangLine() < 0.0) && CHARGETYPE(status,data4.GetKaiPanPrice() < data3.GetShouPanPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly014(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();


	//连续三个创新高小阳线
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() < middlePercent)
		&&(data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetShouPanPrice() > data1.GetShouPanPrice()/* && data2.GetKaiPanPrice() > data1.GetKaiPanPrice()*/)
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() < middlePercent) && CHARGETYPE(status,data3.GetShouPanPrice() > data2.GetShouPanPrice())/* && CHARGETYPE(status,data3.GetKaiPanPrice() > data2.GetKaiPanPrice())*/)
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly015(bool status)
{
	//取数据
	int days = 8;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();
	StockData data6 = dataList.front();
	dataList.pop_front();
	StockData data7 = dataList.front();
	dataList.pop_front();
	StockData data8 = dataList.front();
	dataList.pop_front();

	//略微倾斜的向上的小阳小阴十字星
	if ((data1.GetEntityPercent() < smallPercent)
		&&(data2.GetEntityPercent() < smallPercent)
		&&(data3.GetEntityPercent() < smallPercent)
		&&(data4.GetEntityPercent() < smallPercent)
		&&(data5.GetEntityPercent() < smallPercent)
		&&(data6.GetEntityPercent() < smallPercent)
		&&(data7.GetEntityPercent() < smallPercent)
		&&(CHARGETYPE(status,data8.GetEntityPercent() < smallPercent))
		&&(CHARGETYPE(status,data8.GetEntityHighPrice() > data1.GetEntityHighPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly016(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() > 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > middlePercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetYinYangLine() > 0.0 && data.GetEntityPercent() < smallPercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			else
			{
				result = 1;;
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly017(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if ((CHARGETYPE(i == 1 && status,data.GetYinYangLine() > 0.0) && CHARGETYPE(i == 1 && status,data.GetEntityPercent() > middlePercent)) || (CHARGETYPE(i == 1 && status,data.GetYinYangLine() < 0.0) && CHARGETYPE(i == 1 && status,data.GetEntityPercent() < middlePercent)))
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 5)
			{
				return result;
			}
			else
			{
				result = 1;;
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly018(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	StockData lastData = StockDataArray::GetInstance()->GetDayAt(i);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (CHARGETYPE(i==2 && status,data.GetEntityHighPrice() < lastData.GetEntityLowPrice()) )
		{
			dataList.push_back(data);
			i++;
			lastData = data;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			else
			{
				result = 1;;
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly019(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	StockData lastData = StockDataArray::GetInstance()->GetDayAt(i);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (CHARGETYPE(i == 2 && status,data.GetEntityLowPrice() < lastData.GetEntityLowPrice()))
		{
			dataList.push_back(data);
			i++;
			lastData = data;
		}
		else
		{
			if (i < 5)
			{
				return result;
			}
			else
			{
				result = 1;;
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly020(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//
	if ((CHARGETYPE(status,data2.GetYinYangLine() > 0.0) && CHARGETYPE(status,data2.GetEntityPercent() > largePercent) && CHARGETYPE(status,data2.GetEntityLowPrice() < data1.GetEntityLowPrice())/* && CHARGETYPE(status,data2.GetEntityHighPrice() > data1.GetEntityHighPrice())*/)
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly021(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//一个中大阳线右上方有两个小K
	if ((data1.GetEntityPercent() > middlePercent  && data1.GetYinYangLine() > 0.0)
		&&(data2.GetEntityPercent() < smallPercent && status,data2.GetKaiPanPrice() > data1.GetShouPanPrice() && data2.GetKaiPanPrice() > data1.GetShouPanPrice())
		&&(CHARGETYPE(status,data3.GetEntityPercent() < smallPercent) && CHARGETYPE(status,data3.GetKaiPanPrice() > data1.GetShouPanPrice()) && CHARGETYPE(status,data3.GetKaiPanPrice() > data1.GetShouPanPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly022(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//
	if ((data2.GetYinYangLine() > 0.0 && data2.GetKaiPanPrice() > data1.GetHighPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetShouPanPrice() > data2.GetKaiPanPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly023(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//
	if ((data2.GetYinYangLine() > 0.0 && data2.GetKaiPanPrice() > data1.GetHighPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,fabs(data3.GetKaiPanPrice() - data2.GetKaiPanPrice()) / data2.GetKaiPanPrice() < microPercent))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly024(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();

	//
	if ((data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetHighPrice() < data1.GetLowPrice())
		&&(data3.GetYinYangLine() < 0.0 && data3.GetEntityPercent() < middlePercent && data3.GetHighPrice() < data1.GetLowPrice())
		&&(CHARGETYPE(status,data4.GetYinYangLine() < 0.0) && CHARGETYPE(status,data4.GetEntityPercent() < middlePercent) && CHARGETYPE(status,data4.GetHighPrice() < data1.GetLowPrice()))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly025(bool status)
{
	//取数据
	int days = 5;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetLowPrice() > data1.GetKaiPanPrice())
		&&(data3.GetYinYangLine() < 0.0 && data3.GetEntityPercent() < middlePercent && data3.GetLowPrice() > data1.GetKaiPanPrice())
		&&(data4.GetYinYangLine() < 0.0 && data4.GetEntityPercent() < middlePercent && data4.GetLowPrice() > data1.GetKaiPanPrice())
		&&(CHARGETYPE(status,data5.GetYinYangLine() > 0.0) && CHARGETYPE(status,data5.GetEntityPercent() > middlePercent))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly026(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() > 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > middlePercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetEntityPercent() < middlePercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			//if (i < 4)
			//{
			//	return result;
			//}
			if (data.GetYinYangLine() > 0.0 && data.GetEntityPercent() > middlePercent && data.GetUpperShadowPercent() > middlePercent && CHARGETYPE(status,data1.GetEntityHighPrice() > data.GetHighPrice()))
			{
				result = 1;;
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	result = 1;;
	return result;
}

int Analysis::KLineAnaly027(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetKaiPanPrice() < data1.GetShouPanPrice() && CHARGETYPE(status,data2.GetKaiPanPrice() < data3.GetShouPanPrice()) && data2.GetShouPanPrice() > data1.GetKaiPanPrice() && CHARGETYPE(status,data2.GetShouPanPrice() > data3.GetKaiPanPrice()))
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent))
		)
	{
		result = 1;;
	}
	return result;
}

int Analysis::KLineAnaly028(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//大阳 + 十字星 + 大阴
	if ((data1.isZhongYangXian() || data1.isDaYangXian())
		&&(data2.isShiZiXian() || data2.isChangShiZiXian())
		&& (CHARGETYPE(status,data3.isDaYinXian()) || CHARGETYPE(status,data3.isZhongYinXian()))
		)
	{
		//if (Analysis::TrendAnalysis() < 0.0)//在下降趋势中
		{
			//十字星的一字在另两根线的线的底部下方
			//if (data2.GetKaiPanPrice() < data1.GetShouPanPrice() && data2.GetShouPanPrice() < data1.GetShouPanPrice()
			//	&& data2.GetKaiPanPrice() < data3.GetKaiPanPrice() && data2.GetShouPanPrice() < data3.GetKaiPanPrice())
			{
				result = -1;;
			}
		}
	}
	return result;
}

int Analysis::KLineAnaly029(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//大阳 + 小阴（小阳） + 大阴
	if ((data1.isZhongYangXian() || data1.isDaYangXian())
		&&(data2.isXiaoYinXian() || data2.isXiaoYangXian())
		&& (CHARGETYPE(status,data3.isDaYinXian()) || CHARGETYPE(status,data3.isZhongYinXian()))
		)
	{
		//if (Analysis::TrendAnalysis() < 0.0)//在下降趋势中
		{
			//十字星的一字在另两根线的线的底部下方
			//if (data2.GetKaiPanPrice() < data1.GetShouPanPrice() && data2.GetShouPanPrice() < data1.GetShouPanPrice()
			//	&& data2.GetKaiPanPrice() < data3.GetKaiPanPrice() && data2.GetShouPanPrice() < data3.GetKaiPanPrice())
			{
				result = -1;;
			}
		}
	}
	return result;
}

int Analysis::KLineAnaly030(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阳  + 大阴
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() > 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() < 0))
		&& (CHARGETYPE(status,data2.GetKaiPanPrice() > data1.GetShouPanPrice()))
		&&(CHARGETYPE(status,fabs(data2.GetShouPanPrice() - data1.GetShouPanPrice()) / data1.GetShouPanPrice() < microPercent))
		)
	{
		result = -1;;
	}
	return result;
}


int Analysis::KLineAnaly031(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阳  + 大阴
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() > 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() < 0))
		&&(CHARGETYPE(status,data2.GetShouPanPrice() < (data1.GetShouPanPrice() + (data1.GetKaiPanPrice() - data1.GetShouPanPrice()) / 2)))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly032(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//大阳  + 大阴
	if ((data1.GetEntityPercent() > middlePercent && data1.GetYinYangLine() > 0)
		&& (CHARGETYPE(status,data2.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data2.GetYinYangLine() < 0))
		&&(CHARGETYPE(status,data2.GetShouPanPrice() < data1.GetKaiPanPrice()))
		&&(CHARGETYPE(status,data2.GetKaiPanPrice() < data1.GetShouPanPrice()))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly033(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();


	//倒锤线
	if (CHARGETYPE(status,data1.isDaoChuiTouXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp >= ZOUSHI_LOWUP)
		{
			result = -1;;
		}
	}
	return result;
}

int Analysis::KLineAnaly034(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//锤线
	if (CHARGETYPE(status,data1.isChuiTouXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp >= ZOUSHI_LOWUP)
		{
			result = -1;;
		}
	}
	return result;
}

int Analysis::KLineAnaly035(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//最高价相同
	if ((CHARGETYPE(status,fabs(data1.GetHighPrice() - data2.GetHighPrice()) / data1.GetHighPrice() < microPercent))
		&& data1.GetLowerShadowPercent() < smallPercent
		&& CHARGETYPE(status,data2.GetLowerShadowPercent() < smallPercent)
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly036(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.isDaYinXian()) && CHARGETYPE(status,data1.isZhongYinXian())))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.isXiaoYangXian() || data.isXiaoYinXian())
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			if (data.isDaYangXian() || data.isZhongYangXian())
			{
				int tmp = Analysis::TrendAnalysis(false);
				if (tmp >= ZOUSHI_LOWUP)
				{
					result = -1;
				}

				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	//result = -1;;
	return result;
}

int Analysis::KLineAnaly037(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() < 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > smallPercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	StockData data2 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(data2.GetEntityPercent() < middlePercent && CHARGETYPE(status,data2.GetLowPrice() > data1.GetHighPrice())) )
	{
		return result;
	}

	dataList.push_back(data2);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetEntityPercent() < middlePercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			if (data.GetYinYangLine() > 0.0 && data.GetEntityPercent() > middlePercent)
			{
				result = -1;;
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly038(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();


	//
	if ((data1.GetYinYangLine() > 0.0)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetShouPanPrice() > data1.GetShouPanPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data3.GetKaiPanPrice() > data2.GetKaiPanPrice()) && CHARGETYPE(status,data3.GetShouPanPrice() < data2.GetShouPanPrice()) &&  CHARGETYPE(status,data3.GetShouPanPrice() > data1.GetShouPanPrice()))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly039(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();


	//
	if ((data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() > middlePercent && data2.GetKaiPanPrice() > data1.GetEntityLowPrice())
		&&(data3.GetYinYangLine() < 0.0 && data3.GetEntityPercent() > middlePercent  && data3.GetKaiPanPrice() > data2.GetEntityLowPrice())
		&&(CHARGETYPE(status,data4.GetYinYangLine() < 0.0) && CHARGETYPE(status,data4.GetEntityPercent() > middlePercent)  && CHARGETYPE(status,data4.GetKaiPanPrice() > data3.GetEntityLowPrice()))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly040(bool status)
{
	//取数据
	int days = 6;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();
	StockData data6 = dataList.front();
	dataList.pop_front();


	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() < middlePercent)
		&&(data3.GetYinYangLine() < 0.0 && data3.GetEntityPercent() < middlePercent)
		&&(data4.GetYinYangLine() < 0.0 && data4.GetEntityPercent() < middlePercent)
		&&(data5.GetYinYangLine() < 0.0 && data5.GetEntityPercent() < middlePercent)
		&&(CHARGETYPE(status,data6.GetYinYangLine() < 0.0) && CHARGETYPE(status,data6.GetEntityPercent() < middlePercent))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly041(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();


	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > smallPercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetHighPrice() > data1.GetHighPrice() && data2.GetLowPrice() < data1.GetLowPrice())
		&&(data3.GetYinYangLine() > 0.0 && data3.GetEntityPercent() < middlePercent && data3.GetEntityPercent() < data2.GetEntityPercent())
		&&(CHARGETYPE(status,data4.GetYinYangLine() < 0.0) && CHARGETYPE(status,fabs(data4.GetShouPanPrice() - data3.GetShouPanPrice()) / (data3.GetShouPanPrice() - data3.GetKaiPanPrice()) > 0.5))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly042(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() < 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > smallPercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	StockData data2 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(data2.GetEntityPercent() < smallPercent && CHARGETYPE(status,data1.GetKaiPanPrice() < data2.GetEntityLowPrice())))
	{
		return result;
	}

	dataList.push_back(data2);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if ((data.GetEntityPercent() < smallPercent))
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			else
			{
				result = -1;;
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly043(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();


	//连续三个创新低小阴线
	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() < middlePercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetShouPanPrice() < data1.GetShouPanPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetEntityPercent() < middlePercent) && CHARGETYPE(status,data3.GetShouPanPrice() < data2.GetShouPanPrice()))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly044(bool status)
{
	//取数据
	int days = 8;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();
	StockData data6 = dataList.front();
	dataList.pop_front();
	StockData data7 = dataList.front();
	dataList.pop_front();
	StockData data8 = dataList.front();
	dataList.pop_front();

	//略微倾斜的向下的小阳小阴十字星
	if ((data1.GetEntityPercent() < smallPercent)
		&&(data2.GetEntityPercent() < smallPercent)
		&&(data3.GetEntityPercent() < smallPercent)
		&&(data4.GetEntityPercent() < smallPercent)
		&&(data5.GetEntityPercent() < smallPercent)
		&&(data6.GetEntityPercent() < smallPercent)
		&&(data7.GetEntityPercent() < smallPercent)
		&&(CHARGETYPE(status,data8.GetEntityPercent() < smallPercent))
		&&(CHARGETYPE(status,data8.GetEntityLowPrice() < data1.GetEntityLowPrice()))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly045(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() < 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > middlePercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetYinYangLine() < 0.0 && data.GetEntityPercent() < middlePercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			else
			{
				result = -1;;
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly046(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if ((CHARGETYPE(i == 1 && status,data.GetYinYangLine() > 0.0) && CHARGETYPE(i == 1 && status,data.GetEntityPercent() < middlePercent)) || (CHARGETYPE(i == 1 && status,data.GetYinYangLine() < 0.0) && CHARGETYPE(i == 1 && status,data.GetEntityPercent() > middlePercent)))
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 5)
			{
				return result;
			}
			else
			{
				result = -1;;
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly047(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	StockData lastData = StockDataArray::GetInstance()->GetDayAt(i);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (CHARGETYPE(i == 2 && status,data.GetEntityLowPrice() > lastData.GetEntityHighPrice()))
		{
			dataList.push_back(data);
			i++;
			lastData = data;
		}
		else
		{
			if (i < 4)
			{
				return result;
			}
			else
			{
				result = -1;;
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly048(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();


	//略微倾斜的向上的小阳小阴十字星
	if ((CHARGETYPE(status,data2.GetYinYangLine() < 0.0) && CHARGETYPE(status,data2.GetEntityPercent() > largePercent) && CHARGETYPE(status,data2.GetEntityHighPrice() > data1.GetEntityHighPrice())/* && CHARGETYPE(status,data2.GetEntityHighPrice() > data1.GetEntityHighPrice())*/)
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly049(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetEntityPercent() < middlePercent /*&& data2.GetEntityHighPrice() < data1.GetEntityLowPrice()*/)
		&&(data3.GetEntityPercent() < middlePercent /*&& data3.GetEntityHighPrice() < data1.GetEntityLowPrice()*/)
		&&(CHARGETYPE(status,data4.GetEntityPercent() < middlePercent) /*&& CHARGETYPE(status,data4.GetEntityHighPrice() < data1.GetEntityLowPrice())*/)
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly050(bool status)
{
	//取数据
	int days = 5;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();
	StockData data5 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() < middlePercent && data2.GetHighPrice() < data1.GetKaiPanPrice())
		&&(data3.GetYinYangLine() > 0.0 && data3.GetEntityPercent() < middlePercent && data3.GetHighPrice() < data1.GetKaiPanPrice())
		&&(data4.GetYinYangLine() > 0.0 && data4.GetEntityPercent() < middlePercent && data4.GetHighPrice() < data1.GetKaiPanPrice())
		&&(CHARGETYPE(status,data5.GetYinYangLine() < 0.0) && CHARGETYPE(status,data5.GetEntityPercent() > middlePercent))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly051(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;
	StockData data1 = StockDataArray::GetInstance()->GetDayAt(i);
	if (!(CHARGETYPE(status,data1.GetYinYangLine() < 0.0) && CHARGETYPE(status,data1.GetEntityPercent() > middlePercent)))
	{
		return result;
	}

	dataList.push_back(data1);
	i++;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if (data.GetEntityPercent() < middlePercent)
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			//if (i < 4)
			//{
			//	return result;
			//}
			if (data.GetYinYangLine() < 0.0 && data.GetEntityPercent() > middlePercent && data.GetLowerShadowPercent() > middlePercent && CHARGETYPE(status,data1.GetEntityLowPrice() < data.GetLowPrice()))
			{
				result = -1;;
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	result = -1;;
	return result;
}

int Analysis::KLineAnaly052(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();


	//
	if ((data2.GetYinYangLine() > 0.0 && data2.GetEntityHighPrice() < data1.GetEntityLowPrice() && data2.GetEntityLowPrice() < data1.GetEntityLowPrice())
		&&(data3.GetYinYangLine() > 0.0 && data3.GetEntityHighPrice() < data2.GetEntityLowPrice() && data3.GetEntityLowPrice() < data2.GetEntityLowPrice())
		&&(CHARGETYPE(status,data4.GetYinYangLine() > 0.0) && CHARGETYPE(status,data4.GetEntityHighPrice() < data3.GetEntityLowPrice()) && CHARGETYPE(status,data4.GetEntityLowPrice() < data3.GetEntityLowPrice()))
		)
	{
		result = -1;;
	}
	return result;
}
int Analysis::KLineAnaly053(bool status)
{
	//取数据
	int days = 4;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	StockData data4 = dataList.front();
	dataList.pop_front();


	//
	if ((data2.GetYinYangLine() > 0.0 && data2.GetKaiPanPrice() > data1.GetEntityHighPrice())
		&&(data3.GetYinYangLine() > 0.0 && data3.GetKaiPanPrice() > data2.GetEntityHighPrice())
		&&(CHARGETYPE(status,data4.GetYinYangLine() > 0.0) && CHARGETYPE(status,data4.GetKaiPanPrice() > data3.GetEntityHighPrice()))
		)
	{
		result = -1;;
	}
	return result;
}
int Analysis::KLineAnaly054(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();



	//
	if ((data1.GetYinYangLine() > 0.0 )
		&&(data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() < data1.GetEntityPercent())
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() < data2.GetEntityPercent()) && CHARGETYPE(status,data3.GetUpperShadowPercent() > smallPercent))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly055(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() > 0.0 && data2.GetEntityPercent() > middlePercent)
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() < middlePercent))
		)
	{
		result = -1;;
	}
	return result;
}
int Analysis::KLineAnaly056(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	//
	if ((data1.GetYinYangLine() > 0.0 )
		&&(data2.GetYinYangLine() > 0.0 && data2.GetKaiPanPrice() < data1.GetShouPanPrice())
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetKaiPanPrice() < data2.GetShouPanPrice()) && CHARGETYPE(status,data3.GetShouPanPrice() < data2.GetShouPanPrice()))
		)
	{
		result = -1;;
	}
	return result;
}
int Analysis::KLineAnaly057(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();
	//
	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetYinYangLine() > 0.0 && data2.GetKaiPanPrice() > data1.GetShouPanPrice() && CHARGETYPE(status,data2.GetKaiPanPrice() > data3.GetShouPanPrice()) && data2.GetShouPanPrice() < data1.GetKaiPanPrice() && CHARGETYPE(status,data2.GetShouPanPrice() < data3.GetKaiPanPrice()))
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent))
		)
	{
		result = -1;;
	}
	return result;
}

int Analysis::KLineAnaly058(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isDaYangXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp == ZOUSHI_HIGHUP)
		{
			result = -1;
		}
		else if (tmp == ZOUSHI_HIGHDOWN)
		{
			result = 1;
		}
		else if(tmp == ZOUSHI_LOWUP)
		{
			result = 2;
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

int Analysis::KLineAnaly059(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isDaYinXian()))
	{
		int tmp = Analysis::TrendAnalysis(false);
		if (tmp == ZOUSHI_HIGHUP)
		{
			result = -2;
		}
		else if (tmp == ZOUSHI_HIGHDOWN)
		{
			result = 1;
		}
		else if(tmp == ZOUSHI_LOWDOWN)
		{
			result = -1;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

int Analysis::KLineAnaly060(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isXiaoYangXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly061(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isXiaoYinXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly062(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isShiZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly063(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isChangShiZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly064(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isLuoXuanJiang()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly065(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isYiZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly066(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isTZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly067(bool status)
{
	//取数据
	int days = 1;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();

	//
	if (CHARGETYPE(status,data1.isDaoTZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly068(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();

	//
	if (data1.isTZiXian() && CHARGETYPE(status,data2.isDaoTZiXian()))
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly069(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.isDaYangXian() || data1.isZhongYangXian())
		&& (CHARGETYPE(status,data2.isShiZiXian()) || CHARGETYPE(status,data2.isXiaoYangXian()) || CHARGETYPE(status,data2.isXiaoYinXian()))
		&& (CHARGETYPE(status,data2.GetHighPrice() < data1.GetHighPrice()) && CHARGETYPE(status,data2.GetLowPrice() > data1.GetShouPanPrice()))
		)
	{
		result = 0;;
	}

	if ((data1.isDaYinXian() || data1.isZhongYinXian())
		&& (CHARGETYPE(status,data2.isShiZiXian()) || CHARGETYPE(status,data2.isXiaoYangXian()) || CHARGETYPE(status,data2.isXiaoYinXian()))
		&& (CHARGETYPE(status,data2.GetHighPrice() < data1.GetShouPanPrice()) && CHARGETYPE(status,data2.GetLowPrice() > data1.GetLowPrice()))
		)
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly070(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() > 0.0)
		&& (CHARGETYPE(status,data2.GetYinYangLine() < 0.0))
		&& (CHARGETYPE(status,data2.GetEntityHighPrice() > data1.GetEntityHighPrice()) && CHARGETYPE(status,data2.GetEntityLowPrice() < data1.GetEntityLowPrice()))
		)
	{
		result = 0;;
	}

	if ((data1.GetYinYangLine() < 0.0)
		&& (CHARGETYPE(status,data2.GetYinYangLine() > 0.0))
		&& (CHARGETYPE(status,data2.GetEntityHighPrice() > data1.GetEntityHighPrice()) && CHARGETYPE(status,data2.GetEntityLowPrice() < data1.GetEntityLowPrice()))
		)
	{
		result = 0;;
	}
	return result;
}

int Analysis::KLineAnaly071(bool status)
{
	//取数据
	int days = 2;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();

	//
	if ((CHARGETYPE(status,data1.GetEntityHighPrice() > data2.GetHighPrice()) && CHARGETYPE(status,data1.GetEntityLowPrice() < data2.GetLowPrice()))
		&&(CHARGETYPE(status,data2.isXiaoYangXian()) || CHARGETYPE(status,data2.isXiaoYinXian()) || CHARGETYPE(status,data2.isShiZiXian()) || CHARGETYPE(status,data2.isChangShiZiXian()))
		)
	{
		result = 0;;
	}

	return result;
}

int Analysis::KLineAnaly072(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() > 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetEntityPercent() < middlePercent && fabs(data2.GetHighPrice() - data1.GetHighPrice()) / data2.GetHighPrice() < microPercent)
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent) && CHARGETYPE(status,fabs(data3.GetHighPrice() - data2.GetHighPrice()) / data3.GetHighPrice() < microPercent))
		)
	{
		result = 0;;
	}

	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() > middlePercent)
		&&(data2.GetEntityPercent() < middlePercent && fabs(data2.GetLowPrice() - data1.GetLowPrice()) / data2.GetLowPrice() < microPercent)
		&&(CHARGETYPE(status,data3.GetYinYangLine() > 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent) && CHARGETYPE(status,fabs(data3.GetLowPrice() - data2.GetLowPrice()) / data3.GetLowPrice() < microPercent))
		)
	{
		result = 0;;
	}

	return result;
}

int Analysis::KLineAnaly073(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	do 
	{
		StockData data = StockDataArray::GetInstance()->GetDayAt(i);
		if ((CHARGETYPE(i == 1 && status,data.GetEntityPercent() < smallPercent)))
		{
			dataList.push_back(data);
			i++;
		}
		else
		{
			if (i < 5)
			{
				return result;
			}
			if (data.GetYinYangLine() > 0.0 && data.GetEntityPercent() > middlePercent)
			{
				result = 0;;
				return result;
			}
			else
			{
				return result;
			}
		}

	} while (i < 20);

	result = 0;;
	return result;
}

int Analysis::KLineAnaly074(bool status)
{
	//取数据
	int result = 0;
	list<StockData> dataList;
	int i = 1;

	StockData lastData = StockDataArray::GetInstance()->GetDayAt(i);
	i++;

	if (lastData.GetYinYangLine() > 0.0)
	{
		do 
		{
			StockData data = StockDataArray::GetInstance()->GetDayAt(i);
			if (data.GetYinYangLine() > 0.0 && CHARGETYPE(i == 2 && status,data.GetEntityPercent() < lastData.GetEntityPercent()) && CHARGETYPE(i == 2 && status,lastData.GetKaiPanPrice() > data.GetKaiPanPrice()))
			{
				dataList.push_back(data);
				i++;
				lastData = data;
			}
			else
			{
				if (i < 5)
				{
					return result;
				}
				else
				{
					return result;
				}
			}

		} while (i < 20);
	}
	else
	{
		do 
		{
			StockData data = StockDataArray::GetInstance()->GetDayAt(i);
			if (data.GetYinYangLine() < 0.0 && CHARGETYPE(i == 2 && status,data.GetEntityPercent() < lastData.GetEntityPercent()) && CHARGETYPE(i == 2 && status,lastData.GetKaiPanPrice() < data.GetKaiPanPrice()))
			{
				dataList.push_back(data);
				i++;
				lastData = data;
			}
			else
			{
				if (i < 5)
				{
					return result;
				}
				else
				{
					result = 0;;
					return result;
				}
			}

		} while (i < 20);
	}


	result = 0;;
	return result;
}

int Analysis::KLineAnaly075(bool status)
{
	//取数据
	int days = 3;
	int result = 0;

	list<StockData> dataList = StockDataArray::GetInstance()->GetLastNDaysData(days);
	if (dataList.size() != days)
	{
		return result;
	}

	//分析
	StockData data1 = dataList.front();
	dataList.pop_front();
	StockData data2 = dataList.front();
	dataList.pop_front();
	StockData data3 = dataList.front();
	dataList.pop_front();

	//
	if ((data1.GetYinYangLine() < 0.0 && data1.GetEntityPercent() > middlePercent && data1.GetLowerShadowPercent() < microPercent)
		&&(data2.GetYinYangLine() < 0.0 && data2.GetEntityPercent() > middlePercent && data2.GetLowerShadowPercent() < microPercent)
		&&(CHARGETYPE(status,data3.GetYinYangLine() < 0.0) && CHARGETYPE(status,data3.GetEntityPercent() > middlePercent) && CHARGETYPE(status,data3.GetLowerShadowPercent() < microPercent))
		)
	{
		result = 0;;
	}

	return result;
}