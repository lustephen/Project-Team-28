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
//Account constructor used to save users information
Account::Account(string name, string dob, char gender, string ufid) {
  Person temp(name,dob,gender,ufid);
  this -> person = temp;
}
//Account overloaded constructor used to save name of person
Account::Account(string name) {
  Person temp(name);
  this -> person = temp;
}
//Default Account constructor
Account::Account() {

}
//Getter and Setter for Settings, Settings may not be used
Settings& Account::getSettings() {
  return this -> settings;
}

void Account::setSettings(Settings setting) {
  this -> settings = setting;
}
//Getter and Setter for Person objects
Person& Account::getPerson() {
  return this -> person;
}

void Account::setPerson(Person p) {
  this -> person = p;
}
//Getter and Setters for Transaction history
void Account::addTransaction (Transaction t) {
  this -> transactions.push_back(t);
}

vector<Transaction> Account::getTransactionHistory() {
  return this -> transactions;
}
//Function that returns persons Name, Date of Birth, and UFID
string Account::print() {
    return "Name: " + person.getName() + "\nDOB: " + person.getDOB() + "\nUFID: " + person.getID() + "\n";
}
//Function that returns persons Name, Date of Birth, and UFID neatly using \t
string Account::titlePrint() {
  string separator = "\t";
  return "Name: " + person.getName() + separator + "DOB: " + person.getDOB() + separator + "UFID: " + person.getID() + separator + "G: " + person.getGender() + separator + '\n';
}
