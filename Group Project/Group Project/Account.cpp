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
    return to_string(this -> month) + "/" + to_string(this -> day) + "/" + to_string(this -> year);
}

int Account::getUFID() {
    return this -> ufid;
}

void Account::setName(string name) {
    this -> name = name;
}

void Account::setDOB(int mm, int dd, int yyyy) {
    this -> month = mm;
    this -> day = dd;
    this -> year = yyyy;
}

void Account::setUFID(int ufid) {
    this -> ufid = ufid;
}
