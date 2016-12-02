#include <iostream>
#include <string>
#include <vector>



class Person
{
private:
	std::string name;
	int month;
	int day;
	int year;
	char gender;
	int ufid;

public:
	Person(int mm, int dd, int yr, std::string n, char gender, int ufid);

	std::string getName();
	char getGender();
	int getID();
	int getDay();
	int getMonth();
	int getYear();
};
