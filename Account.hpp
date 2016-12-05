//
//  Account.hpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Settings.hpp"
#include "Person.hpp"
#include "Transaction.hpp"
//Account classed used to keep track of users login info, users profile, and users transaction history
class Account {
private:
	//Holds Transaction list (vector) and Person info, holds settings as well but settings may not be used
    std::vector<Transaction> transactions;
    Settings settings;
    Person person;
public:
	//Overloaded constructors used to save profile information
    Account(std::string,std::string,char,std::string);
    Account(std::string);
	//Default Account Constructor
    Account();
	//Functions to get and set Person Profile information
    Person& getPerson();
    void setPerson(Person);
	//Functions to get and set Settings information, Settings may not be used
    Settings& getSettings();
    void setSettings(Settings);
	//Returns person profile information
    std::string print();
    std::string titlePrint();
	//Function used to add transaction to account
    void addTransaction(Transaction t);
    std::vector<Transaction> getTransactionHistory();
    // Insertion operator
  	friend std::ostream& operator<<(std::ostream& os, const Account& acc)
  	{
  		// write out individual members of s with an end of line between each one
  		os << acc.person << acc.settings;
      for(Transaction t: acc.transactions) {
        os << t;
      }
  		return os;
  	}

  	// Extraction operator
  	friend std::istream& operator>>(std::istream& is, Account& acc)
  	{
  		// read in individual members of s
  		is >> acc.person >> acc.settings;

      std::copy(std::istream_iterator<Transaction>(is), std::istream_iterator<Transaction>(), std::back_inserter(acc.transactions));
      
  		return is;
  	}
};

#endif /* Account_hpp */
