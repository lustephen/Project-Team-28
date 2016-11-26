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
#include "md5/hl_md5wrapper.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

using namespace std;

TEST_CASE( "System Tester", "[system]" ) {
    
    System system (true);
    
    SECTION("User exists") {
        REQUIRE( system.userExists("Admin") == true );
    }
    
    SECTION("User does not exist") {
        REQUIRE( system.userExists("TEMP_USER") == false );
    }
    
    SECTION("Valid login attempt") {
        REQUIRE( system.userExists("Admin") == true );
        
        REQUIRE( system.login("Admin", "Passw0rd!") == true );
    }
    
    SECTION("Invalid login attempt") {
        REQUIRE( system.userExists("Admin") == true );
        
        REQUIRE( system.login("Admin", "incorrectpassword") == false );
    }
    
    SECTION("Create User [user already exists]") {
        REQUIRE( system.userExists("Admin") == true );
        
        REQUIRE( system.createUser("Admin", "Passw0rd!") == false );
    }
    
    SECTION("Remove User [user exists]") {
        hashwrapper *md5 = new md5wrapper();
        system.createUser("TEMP_USER", md5->getHashFromString("TEMP_PASSWORD"));
        
        REQUIRE( system.userExists("TEMP_USER") == true );
        
        REQUIRE( system.removeUser("TEMP_USER") == true );
    }
    
    SECTION("Remove User [user does not exist]") {
        REQUIRE( system.userExists("TEMP_USER") == false );
        
        REQUIRE( system.removeUser("TEMP_USER") == false );
    }
}

TEST_CASE( "AccountTester", "[account]" ) {
    string testName = "Bob";
    int testID = 98765432;
    int mm = 1;
    int dd = 1;
    int yyyy = 1990;
    string testDOB = "1/1/1990";
    
    Account testAccount (testName);
    testAccount.setUFID(testID);
    testAccount.setDOB(mm,dd,yyyy);
    testAccount.setLocation(0, 0);
    
    REQUIRE( testAccount.getName() == testName );
    REQUIRE( testAccount.getUFID() == testID );
    REQUIRE( testAccount.getDOB() == testDOB );
    REQUIRE( testAccount.distanceTo((int[]){0,0}) == 0 );
    REQUIRE( testAccount.distanceTo((int[]){3,4}) == 5 );
}

//EXAMPLE
//TEST_CASE( "Factorials are computed", "[factorial]" ) {
//    REQUIRE( Factorial(1) == 1 );
//    REQUIRE( Factorial(2) == 2 );
//    REQUIRE( Factorial(3) == 6 );
//    REQUIRE( Factorial(10) == 3628800 );
//}
