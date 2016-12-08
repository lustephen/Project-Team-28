#include "Transaction.hpp"
//Transaction constructor sets name, exchange rate, and purchase cost
Transaction::Transaction(std::string n, double exchRate, double purch, std::string tType){
  this -> name = n;
  this -> exchangeRate = exchRate;
  this -> purchase = purch;
  this -> transactionType = tType;
}
//Default Constructor for Transaction Class
Transaction::Transaction() {

}
//Functions to set Transaction private variables one at a time
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
void Transaction::setTransactionType(std::string tType)
{
    transactionType = tType;
}
//Functions used to get private variables
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
std::string Transaction::getTransactionType()
{
    return transactionType;
}
