//
//  Flexbucks.hpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#ifndef Flexbucks_hpp
#define Flexbucks_hpp

#include "Account.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Flexbucks {
public:
    Flexbucks(bool);
    bool login(string,string);
    bool createUser(string,string);
    bool createUser(string,string,Account);
    bool removeUser(string);
    bool userExists(string);
    string printMap();
    void setMap(vector< vector<Account> >);
    bool addToMap(Account,int,int);
    Account getLoggedInUser();
private:
    Account loggedInAcc;
    vector< vector<Account> > map;
    bool loggedIn;
    bool debugMode;
};

#endif /* Flexbucks_hpp */
