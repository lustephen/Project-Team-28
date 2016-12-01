#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<Seller>
#include<Buyer>
#include<BuyerSellerTree>

Seller::Seller(int l[], double min, double max, double ex)
{
	for (int i = 0; i < locationCoordinateSize; i++)
		location[i] = l[i];
	minPurhcase = min;
	maxDist = max;
	exRate = ex;
}
//Don't know the order in the main for when to implement this
double Seller::calculateDistanceToBuyer(int buyerLocation[])
{
	int temp = 0;
	for (int i = 0; i < locationCoordinateSize; i++)
		temp += pow(std::abs(location[i] - buyerLocation[i]), 2);
	distanceToBuyer= sqrt(temp);
}

double Seller::getDistanceToBuyer()
{
	return distanceToBuyer;
}


void Seller::setBuyerList(std::vector<Buyer*> buyList)
{
	for (int i = 0; i < buyList.size; i++)
		buyerList[i] = buyList[i];
}

/*
not implemented yet
void Seller::removeOutOfRangeValues()
{
}
*/

/*
Buyer:: selectMatch()
*/


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

