#include "Bankomat.cpp"
#include "Bankomat.h"
#include <iostream>
using namespace std;

Bankomat makeBankomat() {
    Bankomat bankomat; 
    
    bankomat.getNumber();
    bankomat.giveMoney(0);
    bankomat.giveMoney(0);
    bankomat.giveMoney(0);
    bankomat.calculateMoney();
    bankomat.checkmoneystate();
    /*bankomat.toString();*/
    bankomat.Display();
    
    return bankomat;
}

int main() {
    Bankomat bankomat1;
    makeBankomat();
    
    return 0;
}
