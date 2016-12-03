#include<vector>
#include"Seller.hpp"
#include"Buyer.hpp"
class SortAndCalculate
{
	Buyer *buyer;
	Seller *seller;
	vector<Seller*> sellerList;
	vector<Buyer*> buyerList;
	vector<Seller*> sortedSellerList;
	vector<Buyer*> sortedBuyerList;
	void sortSellerList();
	void sortBuyerList();
	void removeOutOfRangeValues(Buyer *b, vector<Seller*> s);
	void removeOutOfRangeValues(Seller *s, vector<Buyer*> b);
	//void calculateDistanceToBuyer();
	//void calculateDistanceToSeller();

public:
	SortAndCalculate(Buyer *b, vector<Seller*> s);
	SortAndCalculate(Seller *s, vector<Buyer*> b);
	Buyer* getSelectedBuyer();
	Seller* getSelectedSeller();

	void buyerFlow();
	void sellerFlow();
	
};
