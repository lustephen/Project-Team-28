#include "Settings.hpp"
//Simple setters and getters for Settings variables, May not use settings
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
