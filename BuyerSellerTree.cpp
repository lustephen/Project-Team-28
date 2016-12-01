#include<vector>
#include"Seller.hpp"
#include"Buyer.hpp"
#include"BuyerSellerTree.hpp"

tree::tree()
{
	root = 0;
}
//Buyer

tree::node* tree::makeLeaf(int data,Buyer *b)
{
	node* n = new node();
	n->whichBuyer = b;
	n->data = data;
	n->left = 0;
	n->right = 0;
	return n;
}

void tree::addLeaf(int data,Buyer *b)
{
	addLeaf(data, root,b);
}

void tree::addLeaf(int data, node* p,Buyer *b)
{
	if (root == 0)
	{
		root = makeLeaf(data, b);
	}

	//This is what I planned to do. Currently I just stick it on the left tree

	/*Only look at cases that are less than or greater than. If the values are equivalent than
	look at which has a smaller distance between them or lower price.
	*/
	else if (data <= p->data)
	{
		if (p->left != 0)
		{
			addLeaf(data, p->left,b);
		}
		else
			p->left = makeLeaf(data,b);
	}

	else if (data > p->data)
	{
		if (p->right != 0)
		{
			addLeaf(data, p->right,b);
		}
		else
			p->right = makeLeaf(data,b);
	}
}


//Seller

tree::node* tree::makeLeaf(int data, Seller *s)
{
	node* n = new node();
	n->whichSeller = s;
	n->data = data;
	n->left = 0;
	n->right = 0;
	return n;
}

void tree::addLeaf(int data, Seller* s)
{
	addLeaf(data, root, s);
}

void tree::addLeaf(int data, node* p, Seller* s)
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

void tree::inOrderSellerList(node* n)
{	
	if (n == 0)
		return;
	inOrderSellerList(n->left);
	sortedSellerList.push_back(n->whichSeller);
	inOrderSellerList(n->right);


}

void tree::inOrderBuyerList(node* n)
{
	if (n == 0)
		return;
	inOrderBuyerList(n->left);
	sortedBuyerList.push_back(n->whichBuyer);
	inOrderBuyerList(n->right);


}

std::vector<Seller*> tree::getSortedSellerList()
{
	return sortedSellerList;
}

std::vector<Buyer*> tree::getSortedBuyerList()
{
	return sortedBuyerList;
}

void Seller::sortBuyerList()
{
	tree oak;

	for (int i = 0; i < buyerList.size; i++)
		oak.addLeaf(buyerList[i]->getMaxDist, buyerList[i]);

	for (int i = 0; i < oak.getSortedBuyerList.size; i++)
		sortedBuyerList.push(oak.getSortedBuyerList[i]);
}
