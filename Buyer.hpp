class Buyer: public Person
{
	const int locationCoordinateSize = 2;
	//int location[2];
	double estPurchase;
	//double maxDist;
	double exRate;
	//double distanceToSeller;
	
public:
	Buyer(double est, double ex);
	Buyer(double est, double ex, int mm, int dd, int yr, std::string n, char gender, int ufid);
	

	//double getMaxDist();
	double getEstPurchase();
	double getExcangeRate();
	//int* getLocation();
	//int getLocationCoordinateSize();
	//void setDistanceToSeller(double dist);
	//double getDistanceToSeller();
};
