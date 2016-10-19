#pragma once

#include "stdafx.h"

class Analysis
{
public:
	static int TrendAnalysis(bool printfLog);//趋势分析，负值为下降趋势，正值为上升趋势，0为横盘,要结合实际情况进行优化
	static void KaipanZoushiAnalysis();//开盘走势分析
	static void StartBuyOrSale();//根据算法复盘买卖能否赚到钱
public:
	static int KLineAnaly001(bool status);//希望十字星
	static int KLineAnaly002(bool status);//希望之星
	static int KLineAnaly003(bool status);//好友反攻
	static int KLineAnaly004(bool status);//曙光初现
	static int KLineAnaly005(bool status);//旭日东升
	static int KLineAnaly006(bool status);//倒锤头线
	static int KLineAnaly007(bool status);//锤头线
	static int KLineAnaly008(bool status);//平底
	static int KLineAnaly009(bool status);//塔形底
	static int KLineAnaly010(bool status);//圆底
	static int KLineAnaly011(bool status);//低位并排阳线
	static int KLineAnaly012(bool status);//低档五阳线
	static int KLineAnaly013(bool status);//连续跳空三阴线
	static int KLineAnaly014(bool status);//红三兵
	static int KLineAnaly015(bool status);//冉冉上升
	static int KLineAnaly016(bool status);//徐缓上升
	static int KLineAnaly017(bool status);//稳步上涨
	static int KLineAnaly018(bool status);//上升抵抗型
	static int KLineAnaly019(bool status);//弧形线
	static int KLineAnaly020(bool status);//下探上涨型
	static int KLineAnaly021(bool status);//上涨两颗星
	static int KLineAnaly022(bool status);//跳空上扬形
	static int KLineAnaly023(bool status);//高位并排阳线
	static int KLineAnaly024(bool status);//跳空下跌三颗星
	static int KLineAnaly025(bool status);//上升三部曲
	static int KLineAnaly026(bool status);//多方尖兵********************
	static int KLineAnaly027(bool status);//两红夹一黑

	static int KLineAnaly028(bool status);//黄昏十字星
	static int KLineAnaly029(bool status);//黄昏之星
	static int KLineAnaly030(bool status);//淡友反攻
	static int KLineAnaly031(bool status);//乌云盖顶
	static int KLineAnaly032(bool status);//倾盆大雨
	static int KLineAnaly033(bool status);//射击之星
	static int KLineAnaly034(bool status);//吊颈线
	static int KLineAnaly035(bool status);//平顶
	static int KLineAnaly036(bool status);//塔型顶
	static int KLineAnaly037(bool status);//圆顶
	static int KLineAnaly038(bool status);//双飞乌鸦
	static int KLineAnaly039(bool status);//三只乌鸦
	static int KLineAnaly040(bool status);//高档五阴线
	static int KLineAnaly041(bool status);//下降覆盖线
	static int KLineAnaly042(bool status);//低档盘旋形
	static int KLineAnaly043(bool status);//黑三兵
	static int KLineAnaly044(bool status);//绵绵阴跌型
	static int KLineAnaly045(bool status);//徐缓下跌型
	static int KLineAnaly046(bool status);//下跌不止型
	static int KLineAnaly047(bool status);//下跌抵抗型
	static int KLineAnaly048(bool status);//高开出逃型
	static int KLineAnaly049(bool status);//下跌三颗星
	static int KLineAnaly050(bool status);//下降三部曲
	static int KLineAnaly051(bool status);//空方尖兵
	static int KLineAnaly052(bool status);//倒三阳
	static int KLineAnaly053(bool status);//连续跳空三阳线
	static int KLineAnaly054(bool status);//升势受阻
	static int KLineAnaly055(bool status);//升势停顿
	static int KLineAnaly056(bool status);//阳线坡脚型
	static int KLineAnaly057(bool status);//两黑夹一红

	static int KLineAnaly058(bool status);//大阳线
	static int KLineAnaly059(bool status);//大阴线
	static int KLineAnaly060(bool status);//小阳线
	static int KLineAnaly061(bool status);//小阴线
	static int KLineAnaly062(bool status);//十字线
	static int KLineAnaly063(bool status);//长十字线
	static int KLineAnaly064(bool status);//螺旋桨
	static int KLineAnaly065(bool status);//一字线
	static int KLineAnaly066(bool status);//T字线
	static int KLineAnaly067(bool status);//倒T字线
	static int KLineAnaly068(bool status);//搓揉线
	static int KLineAnaly069(bool status);//尽头线
	static int KLineAnaly070(bool status);//穿头破脚
	static int KLineAnaly071(bool status);//身怀六甲
	static int KLineAnaly072(bool status);//镊子线
	static int KLineAnaly073(bool status);//上档盘旋形
	static int KLineAnaly074(bool status);//加速度线
	static int KLineAnaly075(bool status);//下跌三连阴
};
