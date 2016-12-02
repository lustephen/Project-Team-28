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
	vector <Seller*> sortedSellerList;
	vector<Buyer*> sortedBuyerList;
public:
	node* root;
	tree();
	//node* getRoot();
	void addLeaf(double data, Buyer* b);
	void addLeaf(double data, Seller* s);
	void inOrderBuyerList(node* n);
	void inOrderSellerList(node* n);
	vector<Seller*> getSortedSellerList();
	vector<Buyer*> getSortedBuyerList();

};
