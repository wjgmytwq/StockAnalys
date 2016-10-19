#include "StdAfx.h"
#include "KlINE.h"
#include "Analysis.h"
#include "StockData.h"
#include "StockHeader.h"
#include <math.h>


KlINEArray* KlINEArray::m_pKLineArray = NULL;

KlINE::KlINE(void)
{
}

KlINE::~KlINE(void)
{
}
/*******************************************************************************/
KlINEArray::KlINEArray()
{
	m_kLineArray.clear();

	KlINE line001;
	line001.SetKLineName("早晨十字星（希望十字星）1\n");
	line001.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由三根线组成，第一根是阴线，第二根是十字星，第三根是阳线，第三根实体深入到第一根内部 \n\
\t见底信号，后市看涨！\n");
	line001.SetKLineAnalysFun(Analysis::KLineAnaly001);
	m_kLineArray.push_back(line001);


	KlINE line002;
	line002.SetKLineName("早晨之星（希望之星）2\n");
	line002.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由三根线组成，第一根是阴线，第二根是小阴或小阳，第三根是阳线，第三根实体深入到第一根内部 \n\
\t见底信号，后市看涨！\n\
\t信号不如早晨十字星强烈！\n");
	line002.SetKLineAnalysFun(Analysis::KLineAnaly002);
	m_kLineArray.push_back(line002);

	KlINE line003;
	line003.SetKLineName("好友反攻3\n");
	line003.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由一阴一阳两根K线组成 \n\
\t3.先是一根大阴线，接着跳低开盘，结果收了一根中阳线或大阳线，并且收在前一根K线收盘价相同或相近的位置上 \n\
\t见底信号，后市看涨！\n\
\t信号不如早晨十字星曙光初现强烈！\n");
	line003.SetKLineAnalysFun(Analysis::KLineAnaly003);
	m_kLineArray.push_back(line003);

	KlINE line004;
	line004.SetKLineName("曙光初现4\n");
	line004.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由一阴一阳两根K线组成 \n\
\t3.先是一根大阴线，接着一根中阳线或大阳线，阳线的实体深入到阴线实体的二分之一以上处 \n\
\t见底信号，后市看涨！\n\
\t阳线实体深入阴线实体的部分越多，转势信号越强\n");
	line004.SetKLineAnalysFun(Analysis::KLineAnaly004);
	m_kLineArray.push_back(line004);

	KlINE line005;
	line005.SetKLineName("旭日东升5\n");
	line005.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由一阴一阳两根K线组成 \n\
\t3.先是一根大阴线，接着一根中阳线或大阳线，阳线的收盘价已高于前一天的开盘价 \n\
\t见底信号，后市看涨！\n\
\t见底信号强于曙光初现，阳线实体高出阴线实体部分越多，转势信号越强\n");
	line005.SetKLineAnalysFun(Analysis::KLineAnaly005);
	m_kLineArray.push_back(line005);

	KlINE line006;
	line006.SetKLineName("倒锤头线6\n");
	line006.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.阳线或阴线实体很小，上影线大于或等于实体的两倍 \n\
\t3.一般无下影线，少数会略有一点下影线 \n\
\t见底信号，后市看涨！\n\
\t实体与上影线比例越悬殊，信号越有参考价值。如倒垂头与早晨之星同时出现，见底信号就更加牢靠\n");
	line006.SetKLineAnalysFun(Analysis::KLineAnaly006);
	m_kLineArray.push_back(line006);

	KlINE line007;
	line007.SetKLineName("倒锤头线7\n");
	line007.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.阳线或阴线实体很小，下影线大于或等于实体的两倍 \n\
\t3.一般无上影线，少数会略有一点上影线 \n\
\t见底信号，后市看涨！\n\
\t实体与下影线比例越悬殊，信号越有参考价值。如垂头与早晨之星同时出现，见底信号就更加牢靠\n");
	line007.SetKLineAnalysFun(Analysis::KLineAnaly007);
	m_kLineArray.push_back(line007);

	KlINE line008;
	line008.SetKLineName("平底（钳子底）8\n");
	line008.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由两根或两根以上的K线组成\n\
\t3.一般无上影线，少数会略有一点上影线，最低价处于同一水平位置 \n\
\t见底信号，后市看涨！\n\
\t\n");
	line008.SetKLineAnalysFun(Analysis::KLineAnaly008);
	m_kLineArray.push_back(line008);

	KlINE line009;
	line009.SetKLineName("塔形底9\n");
	line009.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.先是一根大阴线或中阴线，后为一串小阴小阳线，最后出现一根大阳线或或中阳线\n\
\t3. \n\
\t见底信号，后市看涨！\n\
\t\n");
	line009.SetKLineAnalysFun(Analysis::KLineAnaly009);
	m_kLineArray.push_back(line009);

	KlINE line010;
	line010.SetKLineName("圆底10\n");
	line010.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.股价形成一个圆弧低\n\
\t3.圆弧内的K线多为小阴小阳线，最后以向上的跳空缺口来确认圆底形态成立 \n\
\t见底信号，后市看涨！\n\
\t\n");
	line010.SetKLineAnalysFun(Analysis::KLineAnaly010);
	m_kLineArray.push_back(line010);

	KlINE line011;
	line011.SetKLineName("低位并排阳线11\n");
	line011.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由两根阳线组成\n\
\t3.第一根阳线跳空低开，其收盘时在前一根K线下方留下一个缺口，后面一跟阳线与第一根阳线并肩而立 \n\
\t见底信号，后市看涨！\n\
\t\n");
	line011.SetKLineAnalysFun(Analysis::KLineAnaly011);
	m_kLineArray.push_back(line011);

	KlINE line012;
	line012.SetKLineName("低档五阳线12\n");
	line012.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.连续拉出五根阳线，多为小阳线\n\
\t3. \n\
\t见底信号，后市看涨！\n\
\t低档五阳线不一定都是五根阳线，有可能是六根，七根阳线\n");
	line012.SetKLineAnalysFun(Analysis::KLineAnaly012);
	m_kLineArray.push_back(line012);

	KlINE line013;
	line013.SetKLineName("连续跳空三阴线13\n");
	line013.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.连续出现三根向下跳空低开的阴线\n\
\t3. \n\
\t见底信号，后市看涨！\n\
\t如果股价已有大幅下挫的情况下出现，见底可能性更大\n");
	line013.SetKLineAnalysFun(Analysis::KLineAnaly013);
	m_kLineArray.push_back(line013);

	KlINE line014;
	line014.SetKLineName("红三兵14\n");
	line014.SetKLineDescription("\t1.出现在上涨行情初期\n\
\t2.由连续三根连创新高的小阳线组成\n\
\t3. \n\
\t买进信号，后市看涨！\n\
\t当三根阳线收于最高或接近最高时，称为三个白色武士，三个白色武士拉升股价作用强于普通的红三兵，投资者应该引起足够重视\n");
	line014.SetKLineAnalysFun(Analysis::KLineAnaly014);
	m_kLineArray.push_back(line014);

	KlINE line015;
	line015.SetKLineName("冉冉上升15\n");
	line015.SetKLineDescription("\t1.在盘整后期出现\n\
\t2.由若干个小K线组成，一般不少于8根，其中小阳线居多，中间也可夹着小阴线，十字线\n\
\t3.整个K线排列略微向上倾斜 \n\
\t买进信号，后市看涨！\n\
\t该K线组合犹如冉升起的旭日，升幅虽不大，但他往是股价大涨的前兆，如果成交量能同步放大，这种可能性就很大\n");
	line015.SetKLineAnalysFun(Analysis::KLineAnaly015);
	m_kLineArray.push_back(line015);

	KlINE line016;
	line016.SetKLineName("徐缓上升16\n");
	line016.SetKLineDescription("\t1.多数出现在涨势初期\n\
\t2.先接连出现几根小阳线，然后才拉出大阳线\n\
\t3. \n\
\t买进信号，后市看涨！\n\
\t\n");
	line016.SetKLineAnalysFun(Analysis::KLineAnaly016);
	m_kLineArray.push_back(line016);

	KlINE line017;
	line017.SetKLineName("稳步上涨17\n");
	line017.SetKLineDescription("\t1.出现在上涨行情中\n\
\t2.众多阳线中夹着较小的阴线，整个K线向上倾斜\n\
\t3. \n\
\t买进信号，后市看涨！\n\
\t后面的阳线对插入的阴线覆盖的速度越快越有力，上升的潜力就越大\n");
	line017.SetKLineAnalysFun(Analysis::KLineAnaly017);
	m_kLineArray.push_back(line017);

	KlINE line018;
	line018.SetKLineName("上升抵抗形18\n");
	line018.SetKLineDescription("\t1.在上涨途中出现\n\
\t2.由若干根K线组成\n\
\t3.连续跳高开盘，及时中间收出阴线，但收盘价也比前一个根K线的收盘价高 \n\
\t买进信号，后市看涨！\n\
\t后面的阳线对插入的阴线覆盖的速度越快越有力，上升的潜力就越大\n");
	line018.SetKLineAnalysFun(Analysis::KLineAnaly018);
	m_kLineArray.push_back(line018);

	KlINE line019;
	line019.SetKLineName("弧线形19\n");
	line019.SetKLineDescription("\t1.在上涨初期出现\n\
\t2.由若干根K线组成\n\
\t3.股价走势是一个向上的抛物线 \n\
\t买进信号，后市看涨！\n\
\t一旦弧形线为市场认可，上涨周期可能很长\n");
	line019.SetKLineAnalysFun(Analysis::KLineAnaly019);
	m_kLineArray.push_back(line019);

	KlINE line020;
	line020.SetKLineName("下探上涨型20\n");
	line020.SetKLineDescription("\t1.在上涨途中突然跳低开盘，甚至以跌停开盘，当日以涨势收盘收出一根大阳线，甚至以涨停板收盘\n\
\t2.\n\
\t3. \n\
\t买进信号，后市看涨！\n\
\t多数为控盘庄家利用消息吸盘，一般厚实将有一段较大升势\n");
	line020.SetKLineAnalysFun(Analysis::KLineAnaly020);
	m_kLineArray.push_back(line020);

	KlINE line021;
	line021.SetKLineName("上涨两颗星21\n");
	line021.SetKLineDescription("\t1.在涨势初期、中期内出现\n\
\t2.由一大二小3根k线组成\n\
\t3.在上涨时，先出现一根大阳线或中阳线，随后就在这个阳线的上方出现2根小k线，既可以是小十字线，也可以是实体很小的阳线、阴线 \n\
\t继续看涨！\n\
\t少数情况下会在一根大阳线上方出现3根小k线，这时，就称为上涨三颗星。上涨3颗星技术含义与上涨2颗星相同\n");
	line021.SetKLineAnalysFun(Analysis::KLineAnaly021);
	m_kLineArray.push_back(line021);

	KlINE line022;
	line022.SetKLineName("跳空上扬形22\n");
	line022.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由两根一阳一阴的线组成\n\
\t3.先是拉出一根跳空上扬的阳线，留下一个缺口，第二天又出现一根低收的阴线，但他收在前一根阳线缺口上方附近 \n\
\t继续看涨！\n\
\t\n");
	line022.SetKLineAnalysFun(Analysis::KLineAnaly022);
	m_kLineArray.push_back(line022);

	KlINE line023;
	line023.SetKLineName("高位并排阳线23\n");
	line023.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由两根阳线组成\n\
\t3.第一根阳线跳空向上，其收盘时在前一根K线上方留下一个缺口。第二个根阳线与之并排，开盘价与第一根阳线的开盘价基本相同 \n\
\t继续看涨！\n\
\t这个向上跳空的缺口对日后的股价走势有较强的支撑作用，但如发现日后股价跌破这个缺口，股价走势就会转弱\n");
	line023.SetKLineAnalysFun(Analysis::KLineAnaly023);
	m_kLineArray.push_back(line023);

	KlINE line024;
	line024.SetKLineName("跳空下跌三颗星24\n");
	line024.SetKLineDescription("\t1.出现在连续下跌途中\n\
\t2.由三根小阴线组成\n\
\t3.三根小阴线与上面一个K线有一个明显的空白区域，也即通常说的缺口 \n\
\t见底信号！\n\
\t如果在三根小阴线后出现一根大阳线，上涨可能性更大\n");
	line024.SetKLineAnalysFun(Analysis::KLineAnaly024);
	m_kLineArray.push_back(line024);

	KlINE line025;
	line025.SetKLineName("上升三部曲25\n");
	line025.SetKLineDescription("\t1.出现在上涨途中\n\
\t2.由大小不等5根K线组成\n\
\t3.先拉出一根大阳线或中阳线，接着连续出现三根小阳线，但是都没跌破前面的阳线的开盘价，随后出现一根大阳线或中阳线，其走势有点类似英文字母N\n\
\t继续上涨！\n\
\t\n");
	line025.SetKLineAnalysFun(Analysis::KLineAnaly025);
	m_kLineArray.push_back(line025);

	KlINE line026;
	line026.SetKLineName(" 多方尖兵26\n");
	line026.SetKLineDescription("\t1.出现在上涨途中\n\
\t2.由若干根K线组成\n\
\t3.在拉出一根中阳线或大阳线时，留下了一根较长的上影线，然后股价回落，但不久股价又上涨至上影线的上方\n\
\t继续上涨！\n\
\t走势图上出现这种K线形态，实际上是多方主力发动全面进攻前的一次试盘\n");
	line026.SetKLineAnalysFun(Analysis::KLineAnaly026);
	m_kLineArray.push_back(line026);

	KlINE line027;
	line027.SetKLineName("两红夹一黑27\n");
	line027.SetKLineDescription("\t1.即可能在涨势中也可能在跌势中\n\
\t2.由2根较长的阳线和一根较短的阴线组成，阴线夹在阳线之中\n\
\t3.\n\
\t在涨势中出现，继续看涨，在跌势中出现，是见底信号！\n\
\t\n");
	line027.SetKLineAnalysFun(Analysis::KLineAnaly027);
	m_kLineArray.push_back(line027);

	KlINE line028;
	line028.SetKLineName("黄昏十字星28\n");
	line028.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根K线组成，第一根为阳线，第二根为十字线，第三根为阴线。第三根K线实体深入到第一根K线实体内部\n\
\t3.\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line028.SetKLineAnalysFun(Analysis::KLineAnaly028);
	m_kLineArray.push_back(line028);

	KlINE line029;
	line029.SetKLineName("黄昏之星29\n");
	line029.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根K线组成，第一根为阳线，第二根为十字线小阳或小阴，第三根为阴线。第三根K线实体深入到第一根K线实体内部\n\
\t3.\n\
\t见顶信号，后市看跌！\n\
\t信号不如黄昏十字星强烈\n");
	line029.SetKLineAnalysFun(Analysis::KLineAnaly029);
	m_kLineArray.push_back(line029);

	KlINE line030;
	line030.SetKLineName("淡友反攻30\n");
	line030.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由一阳一阴2根K线组成\n\
\t3.先是出现一根大阳线接着跳盘高开，结果拉出一根中阴线或大阴线，收在前一根K线收盘价相同的位置\n\
\t见顶信号，后市看跌！\n\
\t转势信号不如乌云盖顶\n");
	line030.SetKLineAnalysFun(Analysis::KLineAnaly030);
	m_kLineArray.push_back(line030);

	KlINE line031;
	line031.SetKLineName("乌云盖顶31\n");
	line031.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由一根中阳线或大阳线和一根中阴线和大阴线组成\n\
\t3.阴线已深入到阳线实体二分之一以下处\n\
\t见顶信号，后市看跌！\n\
\t阴线深入阳线实体部分越多，转势信号越强\n");
	line031.SetKLineAnalysFun(Analysis::KLineAnaly031);
	m_kLineArray.push_back(line031);

	KlINE line032;
	line032.SetKLineName("倾盆大雨32\n");
	line032.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由一阳一阴2根K线组成\n\
\t3.先是一根大阳线或中阳线，接着出现一根低开的大阴线或中阴线，阴线收盘价已低于前一根阳线开盘价\n\
\t见顶信号，后市看跌！\n\
\t见顶信号强于乌云盖顶，阴线实体低于阳线实体部分越多，转势信号越强\n");
	line032.SetKLineAnalysFun(Analysis::KLineAnaly032);
	m_kLineArray.push_back(line032);

	KlINE line033;
	line033.SetKLineName("射击之星（扫帚星）33\n");
	line033.SetKLineDescription("\t1.出现在涨势中\n\
\t2.阳线，也可以是阴线，实体很小，上影线大于等于实体的两倍\n\
\t3.一般无下影线，少数会略有一点下影线\n\
\t见顶信号，后市看跌！\n\
\t实体与上影线比例越悬殊，信号越有参考价值，如射击之星与黄昏之星同时出现，见顶信号就更加可靠\n");
	line033.SetKLineAnalysFun(Analysis::KLineAnaly033);
	m_kLineArray.push_back(line033);

	KlINE line034;
	line034.SetKLineName("吊颈线（绞刑线）34\n");
	line034.SetKLineDescription("\t1.出现在涨势中\n\
\t2.阳线，也可以是阴线，实体很小，下影线大于等于实体的两倍\n\
\t3.一般无上影线，少数会略有一点上影线\n\
\t见顶信号，后市看跌！\n\
\t实体与下影线比例越悬殊，信号越有参考价值，如射击之星与黄昏之星同时出现，见顶信号就更加可靠\n");
	line034.SetKLineAnalysFun(Analysis::KLineAnaly034);
	m_kLineArray.push_back(line034);

	KlINE line035;
	line035.SetKLineName("平顶（钳子顶）35\n");
	line035.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由两根或两根以上K线组成\n\
\t3.最高价处于同一水平位置上\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line035.SetKLineAnalysFun(Analysis::KLineAnaly035);
	m_kLineArray.push_back(line035);

	KlINE line036;
	line036.SetKLineName("塔形顶36\n");
	line036.SetKLineDescription("\t1.出现在涨势中\n\
\t2.先由一根大阳线或中阳线，后为一连串的小阳小阴线，最后出现一根大阴线或中阴线\n\
\t3.\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line036.SetKLineAnalysFun(Analysis::KLineAnaly036);
	m_kLineArray.push_back(line036);

	KlINE line037;
	line037.SetKLineName("圆顶37\n");
	line037.SetKLineDescription("\t1.出现在涨势中\n\
\t2.股价形成一个圆弧顶\n\
\t3.圆弧内的K线多为小阳小阴线，最后以向下跳空缺口来确认圆顶形态成立\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line037.SetKLineAnalysFun(Analysis::KLineAnaly037);
	m_kLineArray.push_back(line037);

	KlINE line038;
	line038.SetKLineName("双飞乌鸦38\n");
	line038.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由两根一大一下阴线组成\n\
\t3.第一根阴线的收盘价高于前一根阳线的收盘价，且第二根阴线完全包容了第一根线\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line038.SetKLineAnalysFun(Analysis::KLineAnaly038);
	m_kLineArray.push_back(line038);

	KlINE line039;
	line039.SetKLineName("三只乌鸦（暴跌三杰）39\n");
	line039.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根阴线组成，阴线多为大阴或中阴线\n\
\t3.第一根阴线的收盘价高于前一根阳线的收盘价，且第二根阴线完全包容了第一根线每次均以跳离开盘，最后以下跌收盘\n\
\t见顶信号，后市看跌！\n\
\t\n");
	line039.SetKLineAnalysFun(Analysis::KLineAnaly039);
	m_kLineArray.push_back(line039);

	KlINE line040;
	line040.SetKLineName("高档五连阴40\n");
	line040.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由五根阴线组成，但多为小阴线\n\
\t3.先是拉出一根较有利的阳线，接着连续出现五根并排阴线\n\
\t见顶信号，后市看跌！\n\
\t不一定都是五根阴线，也有可能是六根七根阴线\n");
	line040.SetKLineAnalysFun(Analysis::KLineAnaly040);
	m_kLineArray.push_back(line040);

	KlINE line041;
	line041.SetKLineName("下降覆盖线41\n");
	line041.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由4根K线组成。前两根K线构成一个穿头破脚形态，第三个呢K线是一个中阳线或者小阳线，但阳线的尸体通常比前一根阴线要短，之后又出现一根中阴线或小阴线，阴线尸体已经深入到前一根阳线实体之中。\n\
\t3.先是拉出一根较有利的阳线，接着连续出现五根并排阴线\n\
\t见顶信号，后市看跌！\n\
\t见顶信号强于穿头破脚\n");
	line041.SetKLineAnalysFun(Analysis::KLineAnaly041);
	m_kLineArray.push_back(line041);

	KlINE line042;
	line042.SetKLineName("抵档盘旋形42\n");
	line042.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由若干根小阴小阳线组成\n\
\t3.先是小阴小阳的横盘，后来出现一根跳空向下的阴线\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line042.SetKLineAnalysFun(Analysis::KLineAnaly042);
	m_kLineArray.push_back(line042);

	KlINE line043;
	line043.SetKLineName("黑三兵43\n");
	line043.SetKLineDescription("\t1.即可在涨势中出现，也可在跌势中出现\n\
\t2.由三根小阴线组成，最低价一根比一根低\n\
\t3.\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line043.SetKLineAnalysFun(Analysis::KLineAnaly043);
	m_kLineArray.push_back(line043);

	KlINE line044;
	line044.SetKLineName("绵绵阴跌型44\n");
	line044.SetKLineDescription("\t1.在盘整后期出现\n\
\t2.由若干根小K线组成，一般不少于8根，其中以小阴线居多，中间也可夹杂一些小阳线，十字线\n\
\t3.整个K线排列略微向下倾斜\n\
\t卖出信号，后市看跌！\n\
\t绵绵阴跌，跌幅虽然不大，但犹如黄梅天的阴雨下个不停，从而延长了下跌的时间和扩展了下跌的空间，股价很可能就此长期走弱了。因此对绵绵阴跌走势的个股，应该及早作出停损离场的决断\n");
	line044.SetKLineAnalysFun(Analysis::KLineAnaly044);
	m_kLineArray.push_back(line044);

	KlINE line045;
	line045.SetKLineName("徐缓下跌型45\n");
	line045.SetKLineDescription("\t1.多数出现在下跌初期\n\
\t2.先接连出现几根小阴线，然后拉出中大阴线\n\
\t3.\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line045.SetKLineAnalysFun(Analysis::KLineAnaly045);
	m_kLineArray.push_back(line045);

	KlINE line046;
	line046.SetKLineName("下跌不止型46\n");
	line046.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.众多阴线中夹着较少的小阳线，整个K线排列成向下倾斜状态\n\
\t3.\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line046.SetKLineAnalysFun(Analysis::KLineAnaly046);
	m_kLineArray.push_back(line046);

	KlINE line047;
	line047.SetKLineName("下降抵抗形47\n");
	line047.SetKLineDescription("\t1.出现在下跌途中\n\
\t2.由若干根阴线和阳线组成，但阴线大大多于阳线\n\
\t3.连续跳低开盘，即使中间收出阳线，但收盘价也比前一根k线的收盘价低\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line047.SetKLineAnalysFun(Analysis::KLineAnaly047);
	m_kLineArray.push_back(line047);

	KlINE line048;
	line048.SetKLineName("高开出逃型48\n");
	line048.SetKLineDescription("\t1.突然跳高开盘，甚至以涨停板开盘，然后一路下跌，最后收出一根大阴线，甚至以跌停板收盘\n\
\t2.\n\
\t3.\n\
\t卖出信号，后市看跌！\n\
\t多数为被套庄家利用朦胧消息拉高出货所致，一般后市将有一段较大跌势\n");
	line048.SetKLineAnalysFun(Analysis::KLineAnaly048);
	m_kLineArray.push_back(line048);

	KlINE line049;
	line049.SetKLineName("下跌三颗星49\n");
	line049.SetKLineDescription("\t1.在下跌行情初期中期出现\n\
\t2.由一大三小4根k线组成\n\
\t3.在下跌时，先出现一根大阴线或中阴线，随后就在这根阴线的下方出现了3根小K线，既可以是小十字线，也可以是实体很小的阳线阴线\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line049.SetKLineAnalysFun(Analysis::KLineAnaly049);
	m_kLineArray.push_back(line049);

	KlINE line050;
	line050.SetKLineName("下降三部曲（降势三鹤）50\n");
	line050.SetKLineDescription("\t1.出现在下降趋势中\n\
\t2.由五根大小不等的K线组成\n\
\t3.先出现一根大阴线或中阴线，接着出现3根向上爬升的小阳线，但这三根小阳线都没有冲破第一根阳线开盘价，最后一根大阴线或中阴线又一下子全部或大部分吞吃了前面三根小阳线\n\
\t卖出信号，后市看跌！\n\
\t\n");
	line050.SetKLineAnalysFun(Analysis::KLineAnaly050);
	m_kLineArray.push_back(line050);

	KlINE line051;
	line051.SetKLineName("空方尖兵51\n");
	line051.SetKLineDescription("\t1.出现在下跌行情中\n\
\t2.由若干K线组成\n\
\t3.在拉出一根中阴线或大阴线时，留下一根较长的下影线，然后股价反弹，但不久股价又跌至下影线下方\n\
\t卖出信号，后市看跌！\n\
\t走势图上出现这种K线形态，实际上是空方主力像多方进行全面扫荡前的一次试盘\n");
	line051.SetKLineAnalysFun(Analysis::KLineAnaly051);
	m_kLineArray.push_back(line051);

	KlINE line052;
	line052.SetKLineName("倒三阳52\n");
	line052.SetKLineDescription("\t1.出现在下跌初期\n\
\t2.由三根阳线组成\n\
\t3.每日都是低开高走，第一根K线以跌盘收盘，后2根K线在收盘价低于或接近于前一日的阳线开盘价，因此虽然连收3根阳线，但是图形上却出现了类似连续三根阴线的跌势\n\
\t卖出信号，后市看跌！\n\
\t此种情况多数发生在庄家股上，出现这种K线图下跌概率极大，投资者要趁早果断斩仓离场\n");
	line052.SetKLineAnalysFun(Analysis::KLineAnaly052);
	m_kLineArray.push_back(line052);

	KlINE line053;
	line053.SetKLineName("连续跳空三阳线53\n");
	line053.SetKLineDescription("\t1.出现在上涨行情中\n\
\t2.连续出现3根向上跳空高开的阳线\n\
\t3.\n\
\t滞涨信号，后市看跌！\n\
\t\n");
	line053.SetKLineAnalysFun(Analysis::KLineAnaly053);
	m_kLineArray.push_back(line053);

	KlINE line054;
	line054.SetKLineName("升势受阻54\n");
	line054.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根阳线组成\n\
\t3.三根阳线实体越来越小，最后一根阳线的上影线很长\n\
\t滞涨信号，后市看跌！\n\
\t\n");
	line054.SetKLineAnalysFun(Analysis::KLineAnaly054);
	m_kLineArray.push_back(line054);

	KlINE line055;
	line055.SetKLineName("升势停顿55\n");
	line055.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根阳线组成\n\
\t3.上升时先拉出2根大阳线或中阳线，第三个根阳线实体很小，反应升势可能停顿\n\
\t滞涨信号，后市看跌！\n\
\t\n");
	line055.SetKLineAnalysFun(Analysis::KLineAnaly055);
	m_kLineArray.push_back(line055);

	KlINE line056;
	line056.SetKLineName("阳线坡脚型56\n");
	line056.SetKLineDescription("\t1.出现在涨势中\n\
\t2.由三根或以上阳线组成\n\
\t3.最后两根阳线都是低开，且最后一根阳线收盘价比前面阳线收盘价要低\n\
\t滞涨信号，后市看跌！\n\
\t\n");
	line056.SetKLineAnalysFun(Analysis::KLineAnaly056);
	m_kLineArray.push_back(line056);

	KlINE line057;
	line057.SetKLineName("两黑夹一红57\n");
	line057.SetKLineDescription("\t1.出现在涨势或跌势中\n\
\t2.由两根较长的阴线和一根较短的阳线组成。阳线加在阴线之中\n\
\t3.\n\
\t在涨势中出现，是见顶信号，在跌势中出现，继续看跌！\n\
\t\n");
	line057.SetKLineAnalysFun(Analysis::KLineAnaly057);
	m_kLineArray.push_back(line057);

	KlINE line058;
	line058.SetKLineName("大阳线58\n");
	line058.SetKLineDescription("\t1.可出现在任何情况下\n\
\t2.阳线实体较长，可略带上下影线\n\
\t3.\n\
\t在上涨刚开始时，出现大阳线厚实看涨，在上涨途中出现大阳线，继续看涨，在连续加速上涨行情中出现大阳线，是见顶信号。在连续下跌的行情中出现大阳线，由见底回升的意义\n\
\t阳线实体越长，信号越可靠\n");
	line058.SetKLineAnalysFun(Analysis::KLineAnaly058);
	m_kLineArray.push_back(line058);

	KlINE line059;
	line059.SetKLineName("大阴线59\n");
	line059.SetKLineDescription("\t1.可以出现在任何情况下\n\
\t2.阴线实体较长，可略带上下影线\n\
\t3.\n\
\t在涨势中出现大阴线，是见顶信号，在下跌刚开始时，出现大阴线，后市看跌，在下跌途中出现大阴线，继续看跌，在连续加速下跌行情中出现大阴线，有空头陷阱之嫌疑！\n\
\t\n");
	line059.SetKLineAnalysFun(Analysis::KLineAnaly059);
	m_kLineArray.push_back(line059);

	KlINE line060;
	line060.SetKLineName("小阳线60\n");
	line060.SetKLineDescription("\t1.在盘整行情中出现较多，也可在上涨下跌行情中出现\n\
\t2.K线实体很小，可略带上下影线\n\
\t3.\n\
\t说明行情不明朗，多空双方小心接触，但多方会略占上风！\n\
\t单根小阳线研判意义不大，应结合其他K线形态一起研判\n");
	line060.SetKLineAnalysFun(Analysis::KLineAnaly060);
	m_kLineArray.push_back(line060);

	KlINE line061;
	line061.SetKLineName("小阴线61\n");
	line061.SetKLineDescription("\t1.在盘整行情中出现较多，也可在下跌和上涨行情中出现\n\
\t2.K线实体很小，可略带上下影线\n\
\t3.\n\
\t说明行情不明朗，多空双方小心接触，但空方略占上风！\n\
\t单根小阴线研判意义不大，应结合其它K线形态一起研判\n");
	line061.SetKLineAnalysFun(Analysis::KLineAnaly061);
	m_kLineArray.push_back(line061);

	KlINE line062;
	line062.SetKLineName("十字线62\n");
	line062.SetKLineDescription("\t1.即可出现在涨势中，也可出现在跌势中\n\
\t2.开盘价收盘价相同，成为一字，但上下影较短\n\
\t3.\n\
\t在上涨趋势末端出现，是见顶信号，在下跌趋势末端出现，是见底信号。在上涨途中出现，继续看涨，在下跌途中出现，继续看跌！\n\
\t信号可靠性不强，应结合其它K线一起研判\n");
	line062.SetKLineAnalysFun(Analysis::KLineAnaly062);
	m_kLineArray.push_back(line062);

	KlINE line063;
	line063.SetKLineName("长十字线63\n");
	line063.SetKLineDescription("\t1.即可出现在涨势中，也可出现在跌势中\n\
\t2.开盘价收盘价相同，成为一字，但最高价与最低价拉的很开，因此上下影线都很长\n\
\t3.\n\
\t在上涨趋势末端出现，是见顶信号，在下跌趋势末端出现，是见底信号，在上涨途中出现，继续看涨，在下跌途中出现，继续看跌！\n\
\t虽然长十字线的技术含义与一般十字线的含义相同但其信号可靠程度远比后者高。因此，投资者可将它作为逃顶与抄底的重要参考指标\n");
	line063.SetKLineAnalysFun(Analysis::KLineAnaly063);
	m_kLineArray.push_back(line063);

	KlINE line064;
	line064.SetKLineName("螺旋桨64\n");
	line064.SetKLineDescription("\t1.即可出现在涨势中，也可出现在跌势中\n\
\t2.开盘价收盘价接近，K线实体可阴可阳很小，但最高价与最低价拉的很开，因此上下影线都很长\n\
\t3.\n\
\t在涨势中出现，后市看跌，在下跌途中出现，继续看跌，连续加速下跌行情中出现，有见底回升的意义！\n\
\t转势信号比长十字线更强\n");
	line064.SetKLineAnalysFun(Analysis::KLineAnaly064);
	m_kLineArray.push_back(line064);

	KlINE line065;
	line065.SetKLineName("一字线65\n");
	line065.SetKLineDescription("\t1.即可出现在涨势中，也可出现在跌势中\n\
\t2.开盘价、收盘价、最高价、最低价几乎相同，形成一字\n\
\t3.\n\
\t在上涨趋势中出现，是买进信号，在下跌趋势中出现，是卖出信号！\n\
\t在涨跌停板制度下，一字线有特别意义，涨势中出现一字线，表示股价封在涨停价上，说明多头气盛，日后该股往往会变成强势股，跌势中出现一字线，表示股价封杀在跌停价上，说明空头力量及强大，日后该股往往会变成弱势股\n");
	line065.SetKLineAnalysFun(Analysis::KLineAnaly065);
	m_kLineArray.push_back(line065);

	KlINE line066;
	line066.SetKLineName("T字线66\n");
	line066.SetKLineDescription("\t1.开盘价、收盘价、最高价连在一起，成为一字，但最低价与之有相当距离，因而在K线上留下一根下影线，构成T字状图\n\
\t2.\n\
\t3.\n\
\t在上涨趋势末端出现，为卖出信号，在下跌趋势末端出现，为买进信号。在上涨途中出现，继续看涨，在下跌途中出现，继续看跌！\n\
\tT字线下影线越长，力度越大，信号越可靠\n");
	line066.SetKLineAnalysFun(Analysis::KLineAnaly066);
	m_kLineArray.push_back(line066);

	KlINE line067;
	line067.SetKLineName("倒T字线67\n");
	line067.SetKLineDescription("\t1.开盘价、收盘价、最低价粘连在一起，成为一字，但是最高价与之有相当距离，因而在K线上留下一根上影线，构成倒T字状图形\n\
\t2.\n\
\t3.\n\
\t在上涨趋势末端出现，为卖出信号，在下跌趋势末端出现，为买进信号，在上涨途中出现，继续看涨，在下跌途中出现，继续看跌！\n\
\t倒T字线上影线越长，力度越大，信号越可靠。在上升趋势中出现的倒T字线，称为上档倒T字线，又称下跌转折线\n");
	line067.SetKLineAnalysFun(Analysis::KLineAnaly067);
	m_kLineArray.push_back(line067);

	KlINE line068;
	line068.SetKLineName("搓揉线68\n");
	line068.SetKLineDescription("\t1.多数出现在涨势中\n\
\t2.由一正一反两根T线组成\n\
\t3.\n\
\t在上涨途中出现，继续看涨，在上涨末端出现，是见顶信号！\n\
\t在上涨途中出现的搓揉线以小T字线居多，在上涨末端出现的搓揉线，以大T居多\n");
	line068.SetKLineAnalysFun(Analysis::KLineAnaly068);
	m_kLineArray.push_back(line068);

	KlINE line069;
	line069.SetKLineName("尽头线69\n");
	line069.SetKLineDescription("\t1.既可以出现在涨势中，也可以出现在跌势中\n\
\t2.由两根一大一小K线组成\n\
\t3.出现在涨势中，第一根K线为大阳线或中阳线并留有一根上影线，第二根K线为小十字线或小阳小阴线，依附在第一根K线的上影线之内\n\
\t4.出现在跌势中，则第一根K线为大阴线或中阴线，并留有一根下影线，第二根K线为小阳小阴小十字线，依附在第一根K线的下影线之内\n\
\t出现在涨势中，是见顶信号，出现在跌势中，是见底信号！\n\
\t尽头线的上影线或下影线的右方，带着的K线越小，如小十字星，则信号越强\n");
	line069.SetKLineAnalysFun(Analysis::KLineAnaly069);
	m_kLineArray.push_back(line069);

	KlINE line070;
	line070.SetKLineName("穿头破脚70\n");
	line070.SetKLineDescription("\t1.即可在上涨趋势中出现，也可以在下跌趋势中出现\n\
\t2.由大小不等，阴阳相反的两根K线组成\n\
\t3.在上涨趋势中出现，前一根为阳线，后一个呢为阴线，后者将前者实体全部包在内，不包括上下影线\n\
\t4.在下跌趋势中出现，前一根为阴线，后一个呢为阳线，后者将前者实体全部包在内，不包括上下影线\n\
\t在上涨趋势中出现，是卖出信号，在下跌趋势中出现，为买入信号！\n\
\t2根K线的长短越悬殊，或一根长的K线包容前面的K线越多，信号的参考价值就越大\n");
	line070.SetKLineAnalysFun(Analysis::KLineAnaly070);
	m_kLineArray.push_back(line070);

	KlINE line071;
	line071.SetKLineName("身怀六甲71\n");
	line071.SetKLineDescription("\t1.即可在上涨趋势中出现，也可以在下跌趋势中出现\n\
\t2.由大小不等的两根K线组成，两根K线可一阴一阳，可以两阳两阴\n\
\t3.第一根K线实体要能完全包容第二根K线实体\n\
\t4.第二根K线可以是小阴小阳十字线\n\
\t在上涨趋势中出现，是卖出信号，在下跌趋势中出现，是买进信号！\n\
\t若第二根K线为十字线，俗称十字胎，在身怀六甲中，十字胎是力度最大的K线形态之一\n");
	line071.SetKLineAnalysFun(Analysis::KLineAnaly071);
	m_kLineArray.push_back(line071);

	KlINE line072;
	line072.SetKLineName("镊子线72\n");
	line072.SetKLineDescription("\t1.即可在上涨趋势中出现，也可以在下跌趋势中出现\n\
\t2.由三根两大一小的K线组成\n\
\t3.3根K线的最高价几乎处在同一水平线上\n\
\t在上涨时出现为头部信号，在下跌时出现为底部信号！\n\
\t\n");
	line072.SetKLineAnalysFun(Analysis::KLineAnaly072);
	m_kLineArray.push_back(line072);

	KlINE line073;
	line073.SetKLineName("上档盘旋形73\n");
	line073.SetKLineDescription("\t1.出现在上涨途中\n\
\t2.由若干根或十几根K线组成\n\
\t3.在上涨时拉出一根有力度的阳线后，就出现阴阳交错，上下波动范围很小的横盘走势\n\
\t上档盘旋时间在5-14天内，多数看涨，超过14天，多数看跌！\n\
\t盘旋时间太久，说明多方上工冤枉不强，因而下跌可能性很大\n");
	line073.SetKLineAnalysFun(Analysis::KLineAnaly073);
	m_kLineArray.push_back(line073);



	KlINE line074;
	line074.SetKLineName("加速度线74\n");
	line074.SetKLineDescription("\t1.即可出现在涨势中，也可出现在跌势中\n\
\t2.上涨时出现加速度线，表现为开始缓慢爬升，后来攀升速度越来越快，接着连续拉出中阳线或大阳线\n\
\t3.下跌时出现加速度线，表现为开始缓慢下跌，后来下跌速度越来越快，接着连续拉出中阴线或大阴线\n\
\t在上涨时为头部信号，在下跌时出现为底部信号！\n\
\t\n");
	line074.SetKLineAnalysFun(Analysis::KLineAnaly074);
	m_kLineArray.push_back(line074);

	KlINE line075;
	line075.SetKLineName("下跌三连阴75\n");
	line075.SetKLineDescription("\t1.出现在跌势途中\n\
								\t2.由三根阴线组成，阴线多为大阴线或中阴线\n\
								\t3.每根阴线都以最低价或次低价报收，最后一根阴线往往是大阴线\n\
								\t在下跌初期出现，继续看跌，在下跌后期出现，是见底信号！\n\
								\t在连续阴跌不止情况下，特别是股价有较大跌幅后出现三连阴，表示空方力量已用尽\n");
	line075.SetKLineAnalysFun(Analysis::KLineAnaly075);
	m_kLineArray.push_back(line075);

}

int KlINEArray::StartAnalysis(bool bPrintf)
{
	list<KlINE>::iterator iter;
	int totalResult = 0;
	for (iter = m_kLineArray.begin();iter != m_kLineArray.end();iter++)
	{

		int result = iter->m_kLineAnalysFun(false);
		totalResult += result;
		if (bPrintf && result != 0)
		{
			printf("/************************************/\n");
			printf("结果：%s",iter->GetKLineName().GetString());
			printf("强度：");
			if (result < 0)
			{
				for (int i = 0; i < abs(result); i++)
				{
					printf("↓");
				}

			}
			else
			{
				for (int i = 0; i < abs(result); i++)
				{
					printf("↑");
				}
			}
			printf("\n");
			printf("描述：\n%s",iter->GetKLineDescription().GetString());
			printf("/************************************/\n");
		}
	}

	return totalResult;
}

void KlINEArray::StartForecast()
{
	list<KlINE>::iterator iter;
	for (iter = m_kLineArray.begin();iter != m_kLineArray.end();iter++)
	{

		double result = iter->m_kLineAnalysFun(true);
		if (result > 0)
		{
			printf("/####################################/\n");
			printf("预测：%s",iter->GetKLineName().GetString());
			printf("描述：\n%s",iter->GetKLineDescription().GetString());
			printf("/####################################/\n");
		}
	}
}

void KlINEArray::StartBuyOrSale(unsigned int days,const char* pathName,int buyOrSaleType,bool bPrintf)
{
	if (StockDataArray::GetInstance()->GetArraySize() <= 0)
	{
		return;
	}
	//数据做一下备份
	list<StockData> tmpStockDataList;
	tmpStockDataList.assign( StockDataArray::GetInstance()->GetAllData().begin( ), StockDataArray::GetInstance()->GetAllData().end( ) );

	list<BuyOrSaleStock> arrayList;

	StockData lastData = StockDataArray::GetInstance()->front();
	StockDataArray::GetInstance()->PopFront();
	while(StockDataArray::GetInstance()->GetArraySize() > 0 && days > 0)
	{

		list<KlINE>::iterator iter;
		int result = 0;
		for (iter = m_kLineArray.begin();iter != m_kLineArray.end();iter++)
		{
			result += iter->m_kLineAnalysFun(false);
		}
		//printf("result = %d\n",result);
		BuyOrSaleStock elem;
		elem.stockType = result;
		elem.stockData = lastData;

		arrayList.push_front(elem);

		lastData = StockDataArray::GetInstance()->front();
		StockDataArray::GetInstance()->PopFront();;
		days--;
	}
	//把数据在倒回来
	StockDataArray::GetInstance()->GetAllData().clear();
	StockDataArray::GetInstance()->GetAllData().assign( tmpStockDataList.begin( ), tmpStockDataList.end( ) );
	
	if (arrayList.size() > 0)
	{
		list<BuyOrSaleStock>::iterator iter;
		unsigned int totalCount = 0;
		double totalValue = 0;
		double totalStockValue = 0;
		bool lastType = false;
		double lastValue = 0.0;
		double maxCharge = 0.0;
		unsigned int totalYuce = 0;
		unsigned int totalYuceSuccess = 0;
		unsigned int totalShangZhangYuce = 0;
		unsigned int totalShangZhangYuceSuccess = 0;
		unsigned int totalXiadieYuce = 0;
		unsigned int totalXiadieYuceSuccess = 0;
		//unsigned int totalChipingYuce = 0;
		//unsigned int totalChipingYuceSuccess = 0;
	

		int eachBuyOrSaleCount = 500;
		for (iter = arrayList.begin();iter != arrayList.end();iter++)
		{
			int realBuyOrSale = 0;
			if (iter->stockType > 0)
			{
				if ((buyOrSaleType == 0  &&  totalCount <= 0) || buyOrSaleType == 1) //buyorsaletype 为0表示连续上涨期间只买一次，为1表示只要上涨就买入
				{
					totalCount += eachBuyOrSaleCount;
					totalValue -= eachBuyOrSaleCount * iter->stockData.GetKaiPanPrice();
					totalStockValue += eachBuyOrSaleCount * iter->stockData.GetKaiPanPrice();
					lastType = true;
					realBuyOrSale = 1;
				}

				totalYuce++;
				totalShangZhangYuce++;
				if (iter->stockData.GetYinYangLine() > 0)
				{
					totalYuceSuccess++;
					totalShangZhangYuceSuccess++;
				}
			}
			if (iter->stockType < 0 )
			{
				if (totalCount > 0)
				{
					totalValue += totalCount * iter->stockData.GetKaiPanPrice();
					totalCount = 0;
					totalStockValue = 0;
					lastType = false;
					realBuyOrSale = -1;
				}

				totalYuce++;
				totalXiadieYuce++;
				if (iter->stockData.GetYinYangLine() < 0)
				{
					totalYuceSuccess++;
					totalXiadieYuceSuccess++;
				}
			}
			//持平计算准确率是没有意义的，因为持平并不是真的算出来是持平，而是无法预测
			//持平的时候按照止盈止损计算卖出
			if (iter->stockType == 0)
			{
				if (totalStockValue > 0 && totalCount > 0)//有股票的时候才进行判断
				{
					double averageStockValue = totalStockValue / totalCount;
					double lowAverageStockValue = averageStockValue * 0.9; 
					double highAverageStockValue = averageStockValue * 1.1; 

					//当一天的波动里，既有止损点又有止盈点，优先按止损点卖出，按最小收益计算结果（也可以反过来，按最大利益计算结果）
					//止损点抛出
					if (lowAverageStockValue >= iter->stockData.GetLowPrice() && lowAverageStockValue <= iter->stockData.GetHighPrice())
					{
						totalValue += totalCount * lowAverageStockValue;
						totalCount = 0;
						totalStockValue = 0;
						lastType = false;
						realBuyOrSale = -2;
					}
					else
					{
						//止赢点抛出
						if (highAverageStockValue >= iter->stockData.GetLowPrice() && highAverageStockValue <= iter->stockData.GetHighPrice())
						{
							totalValue += totalCount * highAverageStockValue;
							totalCount = 0;
							totalStockValue = 0;
							lastType = false;
							realBuyOrSale = -3;
						}
					}
				}
			}


			lastValue = iter->stockData.GetShouPanPrice();
			if (maxCharge > totalValue)
			{
				maxCharge = totalValue;
			}
			if (bPrintf)
			{
				int realResult = 0;
				if (iter->stockData.GetEntityPercent() < microPercent)
				{
					realResult = 0;
				}
				else
				{
					 if (iter->stockData.GetYinYangLine() > 0)
					 {
							realResult  = 1;
					 }
					 else if (iter->stockData.GetYinYangLine() < 0)
					 {
						 realResult = -1;
					 }
					 else
					 {
						 realResult = 0;
					 }

				}

				printf("时间 = %d,\t预测买卖 = %d,\t实际买卖 = %d,\t股票数 = %d,\t股票总额 = %.2f,\t实际营收 = %.2f\n",iter->stockData.GetStockTime(),iter->stockType,realBuyOrSale,totalCount,totalStockValue,totalValue + totalCount * lastValue);
			}
			
		}
		
		//收入在2000块以上，并且投入产出比在20%以上
		//if (totalValue + totalCount * lastValue > 2000.0 && ((totalValue + totalCount * lastValue) * 100) / fabs(maxCharge) > 20.0)
		{
			if (!bPrintf)
			{
				printf("%s,type=%d,",pathName,buyOrSaleType);
			}
			printf("总共营收：%.2f,最大支出：%.2f,最大投入产出比：%.2f%%,总共预测：%d,成功次数：%d,成功百分比：%.2f%%,上涨预测：%d,成功次数：%d,成功百分比：%.2f%%,下跌预测：%d,成功次数：%d,成功百分比：%.2f%%\n",totalValue + totalCount * lastValue,fabs(maxCharge),(maxCharge != 0 ? ((totalValue + totalCount * lastValue) * 100) / fabs(maxCharge):0),totalYuce,totalYuceSuccess,(totalYuce > 0 ? totalYuceSuccess * 100.0 / totalYuce:0),totalShangZhangYuce,totalShangZhangYuceSuccess,(totalShangZhangYuce > 0 ? totalShangZhangYuceSuccess * 100.0 / totalShangZhangYuce:0),totalXiadieYuce,totalXiadieYuceSuccess,(totalXiadieYuce > 0 ? totalXiadieYuceSuccess * 100.0 / totalXiadieYuce:0));
		}

		//printf("总共预测：%d  ，成功次数：%d,成功百分比：%.2f%%\n",totalYuce,yuceSuccess,yuceSuccess * 100.0 / totalYuce);

	}

}
