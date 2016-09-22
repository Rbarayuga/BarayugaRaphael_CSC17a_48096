
/* 
 * File:   main.cpp
 * Author: Raphael M.B Barayuga
 *
 * Created on September 21, 2016, 10:02 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    //Declare
    int pop, days; //population and days 
    float growth;

    //Input
    cout << "What is the starting population?" << endl;
    cin >> pop
            //Input growth rate
    cout << "What is the growth rate?(by percentage)" << endl;
    cin >> growth       
    growth /= 100.00;
    //Input amount of days for growth
    cout << "How many days will the population grow?" << endl;
    cin >> days;

    //loop for population
    for (int i = 0; i <= days; i++) {

        //Displays output
        cout << "Day " << i << ": " << pop << "\n";
        pop = (pop * growth) + pop;
    }
    return 0;
}

