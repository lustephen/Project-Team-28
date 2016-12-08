#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
//Transaction Object used to save History of Transactions for each account
class Transaction
{
	//Transaction saves the Name, exchange rate of the Seller/Buyer to the user and the purchase cost
    private:
        std::string name;
        std::string transactionType;
        double exchangeRate;
        double purchase;
	//Constructor and methods used to set the Name, Exchange Rate, and Purchase cost variables
    public:
        Transaction(std::string,double,double,std::string);
        Transaction();
        void setName(std::string);
        void setExchangeRate(double);
        void setPurchase(double);
        void setTransactionType(std::string);

        std::string getTransactionType();
        std::string getName();
        double getExchangeRate();
        double getPurchase();

		//Functions required to be able to save and retrieve Transaction objects from saved .txt file
    	  friend std::ostream& operator<<(std::ostream& os, const Transaction& transact)
      	{
      		// write out individual members of s with an end of line between each one
      		os << transact.name << '\n';
      		os << transact.exchangeRate << '\n';
      		os << transact.purchase << '\n';
          os << transact.transactionType << '\n';
      		return os;
      	}
        // Extraction operator
      	friend std::istream& operator>>(std::istream& is, Transaction& transact)
      	{
      		// read in individual members of s
      		is >> transact.name >> transact.exchangeRate >> transact.purchase >> transact.transactionType;
      		return is;
      	}
};

#endif
