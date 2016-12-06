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
//On Startup Menu Options for Program
//User Can either Create a New accont that will be saved or Login to an Account
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
	//Trouble Shooting incase user does not choose options 1 or 2
    if(inp < 1 || inp > 2) {
      cout << "Invalid input, please try again." << endl;
    }
  }
  return inp;
}
//Login Fuction to check username and password of the account
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
//Function for creating a new account, passes username and password to be saved in a .txt file
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

  //Account creation, Profile is filled out as well then saved into a .txt file
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
//Clears the Command line window to keep program functioning smoothly
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
//Function to print out Gretting screen of FlexBucks Market
void printGreetingScreen() {
  cout << functions::readFile("res/welcomescreen.txt");
}
//Function to print out Main Menu after logging in
//User can select to Buy/Sell, View their transaction history, or exit the program
void printMainMenu() {
  cout << "  1) Buy" << endl;
  cout << "  2) Sell" << endl;
  cout << "  3) View Transaction History" << endl;
  cout << "  4) Exit" << endl;
}
//Function if the user wants to be a buyer, function used for simpler coding in the main
void BuyerOptions() {
  //IF THE USER IF A BUYER CASE
	//Variables Purcahse cost and Exchange rate are needed inputs from the user
	double varEstPurchase;
	double varExchangeRate;
	int count = 0;
	//Asks for Estimated Purchase cost and Troubleshoots for invalid inputs
	while (count == 0) {
		std::cout << "You have chosen to be a Buyer, Please fill out below" << std::endl << "Enter your Estimated purchase cost $(1.00 - 40.00): ";
		std::cin >> varEstPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		//Estimated purchase can only be between $1 and $40 inclusive
		while (varEstPurchase < 1.00 || varEstPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Estimated Purchase Cost $(1.00-40.00): ";
			std::cin >> varEstPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		//Asks for exchange rate Troubleshoots for invalid inputs as well
		//Exchange rate can only be in between .55-99 inclusive
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
		//Validates that the user wants to buy x Amount for y Exchange rate
		//Continues to trouble shoot if user does not input Y or N (y and n also)
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
			//If user wants to continue breaks out of while loops
			if (decision == "Y" || decision == "y") {
				staller = 1;
				count = 1;
			}
			//If user declines, will be asked if they want to change their preferences
			else if (decision == "N" || decision == "n") {
				int holder = 0;
				while (holder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N continues with current settings) ";
					std::cin >> decision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					//If user asks to change preferences then they will be taken back and asked for exchange rate, estimated purcahse etc...
					if (decision2 == "Y" || decision2 == "y") {
						holder = 1;
						staller = 1;
						count = 0;
					}
					//If users says no then program will look for seller based on the current preferences
					//Breaks out of while loops and continues program
					else if (decision2 == "N" || decision2 == "n") {
						holder = 1;
						staller = 1;
						count = 1;
					}
					else {	//error for the holder while loop, checking if user does not select Y, N, y ,n
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error staller while loop, same thing as holder loop
				std::cout << "Invalid choice, Please try again." << std::endl;

			}

		}	//end of staller while loop

	}	//end of count while loop


	std::cout << "Processing..." << std::endl;
	//If preferences are chosen,
	//Pass to buyer class to find best person (lowest exchange rate, meets sellers min purchase requirement)

	//Creates user as a buyer object with their preferences passed in parameters
	Buyer *user = new Buyer(varEstPurchase, varExchangeRate);
	std::vector<Seller*> sellerlist;
	//Seller list is then filled with a random population of sellers
	sellerlist = Random::createSellerPop();
	//SortAndCalculate Object made passes the user and sellerlist
	SortAndCalculate *sellercompute = new SortAndCalculate(user, sellerlist);

	//Checks to see if there is anyone in seller list that meets requirements of the user, if no one matches return back to main menu
	if(sellercompute->avaliableSellerCheck())
	{
		bool tr = false;
		char Y_N;
		//If there is a seller in seller list that matches requirements buyerFlow searches for optimal Seller (lowest exchange rate)
		sellercompute->buyerFlow();
		//Selected Seller is found and user will be asked if he/she wants to trade with the selected seller
		Seller *selectedSeller=sellercompute->getSelectedSeller();
		std::cout<<"Seller: "<<selectedSeller->getName()<<" has exchange rate: "<<selectedSeller->getExchangeRate()<<std::endl;
		std::cout<<"Would you like to trade with "<<selectedSeller->getName()<<" Y/N"<<std::endl;
		cin >> Y_N;


		do
		{
			if(Y_N == 'Y' || Y_N == 'y')
			{
				//if User goes through transaction the Name exchange rate of seller and the purcahse cost of user is stored in tranaction object
				cout << "Transaction successfully completed!" << endl;
        Transaction t (selectedSeller->getName(), selectedSeller->getExchangeRate(), user->getEstPurchase());
        sys.getLoggedInUser().addTransaction(t);
		//saves transaction to .txt file
        sys.save();
				//functions that are used to pass to transaction
				// setName(selectedSeller->getName());
				// setExchangeRate(selectedSeller->getExchangeRate());
				// setPurchase(user->getEstPurchase());
			}
			//If user does not go through transaction returns back to main menu
			else if(Y_N == 'N' || Y_N == 'n')
			{
				cout << "Transaction Cancelled. Have a nice day!" << endl;
			}
			//Trouble shooting error if user does not select Y,N,y,n
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
	//As stated above, if no seller in list meets requirements return to main menu
	else
	{
		cout << "There is no match, return any key to exit" << endl;
		string temp;
		cin >> temp;
	}
}
//Function for if the user wants to be a seller, function used for simpler coding in the main
void SellerOptions()
{
	//The user Sellers stores a exchange rate and minimum purchase variables
  double varMinPurchase;
	double varExchangeRate2;
	int scount = 0;
	//Asks for Minimum purchase cost
	while (scount == 0) {
		std::cout << "You have chosen to be a Seller, Please fill out below" << std::endl << "Enter your Minimum Purchase cost $(1.00 - 40.00): ";
		std::cin >> varMinPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		//Users minimum purchase cost has to be between $1 and $40 inclusive
		//Trouble shooting errors if not in between 1-40
		while (varMinPurchase < 1.00 || varMinPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Minimum Purchase Cost $(1.00-40.00): ";
			std::cin >> varMinPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		//Asks for exchange rate
		//Exchange rate checked to see if between .55-.99 inclusive
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
		//Asks user to verify their search for their minimum purchae and exchange rate
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
			//If user accepts it will exit while loops and continue program
			if (sdecision == "Y" || sdecision == "y") {
				sstaller = 1;
				scount = 1;
			}
			//If user rejects they will be asked if he/she wants to change preferences
			else if (sdecision == "N" || sdecision == "n") {
				int sholder = 0;
				while (sholder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N continues with current settings) ";
					std::cin >> sdecision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					//If user wants to change setting will be taken back to be asked for minimum purchase
					if (sdecision2 == "Y" || sdecision2 == "y") {
						sholder = 1;
						sstaller = 1;
						scount = 0;
					}
					//If user rejects will, program will continue with the preferences that they filled out already
					//breaks out of while loop to continue program
					else if (sdecision2 == "N" || sdecision2 == "n") {
						sholder = 1;
						sstaller = 1;
						scount = 1;

					}
					else {	//error sholder loop, trouble shoot for user input errors
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error sstaller while loop, trouble shoot for user input errors
				std::cout << "Invalid choice, Please try again." << std::endl;

			}

		}	//end of sstaller while loop

	}	//end of scount while loop
		//If Seller variables are set will continue program
		//Pass to seller class to find best Buyer (highest exchange rate and meets min purchase requirement)

		//Creates the user as a Seller object
		Seller *user2 = new Seller(varMinPurchase, varExchangeRate2);
		std::vector<Buyer*> buyerlist;
		//Fills buyerlist with population of random buyers
		buyerlist = Random::createBuyerPop();
		//Passes the seller user and buyer list
		SortAndCalculate *buyercompute = new SortAndCalculate(user2, buyerlist);

		//checks to see if anyone in buyerlist meets the requirements of user, if not then there is no match, back to main menu
		if(buyercompute->avaliableBuyerCheck())
		{
		bool fl = false;
		char Y_N;
		//If one person matches then sellerFlow finds the optimal buyer
		buyercompute->sellerFlow();

		//Selected buyers info shown and asks the user to verify transaction
		Buyer *selectedBuyer=buyercompute->getSelectedBuyer();

		std::cout<<"Buyer: "<<selectedBuyer->getName()<<" has exchange rate: "<<selectedBuyer->getExchangeRate()
		<<" and a estimated purchase of "<<selectedBuyer->getEstPurchase()<<std::endl;

		std::cout<<"Would you like to trade with "<<selectedBuyer->getName()<<" Y/N"<<std::endl;

		std::cin >> Y_N;



		do
		{
			//If user accepts transaction it is comepleted and goes bac to main menu
			if(Y_N == 'Y' || Y_N == 'y')
			{
				//pass buyers' name, exchange rate, and estimated purchase.
				cout << "Transaction successfully completed!" << endl;
				//function that are used to pass to transaction
				//setName(user2->getName());
				//setExchangeRate(user2->getExchangeRate());
				//setPurchase(user2->getEstPurchase());

				break;
			}
			//If user rejects transaction returns to main menu
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
	//if no one in buyer list meets requirements returns to main menu
	else
	{
		cout << "There is no match, return any key to exit" << endl;
		string temp;
		cin >> temp;
	}
}

int main(int argc, const char * argv[]) {
	//Seeds rand() so it creates random variables every time
  srand(time(NULL));
  //clears command line
  clear();
  //If login information is false
  bool loggedIn = false;
  string temp;
  while(!loggedIn) {
    int inp = loginMenuOption();
	//If user wants to login, username and password is asked and passed to login
    if(inp == 1) {
      loggedIn = login();
      if(!loggedIn) {
        cout << "Username or password is incorrect!" << endl;
      }
    }
	//If ser wants to create and account createUser function is called and asks for username and password
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

  string error = "";
  int inp = 0;

  while(inp != 4) { //Main ui loop
	  //Prints Flexbucks greeting screen
    printGreetingScreen();
    cout << sys.getLoggedInUser().titlePrint();

    cout << sys.printMap();
    cout << "\nReitz Union Food Court Map\nKey: P = Panda Express, C = Croutons, J = Papa John's\nW = Wendy's, S = Starbucks, T = Pollo Tropical, x = Wall\n\n";

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
	//Cases for each case that the user can select from the main menu
    switch(inp) {
		//If user is Buyer
      case 1:
        clear();
        BuyerOptions();
        error = "";
        break;
      case 2:
		  //If user is Seller
        clear();
        SellerOptions();
        error = "";
        break;
      case 3:
		  //If user wants to see transaction history, reads .txt file and displays transaction history
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
		//Exits program case
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
