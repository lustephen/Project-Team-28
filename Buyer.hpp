class Buyer
{
	const int locationCoordinateSize = 2;
	int location[2];
	double estPurchase;
	//bool isSimulated;
	double maxDist;
	double exRate;
	double distanceToSeller;
	std::vector<Seller*> sellerList;
	std::queue<Seller*> sortedSellerList;

	void setSellerList(std::vector<Seller*> sellList);
	void removeOutOfRangeValues();
	//void printBuyer();
	void sortSellerList();
	void test();
	Seller selectMatch();
	


	public:
	Buyer(int l[],double est, double max,double ex);
	//Buyer(Random Person)
	
	double getMaxDist();
	double getEstPurchase();
	double getExcangeRate();
	int* getLocation();
};
