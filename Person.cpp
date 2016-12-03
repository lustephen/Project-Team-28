#include "Person.hpp"
#include "functions.hpp"

using namespace std;

Person::Person(string n,string dob, char g, string id){
	name = n;
	gender = g;
	ufid = id;
	setDOB(dob);
}

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

Person::Person() {

}

std::string Person::getName()
{
	return name;
}

void Person::setName(string name) {
  this -> name = name;
}

char Person::getGender()
{
	return gender;
}

void Person::setGender(char g) {
	this -> gender = g;
}

string Person::getID()
{
	return ufid;
}

void Person::setID(string id) {
	this -> ufid = id;
}

string Person::getDOB() {
	return to_string(this -> month) + "/" + to_string(this -> day) + "/" + to_string(this -> year);
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

void Person::setDOB(int mm, int dd, int yyyy) {
	this -> month = mm;
	this -> day = dd;
	this -> year = yyyy;
}

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
