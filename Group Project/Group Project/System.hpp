//
//  System.hpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#ifndef System_hpp
#define System_hpp

#include <stdio.h>
#include <string>

using namespace std;

class System {
public:
    System(bool);
    bool login(string,string);
    bool createUser(string,string);
    bool removeUser(string);
private:
    bool loggedIn;
    bool debugMode;
    string readFile(string);
};

#endif /* System_hpp */
