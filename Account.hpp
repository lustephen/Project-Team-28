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

class Account {
private:
    std::string name;
    int month;
    int day;
    int year;
    int ufid;
public:
    Account(std::string);
    Account();
    std::string getName();
    void setName(std::string);
    std::string getDOB();
    void setDOB(int, int, int);
    int getUFID();
    void setUFID(int);
    // Insertion operator
  	friend std::ostream& operator<<(std::ostream& os, const Account& acc)
  	{
  		// write out individual members of s with an end of line between each one
  		os << acc.name << '\n';
  		os << acc.month << '\n';
  		os << acc.day << '\n';
  		os << acc.year << '\n';
  		os << acc.ufid << '\n';
  		return os;
  	}

  	// Extraction operator
  	friend std::istream& operator>>(std::istream& is, Account& acc)
  	{
  		// read in individual members of s
  		is >> acc.name >> acc.month >> acc.day >> acc.year >> acc.ufid;
  		return is;
  	}
};

#endif /* Account_hpp */
