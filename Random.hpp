#ifndef Random_hpp
#define Random_hpp

#include <iostream>
#include <string>
#include <math>

using namespace std;

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
  static int randUfid();
  static void createBuyerPop(vector<Buyer*>);
  static void createSellerPop(vector<Seller*>);
  }
  
  #endif
