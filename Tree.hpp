#ifndef Tree_hpp
#define Tree_hpp

#include "Buyer.hpp"
#include "Seller.hpp"
#include <vector>
//Tree used to sort Seller and Buyer Vectors using nodes (Binary Tree)
class tree
{
private:

	struct node
	{
		double data;
		Buyer* whichBuyer;
		Seller* whichSeller;
		node* left;
		node* right;
	};


	node* makeLeaf(double data, Buyer *b);
	void addLeaf(double data, node* p, Buyer *b);

	node* makeLeaf(double data, Seller* s);
	void addLeaf(double data, node* p, Seller* s);
	std::vector <Seller*> sortedSellerList;
	std::vector<Buyer*> sortedBuyerList;
public:
	node* root;
	tree();
	void addLeaf(double data, Buyer* b);
	void addLeaf(double data, Seller* s);
	void inOrderBuyerList(node* n);
	void inOrderSellerList(node* n);
	std::vector<Seller*> getSortedSellerList();
	std::vector<Buyer*> getSortedBuyerList();
};

#endif
