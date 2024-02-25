#include <iostream>
#include "Bankomat.h"

using namespace std;

Bankomat createBankomat() {
    int atm_id, min_withdrawal, max_withdrawal;
    cout << "Enter ATM ID: ";
    cin >> atm_id;
    cout << "Enter minimum withdrawal amount: ";
    cin >> min_withdrawal;
    cout << "Enter maximum withdrawal amount: ";
    cin >> max_withdrawal;

    return Bankomat(atm_id, min_withdrawal, max_withdrawal);
}

int main() {
    Bankomat atm = createBankomat();

    int denomination, quantity;
    cout << "Enter denomination to load: ";
    cin >> denomination;
    cout << "Enter quantity of notes: ";
    cin >> quantity;
    atm.loadMoney(denomination, quantity);

    cout << "Enter amount to withdraw: ";
    int amount_to_withdraw;
    cin >> amount_to_withdraw;
    atm.withdrawMoney(amount_to_withdraw);

    cout << atm.toString() << endl;

    return 0;
}