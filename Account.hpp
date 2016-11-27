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

using namespace std;

const bool SELLER = true;
const bool BUYER = false;

class Account {
private:
    string name;
    string gender;
    string description;
    int month;
    int day;
    int year;
    int ufid;
    int location[2];
    bool isseller;
    double exchangeRate;
    double maxDistance;
    double price;
public:
    Account(string, int, int, int, int, int[2], bool, double, double, double);
    Account(string);
    string getName();
    void setName(string);
    string getDOB();
    void setDOB(int, int, int);
    int getUFID();
    void setUFID(int);
    int* getLocation();
    void setLocation(int, int);
    bool getTradeStatus();
    void setTradeStatus(bool);
    double getExchangeRate();
    void setExchangeRate(double);
    double getMaxDistance();
    void setMaxDistance(double);
    double getPrice();
    void setPrice(double);
    double distanceTo(int[2]);
    
    
};

#endif /* Account_hpp */
