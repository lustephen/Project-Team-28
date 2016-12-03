#include<iostream>
#include<vector>
#include"Buyer.hpp"
#include"person.hpp"
Buyer::Buyer(double est, double ex, int mm, int dd, int yr, std::string n, char u, int ufid) : Person(mm, dd, yr, n, u, ufid)
{
	estPurchase = est;
	exRate = ex;
}
Buyer::Buyer(double est, double ex)
{
	//for (int i = 0; i < locationCoordinateSize; i++)
		//location[i] = l[i];
	estPurchase = est;
	//maxDist = max;
	exRate = ex;
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

double Buyer::getExcangeRate()
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
