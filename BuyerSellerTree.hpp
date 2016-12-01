class tree 
{
private:

	struct node
	{
		int data;
		Buyer* whichBuyer;
		Seller* whichSeller;
		node* left;
		node* right;
	};

	node* root;
	node* makeLeaf(int data,Buyer *b);
	void addLeaf(int data, node* p,Buyer *b);

	node* makeLeaf(int data, Seller* s);
	void addLeaf(int data, node* p, Seller* s);
	std::vector<Seller*> sortedSellerList;
	std::vector<Buyer*> sortedBuyerList;
public:
	tree();
	void addLeaf(int data, Buyer* b);
	void addLeaf(int data, Seller* s);
	void inOrderBuyerList(node* n);
	void inOrderSellerList(node* n);
	std::vector<Seller*> getSortedSellerList();
	std::vector<Buyer*> getSortedBuyerList();

};
