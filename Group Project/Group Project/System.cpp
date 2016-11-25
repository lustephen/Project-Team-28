//
//  System.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include<fstream>
#include<iostream> //Remove from production
#include "System.hpp"

using namespace std;

System::System(bool debugMode) {
    this -> debugMode = debugMode;
}

bool System::login(string user, string hPassword) {
    ifstream myfile;
    myfile.open ("users.txt", ios::in);
    string line;
    if (myfile.is_open()) {
        while ( getline(myfile, line) ) {
            cout << line << '\n';
        }
    }
    else {
        cout << "Unable to open file";
        return false;
    }

    myfile.close();
    
    return true;
}

bool System::createUser(string user, string hPassword) {
    ofstream myfile;
    myfile.open ("users.txt", ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << endl << user << ":" << hPassword;
    }
    else {
        cout << "Unable to open file";
        return false;
    }
    
    myfile.close();
    
    return true;

}
