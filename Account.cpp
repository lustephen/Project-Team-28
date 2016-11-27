//
//  Account.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <cmath>
#include "Account.hpp"

Account::Account(string name, int ufid, int mm, int dd, int yyyy, int loc[2], bool tradeStatus, double exchangeRate, double maxDist, double price) {
    this -> name = name;
    this -> ufid = ufid;
    this -> month = mm;
    this -> day = dd;
    this -> year = yyyy;
    this -> location[0] = loc[0];
    this -> location[1] = loc[1];
    this -> isseller = tradeStatus;
    this -> exchangeRate = exchangeRate;
    this -> maxDistance = maxDist;
    this -> price = price;
}

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

int* Account::getLocation() {
    return this -> location;
}

void Account::setLocation(int lat, int lon) {
    this -> location[0] = lat;
    this -> location[1] = lon;
}

bool Account::getTradeStatus() {
    return this -> isseller;
}

void Account::setTradeStatus(bool status) {
    this -> isseller = status;
}

double Account::getExchangeRate() {
    return this -> exchangeRate;
}

void Account::setExchangeRate(double rate) {
    this -> exchangeRate = rate;
}

double Account::getMaxDistance() {
    return this -> maxDistance;
}

void Account::setMaxDistance(double maxDist) {
    this -> maxDistance = maxDist;
}

double Account::getPrice() {
    return this -> price;
}

void Account::setPrice(double price) {
    this -> price = price;
}

double Account::distanceTo(int dest[2]) {
    return sqrt(pow(dest[0] - this -> location[0], 2) + pow(dest[1] - this -> location[1], 2));
}
