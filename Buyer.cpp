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
	//for (int i = 0; i < locationCoordinateSize; i++)
		//location[i] = l[i];
	estPurchase = est;
	//maxDist = max;
	exRate = ex;
	Person();
}

/*
int* Buyer::getLocation()
{
	return location;
}

double Buyer::getMaxDist()
{
	return maxDist;
}
*/
double Buyer::getEstPurchase()
{
	return estPurchase;
}

double Buyer::getExchangeRate()
{
	return exRate;
}
/*
int Buyer::getLocationCoordinateSize()
{
	return locationCoordinateSize;
}

void Buyer::setDistanceToSeller(double dist)
{
	distanceToSeller = dist;
}

double Buyer::getDistanceToSeller()
{
	return distanceToSeller;
}
*/
