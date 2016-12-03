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


