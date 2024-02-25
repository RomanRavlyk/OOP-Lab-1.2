#include <iostream>
#include "Bankomat.h"

using namespace std;

Bankomat createBankomat() {
    Bankomat atm;
    atm.Read();
    return atm;
}

int main() {
    Bankomat atm = createBankomat();

    int denomination, quantity;
    cout << "Enter denomination to load: ";
    cin >> denomination;
    cout << "Enter quantity of notes: ";
    cin >> quantity;
    atm.loadMoney(denomination, quantity);
    cout << "current money: " << atm.getCurrentMoney() << endl;
    cout << "Enter amount to withdraw: ";
    int amount_to_withdraw;
    cin >> amount_to_withdraw;
    atm.withdrawMoney(amount_to_withdraw);

    atm.Display();
    return 0;
}