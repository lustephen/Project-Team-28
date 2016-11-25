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

class Account {
private:
    string name;
    string dob;
    string gender;
    int ufid;
public:
    Account(string);
    string getName();
    void setName(string);
    string getDOB();
    void setDOB(string);
    int getUFID();
    void setUFID(int);
};

#endif /* Account_hpp */
