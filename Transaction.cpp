#include "Transaction.hpp"

void Transaction::setName(std::string n)
{
    name = n;
}
void Transaction::setExchangeRate(double exchange)
{
    exchangeRate = exchange;
}
void Transaction::setPurchase(double purch)
{
    purchase = purch;
}

std::string Transaction::getName()
{
    return name;
}
double Transaction::getExchangeRate()
{
    return exchangeRate;
}
double Transaction::getPurchase()
{
    return purchase;
}