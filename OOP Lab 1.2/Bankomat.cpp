#include <iostream>
#include "Bankomat.h"
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
        cout << "Invalid denomination" << std::endl;
    }
    current_money += denominations * quantity;
}

bool Bankomat::withdrawMoney(int amount) {
    if (amount < min_withdrawal || amount > max_withdrawal || amount > current_money) {
        cout << "Invalid withdrawal amount" << endl;
        return false;
    }

    int remaining_amount = amount;
    remaining_amount = withdrawHelper(remaining_amount, 500, po500);
    remaining_amount = withdrawHelper(remaining_amount, 200, po200);
    remaining_amount = withdrawHelper(remaining_amount, 100, po100);
    remaining_amount = withdrawHelper(remaining_amount, 50, po50);
    remaining_amount = withdrawHelper(remaining_amount, 20, po20);
    remaining_amount = withdrawHelper(remaining_amount, 10, po10);

    if (remaining_amount >= 0) {
        current_money -= amount;
        cout << "Withdrawal successful" << endl;
        return true;
    }
    else {
        cout << "Cannot dispense requested amount" << endl;
        return false;
    }
}

int Bankomat::withdrawHelper(int amount, int denomination, int& quantity) {
    int num_notes = amount / denomination;
    if (num_notes > quantity) {
        num_notes = quantity;
    }

    int withdrawn_amount = num_notes * denomination;
    quantity -= num_notes;
    amount -= withdrawn_amount;

    return amount;
}

std::string Bankomat::toString() const {
    return "Current amount in ATM: " + to_string(current_money);
}

void Bankomat::Read() {
    cout << "Enter ATM ID: ";
    cin >> atm_id;
    cout << "Enter minimum withdrawal amount: ";
    cin >> min_withdrawal;
    cout << "Enter maximum withdrawal amount: ";
    cin >> max_withdrawal;
}

void Bankomat::Display() const {
    cout << "ATM ID: " << atm_id << endl;
    cout << "Current Money: " << current_money << endl;
    cout << "Min Withdrawal: " << min_withdrawal << endl;
    cout << "Max Withdrawal: " << max_withdrawal << endl;
}