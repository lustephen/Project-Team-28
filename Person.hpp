#include <iostream>
#include <string>
#include <vector>
#include <ctime>


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


//random methods just here to generate the random Pop later
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

double randExRate() {
	double rate = ((double)rand() / (double)RAND_MAX);

	while (rate < .55) {
		rate = ((double)rand() / (double)RAND_MAX);
	}

	return rate;
}

double randEstPurchase() {
	double purchase = (double)(rand() % 18) + 3;
	return purchase;
}

double randMinPurchase() {
	double purchase = (double)(rand() % 10) + 1;
	return purchase;
}

void createBuyerPop(std::vector<Buyer*> vec) {
	for (int g = 0; g < 20; g++) {
		int a = randMonth();
		char b = randGender();
		Buyer *buy = new Buyer(randEstPurchase(), randExRate(), a, randDay(a), randYear(), randName(b), b, randUfid());
		vec.push_back(buy);

	}
}

void createSellerPop(std::vector<Seller*> vec) {
	for (int h = 0; h < 20; h++) {
		int j = randMonth();
		char z = randGender();
		Seller *sell = new Seller(randMinPurchase(), randExRate(), j, randDay(j), randYear(), randName(z), z, randUfid());
		vec.push_back(sell);
	}
}
