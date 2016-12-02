class Seller: public Person
{
	const int locationCoordinateSize = 2;
	int location[2];
	double minPurhcase;
	double maxDist;
	double exRate;
	double distanceToBuyer;
	

public:
	Seller(int location[], double minPurchase, double maxDist, double exRate);
	double getMinPurchase();
	double getMaxDist();
	double getExcangeRate();
	
};
