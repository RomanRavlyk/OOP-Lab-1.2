#include "Bankomat.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

void Bankomat::initialize() {
	money_state = 0;
	minMax = 10;
	maxMax = 10000;

	po500, po200, po100, po50, po20, po10 = 0;
}

void Bankomat::giveMoney(int value) {
	cout << "How many money you want to give?: "; cin >> value;
	if (value == 500) {
		po500++;
	}
	else if (value == 200) {
		po200++;
	}
	else if (value == 100) {
		po100++;
	}
	else if (value == 50) {
		po50++;
	}
	else if (value == 20) {
		po20++;
	}
	else if (value == 10) {
		po10++ ;
	}
	else { cout << "Error, unaccpatable value, please try again" << endl; }
}

void Bankomat::takeMoney(int value) {
	cout << "How many money you want to take?: "; cin >> value;

	if (value == 500 && (money_state >= value) && po500 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po500--;
		cout << "Success" << endl;
	}
	else if (value == 200 && (money_state >= value) && po200 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po200--;
		cout << "Success" << endl;
	}
	else if (value == 100 && (money_state >= value) && po100 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po100--;
		cout << "Success" << endl;
	}
	else if (value == 50 && (money_state >= value) && po50 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po50--;
		cout << "Success" << endl;
	}
	else if (value == 20 && (money_state >= value) && po20 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po20--;
		cout << "Success" << endl;
	}
	else if (value == 10 && (money_state >= value) && po10 >= 1 && maxMax >= minMax) {
		money_state -= value;
		maxMax -= value;
		po10--;
		cout << "Success" << endl;
	}
	else {
		cout << "Error, unaccpatable value, please try again" << endl;
	}
}	

int Bankomat::calculateMoney() {
	money_state += 500 * po500;
	money_state += 200 * po200;
	money_state += 100 * po100;
	money_state += 50 * po50;
	money_state += 20 * po20;
	money_state += 10 * po10;
	return money_state;
}

void Bankomat::Display() {
	cout << "Your money :" << checkmoneystate() << endl;
	cout << "Minimum money which you can take: " << minMax << ", maximum money which you can take: " << maxMax << endl;
}

//string Bankomat::toString() const
//{
//	stringstream sout;
//	sout << "Money state = " << money_state << endl;
//	return sout.str();
//}
