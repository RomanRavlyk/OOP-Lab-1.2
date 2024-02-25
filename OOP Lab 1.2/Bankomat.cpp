#include "Bankomat.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

void Bankomat::loadMoney(int denominations, int quantity) {
	switch (denominations) {
	case 500:
		po500 += quantity;
		break;
	case 200:
		po200 += quantity;
		break;
	case 100:
		po100 += quantity;
		break;
	case 50:
		po50 += quantity;
		break;
	case 20:
		po20 += quantity;
		break;
	case 10:
		po10 += quantity;
		break;
	default:
		std::cout << "Invalid denomination" << std::endl;
	}
	current_money += denominations * quantity;
}

int Bankomat::withdrawHelper(int amount, int denomination, int& quantity) {
	int num_notes = amount / denomination;
	if (num_notes > quantity) {
		num_notes = quantity;
	}
	quantity -= num_notes;
	amount -= num_notes * denomination;
	return amount;
}

bool Bankomat::withdrawMoney(int amount) {
	if (amount < min_withdrawal || amount > max_withdrawal || amount > current_money) {
		std::cout << "Invalid withdrawal amount" << std::endl;
		return false;
	}

	int remaining_amount = amount;
	remaining_amount = withdrawHelper(remaining_amount, 500, po500);
	remaining_amount = withdrawHelper(remaining_amount, 200, po200);
	remaining_amount = withdrawHelper(remaining_amount, 100, po100);
	remaining_amount = withdrawHelper(remaining_amount, 50, po50);
	remaining_amount = withdrawHelper(remaining_amount, 20, po20);
	remaining_amount = withdrawHelper(remaining_amount, 10, po10);

	if (remaining_amount == 0) {
		current_money -= amount;
		return true;
	}
	else {
		std::cout << "Cannot dispense requested amount" << std::endl;
		return false;
	}
}

string Bankomat::toString() const{
	return "Current amount in ATM: " + to_string(current_money);
}
