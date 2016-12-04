#include <iostream>
#include <math>
#include <vectors>
#include <string>
#include "Random.hpp"

static int Random::randMonth() {
	return (rand() % 12 + 1);
}

static int Random::randDay(int m) {
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

static int Random::randYear() {
	return rand() % 31 + 1968;					//1968 - 1998
}

static char Random::randGender() {
	int a = rand() % 2;
	if (a == 0) {
		return 'F';
	}
	else {
		return 'M';
	}
}

static double Random::randExRate() {
	double rate = ((double)rand() / (double)RAND_MAX);

	while (rate < .55) {
		rate = ((double)rand() / (double)RAND_MAX);
	}

	return rate;
}

static double Random::randEstPurchase() {
	double purchase = (double)(rand() % 18) + 3;
	return purchase;
}

static double Random::randMinPurchase() {
	double purchase = (double)(rand() % 10) + 1;
	return purchase;
}

std::string Random::randName(char g) {
	std::vector<std::string> femalenames = { "Susan", "Rebecca" , "Nicole" , "Alexis" , "Zoe" , "Kayla" };
	std::vector<std::string> malenames = { "Daniel", "Alex", "Ajax", "Michael", "Brian", "Jeffrey" };
	int place = rand() % 6;

	if (g == 'F') {
		return femalenames[place];
	}
	else {
		return malenames[place];
	}
}

int Random::randUfid() {
	return rand() % 90000000 + 10000000;
}

void Random::createBuyerPop(std::vector<Buyer*> vec) {
	for (int g = 0; g < 20; g++) {
		int a = randMonth();
		char b = randGender();
		Buyer *buy = new Buyer(randEstPurchase(), randExRate(), a, randDay(a), randYear(), randName(b), b, randUfid());
		vec.push_back(buy);

	}
}

void Random::createSellerPop(std::vector<Seller*> vec) {
	for (int h = 0; h < 20; h++) {
		int j = randMonth();
		char z = randGender();
		Seller *sell = new Seller(randMinPurchase(), randExRate(), j, randDay(j), randYear(), randName(z), z, randUfid());
		vec.push_back(sell);
	}
}
