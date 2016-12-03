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
#include "Settings.hpp"
#include "Person.hpp"

class Account {
private:
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
    // Insertion operator
  	friend std::ostream& operator<<(std::ostream& os, const Account& acc)
  	{
  		// write out individual members of s with an end of line between each one
  		os << acc.person << acc.settings;
  		return os;
  	}

  	// Extraction operator
  	friend std::istream& operator>>(std::istream& is, Account& acc)
  	{
  		// read in individual members of s
  		is >> acc.person >> acc.settings;
  		return is;
  	}
};

#endif /* Account_hpp */
