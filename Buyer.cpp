#include<iostream>
#include<vector>
#include"Buyer.hpp"

Buyer::Buyer(int l[], double est, double max, double ex)
{
	for (int i = 0; i < locationCoordinateSize; i++)
		location[i] = l[i];
	estPurchase = est;
	maxDist = max;
	exRate = ex;
}


int* Buyer::getLocation()
{
	return location;
}

double Buyer::getMaxDist()
{
	return maxDist;
}

double Buyer::getEstPurchase()
{
	return estPurchase;
}

double Buyer::getExcangeRate()
{
	return exRate;
}

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
