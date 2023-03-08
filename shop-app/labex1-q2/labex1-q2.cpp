// labex1-q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "CoffeeShop.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;


int menu_() {
    int n;
    cout << endl << endl << "Thamie Coffee Shop Menu" << endl;
    cout << "=======================================" << endl;
    cout << "1. Load Products" << endl;
    cout << "2. Buy a Products" << endl;
    cout << "3. Display all Products" << endl;
    cout << "4. Exit" << endl;
    cout << "Choice: ";

    cin >> n;
    return n;
}

int main()
{
    CoffeeShop object("Thamie's Shop");
    int menu;
    do {
        menu = menu_();

        if (menu == 1) {
            object.loadProduct("List.csv");
            cout << endl << "Products Loaded" << endl;
        }
        else if (menu == 2) {
            string n; int q; double a;
            cout << "Enter name of product[Cup, Tea, Cof, Cho, Gre]: ";
            cin >> n;

            cout << "Enter quantity of ['" << n << "'] product: ";
            cin >> q;

            cout << "Enter amount: ";
            cin >> a;

            bool isBought = object.buy(a, n, q);
            if (isBought == true) {
                cout << "Transaction Successful." << endl;
            }
            else {
                cout << "Transaction Unsuccessful." << endl;
            }
        }
        else if (menu == 3) {
            object.display();
        }
        else if (menu == 4) {
            menu = -1;
        }

    } while (menu > 0 && menu < 4);
    // 
    system("pause");
}