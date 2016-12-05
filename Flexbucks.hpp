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
//Class Flexbucks used for Account functions and map functions
class Flexbucks {
public:
    Flexbucks(bool);
	//Function to check to see if login information is correct
    bool login(string,string);
	//Functions to create a new user Account
    bool createUser(string,string);
    bool createUser(string,string,Account);
	//Function to remove user
    bool removeUser(string);
	//Function to see if account exists
    bool userExists(string);
	//Prints out map of Reitz Union food places second floor
    string printMap();
	//Functions to load map neatly
    void setMap(vector< vector<Account> >);
    bool loadMap(string filename,char sep);
    bool loadMap(string filename);
    bool addToMap(Account,int,int);
	//Getter for saved Account information
    Account& getLoggedInUser();
	//Saves account information in .txt file
    bool save();
private:
    Account loggedInAcc;
    vector< vector<Account> > map;
    bool loggedIn;
    bool debugMode;
};

#endif /* Flexbucks_hpp */
