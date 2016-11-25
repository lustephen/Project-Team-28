//
//  System.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <iostream> //Remove from prod
#include <fstream>
#include <sstream>
#include <vector>
#include "System.hpp"

using namespace std;

System::System(bool debugMode) {
    this -> debugMode = debugMode;
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

string System::readFile(string filename) {
    ifstream myfile;
    myfile.open ("users.txt", ios::in);
    string file_str;
    string line;
    if (myfile.is_open()) {
        while ( getline(myfile, line) ) {
            file_str += line;
        }
    }
    else {
        return NULL;
    }
    
    myfile.close();
    
    return file_str;
}

bool System::login(string user, string hPassword) {
    vector<string> lines;
    vector<string> temp;
    split(readFile("users.txt"), '\n', lines);
    
    for(vector<string>::iterator i = lines.begin(); i != lines.end(); ++i) {
        split(*i,':',temp);
        if(temp.front() == user && temp.back() == hPassword) {
            return true;
        }
    }
    
    return false;
}

bool System::createUser(string user, string hPassword) {
    fstream myfile;
    myfile.open ("users.txt", ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << user << ":" << hPassword << '\n';
    }
    else {
        return false;
    }
    
    myfile.close();
    
    return true;

}

bool System::removeUser(string user) {
    fstream myfile;
    string file_str;
    string line;
    bool found_user = false;
    
    myfile.open ("users.txt", ios::in);
    if (myfile.is_open()) {
        while ( getline(myfile, line) ) {
            vector<string> temp;
            split(line,':',temp);
            if(temp.front() != user) {
                file_str += line;
            }
            else {
                found_user = true;
            }
        }
    }
    else {
        return false;
    }
    
    myfile.close();
    
    myfile.open ("users.txt", ios::out);
    myfile << file_str;
    myfile.close();
    
    return found_user;
}
