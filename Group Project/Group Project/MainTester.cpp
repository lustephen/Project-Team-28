//
//  MainTester.cpp
//  Group Project
//
//  Created by Alejandro Munoz-McDonald on 11/24/16.
//  Copyright © 2016 Alejandro Munoz-McDonald. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Account.hpp"
#include "System.hpp"
#include "hl_md5wrapper.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace std;

//int main(int argc, const char * argv[]) {
//    Account testAccount ("Bob");
//    testAccount.setUFID(74341234);
//    testAccount.setDOB("01/01/1990");
//    cout << testAccount.getName() << endl;
//    cout << testAccount.getUFID() << endl;
//    cout << testAccount.getDOB() << endl;
//    System system (true);
////    hashwrapper *md5 = new md5wrapper();
////    string user;
////    cin >> user;
////    string pass;
////    cin >> pass;
////    system.createUser(user, md5->getHashFromString(pass));
//    system.login("Harry", "Pass");
//    return 0;
//}

TEST_CASE( "Valid login is attempted", "[login]" ) {
    System system (true);
    hashwrapper *md5 = new md5wrapper();
    
    REQUIRE( system.login("Admin", "Passw0rd!") == true );
}

TEST_CASE( "Invalid login is attempted", "[login]" ) {
    System system (true);
    hashwrapper *md5 = new md5wrapper();
    
    REQUIRE( system.login("Admin", "incorrectpassword") == false );
}

//TEST_CASE( "Factorials are computed", "[factorial]" ) {
//    REQUIRE( Factorial(1) == 1 );
//    REQUIRE( Factorial(2) == 2 );
//    REQUIRE( Factorial(3) == 6 );
//    REQUIRE( Factorial(10) == 3628800 );
//}
