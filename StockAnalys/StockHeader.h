#pragma once

const double microPercent = 0.002;
const double smallPercent = 0.01;
const double middlePercent = 0.03;
const double largePercent = 0.07;

typedef enum ZOUSHI
{
	ZOUSHI_ZHENGDANGDOWN = -12,
	ZOUSHI_HIGHDOWN = -11,
	ZOUSHI_LOWDOWN = -10,

	ZOUSHI_UNKNOWN = 0,
	ZOUSHI_LOWHENGPAN = 1,
	ZOUSHI_HIGHHENGPAN = 2,

	ZOUSHI_LOWUP = 10,
	ZOUSHI_HIGHUP = 11,
	ZOUSHI_ZHENDANGUP = 12
}ZOUSHI;