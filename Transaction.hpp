#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction
{
    private:
        std::string name;
        double exchangeRate;
        double purchase;
    
    public:
        void setName(std::string);
        void setExchangeRate(double);
        void setPurchase(double);
    
        std::string getName();
        double getExchangeRate();
        double getPurchase();
        
	friend std::ostream& operator<<(std::ostream& os, const Transaction& transact)
  	{
  		// write out individual members of s with an end of line between each one
  		os << transact.exchangeRate << '\n';
  		os << transact.purchase << '\n';
  		return os;
  	}
};

#endif