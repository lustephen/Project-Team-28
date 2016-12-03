#include "Person.hpp"

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

void createSellerPop(std::vector<Seller*> vec) {
	for (int h = 0; h < 20; h++) {
		int j = randMonth();
		char z = randGender();
		Seller *sell = new Seller(randMinPurchase(), randExRate(), j, randDay(j), randYear(), randName(z), z, randUfid());
		vec.push_back(sell);
	}
}
