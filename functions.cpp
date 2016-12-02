//
//  functions.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/25/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//s

#include <fstream>
#include <sstream>
#include <vector>
#include "functions.hpp"

void functions::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

bool functions::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string functions::readFile(string filename) {
    ifstream myfile;
    myfile.open (filename, ios::in);
    string file_str;
    string line;
    if (myfile.is_open()) {
        while ( getline(myfile, line) ) {
            file_str += (line + "\n");
        }
    }
    else {
        return NULL;
    }

    myfile.close();

    return file_str;
}
