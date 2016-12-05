#include <vector>
#include "Tree.hpp"
#include "Seller.hpp"
#include "Buyer.hpp"

tree::tree()
{
	root = 0;
}


/*
Functions for Buyer
Sorts the tree with respect to the data sent
It stores the data and Buyer who contains that
data.
*/
tree::node* tree::makeLeaf(double data, Buyer *b)
{
	node* n = new node();
	n->whichBuyer = b;
	n->data = data;
	n->left = 0;
	n->right = 0;
	return n;
}

void tree::addLeaf(double data, Buyer *b)
{
	addLeaf(data, root, b);
}

void tree::addLeaf(double data, node* p, Buyer *b)
{
	if (root == 0)
	{
		root = makeLeaf(data, b);
	}

	/*
	If the data is equal it simply sticks it on the left node of the tree
	*/
	else if (data <= p->data)
	{
		if (p->left != 0)
		{
			addLeaf(data, p->left, b);
		}
		else
			p->left = makeLeaf(data, b);
	}

	else if (data > p->data)
	{
		if (p->right != 0)
		{
			addLeaf(data, p->right, b);
		}
		else
			p->right = makeLeaf(data, b);
	}
}

/*
Functions for Seller
Sorts the tree with respect to the data sent
It stores the data, and Seller who contains that
data.
*/

tree::node* tree::makeLeaf(double data, Seller *s)
{
	node* n = new node();
	n->whichSeller = s;
	n->data = data;
	n->left = 0;
	n->right = 0;
	return n;
}

void tree::addLeaf(double data, Seller* s)
{
	addLeaf(data, root, s);
}
	/*
	If the data is equal it simply sticks it on the left node of the tree
	*/
void tree::addLeaf(double data, node* p, Seller* s)
{
	if (root == 0)
	{
		root = makeLeaf(data, s);
	}

	else if (data <= p->data)
	{
		if (p->left != 0)
		{
			addLeaf(data, p->left, s);
		}
		else
			p->left = makeLeaf(data, s);
	}

	else if (data > p->data)
	{
		if (p->right != 0)
		{
			addLeaf(data, p->right, s);
		}
		else
			p->right = makeLeaf(data, s);
	}
}
/*
It stores the Sellers into the vector sortedSellerList
by lowest data to highest data(in this case data is the
exchange rate)
*/
void tree::inOrderSellerList(node* n)
{
	if (n == 0)
		return;
	inOrderSellerList(n->left);
	sortedSellerList.push_back(n->whichSeller);
	inOrderSellerList(n->right);


}
/*
It stores the Buyer into the vector sortedBuyerList
by lowest data to highest data(in this case data is the
exchange rate)
*/
void tree::inOrderBuyerList(node* n)
{
	if (n == 0)
		return;
	inOrderBuyerList(n->left);
	sortedBuyerList.push_back(n->whichBuyer);
	inOrderBuyerList(n->right);


}
/*
This returns the sortedList to the SortAndCalculate
class where further manipulations of the list can be
done if needed.
*/
std::vector<Seller*> tree::getSortedSellerList()
{
	return sortedSellerList;
}
/*
This returns the sortedList to the SortAndCalculate
class where further manipulations of the list can be
done if needed.
*/
std::vector<Buyer*> tree::getSortedBuyerList()
{
	return sortedBuyerList;
}
