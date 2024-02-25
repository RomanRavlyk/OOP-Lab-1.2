#pragma once
#include <string>
using namespace std;
class Bankomat {
private:
	int atm_id;
	int current_money;
	int min_withdrawal;
	int max_withdrawal;

	int po500;
	int po200;
	int po100;
	int po50;
	int po20;
	int po10;

public:
	Bankomat(int id, int min, int max) : atm_id(id), min_withdrawal(min), max_withdrawal(max), current_money(0),
		po500(0), po200(0), po100(0), po50(0), po20(0), po10(0) {}
	void loadMoney(int denominations, int quantity);
	bool withdrawMoney(int amount);
	int withdrawHelper(int amount, int denomination, int& quantity);
	string toString() const;
};
