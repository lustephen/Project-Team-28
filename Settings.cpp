#include "Settings.hpp"

void Settings::setExchangeRate(double exchange)
{
	exchangerate = exchange;
}

void Settings::setMinProfit(double minprof)
{
	minprofit = minprof;
}

double Settings::getExchangeRate()
{
	return exchangerate;
}

double Settings::getMinProfit()
{
	return minprofit;
}
