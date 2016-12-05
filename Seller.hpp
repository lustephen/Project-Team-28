#ifndef Seller_hpp
#define Seller_hpp
 
#include "Person.hpp"
/*
Creates a Seller object for the user or the Randomly generated Seller 
*/
class Seller: public Person
{
//Seller stores a minimum purchase and exchange rate
	double minPurchase;
	double exRate;

public:
//First constructor for user
	Seller(double minPurchase, double exRate);
//Second constructor for random seller
	Seller( double minPurchase, double exRate, int mm, int dd, int yr, std::string n, char gender, std::string ufid);
	//etter methods for private variables in Seller
	double getMinPurchase();
	double getExchangeRate();

};



#endif
