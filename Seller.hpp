class Seller: public Person
{
	//const int locationCoordinateSize = 2;
	//int location[2];
	double minPurhcase;
	//double maxDist;
	double exRate;
	//double distanceToBuyer;
	

public:
	Seller(double minPurchase, double exRate);
	Seller( double minPurchase, double exRate, int mm, int dd, int yr, std::string n, char gender, int ufid);
	double getMinPurchase();
	//double getMaxDist();
	double getExcangeRate();
	//int getLocationCoordinateSize();
	//int* getLocation();
	//void setDistanceToBuyer(double dist);
	//double getDistanceToBuyer();

};
