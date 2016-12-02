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
#include "Flexbucks.hpp"
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
  string dob = "";
  string ufid;
  cout << endl << "Account Creation" << endl << endl;
  while(slashes != 3) {
    cout << "Please enter your date of birth (mm/dd/yyyy): ";
    cin >> dob;
    vector<string> dob_checker;
    functions::split(dob,'/',dob_checker);
    if((slashes = dob_checker.size()) != 3) {
      cout << "Invalid date format. Try again." << endl;
    }
  }
  cout << "Plese enter your UF ID: ";
  cin >> ufid;

  Account acc (user, dob, ufid);

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
  cout << "  3) Settings" << endl;
  cout << "  4) Exit" << endl;
}

int main(int argc, const char * argv[]) {
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

  // sys.setMap();
  vector< vector<Account> > tempmap;

  for(int i = 0; i < 10; i++) { //Generate map
    vector<Account> row; // Create an empty row
    for (int j = 0; j < 9; j++) {
      Account tmp ("tmp");
      row.push_back(tmp); // Add an element (column) to the row
    }
    tempmap.push_back(row);
  }

  sys.setMap(tempmap);

  Account acc = sys.getLoggedInUser();

  string error = "";
  int inp = 0;

  while(inp != 4) { //Main ui loop
    printGreetingScreen();
    cout << acc.titlePrint();

    cout << sys.printMap();

    printMainMenu();

    cout << error;
    cout << "> ";
    cin >> inp;

    Account a("Bob");
    string sbinp;

    switch(inp) {
      case 1:
        clear();
        cout << "Seller Options Input Page" << endl; //Placeholder
        error = "";
        cin >> sbinp;
        break;
      case 2:
        clear();
        cout << "Buyer Options Input Page" << endl; //Placeholder
        error = "";
        cin >> sbinp;
        break;
      case 3:
        clear();
        cout << "Settings Input Page" << endl; //Placeholder
        error = "";
        cin >> sbinp;
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
