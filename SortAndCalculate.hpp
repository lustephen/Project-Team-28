#ifndef SortAndCalculate_hpp
#define SortAndCalculate_hpp

#include<vector>
#include"Seller.hpp"
#include"Buyer.hpp"
//SortAndCalculate class used to find the optimal Seller/Buyer for the user 
class SortAndCalculate
{
	//Private vectors used to store population of sellers and population of buyers
	//Additional vectors used to store the sorted list along with functions to sort and organize the list
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
	

public:
	//First constructor if user is a Buyer and needs to find a Seller
	SortAndCalculate(Buyer *b, std::vector<Seller*> s);
	//Second overloaded constructor if user is a Seller and needs to find a Buyer
	SortAndCalculate(Seller *s, std::vector<Buyer*> b);
	//avaliable Seller/Buyer check used to see if passed vector contains buyers/sellers that match requirements of the user
	bool avaliableSellerCheck();
	bool avaliableBuyerCheck();
	//Returns the selected Buyer or Seller from the random population
	Buyer* getSelectedBuyer();
	Seller* getSelectedSeller();

	//General method that uses other methods in the SortAndCalculate class to make main implementation simpler
	void buyerFlow();
	void sellerFlow();

};

#endif
