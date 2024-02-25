#pragma once
#include <string>
using namespace std;
class Bankomat {
private:
	int atm_id;
	int current_money = 0;
	int min_withdrawal;
	int max_withdrawal;

	int po500;
	int po200;
	int po100;
	int po50;
	int po20;
	int po10;

public:
	void loadMoney(int denominations, int quantity);
	bool withdrawMoney(int amount);
	int withdrawHelper(int amount, int denomination, int& quantity);
	string toString() const;
	int getATMId() const { return atm_id; }
	int getCurrentMoney() const { return current_money; }
	int getMinWithdrawal() const { return min_withdrawal; }
	int getMaxWithdrawal() const { return max_withdrawal; }
	void Read();
	void Display() const;
};
