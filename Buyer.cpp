#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include"Seller.hpp"
#include"Buyer.hpp"
#include"BuyerSellerTree.hpp"

Buyer::Buyer(int l[], double est, double max, double ex)
{
	for (int i = 0; i < locationCoordinateSize; i++)
		location[i] = l[i];
	estPurchase = est;
	maxDist = max;
	exRate = ex;
}

//Buyer::Buyer(Random Person)

void Buyer::setSellerList(std::vector<Seller*> sellList)
{
	for(int i=0;i<sellList.size();i++)
	sellerList[i] = sellList[i];

}

void Buyer::sortSellerList()
{
	tree elm;
	
	for (int i = 0; i < sellerList.size; i++)
		elm.addLeaf(sellerList[i]->getMinPurchase,sellerList[i]);
	
	for (int i = 0; i < elm.getSortedSellerList.size; i++)
		sortedSellerList.push(elm.getSortedSellerList[i]);
}

Seller Buyer::selectMatch()
{	
	return sortedSellerList.front;
}
//preformed before the tree sorts
void Buyer::removeOutOfRangeValues()
{	/*
	Removes the values that are greater than the buyer is willing to pay or further than there maxdist
	*/
	for (int i = 0; i < sellerList.size(); i++)
	{
		if (sellerList[i]->getDistanceToBuyer() > maxDist || sellerList[i]->getMaxDist > sellerList[i]->getDistanceToBuyer || sellerList[i]->getMinPurchase > estPurchase)
			sellerList.erase(sellerList.begin()+i);
	}
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
