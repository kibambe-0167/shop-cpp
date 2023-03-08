#pragma once

#pragma once
#include <iostream>
#include <string.h>
#include <string>



using namespace std;

class CoffeeShop {
private:
	string products[5];
	int quantity[5];
	double price[5];
	string shopName;
	double turnover;

	int search(string);

public:
	CoffeeShop(string name);

	void loadProduct(string);

	bool buy(double, string, int);

	void display();
};