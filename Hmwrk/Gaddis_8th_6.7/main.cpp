/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Review Homework
 * Created on September 21, 2016, 9:52 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
float celsius(float);

int main(int argc, char** argv) {

     cout << "Fahrenheit " << setw(13) << " Celsius" << endl;
    
	//convert values from 0 - 20 C from F
	for(int i = 0; i < 21; i++)
        {
                cout << setw(4) << i << setw(10) << "" << setw(10) << fixed
                     << showpoint << setprecision(2)
                     << celsius(i) << endl; 
	}

        return 0;
}

float celsius(float F)
{
        //((5/9) * (Fahrenheit - 32)) calculation given
        return (( 5 / 9.0 ) * ( F - 32.0) );
}
