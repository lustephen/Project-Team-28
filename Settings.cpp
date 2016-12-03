#include "Settings.hpp"

void Settings::setMaxDistance(double max)
{
	maxdistance = max;
}

void Settings::setExchangeRate(double exchange)
{
	exchangerate = exchange;
}

void Settings::setMinDistance(double min)
{
	mindistance = min;
}

void Settings::setMinExchangeRate(double minexchange)
{
	minexchangerate = minexchange;
}

void Settings::setMinProfit(double minprof)
{
	minprofit = minprof;
}

void Settings::setMaxDistance(double max)
{
	maxdistance = max;
}

double Settings::getMaxDistance()
{
	return maxdistance;
}

double Settings::getExchangeRate()
{
	return exchangerate;
}

double Settings::getMinDistance()
{
	return mindistance;
}

double Settings::getMinExchangeRate()
{
	return minexchangerate;
}

double Settings::getMinProfit()
{
	return minprofit;
}
