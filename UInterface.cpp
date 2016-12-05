//
//  UInterface.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/25/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <ctime>
#include "Flexbucks.hpp"
#include "Buyer.hpp"
#include "Seller.hpp"
#include "Random.hpp"
#include "SortAndCalculate.hpp"
#include "functions.hpp"
#include "sha/hl_sha256wrapper.h"

using namespace std;

Flexbucks sys (true);

int loginMenuOption() {
  string rawinp;
  int inp = 0;
  cout << "Welcome to Flex Bucks simulator." << endl;
  cout << "  1) Login" << endl;
  cout << "  2) Create User" << endl;

  while(inp <= 0 || inp > 2) {
    cout << "Please pick an option: ";
    std::cin.clear();
    cin >> rawinp;
    stringstream(rawinp) >> inp;
    if(inp < 1 || inp > 2) {
      cout << "Invalid input, please try again." << endl;
    }
  }
  return inp;
}

bool login() {
  string user;
  string pass;
  cout << "Please enter username: ";
  cin >> user;
  cout << "Please enter password: ";
  cin >> pass;
  hashwrapper *sha = new sha256wrapper();
  return sys.login(user,sha->getHashFromString(pass));
}

bool createUser() {
  string user;
  string pass;
  string pass2;
  cout << "Please enter username: ";
  cin >> user;
  if(sys.userExists(user)) {
    cout << "User already exists!" << endl << endl;
    return false;
  }
  cout << "Please enter password: ";
  cin >> pass;
  hashwrapper *sha = new sha256wrapper();

  //Account creation
  int slashes = 0;
  bool isNumbers = false;
  string dob = "";
  string ufid;
  char gender;
  cout << endl << "Account Creation" << endl << endl;
  while(slashes != 3 || !isNumbers) {
    cout << "Please enter your date of birth (mm/dd/yyyy): ";
    cin >> dob;
    vector<string> dob_checker;
    functions::split(dob,'/',dob_checker);
    if((slashes = dob_checker.size()) == 3) {
      isNumbers = functions::is_number(dob_checker.at(0).c_str());
      isNumbers &= functions::is_number(dob_checker.at(1).c_str());
      isNumbers &= functions::is_number(dob_checker.at(2).c_str());
    }
    if(slashes != 3 || !isNumbers) {
      cout << "Invalid date format. Try again." << endl;
    }
  }
  cout << "Plese enter your UF ID: ";
  cin >> ufid;
  cout << "Please enter you gender(m/f): ";
  cin >> gender;

  Account acc (user, dob, gender, ufid);

  return sys.createUser(user,sha->getHashFromString(pass), acc);
}

void clear() {
  #ifdef OS_WINDOWS
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
  #else
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
  #endif
}

void printGreetingScreen() {
  cout << functions::readFile("res/welcomescreen.txt");
}

void printMainMenu() {
  cout << "  1) Buy" << endl;
  cout << "  2) Sell" << endl;
  cout << "  3) View Transaction History" << endl;
  cout << "  4) Exit" << endl;
}

void BuyerOptions() {
  //IF THE USER IF A BUYER CASE
	double varEstPurchase;
	double varExchangeRate;
	int count = 0;

	while (count == 0) {
		std::cout << "You have chosen to be a Buyer, Please fill out below" << std::endl << "Enter your Estimated purchase cost $(1.00 - 40.00): ";
		std::cin >> varEstPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varEstPurchase < 1.00 || varEstPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Estimated Purchase Cost $(1.00-40.00): ";
			std::cin >> varEstPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}


		std::cout << std::endl << "Enter your Exchange rate (0.55-.99) ";
		std::cin >> varExchangeRate;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varExchangeRate < .55 || varExchangeRate > .99) {
			std::cout << "Invalid input, Please Enter Your Exchange Rate: ";
			std::cin >> varExchangeRate;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		int staller = 0;
		std::string decision;
		std::string decision2;
		while (staller == 0) {
			std::cout << "You have chosen to search for $" << varEstPurchase << " at an exchange rate of " << varExchangeRate << std::endl;
			std::cout << "Do you accept (Y/N)? ";
			std::cin >> decision;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			if (decision == "Y" || decision == "y") {
				staller = 1;
				count = 1;
			}
			else if (decision == "N" || decision == "n") {
				int holder = 0;
				while (holder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N goes back to main menu) ";
					std::cin >> decision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					if (decision2 == "Y" || decision2 == "y") {
						holder = 1;
						staller = 1;
						count = 0;
					}
					else if (decision2 == "N" || decision2 == "n") {
						holder = 1;
						staller = 1;
						count = 1;
						//some other var = 1 so that it goes back to main menu
					}
					else {	//error holder loop
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error staller while loop
				std::cout << "Invalid choice, Please try again." << std::endl;

			}

		}	//end of staller while loop

	}	//end of count while loop


	std::cout << "Processing..." << std::endl;

	//Pass to buyer class to find best person (lowest exchange rate, meets sellers min purchase requirement)


	Buyer *user = new Buyer(varEstPurchase, varExchangeRate);
	std::vector<Seller*> sellerlist;
	sellerlist = Random::createSellerPop();
	SortAndCalculate *sellercompute = new SortAndCalculate(user, sellerlist);


	if(sellercompute->avaliableSellerCheck())
	{
		bool tr = false;
		char Y_N;
		sellercompute->buyerFlow();

		Seller *selectedSeller=sellercompute->getSelectedSeller();
		std::cout<<"Seller: "<<selectedSeller->getName()<<" has exchange rate: "<<selectedSeller->getExchangeRate()<<std::endl;
		std::cout<<"Would you like to trade with "<<selectedSeller->getName()<<" Y/N"<<std::endl;
		cin >> Y_N;


		do
		{
			if(Y_N == 'Y' || Y_N == 'y')
			{
				//pass users estpurchase sellers exchange rate and sellers name
				cout << "Transaction successfully completed!" << endl;
        Transaction t (selectedSeller->getName(), selectedSeller->getExchangeRate(), user->getEstPurchase());
        sys.getLoggedInUser().addTransaction(t);
        sys.save();
				// setName(selectedSeller->getName());
				// setExchangeRate(selectedSeller->getExchangeRate());
				// setPurchase(user->getEstPurchase());
			}

			else if(Y_N == 'N' || Y_N == 'n')
			{
				cout << "Transaction Cancelled. Have a nice day!" << endl;
			}

			else
			{
				cout << "Error: Invalid Input" << endl;
				tr = true;

				std::cout<<"Seller: "<<selectedSeller->getName()<<" has exchange rate: "<<selectedSeller->getExchangeRate()<<std::endl;
				std::cout<<"Would you like to trade with "<<selectedSeller->getName()<<" Y/N"<<std::endl;
				cin >> Y_N;
			}

		}while(tr);

	}

	else
	{
		cout << "There is no match, return any key to exit" << endl;
		string temp;
		cin >> temp;
	}
}

void SellerOptions()
{
  double varMinPurchase;
	double varExchangeRate2;
	int scount = 0;

	while (scount == 0) {
		std::cout << "You have chosen to be a Seller, Please fill out below" << std::endl << "Enter your Minimum Purchase cost $(1.00 - 40.00): ";
		std::cin >> varMinPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varMinPurchase < 1.00 || varMinPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Minimum Purchase Cost $(1.00-40.00): ";
			std::cin >> varMinPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}


		std::cout << std::endl << "Enter your Exchange rate (0.55-.99) ";
		std::cin >> varExchangeRate2;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varExchangeRate2 < .55 || varExchangeRate2 > .99) {
			std::cout << "Invalid input, Please Enter Your Exchange Rate: ";
			std::cin >> varExchangeRate2;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		int sstaller = 0;
		std::string sdecision;
		std::string sdecision2;
		while (sstaller == 0) {
			std::cout << "You have chosen to search for a Minimum Purchase of $" << varMinPurchase << " at an exchange rate of " << varExchangeRate2 << std::endl;
			std::cout << "Do you accept (Y/N)? ";
			std::cin >> sdecision;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			if (sdecision == "Y" || sdecision == "y") {
				sstaller = 1;
				scount = 1;
			}
			else if (sdecision == "N" || sdecision == "n") {
				int sholder = 0;
				while (sholder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N goes back to main menu) ";
					std::cin >> sdecision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					if (sdecision2 == "Y" || sdecision2 == "y") {
						sholder = 1;
						sstaller = 1;
						scount = 0;
					}
					else if (sdecision2 == "N" || sdecision2 == "n") {
						sholder = 1;
						sstaller = 1;
						scount = 1;
						//some other var = 1 so that it goes back to main menu
					}
					else {	//error sholder loop
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error sstaller while loop
				std::cout << "Invalid choice, Please try again." << std::endl;

			}

		}	//end of sstaller while loop

	}	//end of scount while loop

		//Pass to seller lass to find best person (highest exchange rate and meets min purchase requirement)


		Seller *user2 = new Seller(varMinPurchase, varExchangeRate2);
		std::vector<Buyer*> buyerlist;
		buyerlist = Random::createBuyerPop();
		SortAndCalculate *buyercompute = new SortAndCalculate(user2, buyerlist);

			if(buyercompute->avaliableBuyerCheck())
	{
		bool fl = false;
		char Y_N;

		buyercompute->sellerFlow();


		Buyer *selectedBuyer=buyercompute->getSelectedBuyer();

		std::cout<<"Buyer: "<<selectedBuyer->getName()<<" has exchange rate: "<<selectedBuyer->getExchangeRate()
		<<" and a estimated purchase of "<<selectedBuyer->getEstPurchase()<<std::endl;

		std::cout<<"Would you like to trade with "<<selectedBuyer->getName()<<" Y/N"<<std::endl;

		std::cin >> Y_N;



		do
		{
			if(Y_N == 'Y' || Y_N == 'y')
			{
				//pass buyers' name, exchange rate, and estimated purchase.
				cout << "Transaction successfully completed!" << endl;

				//setName(user2->getName());
				//setExchangeRate(user2->getExchangeRate());
				//setPurchase(user2->getEstPurchase());

				break;
			}

			else if(Y_N == 'N' || Y_N == 'n')
			{
				cout << "Transaction cancelled. Have a nice day!" << endl;
				break;
			}

			else
			{
				cout << "Error: Invalid Input" << endl;
				fl = true;

				std::cout<<"Buyer: "<<selectedBuyer->getName()<<" has exchange rate: "<<selectedBuyer->getExchangeRate()
				<<" and a estimated purchase of "<<selectedBuyer->getEstPurchase()<<std::endl;

				std::cout<<"Would you like to trade with "<<selectedBuyer->getName()<<" Y/N"<<std::endl;

				cin >> Y_N;
			}

		}while(fl);

	}

	else
	{
		cout << "There is no match, return any key to exit" << endl;
		string temp;
		cin >> temp;
	}
}

int main(int argc, const char * argv[]) {
  srand(time(NULL));

  clear();

  bool loggedIn = false;
  string temp;
  while(!loggedIn) {
    int inp = loginMenuOption();
    if(inp == 1) {
      loggedIn = login();
      if(!loggedIn) {
        cout << "Username or password is incorrect!" << endl;
      }
    }
    else if(inp == 2) {
     loggedIn = createUser();
     if(!loggedIn) {
       cout << "Failed to create user." << endl;
     }
    }
  }

  cout << endl << "You have succesfully logged in!" << endl << endl;

  clear();

  sys.loadMap("res/Map", ',');

  // if(sys.getLoggedInUser().getTransactionHistory().size() > 0) {
  //   for(Transaction t: sys.getLoggedInUser().getTransactionHistory()) {
  //     cout << t.getName() << endl;
  //     cout << t.getExchangeRate() << endl;
  //     cout << t.getPurchase() << endl;
  //   }
  // }

  // Transaction t("name",2.2,4.4);
  // sys.getLoggedInUser().addTransaction(t);
  // sys.save();

  string error = "";
  int inp = 0;

  while(inp != 4) { //Main ui loop
    printGreetingScreen();
    cout << sys.getLoggedInUser().titlePrint();

    cout << sys.printMap();

    printMainMenu();

    cout << error;
    cout << "> ";
    string tmp_inp;
    cin >> tmp_inp;
    if(functions::is_number(tmp_inp.c_str())) {
      inp = atoi(tmp_inp.c_str());
    }
    else {
      inp = 0;
    }

    string sbinp;
    int count = 1;
    std::string dummy;

    switch(inp) {
      case 1:
        clear();
        BuyerOptions();
        error = "";
        break;
      case 2:
        clear();
        SellerOptions();
        error = "";
        break;
      case 3:
        clear();
        for(Transaction t: sys.getLoggedInUser().getTransactionHistory()) {
          cout << "Transaction: " << count << endl;
          cout << "\tName: " << t.getName() << endl;
          cout << "\tRate: " << t.getExchangeRate() << endl;
          cout << "\tPurchased: " << t.getPurchase() << endl;
          count++;
        }
        cout << "\nEnter m to return to the (m)enu: ";
        cin >> dummy;
        break;
      case 4:
        ;
        break;
      default:
        error = "> Invalid option\n";
        clear();
        break;
    }
    clear();
  }
  cout << "You have exited the program." << endl;
}
