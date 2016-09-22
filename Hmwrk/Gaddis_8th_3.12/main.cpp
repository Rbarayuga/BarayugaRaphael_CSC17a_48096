
/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Review Homework
 * Created on September 21, 2016, 9:39 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables.

    float f;

    float c;

    //output

    cout << "Conversion From Celsius To Fahrenheit" << endl;

    //User Inputs

    cout << "Enter the Celsius" << endl;

    cin >> c;

    //Calculate

    f = (1.8) * (c) + 32;

    //Conversion

    cout << "Fahrenheit:" << setprecision(3) << f << endl;

    //Exit Stage Right

    return 0;
}