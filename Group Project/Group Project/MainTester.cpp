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

TEST_CASE( "System Tester", "[system]" ) {
    
    System system (true);
    
    SECTION("Valid login attempt") {
        hashwrapper *md5 = new md5wrapper();
        
        REQUIRE( system.login("Admin", "Passw0rd!") == true );
    }
    
    SECTION("Invalid login attempt") {
        hashwrapper *md5 = new md5wrapper();
        
        REQUIRE( system.login("Admin", "incorrectpassword") == false );
    }
    
    SECTION("Create User") {
        hashwrapper *md5 = new md5wrapper();
        
        REQUIRE( system.login("Admin", "incorrectpassword") == false );
    }
    
    SECTION("Remove User [user exists]") {
        system.createUser("TEMP_USER", "TEMP_PASSWORD");
        
        REQUIRE( system.removeUser("TEMP_USER") == true );
    }
    
    SECTION("Remove User [user does not exist]") {
        REQUIRE( system.removeUser("TEMP_USER") == false );
    }
}

TEST_CASE( "AccountTester", "[account]" ) {
    string testName = "Bob";
    int testID = 98765432;
    string testDOB = "01/01/1990";
    
    Account testAccount (testName);
    testAccount.setUFID(testID);
    testAccount.setDOB(testDOB);
    
    REQUIRE( testAccount.getName() == testName);
    REQUIRE( testAccount.getUFID() == testID);
    REQUIRE( testAccount.getDOB() == testDOB);
}

//EXAMPLE
//TEST_CASE( "Factorials are computed", "[factorial]" ) {
//    REQUIRE( Factorial(1) == 1 );
//    REQUIRE( Factorial(2) == 2 );
//    REQUIRE( Factorial(3) == 6 );
//    REQUIRE( Factorial(10) == 3628800 );
//}
