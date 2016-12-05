#ifndef Buyer_hpp
#define Buyer_hpp

#include "Person.hpp"
/*
Creates a buyer who has the fields of estimated purchase and exchange rate
*/
class Buyer: public Person
{
	double estPurchase;
	double exRate;
	
public:
	Buyer(double est, double ex);
	Buyer(double est, double ex, int mm, int dd, int yr, std::string n, char gender, std::string ufid);


	
	double getEstPurchase();
	double getExchangeRate();
	
};



#endif
