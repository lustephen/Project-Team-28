//
//  System.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <fstream>
#include <vector>
#include "System.hpp"
#include "functions.hpp"

using namespace std;

System::System(bool debugMode) {
    this -> debugMode = debugMode;
}

bool System::login(string user, string hPassword) {
    vector<string> lines;
    vector<string> temp;
    functions::split(functions::readFile("users.txt"), '\n', lines);
    for(vector<string>::iterator i = lines.begin(); i != lines.end(); ++i) {
        functions::split(*i,':',temp);
        if(temp.at(0) == user && temp.at(1) == hPassword) {
            return true;
        }
    }
    
    return false;
}

bool System::userExists(string user) {
    fstream myfile;
    string file_str;
    string line;
    bool found_user = false;
    
    myfile.open ("users.txt", ios::in);
    if (myfile.is_open()) {
        while ( getline(myfile, line) ) {
            vector<string> temp;
            functions::split(line,':',temp);
            if(temp.size() > 0 && temp.at(0) == user) {
                found_user = true;
            }
        }
    }
    else {
        return false;
    }
    
    myfile.close();
    
    return found_user;

}

bool System::createUser(string user, string hPassword) {
    if(userExists(user)) {
        return false;
    }
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
            functions::split(line,':',temp);
            if(temp.size() > 0 && temp.at(0) != user) {
                file_str += (line + "\n");
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
