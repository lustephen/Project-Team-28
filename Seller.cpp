#include<iostream>
#include<vector>
#include"Seller.hpp"

Seller::Seller(int l[], double min, double max, double ex)
{
	for (int i = 0; i < locationCoordinateSize; i++)
		location[i] = l[i];
	minPurhcase = min;
	maxDist = max;
	exRate = ex;
}

void Seller::setDistanceToBuyer(double dist)
{
	distanceToBuyer = dist;
}

double Seller::getMaxDist()
{
	return maxDist;
}

double Seller::getMinPurchase()
{
	return minPurhcase;
}

double Seller::getExcangeRate()
{
	return exRate;
}

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

