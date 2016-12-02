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

