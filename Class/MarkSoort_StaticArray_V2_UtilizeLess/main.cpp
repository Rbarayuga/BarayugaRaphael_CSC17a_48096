/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Created on September 12, 2016, 1:01 PM
 * Purpose: Shortest Sort
 */

//system Libraries
#include <iostream> //I/O Library 
#include <cstdlib>//rand number generator library
#include <ctime>//time Library

using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int[], int);
void prntAry(int[], int, int);
void mrkSort(int [], int);

//Execution begins here!

int main(int argc, char** argv) {
    //Declare Variables
    int perLine = 10;
    const int SIZE = 100;
    int utilize = SIZE * 0.5;
    int array[SIZE];
    srand(static_cast<unsigned int> (time(0)));
    //Input Data
    fillAry(array, utilize);

    //Display initialization
    prntAry(array, utilize, perLine);
    //Process -> Map the input data to the output
    mrkSort(array, utilize);
    //Display/Output solution here
    prntAry(array, utilize, perLine);
    //Exit Stage right!
    return 0;
}

void mrkSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                a[i] = a[i]^a[j];
                a[j] = a[i]^a[j];
                a[i] = a[i]^a[j];
            }
        }
    }

}

void prntAry(int a[], int n, int perLine) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; //Random 2 digit numbers
        if (i % perLine == (perLine - 1))cout << endl;
    }
}

void fillAry(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 90 + 10; //Random 2 digit numbers
    }
}

