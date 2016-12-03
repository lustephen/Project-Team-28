#include<iostream>
#include<vector>
#include"Seller.hpp"
#include"Person.hpp"

Seller::Seller(double min, double ex)
{
	//for (int i = 0; i < locationCoordinateSize; i++)
		//location[i] = l[i];
	minPurhcase = min;
	//maxDist = max;
	exRate = ex;
}
Seller::Seller(double min, double ex, int mm, int dd, int yr, std::string n, char u, int ufid) : Person(mm, dd, yr, n, u, ufid)
{
	minPurchase = min;
	exRate = ex;
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
	return minPurhcase;
}

double Seller::getExcangeRate()
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
