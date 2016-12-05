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
#include "Settings.hpp"
#include "Person.hpp"
#include "Transaction.hpp"

class Account {
private:
    std::vector<Transaction> transactions;
    Settings settings;
    Person person;
public:
    Account(std::string,std::string,char,std::string);
    Account(std::string);
    Account();
    Person& getPerson();
    void setPerson(Person);
    Settings& getSettings();
    void setSettings(Settings);
    std::string print();
    std::string titlePrint();
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
