#ifndef SortAndCalculate_hpp
#define SortAndCalculate_hpp

#include<vector>
#include"Seller.hpp"
#include"Buyer.hpp"

class SortAndCalculate
{
	Buyer *buyer;
	Seller *seller;
	std::vector<Seller*> sellerList;
	std::vector<Buyer*> buyerList;
	std::vector<Seller*> sortedSellerList;
	std::vector<Buyer*> sortedBuyerList;
	void sortSellerList();
	void sortBuyerList();
	void removeOutOfRangeValuesForSellerList();
	void removeOutOfRangeValuesForBuyerList();
	//void calculateDistanceToBuyer();
	//void calculateDistanceToSeller();

public:
	SortAndCalculate(Buyer *b, std::vector<Seller*> s);
	SortAndCalculate(Seller *s, std::vector<Buyer*> b);
	bool avaliableSellerCheck();
	bool avaliableBuyerCheck();
	Buyer* getSelectedBuyer();
	Seller* getSelectedSeller();

	void buyerFlow();
	void sellerFlow();

};

#endif
