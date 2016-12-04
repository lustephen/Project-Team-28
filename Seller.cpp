#include<iostream>
#include<vector>
#include"Seller.hpp"
#include"Person.hpp"

using namespace std;

Seller::Seller(double min, double ex)
{
	//for (int i = 0; i < locationCoordinateSize; i++)
		//location[i] = l[i];
	minPurchase = min;
	//maxDist = max;
	exRate = ex;
	Person();
}
Seller::Seller(double min, double ex, int mm, int dd, int yr, string n, char u, string ufid) : Person(n, mm, dd, yr, u, ufid)
{
	minPurchase = min;
	exRate = ex;
	Person(n,mm,dd,yr,u,ufid);
}
/*
void Seller::setDistanceToBuyer(double dist)
{
	distanceToBuyer = dist;
}

double Seller::getMaxDist()
{
	return maxDist;
}
*/
double Seller::getMinPurchase()
{
	return minPurchase;
}

double Seller::getExchangeRate()
{
	return exRate;
}
/*
int Seller::getLocationCoordinateSize()
{
	return locationCoordinateSize;
}


int* Seller::getLocation()
{
	return location;
}

double Seller::getDistanceToBuyer()
{
	return distanceToBuyer;
}
*/
