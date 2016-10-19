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
	line001.SetKLineName("�糿ʮ���ǣ�ϣ��ʮ���ǣ�1\n");
	line001.SetKLineDescription("\t1.�������µ�;��\n\
\t2.����������ɣ���һ�������ߣ��ڶ�����ʮ���ǣ������������ߣ�������ʵ�����뵽��һ���ڲ� \n\
\t�����źţ����п��ǣ�\n");
	line001.SetKLineAnalysFun(Analysis::KLineAnaly001);
	m_kLineArray.push_back(line001);


	KlINE line002;
	line002.SetKLineName("�糿֮�ǣ�ϣ��֮�ǣ�2\n");
	line002.SetKLineDescription("\t1.�������µ�;��\n\
\t2.����������ɣ���һ�������ߣ��ڶ�����С����С���������������ߣ�������ʵ�����뵽��һ���ڲ� \n\
\t�����źţ����п��ǣ�\n\
\t�źŲ����糿ʮ����ǿ�ң�\n");
	line002.SetKLineAnalysFun(Analysis::KLineAnaly002);
	m_kLineArray.push_back(line002);

	KlINE line003;
	line003.SetKLineName("���ѷ���3\n");
	line003.SetKLineDescription("\t1.�������µ�;��\n\
\t2.��һ��һ������K����� \n\
\t3.����һ�������ߣ��������Ϳ��̣��������һ�������߻�����ߣ���������ǰһ��K�����̼���ͬ�������λ���� \n\
\t�����źţ����п��ǣ�\n\
\t�źŲ����糿ʮ����������ǿ�ң�\n");
	line003.SetKLineAnalysFun(Analysis::KLineAnaly003);
	m_kLineArray.push_back(line003);

	KlINE line004;
	line004.SetKLineName("������4\n");
	line004.SetKLineDescription("\t1.�������µ�;��\n\
\t2.��һ��һ������K����� \n\
\t3.����һ�������ߣ�����һ�������߻�����ߣ����ߵ�ʵ�����뵽����ʵ��Ķ���֮һ���ϴ� \n\
\t�����źţ����п��ǣ�\n\
\t����ʵ����������ʵ��Ĳ���Խ�࣬ת���ź�Խǿ\n");
	line004.SetKLineAnalysFun(Analysis::KLineAnaly004);
	m_kLineArray.push_back(line004);

	KlINE line005;
	line005.SetKLineName("���ն���5\n");
	line005.SetKLineDescription("\t1.�������µ�;��\n\
\t2.��һ��һ������K����� \n\
\t3.����һ�������ߣ�����һ�������߻�����ߣ����ߵ����̼��Ѹ���ǰһ��Ŀ��̼� \n\
\t�����źţ����п��ǣ�\n\
\t�����ź�ǿ�������֣�����ʵ��߳�����ʵ�岿��Խ�࣬ת���ź�Խǿ\n");
	line005.SetKLineAnalysFun(Analysis::KLineAnaly005);
	m_kLineArray.push_back(line005);

	KlINE line006;
	line006.SetKLineName("����ͷ��6\n");
	line006.SetKLineDescription("\t1.�������µ�;��\n\
\t2.���߻�����ʵ���С����Ӱ�ߴ��ڻ����ʵ������� \n\
\t3.һ������Ӱ�ߣ�����������һ����Ӱ�� \n\
\t�����źţ����п��ǣ�\n\
\tʵ������Ӱ�߱���Խ���⣬�ź�Խ�вο���ֵ���絹��ͷ���糿֮��ͬʱ���֣������źž͸����ο�\n");
	line006.SetKLineAnalysFun(Analysis::KLineAnaly006);
	m_kLineArray.push_back(line006);

	KlINE line007;
	line007.SetKLineName("����ͷ��7\n");
	line007.SetKLineDescription("\t1.�������µ�;��\n\
\t2.���߻�����ʵ���С����Ӱ�ߴ��ڻ����ʵ������� \n\
\t3.һ������Ӱ�ߣ�����������һ����Ӱ�� \n\
\t�����źţ����п��ǣ�\n\
\tʵ������Ӱ�߱���Խ���⣬�ź�Խ�вο���ֵ���紹ͷ���糿֮��ͬʱ���֣������źž͸����ο�\n");
	line007.SetKLineAnalysFun(Analysis::KLineAnaly007);
	m_kLineArray.push_back(line007);

	KlINE line008;
	line008.SetKLineName("ƽ�ף�ǯ�ӵף�8\n");
	line008.SetKLineDescription("\t1.�������µ�;��\n\
\t2.���������������ϵ�K�����\n\
\t3.һ������Ӱ�ߣ�����������һ����Ӱ�ߣ���ͼ۴���ͬһˮƽλ�� \n\
\t�����źţ����п��ǣ�\n\
\t\n");
	line008.SetKLineAnalysFun(Analysis::KLineAnaly008);
	m_kLineArray.push_back(line008);

	KlINE line009;
	line009.SetKLineName("���ε�9\n");
	line009.SetKLineDescription("\t1.�������µ�;��\n\
\t2.����һ�������߻������ߣ���Ϊһ��С��С���ߣ�������һ�������߻��������\n\
\t3. \n\
\t�����źţ����п��ǣ�\n\
\t\n");
	line009.SetKLineAnalysFun(Analysis::KLineAnaly009);
	m_kLineArray.push_back(line009);

	KlINE line010;
	line010.SetKLineName("Բ��10\n");
	line010.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�ɼ��γ�һ��Բ����\n\
\t3.Բ���ڵ�K�߶�ΪС��С���ߣ���������ϵ�����ȱ����ȷ��Բ����̬���� \n\
\t�����źţ����п��ǣ�\n\
\t\n");
	line010.SetKLineAnalysFun(Analysis::KLineAnaly010);
	m_kLineArray.push_back(line010);

	KlINE line011;
	line011.SetKLineName("��λ��������11\n");
	line011.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�������������\n\
\t3.��һ���������յͿ���������ʱ��ǰһ��K���·�����һ��ȱ�ڣ�����һ���������һ�����߲������ \n\
\t�����źţ����п��ǣ�\n\
\t\n");
	line011.SetKLineAnalysFun(Analysis::KLineAnaly011);
	m_kLineArray.push_back(line011);

	KlINE line012;
	line012.SetKLineName("�͵�������12\n");
	line012.SetKLineDescription("\t1.�������µ�;��\n\
\t2.��������������ߣ���ΪС����\n\
\t3. \n\
\t�����źţ����п��ǣ�\n\
\t�͵������߲�һ������������ߣ��п������������߸�����\n");
	line012.SetKLineAnalysFun(Analysis::KLineAnaly012);
	m_kLineArray.push_back(line012);

	KlINE line013;
	line013.SetKLineName("��������������13\n");
	line013.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�������������������յͿ�������\n\
\t3. \n\
\t�����źţ����п��ǣ�\n\
\t����ɼ����д���´������³��֣����׿����Ը���\n");
	line013.SetKLineAnalysFun(Analysis::KLineAnaly013);
	m_kLineArray.push_back(line013);

	KlINE line014;
	line014.SetKLineName("������14\n");
	line014.SetKLineDescription("\t1.�����������������\n\
\t2.���������������¸ߵ�С�������\n\
\t3. \n\
\t����źţ����п��ǣ�\n\
\t����������������߻�ӽ����ʱ����Ϊ������ɫ��ʿ��������ɫ��ʿ�����ɼ�����ǿ����ͨ�ĺ�������Ͷ����Ӧ�������㹻����\n");
	line014.SetKLineAnalysFun(Analysis::KLineAnaly014);
	m_kLineArray.push_back(line014);

	KlINE line015;
	line015.SetKLineName("ȽȽ����15\n");
	line015.SetKLineDescription("\t1.���������ڳ���\n\
\t2.�����ɸ�СK����ɣ�һ�㲻����8��������С���߾Ӷ࣬�м�Ҳ�ɼ���С���ߣ�ʮ����\n\
\t3.����K��������΢������б \n\
\t����źţ����п��ǣ�\n\
\t��K���������Ƚ��������գ������䲻�󣬵������ǹɼ۴��ǵ�ǰ�ף�����ɽ�����ͬ���Ŵ����ֿ����Ծͺܴ�\n");
	line015.SetKLineAnalysFun(Analysis::KLineAnaly015);
	m_kLineArray.push_back(line015);

	KlINE line016;
	line016.SetKLineName("�컺����16\n");
	line016.SetKLineDescription("\t1.�������������Ƴ���\n\
\t2.�Ƚ������ּ���С���ߣ�Ȼ�������������\n\
\t3. \n\
\t����źţ����п��ǣ�\n\
\t\n");
	line016.SetKLineAnalysFun(Analysis::KLineAnaly016);
	m_kLineArray.push_back(line016);

	KlINE line017;
	line017.SetKLineName("�Ȳ�����17\n");
	line017.SetKLineDescription("\t1.����������������\n\
\t2.�ڶ������м��Ž�С�����ߣ�����K��������б\n\
\t3. \n\
\t����źţ����п��ǣ�\n\
\t��������߶Բ�������߸��ǵ��ٶ�Խ��Խ������������Ǳ����Խ��\n");
	line017.SetKLineAnalysFun(Analysis::KLineAnaly017);
	m_kLineArray.push_back(line017);

	KlINE line018;
	line018.SetKLineName("�����ֿ���18\n");
	line018.SetKLineDescription("\t1.������;�г���\n\
\t2.�����ɸ�K�����\n\
\t3.�������߿��̣���ʱ�м��ճ����ߣ������̼�Ҳ��ǰһ����K�ߵ����̼۸� \n\
\t����źţ����п��ǣ�\n\
\t��������߶Բ�������߸��ǵ��ٶ�Խ��Խ������������Ǳ����Խ��\n");
	line018.SetKLineAnalysFun(Analysis::KLineAnaly018);
	m_kLineArray.push_back(line018);

	KlINE line019;
	line019.SetKLineName("������19\n");
	line019.SetKLineDescription("\t1.�����ǳ��ڳ���\n\
\t2.�����ɸ�K�����\n\
\t3.�ɼ�������һ�����ϵ������� \n\
\t����źţ����п��ǣ�\n\
\tһ��������Ϊ�г��Ͽɣ��������ڿ��ܺܳ�\n");
	line019.SetKLineAnalysFun(Analysis::KLineAnaly019);
	m_kLineArray.push_back(line019);

	KlINE line020;
	line020.SetKLineName("��̽������20\n");
	line020.SetKLineDescription("\t1.������;��ͻȻ���Ϳ��̣������Ե�ͣ���̣����������������ճ�һ�������ߣ���������ͣ������\n\
\t2.\n\
\t3. \n\
\t����źţ����п��ǣ�\n\
\t����Ϊ����ׯ��������Ϣ���̣�һ���ʵ����һ�νϴ�����\n");
	line020.SetKLineAnalysFun(Analysis::KLineAnaly020);
	m_kLineArray.push_back(line020);

	KlINE line021;
	line021.SetKLineName("����������21\n");
	line021.SetKLineDescription("\t1.�����Ƴ��ڡ������ڳ���\n\
\t2.��һ���С3��k�����\n\
\t3.������ʱ���ȳ���һ�������߻������ߣ�������������ߵ��Ϸ�����2��Сk�ߣ��ȿ�����Сʮ���ߣ�Ҳ������ʵ���С�����ߡ����� \n\
\t�������ǣ�\n\
\t��������»���һ���������Ϸ�����3��Сk�ߣ���ʱ���ͳ�Ϊ���������ǡ�����3���Ǽ�������������2������ͬ\n");
	line021.SetKLineAnalysFun(Analysis::KLineAnaly021);
	m_kLineArray.push_back(line021);

	KlINE line022;
	line022.SetKLineName("����������22\n");
	line022.SetKLineDescription("\t1.������������\n\
\t2.������һ��һ���������\n\
\t3.��������һ��������������ߣ�����һ��ȱ�ڣ��ڶ����ֳ���һ�����յ����ߣ���������ǰһ������ȱ���Ϸ����� \n\
\t�������ǣ�\n\
\t\n");
	line022.SetKLineAnalysFun(Analysis::KLineAnaly022);
	m_kLineArray.push_back(line022);

	KlINE line023;
	line023.SetKLineName("��λ��������23\n");
	line023.SetKLineDescription("\t1.������������\n\
\t2.�������������\n\
\t3.��һ�������������ϣ�������ʱ��ǰһ��K���Ϸ�����һ��ȱ�ڡ��ڶ�����������֮���ţ����̼����һ�����ߵĿ��̼ۻ�����ͬ \n\
\t�������ǣ�\n\
\t����������յ�ȱ�ڶ��պ�Ĺɼ������н�ǿ��֧�����ã����緢���պ�ɼ۵������ȱ�ڣ��ɼ����ƾͻ�ת��\n");
	line023.SetKLineAnalysFun(Analysis::KLineAnaly023);
	m_kLineArray.push_back(line023);

	KlINE line024;
	line024.SetKLineName("�����µ�������24\n");
	line024.SetKLineDescription("\t1.�����������µ�;��\n\
\t2.������С�������\n\
\t3.����С����������һ��K����һ�����ԵĿհ�����Ҳ��ͨ��˵��ȱ�� \n\
\t�����źţ�\n\
\t���������С���ߺ����һ�������ߣ����ǿ����Ը���\n");
	line024.SetKLineAnalysFun(Analysis::KLineAnaly024);
	m_kLineArray.push_back(line024);

	KlINE line025;
	line025.SetKLineName("����������25\n");
	line025.SetKLineDescription("\t1.����������;��\n\
\t2.�ɴ�С����5��K�����\n\
\t3.������һ�������߻������ߣ�����������������С���ߣ����Ƕ�û����ǰ������ߵĿ��̼ۣ�������һ�������߻������ߣ��������е�����Ӣ����ĸN\n\
\t�������ǣ�\n\
\t\n");
	line025.SetKLineAnalysFun(Analysis::KLineAnaly025);
	m_kLineArray.push_back(line025);

	KlINE line026;
	line026.SetKLineName(" �෽���26\n");
	line026.SetKLineDescription("\t1.����������;��\n\
\t2.�����ɸ�K�����\n\
\t3.������һ�������߻������ʱ��������һ���ϳ�����Ӱ�ߣ�Ȼ��ɼۻ��䣬�����ùɼ�����������Ӱ�ߵ��Ϸ�\n\
\t�������ǣ�\n\
\t����ͼ�ϳ�������K����̬��ʵ�����Ƕ෽��������ȫ�����ǰ��һ������\n");
	line026.SetKLineAnalysFun(Analysis::KLineAnaly026);
	m_kLineArray.push_back(line026);

	KlINE line027;
	line027.SetKLineName("�����һ��27\n");
	line027.SetKLineDescription("\t1.��������������Ҳ�����ڵ�����\n\
\t2.��2���ϳ������ߺ�һ���϶̵�������ɣ����߼�������֮��\n\
\t3.\n\
\t�������г��֣��������ǣ��ڵ����г��֣��Ǽ����źţ�\n\
\t\n");
	line027.SetKLineAnalysFun(Analysis::KLineAnaly027);
	m_kLineArray.push_back(line027);

	KlINE line028;
	line028.SetKLineName("�ƻ�ʮ����28\n");
	line028.SetKLineDescription("\t1.������������\n\
\t2.������K����ɣ���һ��Ϊ���ߣ��ڶ���Ϊʮ���ߣ�������Ϊ���ߡ�������K��ʵ�����뵽��һ��K��ʵ���ڲ�\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line028.SetKLineAnalysFun(Analysis::KLineAnaly028);
	m_kLineArray.push_back(line028);

	KlINE line029;
	line029.SetKLineName("�ƻ�֮��29\n");
	line029.SetKLineDescription("\t1.������������\n\
\t2.������K����ɣ���һ��Ϊ���ߣ��ڶ���Ϊʮ����С����С����������Ϊ���ߡ�������K��ʵ�����뵽��һ��K��ʵ���ڲ�\n\
\t3.\n\
\t�����źţ����п�����\n\
\t�źŲ���ƻ�ʮ����ǿ��\n");
	line029.SetKLineAnalysFun(Analysis::KLineAnaly029);
	m_kLineArray.push_back(line029);

	KlINE line030;
	line030.SetKLineName("���ѷ���30\n");
	line030.SetKLineDescription("\t1.������������\n\
\t2.��һ��һ��2��K�����\n\
\t3.���ǳ���һ�������߽������̸߿����������һ�������߻�����ߣ�����ǰһ��K�����̼���ͬ��λ��\n\
\t�����źţ����п�����\n\
\tת���źŲ������ƸǶ�\n");
	line030.SetKLineAnalysFun(Analysis::KLineAnaly030);
	m_kLineArray.push_back(line030);

	KlINE line031;
	line031.SetKLineName("���ƸǶ�31\n");
	line031.SetKLineDescription("\t1.������������\n\
\t2.��һ�������߻�����ߺ�һ�������ߺʹ��������\n\
\t3.���������뵽����ʵ�����֮һ���´�\n\
\t�����źţ����п�����\n\
\t������������ʵ�岿��Խ�࣬ת���ź�Խǿ\n");
	line031.SetKLineAnalysFun(Analysis::KLineAnaly031);
	m_kLineArray.push_back(line031);

	KlINE line032;
	line032.SetKLineName("�������32\n");
	line032.SetKLineDescription("\t1.������������\n\
\t2.��һ��һ��2��K�����\n\
\t3.����һ�������߻������ߣ����ų���һ���Ϳ��Ĵ����߻������ߣ��������̼��ѵ���ǰһ�����߿��̼�\n\
\t�����źţ����п�����\n\
\t�����ź�ǿ�����ƸǶ�������ʵ���������ʵ�岿��Խ�࣬ת���ź�Խǿ\n");
	line032.SetKLineAnalysFun(Analysis::KLineAnaly032);
	m_kLineArray.push_back(line032);

	KlINE line033;
	line033.SetKLineName("���֮�ǣ�ɨ���ǣ�33\n");
	line033.SetKLineDescription("\t1.������������\n\
\t2.���ߣ�Ҳ���������ߣ�ʵ���С����Ӱ�ߴ��ڵ���ʵ�������\n\
\t3.һ������Ӱ�ߣ�����������һ����Ӱ��\n\
\t�����źţ����п�����\n\
\tʵ������Ӱ�߱���Խ���⣬�ź�Խ�вο���ֵ�������֮����ƻ�֮��ͬʱ���֣������źž͸��ӿɿ�\n");
	line033.SetKLineAnalysFun(Analysis::KLineAnaly033);
	m_kLineArray.push_back(line033);

	KlINE line034;
	line034.SetKLineName("�����ߣ������ߣ�34\n");
	line034.SetKLineDescription("\t1.������������\n\
\t2.���ߣ�Ҳ���������ߣ�ʵ���С����Ӱ�ߴ��ڵ���ʵ�������\n\
\t3.һ������Ӱ�ߣ�����������һ����Ӱ��\n\
\t�����źţ����п�����\n\
\tʵ������Ӱ�߱���Խ���⣬�ź�Խ�вο���ֵ�������֮����ƻ�֮��ͬʱ���֣������źž͸��ӿɿ�\n");
	line034.SetKLineAnalysFun(Analysis::KLineAnaly034);
	m_kLineArray.push_back(line034);

	KlINE line035;
	line035.SetKLineName("ƽ����ǯ�Ӷ���35\n");
	line035.SetKLineDescription("\t1.������������\n\
\t2.����������������K�����\n\
\t3.��߼۴���ͬһˮƽλ����\n\
\t�����źţ����п�����\n\
\t\n");
	line035.SetKLineAnalysFun(Analysis::KLineAnaly035);
	m_kLineArray.push_back(line035);

	KlINE line036;
	line036.SetKLineName("���ζ�36\n");
	line036.SetKLineDescription("\t1.������������\n\
\t2.����һ�������߻������ߣ���Ϊһ������С��С���ߣ�������һ�������߻�������\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line036.SetKLineAnalysFun(Analysis::KLineAnaly036);
	m_kLineArray.push_back(line036);

	KlINE line037;
	line037.SetKLineName("Բ��37\n");
	line037.SetKLineDescription("\t1.������������\n\
\t2.�ɼ��γ�һ��Բ����\n\
\t3.Բ���ڵ�K�߶�ΪС��С���ߣ��������������ȱ����ȷ��Բ����̬����\n\
\t�����źţ����п�����\n\
\t\n");
	line037.SetKLineAnalysFun(Analysis::KLineAnaly037);
	m_kLineArray.push_back(line037);

	KlINE line038;
	line038.SetKLineName("˫����ѻ38\n");
	line038.SetKLineDescription("\t1.������������\n\
\t2.������һ��һ���������\n\
\t3.��һ�����ߵ����̼۸���ǰһ�����ߵ����̼ۣ��ҵڶ���������ȫ�����˵�һ����\n\
\t�����źţ����п�����\n\
\t\n");
	line038.SetKLineAnalysFun(Analysis::KLineAnaly038);
	m_kLineArray.push_back(line038);

	KlINE line039;
	line039.SetKLineName("��ֻ��ѻ���������ܣ�39\n");
	line039.SetKLineDescription("\t1.������������\n\
\t2.������������ɣ����߶�Ϊ������������\n\
\t3.��һ�����ߵ����̼۸���ǰһ�����ߵ����̼ۣ��ҵڶ���������ȫ�����˵�һ����ÿ�ξ������뿪�̣�������µ�����\n\
\t�����źţ����п�����\n\
\t\n");
	line039.SetKLineAnalysFun(Analysis::KLineAnaly039);
	m_kLineArray.push_back(line039);

	KlINE line040;
	line040.SetKLineName("�ߵ�������40\n");
	line040.SetKLineDescription("\t1.������������\n\
\t2.�����������ɣ�����ΪС����\n\
\t3.��������һ�������������ߣ������������������������\n\
\t�����źţ����п�����\n\
\t��һ������������ߣ�Ҳ�п����������߸�����\n");
	line040.SetKLineAnalysFun(Analysis::KLineAnaly040);
	m_kLineArray.push_back(line040);

	KlINE line041;
	line041.SetKLineName("�½�������41\n");
	line041.SetKLineDescription("\t1.������������\n\
\t2.��4��K����ɡ�ǰ����K�߹���һ����ͷ�ƽ���̬����������K����һ�������߻���С���ߣ������ߵ�ʬ��ͨ����ǰһ������Ҫ�̣�֮���ֳ���һ�������߻�С���ߣ�����ʬ���Ѿ����뵽ǰһ������ʵ��֮�С�\n\
\t3.��������һ�������������ߣ������������������������\n\
\t�����źţ����п�����\n\
\t�����ź�ǿ�ڴ�ͷ�ƽ�\n");
	line041.SetKLineAnalysFun(Analysis::KLineAnaly041);
	m_kLineArray.push_back(line041);

	KlINE line042;
	line042.SetKLineName("�ֵ�������42\n");
	line042.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�����ɸ�С��С�������\n\
\t3.����С��С���ĺ��̣���������һ���������µ�����\n\
\t�����źţ����п�����\n\
\t\n");
	line042.SetKLineAnalysFun(Analysis::KLineAnaly042);
	m_kLineArray.push_back(line042);

	KlINE line043;
	line043.SetKLineName("������43\n");
	line043.SetKLineDescription("\t1.�����������г��֣�Ҳ���ڵ����г���\n\
\t2.������С������ɣ���ͼ�һ����һ����\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line043.SetKLineAnalysFun(Analysis::KLineAnaly043);
	m_kLineArray.push_back(line043);

	KlINE line044;
	line044.SetKLineName("����������44\n");
	line044.SetKLineDescription("\t1.���������ڳ���\n\
\t2.�����ɸ�СK����ɣ�һ�㲻����8����������С���߾Ӷ࣬�м�Ҳ�ɼ���һЩС���ߣ�ʮ����\n\
\t3.����K��������΢������б\n\
\t�����źţ����п�����\n\
\t����������������Ȼ���󣬵������÷��������¸���ͣ���Ӷ��ӳ����µ���ʱ�����չ���µ��Ŀռ䣬�ɼۺܿ��ܾʹ˳��������ˡ���˶������������Ƶĸ��ɣ�Ӧ�ü�������ͣ���볡�ľ���\n");
	line044.SetKLineAnalysFun(Analysis::KLineAnaly044);
	m_kLineArray.push_back(line044);

	KlINE line045;
	line045.SetKLineName("�컺�µ���45\n");
	line045.SetKLineDescription("\t1.�����������µ�����\n\
\t2.�Ƚ������ּ���С���ߣ�Ȼ�������д�����\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line045.SetKLineAnalysFun(Analysis::KLineAnaly045);
	m_kLineArray.push_back(line045);

	KlINE line046;
	line046.SetKLineName("�µ���ֹ��46\n");
	line046.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�ڶ������м��Ž��ٵ�С���ߣ�����K�����г�������б״̬\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line046.SetKLineAnalysFun(Analysis::KLineAnaly046);
	m_kLineArray.push_back(line046);

	KlINE line047;
	line047.SetKLineName("�½��ֿ���47\n");
	line047.SetKLineDescription("\t1.�������µ�;��\n\
\t2.�����ɸ����ߺ�������ɣ������ߴ���������\n\
\t3.�������Ϳ��̣���ʹ�м��ճ����ߣ������̼�Ҳ��ǰһ��k�ߵ����̼۵�\n\
\t�����źţ����п�����\n\
\t\n");
	line047.SetKLineAnalysFun(Analysis::KLineAnaly047);
	m_kLineArray.push_back(line047);

	KlINE line048;
	line048.SetKLineName("�߿�������48\n");
	line048.SetKLineDescription("\t1.ͻȻ���߿��̣���������ͣ�忪�̣�Ȼ��һ·�µ�������ճ�һ�������ߣ������Ե�ͣ������\n\
\t2.\n\
\t3.\n\
\t�����źţ����п�����\n\
\t����Ϊ����ׯ������������Ϣ���߳������£�һ����н���һ�νϴ����\n");
	line048.SetKLineAnalysFun(Analysis::KLineAnaly048);
	m_kLineArray.push_back(line048);

	KlINE line049;
	line049.SetKLineName("�µ�������49\n");
	line049.SetKLineDescription("\t1.���µ�����������ڳ���\n\
\t2.��һ����С4��k�����\n\
\t3.���µ�ʱ���ȳ���һ�������߻������ߣ�������������ߵ��·�������3��СK�ߣ��ȿ�����Сʮ���ߣ�Ҳ������ʵ���С����������\n\
\t�����źţ����п�����\n\
\t\n");
	line049.SetKLineAnalysFun(Analysis::KLineAnaly049);
	m_kLineArray.push_back(line049);

	KlINE line050;
	line050.SetKLineName("�½����������������ף�50\n");
	line050.SetKLineDescription("\t1.�������½�������\n\
\t2.�������С���ȵ�K�����\n\
\t3.�ȳ���һ�������߻������ߣ����ų���3������������С���ߣ���������С���߶�û�г��Ƶ�һ�����߿��̼ۣ����һ�������߻���������һ����ȫ����󲿷��̳���ǰ������С����\n\
\t�����źţ����п�����\n\
\t\n");
	line050.SetKLineAnalysFun(Analysis::KLineAnaly050);
	m_kLineArray.push_back(line050);

	KlINE line051;
	line051.SetKLineName("�շ����51\n");
	line051.SetKLineDescription("\t1.�������µ�������\n\
\t2.������K�����\n\
\t3.������һ�������߻������ʱ������һ���ϳ�����Ӱ�ߣ�Ȼ��ɼ۷����������ùɼ��ֵ�����Ӱ���·�\n\
\t�����źţ����п�����\n\
\t����ͼ�ϳ�������K����̬��ʵ�����ǿշ�������෽����ȫ��ɨ��ǰ��һ������\n");
	line051.SetKLineAnalysFun(Analysis::KLineAnaly051);
	m_kLineArray.push_back(line051);

	KlINE line052;
	line052.SetKLineName("������52\n");
	line052.SetKLineDescription("\t1.�������µ�����\n\
\t2.�������������\n\
\t3.ÿ�ն��ǵͿ����ߣ���һ��K���Ե������̣���2��K�������̼۵��ڻ�ӽ���ǰһ�յ����߿��̼ۣ������Ȼ����3�����ߣ�����ͼ����ȴ���������������������ߵĵ���\n\
\t�����źţ����п�����\n\
\t�����������������ׯ�ҹ��ϣ���������K��ͼ�µ����ʼ���Ͷ����Ҫ�������ն���볡\n");
	line052.SetKLineAnalysFun(Analysis::KLineAnaly052);
	m_kLineArray.push_back(line052);

	KlINE line053;
	line053.SetKLineName("��������������53\n");
	line053.SetKLineDescription("\t1.����������������\n\
\t2.��������3���������ո߿�������\n\
\t3.\n\
\t�����źţ����п�����\n\
\t\n");
	line053.SetKLineAnalysFun(Analysis::KLineAnaly053);
	m_kLineArray.push_back(line053);

	KlINE line054;
	line054.SetKLineName("��������54\n");
	line054.SetKLineDescription("\t1.������������\n\
\t2.�������������\n\
\t3.��������ʵ��Խ��ԽС�����һ�����ߵ���Ӱ�ߺܳ�\n\
\t�����źţ����п�����\n\
\t\n");
	line054.SetKLineAnalysFun(Analysis::KLineAnaly054);
	m_kLineArray.push_back(line054);

	KlINE line055;
	line055.SetKLineName("����ͣ��55\n");
	line055.SetKLineDescription("\t1.������������\n\
\t2.�������������\n\
\t3.����ʱ������2�������߻������ߣ�������������ʵ���С����Ӧ���ƿ���ͣ��\n\
\t�����źţ����п�����\n\
\t\n");
	line055.SetKLineAnalysFun(Analysis::KLineAnaly055);
	m_kLineArray.push_back(line055);

	KlINE line056;
	line056.SetKLineName("�����½���56\n");
	line056.SetKLineDescription("\t1.������������\n\
\t2.�������������������\n\
\t3.����������߶��ǵͿ��������һ���������̼۱�ǰ���������̼�Ҫ��\n\
\t�����źţ����п�����\n\
\t\n");
	line056.SetKLineAnalysFun(Analysis::KLineAnaly056);
	m_kLineArray.push_back(line056);

	KlINE line057;
	line057.SetKLineName("���ڼ�һ��57\n");
	line057.SetKLineDescription("\t1.���������ƻ������\n\
\t2.�������ϳ������ߺ�һ���϶̵�������ɡ����߼�������֮��\n\
\t3.\n\
\t�������г��֣��Ǽ����źţ��ڵ����г��֣�����������\n\
\t\n");
	line057.SetKLineAnalysFun(Analysis::KLineAnaly057);
	m_kLineArray.push_back(line057);

	KlINE line058;
	line058.SetKLineName("������58\n");
	line058.SetKLineDescription("\t1.�ɳ������κ������\n\
\t2.����ʵ��ϳ������Դ�����Ӱ��\n\
\t3.\n\
\t�����Ǹտ�ʼʱ�����ִ����ߺ�ʵ���ǣ�������;�г��ִ����ߣ��������ǣ��������������������г��ִ����ߣ��Ǽ����źš��������µ��������г��ִ����ߣ��ɼ��׻���������\n\
\t����ʵ��Խ�����ź�Խ�ɿ�\n");
	line058.SetKLineAnalysFun(Analysis::KLineAnaly058);
	m_kLineArray.push_back(line058);

	KlINE line059;
	line059.SetKLineName("������59\n");
	line059.SetKLineDescription("\t1.���Գ������κ������\n\
\t2.����ʵ��ϳ������Դ�����Ӱ��\n\
\t3.\n\
\t�������г��ִ����ߣ��Ǽ����źţ����µ��տ�ʼʱ�����ִ����ߣ����п��������µ�;�г��ִ����ߣ����������������������µ������г��ִ����ߣ��п�ͷ����֮���ɣ�\n\
\t\n");
	line059.SetKLineAnalysFun(Analysis::KLineAnaly059);
	m_kLineArray.push_back(line059);

	KlINE line060;
	line060.SetKLineName("С����60\n");
	line060.SetKLineDescription("\t1.�����������г��ֽ϶࣬Ҳ���������µ������г���\n\
\t2.K��ʵ���С�����Դ�����Ӱ��\n\
\t3.\n\
\t˵�����鲻���ʣ����˫��С�ĽӴ������෽����ռ�Ϸ磡\n\
\t����С�����������岻��Ӧ�������K����̬һ������\n");
	line060.SetKLineAnalysFun(Analysis::KLineAnaly060);
	m_kLineArray.push_back(line060);

	KlINE line061;
	line061.SetKLineName("С����61\n");
	line061.SetKLineDescription("\t1.�����������г��ֽ϶࣬Ҳ�����µ������������г���\n\
\t2.K��ʵ���С�����Դ�����Ӱ��\n\
\t3.\n\
\t˵�����鲻���ʣ����˫��С�ĽӴ������շ���ռ�Ϸ磡\n\
\t����С�����������岻��Ӧ�������K����̬һ������\n");
	line061.SetKLineAnalysFun(Analysis::KLineAnaly061);
	m_kLineArray.push_back(line061);

	KlINE line062;
	line062.SetKLineName("ʮ����62\n");
	line062.SetKLineDescription("\t1.���ɳ����������У�Ҳ�ɳ����ڵ�����\n\
\t2.���̼����̼���ͬ����Ϊһ�֣�������Ӱ�϶�\n\
\t3.\n\
\t����������ĩ�˳��֣��Ǽ����źţ����µ�����ĩ�˳��֣��Ǽ����źš�������;�г��֣��������ǣ����µ�;�г��֣�����������\n\
\t�źſɿ��Բ�ǿ��Ӧ�������K��һ������\n");
	line062.SetKLineAnalysFun(Analysis::KLineAnaly062);
	m_kLineArray.push_back(line062);

	KlINE line063;
	line063.SetKLineName("��ʮ����63\n");
	line063.SetKLineDescription("\t1.���ɳ����������У�Ҳ�ɳ����ڵ�����\n\
\t2.���̼����̼���ͬ����Ϊһ�֣�����߼�����ͼ����ĺܿ����������Ӱ�߶��ܳ�\n\
\t3.\n\
\t����������ĩ�˳��֣��Ǽ����źţ����µ�����ĩ�˳��֣��Ǽ����źţ�������;�г��֣��������ǣ����µ�;�г��֣�����������\n\
\t��Ȼ��ʮ���ߵļ���������һ��ʮ���ߵĺ�����ͬ�����źſɿ��̶�Զ�Ⱥ��߸ߡ���ˣ�Ͷ���߿ɽ�����Ϊ�Ӷ��볭�׵���Ҫ�ο�ָ��\n");
	line063.SetKLineAnalysFun(Analysis::KLineAnaly063);
	m_kLineArray.push_back(line063);

	KlINE line064;
	line064.SetKLineName("������64\n");
	line064.SetKLineDescription("\t1.���ɳ����������У�Ҳ�ɳ����ڵ�����\n\
\t2.���̼����̼۽ӽ���K��ʵ�����������С������߼�����ͼ����ĺܿ����������Ӱ�߶��ܳ�\n\
\t3.\n\
\t�������г��֣����п��������µ�;�г��֣��������������������µ������г��֣��м��׻��������壡\n\
\tת���źűȳ�ʮ���߸�ǿ\n");
	line064.SetKLineAnalysFun(Analysis::KLineAnaly064);
	m_kLineArray.push_back(line064);

	KlINE line065;
	line065.SetKLineName("һ����65\n");
	line065.SetKLineDescription("\t1.���ɳ����������У�Ҳ�ɳ����ڵ�����\n\
\t2.���̼ۡ����̼ۡ���߼ۡ���ͼۼ�����ͬ���γ�һ��\n\
\t3.\n\
\t�����������г��֣�������źţ����µ������г��֣��������źţ�\n\
\t���ǵ�ͣ���ƶ��£�һ�������ر����壬�����г���һ���ߣ���ʾ�ɼ۷�����ͣ���ϣ�˵����ͷ��ʢ���պ�ù���������ǿ�ƹɣ������г���һ���ߣ���ʾ�ɼ۷�ɱ�ڵ�ͣ���ϣ�˵����ͷ������ǿ���պ�ù������������ƹ�\n");
	line065.SetKLineAnalysFun(Analysis::KLineAnaly065);
	m_kLineArray.push_back(line065);

	KlINE line066;
	line066.SetKLineName("T����66\n");
	line066.SetKLineDescription("\t1.���̼ۡ����̼ۡ���߼�����һ�𣬳�Ϊһ�֣�����ͼ���֮���൱���룬�����K��������һ����Ӱ�ߣ�����T��״ͼ\n\
\t2.\n\
\t3.\n\
\t����������ĩ�˳��֣�Ϊ�����źţ����µ�����ĩ�˳��֣�Ϊ����źš�������;�г��֣��������ǣ����µ�;�г��֣�����������\n\
\tT������Ӱ��Խ��������Խ���ź�Խ�ɿ�\n");
	line066.SetKLineAnalysFun(Analysis::KLineAnaly066);
	m_kLineArray.push_back(line066);

	KlINE line067;
	line067.SetKLineName("��T����67\n");
	line067.SetKLineDescription("\t1.���̼ۡ����̼ۡ���ͼ�ճ����һ�𣬳�Ϊһ�֣�������߼���֮���൱���룬�����K��������һ����Ӱ�ߣ����ɵ�T��״ͼ��\n\
\t2.\n\
\t3.\n\
\t����������ĩ�˳��֣�Ϊ�����źţ����µ�����ĩ�˳��֣�Ϊ����źţ�������;�г��֣��������ǣ����µ�;�г��֣�����������\n\
\t��T������Ӱ��Խ��������Խ���ź�Խ�ɿ��������������г��ֵĵ�T���ߣ���Ϊ�ϵ���T���ߣ��ֳ��µ�ת����\n");
	line067.SetKLineAnalysFun(Analysis::KLineAnaly067);
	m_kLineArray.push_back(line067);

	KlINE line068;
	line068.SetKLineName("������68\n");
	line068.SetKLineDescription("\t1.����������������\n\
\t2.��һ��һ������T�����\n\
\t3.\n\
\t������;�г��֣��������ǣ�������ĩ�˳��֣��Ǽ����źţ�\n\
\t������;�г��ֵĴ�������СT���߾Ӷ࣬������ĩ�˳��ֵĴ����ߣ��Դ�T�Ӷ�\n");
	line068.SetKLineAnalysFun(Analysis::KLineAnaly068);
	m_kLineArray.push_back(line068);

	KlINE line069;
	line069.SetKLineName("��ͷ��69\n");
	line069.SetKLineDescription("\t1.�ȿ��Գ����������У�Ҳ���Գ����ڵ�����\n\
\t2.������һ��һСK�����\n\
\t3.�����������У���һ��K��Ϊ�����߻������߲�����һ����Ӱ�ߣ��ڶ���K��ΪСʮ���߻�С��С���ߣ������ڵ�һ��K�ߵ���Ӱ��֮��\n\
\t4.�����ڵ����У����һ��K��Ϊ�����߻������ߣ�������һ����Ӱ�ߣ��ڶ���K��ΪС��С��Сʮ���ߣ������ڵ�һ��K�ߵ���Ӱ��֮��\n\
\t�����������У��Ǽ����źţ������ڵ����У��Ǽ����źţ�\n\
\t��ͷ�ߵ���Ӱ�߻���Ӱ�ߵ��ҷ������ŵ�K��ԽС����Сʮ���ǣ����ź�Խǿ\n");
	line069.SetKLineAnalysFun(Analysis::KLineAnaly069);
	m_kLineArray.push_back(line069);

	KlINE line070;
	line070.SetKLineName("��ͷ�ƽ�70\n");
	line070.SetKLineDescription("\t1.���������������г��֣�Ҳ�������µ������г���\n\
\t2.�ɴ�С���ȣ������෴������K�����\n\
\t3.�����������г��֣�ǰһ��Ϊ���ߣ���һ����Ϊ���ߣ����߽�ǰ��ʵ��ȫ�������ڣ�����������Ӱ��\n\
\t4.���µ������г��֣�ǰһ��Ϊ���ߣ���һ����Ϊ���ߣ����߽�ǰ��ʵ��ȫ�������ڣ�����������Ӱ��\n\
\t�����������г��֣��������źţ����µ������г��֣�Ϊ�����źţ�\n\
\t2��K�ߵĳ���Խ���⣬��һ������K�߰���ǰ���K��Խ�࣬�źŵĲο���ֵ��Խ��\n");
	line070.SetKLineAnalysFun(Analysis::KLineAnaly070);
	m_kLineArray.push_back(line070);

	KlINE line071;
	line071.SetKLineName("������71\n");
	line071.SetKLineDescription("\t1.���������������г��֣�Ҳ�������µ������г���\n\
\t2.�ɴ�С���ȵ�����K����ɣ�����K�߿�һ��һ����������������\n\
\t3.��һ��K��ʵ��Ҫ����ȫ���ݵڶ���K��ʵ��\n\
\t4.�ڶ���K�߿�����С��С��ʮ����\n\
\t�����������г��֣��������źţ����µ������г��֣�������źţ�\n\
\t���ڶ���K��Ϊʮ���ߣ��׳�ʮ��̥�����������У�ʮ��̥����������K����̬֮һ\n");
	line071.SetKLineAnalysFun(Analysis::KLineAnaly071);
	m_kLineArray.push_back(line071);

	KlINE line072;
	line072.SetKLineName("������72\n");
	line072.SetKLineDescription("\t1.���������������г��֣�Ҳ�������µ������г���\n\
\t2.����������һС��K�����\n\
\t3.3��K�ߵ���߼ۼ�������ͬһˮƽ����\n\
\t������ʱ����Ϊͷ���źţ����µ�ʱ����Ϊ�ײ��źţ�\n\
\t\n");
	line072.SetKLineAnalysFun(Analysis::KLineAnaly072);
	m_kLineArray.push_back(line072);

	KlINE line073;
	line073.SetKLineName("�ϵ�������73\n");
	line073.SetKLineDescription("\t1.����������;��\n\
\t2.�����ɸ���ʮ����K�����\n\
\t3.������ʱ����һ�������ȵ����ߺ󣬾ͳ��������������²�����Χ��С�ĺ�������\n\
\t�ϵ�����ʱ����5-14���ڣ��������ǣ�����14�죬����������\n\
\t����ʱ��̫�ã�˵���෽�Ϲ�ԩ����ǿ������µ������Ժܴ�\n");
	line073.SetKLineAnalysFun(Analysis::KLineAnaly073);
	m_kLineArray.push_back(line073);



	KlINE line074;
	line074.SetKLineName("���ٶ���74\n");
	line074.SetKLineDescription("\t1.���ɳ����������У�Ҳ�ɳ����ڵ�����\n\
\t2.����ʱ���ּ��ٶ��ߣ�����Ϊ��ʼ�������������������ٶ�Խ��Խ�죬�����������������߻������\n\
\t3.�µ�ʱ���ּ��ٶ��ߣ�����Ϊ��ʼ�����µ��������µ��ٶ�Խ��Խ�죬�����������������߻������\n\
\t������ʱΪͷ���źţ����µ�ʱ����Ϊ�ײ��źţ�\n\
\t\n");
	line074.SetKLineAnalysFun(Analysis::KLineAnaly074);
	m_kLineArray.push_back(line074);

	KlINE line075;
	line075.SetKLineName("�µ�������75\n");
	line075.SetKLineDescription("\t1.�����ڵ���;��\n\
								\t2.������������ɣ����߶�Ϊ�����߻�������\n\
								\t3.ÿ�����߶�����ͼۻ�εͼ۱��գ����һ�����������Ǵ�����\n\
								\t���µ����ڳ��֣��������������µ����ڳ��֣��Ǽ����źţ�\n\
								\t������������ֹ����£��ر��ǹɼ��нϴ�������������������ʾ�շ��������þ�\n");
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
			printf("�����%s",iter->GetKLineName().GetString());
			printf("ǿ�ȣ�");
			if (result < 0)
			{
				for (int i = 0; i < abs(result); i++)
				{
					printf("��");
				}

			}
			else
			{
				for (int i = 0; i < abs(result); i++)
				{
					printf("��");
				}
			}
			printf("\n");
			printf("������\n%s",iter->GetKLineDescription().GetString());
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
			printf("Ԥ�⣺%s",iter->GetKLineName().GetString());
			printf("������\n%s",iter->GetKLineDescription().GetString());
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
	//������һ�±���
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
	//�������ڵ�����
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
				if ((buyOrSaleType == 0  &&  totalCount <= 0) || buyOrSaleType == 1) //buyorsaletype Ϊ0��ʾ���������ڼ�ֻ��һ�Σ�Ϊ1��ʾֻҪ���Ǿ�����
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
			//��ƽ����׼ȷ����û������ģ���Ϊ��ƽ���������������ǳ�ƽ�������޷�Ԥ��
			//��ƽ��ʱ����ֹӯֹ���������
			if (iter->stockType == 0)
			{
				if (totalStockValue > 0 && totalCount > 0)//�й�Ʊ��ʱ��Ž����ж�
				{
					double averageStockValue = totalStockValue / totalCount;
					double lowAverageStockValue = averageStockValue * 0.9; 
					double highAverageStockValue = averageStockValue * 1.1; 

					//��һ��Ĳ��������ֹ�������ֹӯ�㣬���Ȱ�ֹ�������������С�����������Ҳ���Է�����������������������
					//ֹ����׳�
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
						//ֹӮ���׳�
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

				printf("ʱ�� = %d,\tԤ������ = %d,\tʵ������ = %d,\t��Ʊ�� = %d,\t��Ʊ�ܶ� = %.2f,\tʵ��Ӫ�� = %.2f\n",iter->stockData.GetStockTime(),iter->stockType,realBuyOrSale,totalCount,totalStockValue,totalValue + totalCount * lastValue);
			}
			
		}
		
		//������2000�����ϣ�����Ͷ���������20%����
		//if (totalValue + totalCount * lastValue > 2000.0 && ((totalValue + totalCount * lastValue) * 100) / fabs(maxCharge) > 20.0)
		{
			if (!bPrintf)
			{
				printf("%s,type=%d,",pathName,buyOrSaleType);
			}
			printf("�ܹ�Ӫ�գ�%.2f,���֧����%.2f,���Ͷ������ȣ�%.2f%%,�ܹ�Ԥ�⣺%d,�ɹ�������%d,�ɹ��ٷֱȣ�%.2f%%,����Ԥ�⣺%d,�ɹ�������%d,�ɹ��ٷֱȣ�%.2f%%,�µ�Ԥ�⣺%d,�ɹ�������%d,�ɹ��ٷֱȣ�%.2f%%\n",totalValue + totalCount * lastValue,fabs(maxCharge),(maxCharge != 0 ? ((totalValue + totalCount * lastValue) * 100) / fabs(maxCharge):0),totalYuce,totalYuceSuccess,(totalYuce > 0 ? totalYuceSuccess * 100.0 / totalYuce:0),totalShangZhangYuce,totalShangZhangYuceSuccess,(totalShangZhangYuce > 0 ? totalShangZhangYuceSuccess * 100.0 / totalShangZhangYuce:0),totalXiadieYuce,totalXiadieYuceSuccess,(totalXiadieYuce > 0 ? totalXiadieYuceSuccess * 100.0 / totalXiadieYuce:0));
		}

		//printf("�ܹ�Ԥ�⣺%d  ���ɹ�������%d,�ɹ��ٷֱȣ�%.2f%%\n",totalYuce,yuceSuccess,yuceSuccess * 100.0 / totalYuce);

	}

}
