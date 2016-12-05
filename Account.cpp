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
#include "Person.hpp"

using namespace std;

Account::Account(string name, string dob, char gender, string ufid) {
  Person temp(name,dob,gender,ufid);
  this -> person = temp;
}

Account::Account(string name) {
  Person temp(name);
  this -> person = temp;
}

Account::Account() {

}

Settings& Account::getSettings() {
  return this -> settings;
}

void Account::setSettings(Settings setting) {
  this -> settings = setting;
}

Person& Account::getPerson() {
  return this -> person;
}

void Account::setPerson(Person p) {
  this -> person = p;
}

void Account::addTransaction (Transaction t) {
  this -> transactions.push_back(t);
}

vector<Transaction> Account::getTransactionHistory() {
  return this -> transactions;
}

string Account::print() {
    return "Name: " + person.getName() + "\nDOB: " + person.getDOB() + "\nUFID: " + person.getID() + "\n";
}

string Account::titlePrint() {
  string separator = ", ";
  return "Name: " + person.getName() + separator + "DOB: " + person.getDOB() + separator + "UFID: " + person.getID() + separator + "G: " + person.getGender() + separator + "Exchange Rate:" + to_string(settings.getExchangeRate()) + separator + "Min Profit: " + to_string(settings.getMinProfit()) + "\n";
}
