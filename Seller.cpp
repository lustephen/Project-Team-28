#include<iostream>
#include<vector>
#include"Seller.hpp"
#include"Person.hpp"

using namespace std;
//Seller Constructor for the user
Seller::Seller(double min, double ex)
{
	minPurchase = min;
	exRate = ex;
	Person();
}
//Seller overloaded constructor for the random seller
Seller::Seller(double min, double ex, int mm, int dd, int yr, string n, char u, string ufid) : Person(n, mm, dd, yr, u, ufid)
{
	minPurchase = min;
	exRate = ex;
	Person(n,mm,dd,yr,u,ufid);
}

double Seller::getMinPurchase()
{
	return minPurchase;
}

double Seller::getExchangeRate()
{
	return exRate;
}


