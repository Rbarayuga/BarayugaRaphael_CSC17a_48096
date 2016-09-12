/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Created on September 12, 2016, 1:01 PM
 * Purpose: database Sort
 */

//system Libraries
#include <iostream> //I/O Library 
#include <cstdlib>//rand number generator library
#include <ctime>//time Library

using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int[], int[], int);
void prntAry(int[], int[], int, int);
void prntAry(int[], int, int);
void mrkSort(int [], int[], int);

//Execution begins here!

int main(int argc, char** argv) {
    //Declare Variables
    int perLine = 10;
    const int SIZE = 100;
    int utilize = SIZE * 0.5;
    int array[SIZE], index[SIZE];

    srand(static_cast<unsigned int> (time(0)));
    //Input Data
    fillAry(array,index, utilize);

    //Display initialization
    cout<<"Original Array output"<<endl;
    prntAry(array, utilize, perLine);
    cout<<"Original Indexed Array Output"<<endl;
    prntAry(index, utilize, perLine);
    cout<<"Array Output utilizing the Index"<<endl;
    prntAry(array, index, utilize, perLine);
    //Process -> Map the input data to the output
    mrkSort(array,index, utilize);
    //Display/Output solution here
   cout<<"Original Array after sorting"<<endl;
    prntAry(array, utilize, perLine);
    cout<<"Sorted Indexed Array"<<endl;
    prntAry(index, utilize, perLine);
    cout<<"Array Output utilizing the Index after Sorting"<<endl;
    prntAry(array, index, utilize, perLine);
    //Exit Stage right!
    return 0;
}

void mrkSort(int a[], int indx[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[indx[i]] > a[indx[j]]) {
                indx[i] = indx[i]^indx[j];
                indx[j] = indx[i]^indx[j];
                indx[i] = indx[i]^indx[j];
            }
        }
    }

}

void prntAry(int a[], int indx[], int n, int perLine) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[indx[i]] << " "; //Random 2 digit numbers
        if (i % perLine == (perLine - 1))cout << endl;
    }
}

void prntAry(int a[], int n, int perLine) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; //Random 2 digit numbers
        if (i % perLine == (perLine - 1))cout << endl;
    }
}

void fillAry(int a[], int indx[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 90 + 10; //Random 2 digit numbers
        indx[i] = i;
    }
}

