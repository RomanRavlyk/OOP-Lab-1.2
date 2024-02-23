#pragma once
//#include <string>

class Bankomat {
private:
	int number = 54636252;
	int money_state = 0;
	int minMax = 50;
	int maxMax = 10000;

	int po500, po200, po100, po50, po20, po10;

public:
	void giveMoney(int value);
	void takeMoney(int value);
	void initialize();
	void Display();
	int getNumber() const { return number; };
	int checkmoneystate() const { return money_state; };
	int calculateMoney();

	/*string toString();*/

	int getPo500() const { return po500; };
	int getPo200() const { return po200; };
	int getPo100() const { return po100; };
	int getPo50() const { return po50; };
	int getPo20() const { return po20; };
	int getPo10() const { return po10; };

};
