//
//  Account.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <string>
#include <vector>
#include <cmath>
#include "Account.hpp"
#include "Settings.hpp"
#include "functions.hpp"

using namespace std;

Account::Account(string name, string dob, string ufid) {
  this -> name = name;
  this -> ufid = ufid;
  setDOB(dob);
}

Account::Account(string name) {
  this -> name = name;
}

Account::Account() {
}

string Account::getName() {
  return this -> name;
}

string Account::getDOB() {
  return to_string(this -> month) + "/" + to_string(this -> day) + "/" + to_string(this -> year);
}

string Account::getUFID() {
  return this -> ufid;
}

void Account::setName(string name) {
  this -> name = name;
}

bool Account::setDOB(string date) {
  vector<string> v;
  functions::split(date,'/',v);

  if(v.size() == 3){
    try {
      this -> month = stoi(v.at(0));
      this -> day = stoi(v.at(1));
      this -> year = stoi(v.at(2));
    }
    catch(int e) {
      return false;
    }
    return true;
  }
  return false;
}

void Account::setDOB(int mm, int dd, int yyyy) {
  this -> month = mm;
  this -> day = dd;
  this -> year = yyyy;
}

void Account::setUFID(string ufid) {
  this -> ufid = ufid;
}

Settings& Account::getSettings() {
  return this -> settings;
}

void Account::setSettings(Settings setting) {
  this -> settings = setting;
}

string Account::print() {
    return "Name: " + getName() + "\nDOB: " + getDOB() + "\nUFID: " + getUFID() + "\n";
}

string Account::titlePrint() {
  return "Name: " + getName() + "\tDOB: " + getDOB() + "\tUFID: " + getUFID() + "\tExchange Rate:" + to_string(settings.getExchangeRate()) + "\tMin Profit: " + to_string(settings.getMinProfit()) + "\n";
}
