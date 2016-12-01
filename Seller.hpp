class Seller
{
	const int locationCoordinateSize = 2;
	int location[2];
	double minPurhcase;
	//bool isSimulated;
	double maxDist;
	double exRate;
	double distanceToBuyer;
	std::vector<Buyer*> buyerList;
	std::queue<Buyer*> sortedBuyerList;
	void setBuyerList(std::vector<Buyer*> buyList);
	void sortBuyerList();
	//not implemented yet
	//void removeOutOfRangeValues();
	//Buyer selectMatch();

	public:
	//int* getLocation();
	Seller(int location[], double minPurchase, double maxDist, double exRate);
	//Seller(Random Person)
	double calculateDistanceToBuyer(int buyerLocation[]);
	//void printSeller();
	double getMinPurchase();
	double getMaxDist();
	double getExcangeRate();
	double Seller::getDistanceToBuyer();
};
