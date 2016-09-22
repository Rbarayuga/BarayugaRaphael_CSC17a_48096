/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Homework
 * Created on August 30, 2016, 1:23 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

/*
//Global Constants
//User Libraries 
 */

//Execution
int main(int argc, char** argv) {
//Display Variables
float YEN_D = 103.05;// Yen to dollars
float EUROS_D = .90;//Euros to dollars
int numDol;
float dolYen, dolEuro;

//Input money
cout << "How much money do you have in US Dollars? ";
cin >> numDol;

//Calculate 
dolYen = static_cast<float>(numDol) * YEN_D;
dolEuro = static_cast<float>(numDol) * EUROS_D;

//Output results
cout << numDol << " Dollars is equal to ";
cout <<setprecision(2) << fixed << "¥" <<dolYen;
cout << " in Yen and " << setprecision(2) << fixed<<endl;
cout << "€" <<dolEuro << " in Euros"<<endl;

//Exit Stage Right
    return 0;
}
