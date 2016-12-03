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

bool Flexbucks::login(string user, string hPassword) {
    vector<string> lines;

    ifstream ifs("accounts/" +user + ".fba");

    Account acc (user);

    // read the object back in
    if(ifs >> acc)
    {
        this -> loggedInAcc = acc;
    }

    functions::split(functions::readFile(USERS_FILE), '\n', lines);

    for(string i: lines) {
        vector<string> temp;
        functions::split(i,':',temp);
        if(temp.at(0) == user && temp.at(1) == hPassword) {
            return true;
        }
    }

    return false;
}

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

bool Flexbucks::save() {
    Account acc = this -> loggedInAcc;

	  ofstream ofs("accounts/" + acc.getPerson().getName() + ".fba");

    if(ofs << acc) {
      ofs.close();
      return true;
    }

    ofs.close();

    return false;
}

bool Flexbucks::createUser(string user, string hPassword, Account acc = Account()) {
    if(userExists(user)) {
        return false;
    }

    this -> loggedInAcc = acc;

	  ofstream ofs("accounts/" + user + ".fba");

    ofs << acc;

    ofs.close();

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

bool Flexbucks::createUser(string user, string hPassword) {
  Account acc (user);

  return createUser(user,hPassword,acc);
}

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

Account& Flexbucks::getLoggedInUser() {
  return this -> loggedInAcc;
}

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

void Flexbucks::setMap(vector< vector<Account> > map) {
  this -> map = map;
}

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

bool Flexbucks::addToMap(Account user, int x, int y) {
  if(x > 0 && x < map.size() && y > 0 && y < map[x].size()) {
    this -> map[x][y] = user;
    return true;
  }
  return false;
}
