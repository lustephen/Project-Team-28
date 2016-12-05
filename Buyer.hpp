#ifndef Buyer_hpp
#define Buyer_hpp

#include "Person.hpp"
/*
Creates a Buyer Object either for the user or someone from the random population
*/
class Buyer: public Person
{
	//Buyer uses the variables estimated Purchase and exchange rate
	double estPurchase;
	double exRate;
	
public:
	//First constructor used for user
	Buyer(double est, double ex);
	//Second constructor used for random Buyer, Passes profile variables to person class
	Buyer(double est, double ex, int mm, int dd, int yr, std::string n, char gender, std::string ufid);


	//Getters to access private variables
	double getEstPurchase();
	double getExchangeRate();
	
};



#endif
