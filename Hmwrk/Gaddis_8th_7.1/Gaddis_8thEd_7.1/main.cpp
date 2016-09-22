/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Largest/Smallest Array
 * Created on September 21, 2016, 9:01 PM
 */

#include <iostream>

using namespace std;

//Global Constants
//User Libraries 


int main(int argc, char** argv) {
     int arr[10];
    int i = 10;
    
    for(i = 0; i < 10; ++i)
    {
        int arrVal;
        cout << "Enter value for array. ";
        cin >> arrVal;
        arr[i] = arrVal;
    }
    
    int arrValL = arr[0];
    
    int arrValS = arr[0];
    
    for(i = 0; i < 10; ++i)
    {
        if(arrValS > arr[i])
        {
            arrValS = arr[i];
        }
        if(arrValL < arr[i])
        {
            arrValL = arr[i];
        }
    }
    cout << "Largest value in array is " << arrValL << endl;
    cout << "Smallest value in array is " << arrValS << endl;
    
    return 0;
}