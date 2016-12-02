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
//Removes the sellers whose requirements do not match the buyers
void SortAndCalculate::removeOutOfRangeValues(Buyer *b, vector<Seller*> s)
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (b->getEstPurchase() < s[i]->getMinPurchase() || b->getExcangeRate() < s[i]->getExcangeRate())
			s.erase(s.begin()+i);
	}
}

void SortAndCalculate::removeOutOfRangeValues(Seller *s, vector<Buyer*> b)
{
	for (unsigned int i = 0; i < b.size(); i++)
	{
		if (b[i]->getEstPurchase() < s->getMinPurchase() || b[i]->getExcangeRate() < s->getExcangeRate())
			b.erase(b.begin() + i);
	}
}

void SortAndCalculate::sortSellerList()
{
	tree *elm = new tree();

	for (unsigned int i = 0; i < sellerList.size(); i++)
		elm->addLeaf(sellerList[i]->getExcangeRate(), sellerList[i]);

	elm->inOrderSellerList(elm->root);
	for (unsigned int i = 0; i < sellerList.size(); i++)
		sortedSellerList.push_back(elm->getSortedSellerList()[i]);
}

void SortAndCalculate::sortBuyerList()
{
	tree *oak = new tree();

	for (unsigned int i = 0; i < buyerList.size(); i++)
		oak->addLeaf(buyerList[i]->getExcangeRate(), buyerList[i]);

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
