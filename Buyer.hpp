class Buyer//: public Person
{
	const int locationCoordinateSize = 2;
	int location[2];
	double estPurchase;
	double maxDist;
	double exRate;
	double distanceToSeller;
	
public:
	Buyer(int l[], double est, double max, double ex);
	

	double getMaxDist();
	double getEstPurchase();
	double getExcangeRate();
	int* getLocation();
	int getLocationCoordinateSize();
	void setDistanceToSeller(double dist);
	double getDistanceToSeller();
};
