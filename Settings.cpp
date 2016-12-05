#include "Settings.hpp"

void Settings::setExchangeRate(double exchange)
{
	exchangerate = exchange;
}

void Settings::setMinPurchase(double minpurch)
{
	minpurchase = minpurch;
}

double Settings::getExchangeRate()
{
	return exchangerate;
}

double Settings::getMinPurchase()
{
	return minpurchase;
}
