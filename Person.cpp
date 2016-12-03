#include "Person.hpp"

Person::Person(int mm, int dd, int yr, std::string n, char g, int id){
	month = mm;
	day = dd;
	year = yr;
	name = n;
	gender = g;
	ufid = id;
}


std::string Person::getName()
{
	return name;
}

char Person::getGender()
{
	return gender;
}

int Person::getID()
{
	return ufid;
}

int Person::getDay()
{
	return day;
}

int Person::getMonth()
{
	return month;
}

int Person::getYear()
{
	return year;
}


int randMonth() {
	return (rand() % 12 + 1);
}

int randDay(int m) {
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

int randYear() {
	return rand() % 31 + 1968;					//1968 - 1998
}

char randGender() {
	int a = rand() % 2;
	if (a == 0) {
		return 'F';
	}
	else {
		return 'M';
	}
}
