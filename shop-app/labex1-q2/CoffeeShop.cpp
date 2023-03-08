#include "CoffeeShop.h"
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <algorithm>

CoffeeShop::CoffeeShop(string name) {
	// set initial values for name and turnover.
	shopName = name;
	turnover = 0.0;
}

void CoffeeShop::loadProduct(string filename) {
	// load items into vectors. close fstream. 
	// loop over the data in vector. normalise data before loading the data into arrays.
	// index is used to increment via the rows.
	vector<vector<string>> csv_data;
	ifstream file(filename);

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		vector<string> fields;
		string field;
		while (getline(ss, field, ',')) { fields.push_back(field); }
		csv_data.push_back(fields);
	}
	file.close();
	int index = 0;
	for (const auto& row : csv_data) {
		products[index] = row[0];
		quantity[index] = stoi(row[1]);
		price[index] = stod(row[2]);
		index++;
	}
}

int CoffeeShop::search(string name) {
	// check if product array has product with given name
	// get index and return index.
	// transform items to lower, in order to have
	for (int i = 0; i < size(products); i++) {
		transform(products[i].begin(), products[i].end(), products[i].begin(), [](unsigned char c) { return tolower(c); });
		transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return tolower(c); });
		if (name == products[i]) { return i; }
	}
	return -1;
}


void CoffeeShop::display() {
	// display quantity and price of products in all arrays.
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << CoffeeShop::products[i] << "\t" << CoffeeShop::quantity[i] << "\t" << CoffeeShop::price[i] << endl;
	}
}

bool CoffeeShop::buy(double a, string n, int q) {
	/* search for products. check
	* 
	*/
	int i = CoffeeShop::search(n);
	if (i < 0 || i > 4) { return false; }
	else {
		if (CoffeeShop::quantity[i] >= q) {
			if ((CoffeeShop::price[i] * q) <= a) {
				CoffeeShop::quantity[i] -= q;
				CoffeeShop::turnover += CoffeeShop::price[i] * q;
				return true;
			}
			else { return false; }
		}
		else { return false;  }
	}
}