#include "Person.hpp"
#include "functions.hpp"

using namespace std;
//Constructor for the user Person, passes a String name, Char gender, string ufid, and string date of birth
Person::Person(string n,string dob, char g, string id){	
	name = n;
	gender = g;
	ufid = id;
	setDOB(dob);
}
//Constructor for Randomly Generated population, passes int month, day, year,  char gender, and string name and string ufid
Person::Person(string n,int mm, int dd, int yr, char g, string id){
	month = mm;
	day = dd;
	year = yr;
	name = n;
	gender = g;
	ufid = id;
}

Person::Person(string name) {
	this -> name = name;
}

//Default constructor class allows for subclass constructors to work if nothing is passed to Person
Person::Person() {

}
//Return name of a Person Object
std::string Person::getName()
{
	return name;
}

//Sets private variable name in a Person Object
void Person::setName(string name) {
  this -> name = name;
}

//Returns gender of a Person Object
char Person::getGender()
{
	return gender;
}

//Sets gender of a Person Object
void Person::setGender(char g) {
	this -> gender = g;
}

//Returns the UFID of a Person Object
string Person::getID()
{
	return ufid;
}

//Sets the UFID of a Person Object
void Person::setID(string id) {
	this -> ufid = id;
}

//Gets Date of Birth from a Person Object
string Person::getDOB() {
	return to_string(this -> month) + "/" + to_string(this -> day) + "/" + to_string(this -> year);
}

//Returns day (apart of date of birth for randomly generated population) of a Person Object
int Person::getDay()
{
	return day;
}

//Returns month similar to getDay()
int Person::getMonth()
{
	return month;
}
//Follows same procedure as getDay() and get Month()
int Person::getYear()
{
	return year;
}

//Sets the date of birth of the user using day month and year parameters
void Person::setDOB(int mm, int dd, int yyyy) {
	this -> month = mm;
	this -> day = dd;
	this -> year = yyyy;
}

//Sets the Date of birth with proper DOB notation mm/dd/yr
bool Person::setDOB(string date) {
  vector<string> v;
  functions::split(date,'/',v);

  if(v.size() == 3){
    try {
      this -> month = stoi(v.at(0));
      this -> day = stoi(v.at(1));
      this -> year = stoi(v.at(2));
    }
    catch(int e) {
      return false;
    }
    return true;
  }
  return false;
}
