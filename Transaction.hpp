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
        Transaction(std::string,double,double);
        Transaction();
        void setName(std::string);
        void setExchangeRate(double);
        void setPurchase(double);

        std::string getName();
        double getExchangeRate();
        double getPurchase();

    	  friend std::ostream& operator<<(std::ostream& os, const Transaction& transact)
      	{
      		// write out individual members of s with an end of line between each one
      		os << transact.name << '\n';
      		os << transact.exchangeRate << '\n';
      		os << transact.purchase << '\n';
      		return os;
      	}
        // Extraction operator
      	friend std::istream& operator>>(std::istream& is, Transaction& transact)
      	{
      		// read in individual members of s
      		is >> transact.name >> transact.exchangeRate >> transact.purchase;
      		return is;
      	}
};

#endif
