SortAndCalculate::SortAndCalculate(Buyer *b, vector<Seller*> s)
{
	buyer = b;
	removeOutOfRangeValues(b, s);
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
	calculateDistanceToBuyer();
	//removes all the sellers who do not match the buyer
	removeOutOfRangeValues(buyer, sellerList);
	//Sorts the seller list and stores the sorted sellerlist into sorted sellerlist
	//I will need a parameter to know if I should sort with respect to distance or price
	sortSellerList();
	//returns the lowest price or distance
	getSelectedSeller();

}

void SortAndCalculate::sellerFlow()
{
	calculateDistanceToSeller();
	removeOutOfRangeValues(seller, buyerList);
	sortBuyerList();
	getSelectedBuyer();
}

//Not tested at all
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
//not tested
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


//Removes the sellers whose requirements do not match the buyers
void SortAndCalculate::removeOutOfRangeValues(Buyer *b, vector<Seller*> s)
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (b->getEstPurchase() < s[i]->getMinPurchase() || b->getExcangeRate() < s[i]->getExcangeRate())
		{
			s.erase(s.begin()+i);
			i--;
		}
		
	}
}

void SortAndCalculate::removeOutOfRangeValues(Seller *s, vector<Buyer*> b)
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i]->getEstPurchase() < s->getMinPurchase() || b[i]->getExcangeRate() < s->getExcangeRate())
		{
			b.erase(b.begin() + i);
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
	oak->inOrderSellerList(oak->root);

	for (unsigned int i = 0; i < buyerList.size(); i++)
		sortedBuyerList.push_back(oak->getSortedBuyerList()[i]);
}

Buyer* SortAndCalculate::getSelectedBuyer()
{
	return sortedBuyerList[0];
}

Seller* SortAndCalculate::getSelectedSeller()
{
	return sortedSellerList[0];
}
