#ifndef Random_hpp
#define Random_hpp

#include <iostream>
#include <string>
#include <cmath>
#include "Buyer.hpp"
#include "Seller.hpp"

using namespace std;
//Random class used to generate profiles for the random population
class Random{
  public:
  static int randMonth();
  static int randDay(int);
  static int randYear();
  static char randGender();
  static double randExRate();
  static double randEstPurchase();
  static double randMinPurchase();
  static string randName(char);
  static string randUfid();
  //Vectors filled with the random populations of buyers/sellers
  static vector<Buyer*> createBuyerPop();
  static vector<Seller*> createSellerPop();
};

  #endif
