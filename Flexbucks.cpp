//
//  Flexbucks.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Flexbucks.hpp"
#include "Account.hpp"
#include "functions.hpp"

using namespace std;

string USERS_FILE = "res/users.txt";

Flexbucks::Flexbucks(bool debugMode) {
    this -> debugMode = debugMode;
}
//Function to login into Account and the Program in general
bool Flexbucks::login(string user, string hPassword) {
    vector<string> lines;

    ifstream ifs("accounts/" + user + ".fba");

    Account acc (user);

    // read the object back in
    ifs >> acc;
    this -> loggedInAcc = acc;
	//Reads .txt file to see if Account username and password exists
    functions::split(functions::readFile(USERS_FILE), '\n', lines);
	//Returns true if account exists or false if account does not exist
    for(string i: lines) {
        vector<string> temp;
        functions::split(i,':',temp);
        if(temp.at(0) == user && temp.at(1) == hPassword) {
            return true;
        }
    }

    return false;
}
//If Account exists return true if Account does not exist returns false
//Function reads .txt file to see if user account was saved
bool Flexbucks::userExists(string user) {
    fstream myfile;
    string file_str;
    string line;
    bool found_user = false;
    myfile.open (USERS_FILE, ios::in);
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
//Function to save all information into currently logged in account
bool Flexbucks::save() {
    Account acc = this -> loggedInAcc;

    cout << "SAVE NAME:" << this->loggedInAcc << endl;

	  ofstream ofs("accounts/" + acc.getPerson().getName() + ".fba");

    cout << "NAME=" << acc.getPerson().getName() << endl;

    if(ofs << acc) {
      ofs.close();
      return true;
    }

    ofs.close();

    return false;
}
//Function to create a new Account for the user
bool Flexbucks::createUser(string user, string hPassword, Account acc = Account()) {
    if(userExists(user)) {
        return false;
    }

    this -> loggedInAcc = acc;

	  ofstream ofs("accounts/" + user + ".fba");

    ofs << acc;

    ofs.close();
	//Saves users account password and username into a .txt file
    fstream myfile;
    myfile.open (USERS_FILE, ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << user << ":" << hPassword << '\n';
    }
    else {
        return false;
    }

    myfile.close();

    return true;
}
//Helper Methods to create an Account for user
bool Flexbucks::createUser(string user, string hPassword) {
  Account acc (user);

  return createUser(user,hPassword,acc);
}
//Function that removes a saved account from the .txt file
bool Flexbucks::removeUser(string user) {
    fstream myfile;
    string file_str;
    string line;
    bool found_user = false;

    remove(("accounts/" + user + ".fba").c_str());

    myfile.open (USERS_FILE, ios::in);
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

    myfile.open (USERS_FILE, ios::out);
    myfile << file_str;
    myfile.close();

    return found_user;
}
//Gets Accounted information
Account& Flexbucks::getLoggedInUser() {
  return this -> loggedInAcc;

//Returns string (to be printed out) which is a layout of the Reitz Union 
string Flexbucks::printMap() {
  string res = "";
  for(int i=0; i < this -> map.size(); i++) {
    for(int j=0; j < this -> map[i].size(); j++) {
      res += (map[i][j].getPerson().getName() + "    ");
    }
    res += "\n";
  }
  return res;
}
//Function to set the Reitz Union Map
void Flexbucks::setMap(vector< vector<Account> > map) {
  this -> map = map;
}
//Loads map
bool Flexbucks::loadMap(string filename, char sep) {
  fstream myfile;
  string line;
  vector< vector<Account> > temp;

  myfile.open (filename, ios::in);
  if (myfile.is_open()) {
      while ( getline(myfile, line) ) {
        if(line != "" && line[0] != '#') {
          vector<Account> row;
          vector<string> sp;
          functions::split(line,sep,sp);
          for(int i=0; i<sp.size();i++) {
            Account tmpAcc (sp.at(i));
            row.push_back(tmpAcc);
          }
          temp.push_back(row);
        }
      }
      setMap(temp);

      return true;
  }
  return false;
}

bool Flexbucks::loadMap(string filename) {
  return loadMap(filename,' ');
}
//Adds Users location to map, May not be used
bool Flexbucks::addToMap(Account user, int x, int y) {
  if(x > 0 && x < map.size() && y > 0 && y < map[x].size()) {
    this -> map[x][y] = user;
    return true;
  }
  return false;
}
