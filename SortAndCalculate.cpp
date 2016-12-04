#include <vector>
#include "Tree.hpp"
#include "SortAndCalculate.hpp"

using namespace std;

SortAndCalculate::SortAndCalculate(Buyer *b, vector<Seller*> s)
{
	buyer = b;
	sellerList = s;
}

SortAndCalculate::SortAndCalculate(Seller *s, vector<Buyer*> b)
{
	seller = s;
	buyerList = b;
}

void SortAndCalculate::buyerFlow()
{
	//Sorts the seller list and stores the sorted sellerlist into sorted sellerlist
	sortSellerList();
}

void SortAndCalculate::sellerFlow()
{

	sortBuyerList();
}
/*
This function checks if there are any buyers who meet
the requirements of the seller. If there is at least
one buyer who meets the requirements of the seller
the function returns true. Otherwise when no buyers
meet the requirements of the seller the function
returns false
*/
bool SortAndCalculate::avaliableBuyerCheck()
{
	removeOutOfRangeValuesForBuyerList();
	if (sellerList.size() == 0)
		return false;
	return true;
}
/*
This function checks if there are any sellers who meet
the requirements of the buyer. If there is at least
one seller who meets the requirements of the buyer
the function returns true. Otherwise when no sellers
meet the requirements of the buyer the function
returns false.
*/
bool SortAndCalculate::avaliableSellerCheck()
{
	removeOutOfRangeValuesForSellerList();
	if (sellerList.size() == 0)
		return false;
	return true;
}
/*
void SortAndCalculate::calculateDistanceToBuyer()
{
	double temp = 0;

	for (unsigned int j = 0; j < sellerList.size(); j++)
	{
		for (unsigned int i = 0; i < buyer->getLocationCoordinateSize(); i++)
		{
			temp += pow(std::abs(sellerList[j]->getLocation()[i] - buyer->getLocation()[i]), 2);
		}
		sellerList[j]->setDistanceToBuyer(temp);
		temp = 0;
	}
}

void SortAndCalculate::calculateDistanceToSeller()
{
	double temp = 0;

	for (unsigned int j = 0; j < buyerList.size(); j++)
	{
		for (unsigned int i = 0; i < seller->getLocationCoordinateSize(); i++)
		{
			temp += pow(std::abs(buyerList[j]->getLocation()[i] - seller->getLocation()[i]), 2);
		}
		buyerList[j]->setDistanceToSeller(temp);
		temp = 0;
	}
}
*/

/*
Removes the sellers whose requirements do not match the buyers
Ie. it removes sellers whose min purchase requirement is greater
than the buyers estimated purchase, and it removes sellers whose
exchange rate is greater than the buyers exchange rate.
*/
void SortAndCalculate::removeOutOfRangeValuesForSellerList()
{

	for (int i = 0; i < sellerList.size(); i++)
	{
		if (buyer->getEstPurchase() < sellerList[i]->getMinPurchase() || buyer->getExchangeRate() < sellerList[i]->getExchangeRate())
		{
			sellerList.erase(sellerList.begin() + i);
			i--;
		}
	}

}
/*
Removes the buyers whose requirements do no match the sellers
ie. if the buyers est purchase is less than the sellers min
purchase the buyer is removed. Additionally if the buyers exchange
rate is less than the sellers the buyer is also removed.
*/
void SortAndCalculate::removeOutOfRangeValuesForBuyerList()
{
	for (unsigned int i = 0; i < buyerList.size(); i++)
	{
		if (buyerList[i]->getEstPurchase() < seller->getMinPurchase() || buyerList[i]->getExchangeRate() < seller->getExchangeRate())
		{
			buyerList.erase(buyerList.begin() + i);
			i--;
		}
	}

}
/*
This function creates a tree object. That uses a binary search
tree to sort the seller list by the exchange rate. It then puts
the seller list in order with inOrderSellerList(this function
contains a vector of type Seller* which it fills). Then the
vector sortedSellerList is filled with the sellers in order
(lowest exchange rate to highest)
*/
void SortAndCalculate::sortSellerList()
{
	tree *elm = new tree();

	for (unsigned int i = 0; i < sellerList.size(); i++)
		elm->addLeaf(sellerList[i]->getExchangeRate(), sellerList[i]);
	/*
	if(distance )
	for (unsigned int i = 0; i < sellerList.size(); i++)
		elm->addLeaf(sellerList[i]->getDistanceToBuyer(), sellerList[i]);
	*/
	elm->inOrderSellerList(elm->root);
	for (unsigned int i = 0; i < sellerList.size(); i++)
		sortedSellerList.push_back(elm->getSortedSellerList()[i]);
}
/*
This function creates a tree object. That uses a binary search
tree to sort the buyerr list by the exchange rate. It then puts
the buyerr list in order with inOrderBuyerList(this function
contains a vector of type Buyer* which it fills). Then the
vector sortedBuyerList is filled with the buyer in order
(lowest exchange rate to highest)
*/
void SortAndCalculate::sortBuyerList()
{
	tree *oak = new tree();

	for (unsigned int i = 0; i < buyerList.size(); i++)
		oak->addLeaf(buyerList[i]->getExchangeRate(), buyerList[i]);
	/*
	if(distance or whatever)
	for (unsigned int i = 0; i < buyerList.size(); i++)
		oak->addLeaf(buyerList[i]->getDistanceToSeller(), buyerList[i]);
	*/
	oak->inOrderBuyerList(oak->root);

	for (unsigned int i = 0; i < buyerList.size(); i++)
		sortedBuyerList.push_back(oak->getSortedBuyerList()[i]);
}
/*
returns the buyer who matches the sellers requirements with
the highest exchange rate
*/
Buyer* SortAndCalculate::getSelectedBuyer()
{
	return sortedBuyerList[sortedBuyerList.size()-1];
}
/*
returns the seller who matches the buyers requirements with
the lowest exchange rate
*/
Seller* SortAndCalculate::getSelectedSeller()
{
	return sortedSellerList[0];
}
