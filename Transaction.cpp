#include "Transaction.hpp"

Transaction::Transaction(std::string n, double exchRate, double purch){
  this -> name = n;
  this -> exchangeRate = exchRate;
  this -> purchase = purch;
}

Transaction::Transaction() {
   
}

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
