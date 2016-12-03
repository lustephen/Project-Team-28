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
	//calculates the distance each seller must go to reach the buyer
	//calculateDistanceToBuyer();
	//removes all the sellers who do not match the buyer
	removeOutOfRangeValuesForSellerList();
	//Sorts the seller list and stores the sorted sellerlist into sorted sellerlist
	//I will need a parameter to know if I should sort with respect to distance or price
	sortSellerList();
	//returns the lowest price or distance
	getSelectedSeller();

}

void SortAndCalculate::sellerFlow()
{
	//calculateDistanceToSeller();
	removeOutOfRangeValuesForBuyerList();
	sortBuyerList();
	getSelectedBuyer();
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

//Removes the sellers whose requirements do not match the buyers
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
//Might pass a parameter to indicate if it is to be sorted by exrate or distance
void SortAndCalculate::sortSellerList()
{
	tree *elm = new tree();

	for (unsigned int i = 0; i < sellerList.size(); i++)
		elm->addLeaf(sellerList[i]->getExcangeRate(), sellerList[i]);
	/*
	if(distance )
	for (unsigned int i = 0; i < sellerList.size(); i++)
		elm->addLeaf(sellerList[i]->getDistanceToBuyer(), sellerList[i]);
	*/
	elm->inOrderSellerList(elm->root);
	for (unsigned int i = 0; i < sellerList.size(); i++)
		sortedSellerList.push_back(elm->getSortedSellerList()[i]);
}

void SortAndCalculate::sortBuyerList()
{
	tree *oak = new tree();

	for (unsigned int i = 0; i < buyerList.size(); i++)
		oak->addLeaf(buyerList[i]->getExcangeRate(), buyerList[i]);
	/*
	if(distance or whatever)
	for (unsigned int i = 0; i < buyerList.size(); i++)
		oak->addLeaf(buyerList[i]->getDistanceToSeller(), buyerList[i]);
	*/
	oak->inOrderBuyerList(oak->root);

	for (unsigned int i = 0; i < buyerList.size(); i++)
		sortedBuyerList.push_back(oak->getSortedBuyerList()[i]);
}

Buyer* SortAndCalculate::getSelectedBuyer()
{
	return sortedBuyerList[sortedBuyerList.size()-1];
}

Seller* SortAndCalculate::getSelectedSeller()
{
	return sortedSellerList[0];
}
