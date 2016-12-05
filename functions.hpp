//
//  functions.hpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/25/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

#endif /* functions_hpp */
//Class functions used to read .txt file where Account information will be stored
class functions {
public:
    static string readFile(string);
    static void split(const string &,char,vector<string> &);
    static bool is_number(const string &);
};
