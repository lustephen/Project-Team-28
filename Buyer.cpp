#include<iostream>
#include<vector>
#include"Buyer.hpp"
#include"Person.hpp"

using namespace std;

Buyer::Buyer(double est, double ex, int mm, int dd, int yr, string n, char u, string ufid) : Person(n, mm, dd, yr, u, ufid)
{
	estPurchase = est;
	exRate = ex;
	Person(n,dd,mm,yr,u,ufid);
}
Buyer::Buyer(double est, double ex)
{
	estPurchase = est;
	exRate = ex;
	Person();
}

double Buyer::getEstPurchase()
{
	return estPurchase;
}

double Buyer::getExchangeRate()
{
	return exRate;
}

