//
//  Account.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include "Account.hpp"

Account::Account(string name) {
    this -> name = name;
}

string Account::getName() {
    return this -> name;
}

string Account::getDOB() {
    return this -> dob;
}

int Account::getUFID() {
    return this -> ufid;
}

void Account::setName(string name) {
    this -> name = name;
}

void Account::setDOB(string dob) {
    this -> dob = dob;
}

void Account::setUFID(int ufid) {
    this -> ufid = ufid;
}
