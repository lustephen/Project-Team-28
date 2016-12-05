
#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
	
//Creation of Person Object
class Person
{
//Name, Gender, UFID self explanatory, month day and year are used to make the date of birth
private:
	std::string name;
	int month;
	int day;
	int year;
	char gender;
	std::string ufid;

public:
	//This constructor is for the random population that needs to be passed to Person class
	Person(std::string, int, int, int, char, std::string);
	//This constructor is for the user to fill our the profile
	Person(std::string, std::string, char, std::string);
	Person(std::string);
	//Default constructor to allow subclasses to make constructors that do not pass to Person class
	Person();
	std::string getName();
	void setName(std::string);
	char getGender();
	void setGender(char);
	std::string getID();
	void setID(std::string);
	std::string getDOB();
	int getDay();
	int getMonth();
	int getYear();
	void setDOB(int,int,int);
	bool setDOB(std::string);
	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		// write out individual members of s with an end of line between each one
		os << p.name << '\n';
		os << p.month << '\n';
		os << p.day << '\n';
		os << p.year << '\n';
		os << p.ufid << '\n';
		os << p.gender << '\n';
		return os;
	}

	// Extraction operator
	friend std::istream& operator>>(std::istream& is, Person& p)
	{
		// read in individual members of s
		is >> p.name >> p.month >> p.day >> p.year >> p.ufid >> p.gender;
		return is;
	}
};


//random methods just here to generate the random Population later
//Rewritten in the Random class and explained there
static int randMonth() {
	return (rand() % 12 + 1);
}

static int randDay(int m) {
	if (m == 2) {
		return rand() % 28 + 1;
	}
	else if (m == 4 || m == 5 || m == 8 || m == 11) {
		return rand() % 30 + 1;
	}
	else {
		return rand() % 31 + 1;
	}
}

static int randYear() {
	return rand() % 31 + 1968;					//1968 - 1998
}

static char randGender() {
	int a = rand() % 2;
	if (a == 0) {
		return 'F';
	}
	else {
		return 'M';
	}
}

static double randExRate() {
	double rate = ((double)rand() / (double)RAND_MAX);

	while (rate < .55) {
		rate = ((double)rand() / (double)RAND_MAX);
	}

	return rate;
}

static double randEstPurchase() {
	double purchase = (double)(rand() % 18) + 3;
	return purchase;
}

static double randMinPurchase() {
	double purchase = (double)(rand() % 10) + 1;
	return purchase;
}

#endif
