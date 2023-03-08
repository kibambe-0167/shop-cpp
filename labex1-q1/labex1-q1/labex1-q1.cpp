// labex1-q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// Aaron Kibambe AK - 220072233
// 
int main() {
    /* ask user to words signs.
    check which color user entered using switch statement.
    if length of letter/digits is more than 6, get the remaining letters after, multiply that by 7, add on cost.
    show user the information.
    */
    int color;
    double ads_on_cost = 7;
    double total = 30.0; // initialise and add base charge
    string sign = "";
    double black_cost = 10.0;
    double gold_cost = 12.0;

    while(sign != "END") {
        cout << endl;
        cout << "Enter letters or digits or END to exit: ";
        getline(cin, sign);
        
        if (sign == "END") break;
  
        cout << "Enter color of letters or digits\n 1. White \n 2. Black \n 3. Gold \n color option:";
        cin >> color;

        switch (color) {
            case 1: total += 0; break;
            case 2: total += black_cost; break;
            case 3: total += gold_cost; break;
            default: total += 0; break;
        }

        if (sign.length() > 6) {
            total += ads_on_cost * (sign.length() - 6);
        }

        cout << endl;
        cout << "Words:\t" << sign << endl << "Color:\t" << color << endl << "Total:\t" << total << endl;
        cin.ignore(1, '\n');
        total = 0.0;
    }
}