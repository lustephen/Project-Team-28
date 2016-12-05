#ifndef Seller_hpp
#define Seller_hpp
 
#include "Person.hpp"
/*
Creates a seller with the fields minimum purchase and exchange rate
*/
class Seller: public Person
{
	
	double minPurchase;
	double exRate;

public:
	Seller(double minPurchase, double exRate);
	Seller( double minPurchase, double exRate, int mm, int dd, int yr, std::string n, char gender, std::string ufid);
	double getMinPurchase();
	double getExchangeRate();

};



#endif
