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

using namespace std;

class Flexbucks {
public:
    Flexbucks(bool);
    bool login(string,string);
    bool createUser(string,string);
    bool removeUser(string);
    bool userExists(string);
private:
    Account loggedInAcc;
    bool loggedIn;
    bool debugMode;
};

#endif /* Flexbucks_hpp */
