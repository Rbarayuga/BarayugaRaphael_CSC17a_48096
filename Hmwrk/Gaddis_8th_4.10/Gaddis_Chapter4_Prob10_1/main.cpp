/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose:Homework
 * Created on September 7, 2016, 10:34 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

/*
//Global Constants
//User Libraries 
 */

//Execution
int main(int argc, char** argv) {
    int y, m, days; // y = years m= month d= days

    bool lYear; //Leap Year

    //Input Month and year
    cout << "Enter month: "; //Enter a month using numbers
    cin >> m;
    cout << "Enter year: ";
    cin >> y;

    //Finding Leap year
    if (y % 400 == 0 && y % 100 == 0) {
        lYear = true;
    }
    if (y / 100 == 0 && y / 4 == 0) {
        lYear = true;
    }

    //How many days in a month
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        cout << "31 days" << endl;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        cout << "30 days" << endl;
    } else if (m == 2) {
        if (lYear == true) {
            cout << "29 days ; Leap year" << endl;
        } else if (lYear == false) {
            cout << "28 days" << endl;
        }
    }
    return 0;
}

