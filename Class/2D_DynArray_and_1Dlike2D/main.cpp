/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Created on September 12, 2016, 1:01 PM
 * Purpose: Shortest sort
 */

//system Libraries
#include <iostream> //I/O Library 
#include <cstdlib>//rand number generator library
#include <ctime>//time Library

using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int* fillAry(int);
int** fillAry(int, int);
void prntAry(int*, int, int);
void prntAry(int**, int, int);


//Execution begins here!

int main(int argc, char** argv) {
    //Declare Variables
    int perLine = 10;
    const int ROW = 10, COL = 10;
    const int SIZE = ROW*COL;
    int *a1D, **a2D;
    //Input Data
    a1D = fillAry(SIZE);
    a2D = fillAry(ROW, COL);

    //Display/Output solution here
    cout << "1 Dimensional Array with " << perLine << "V" << endl;
    prntAry(a1D, SIZE, perLine);
    cout << "2 Dimensional Array with[" << ROW << "," << COL << "]" << endl;
    prntAry(a2D, ROW, COL);

    //Output a specific row and column of either
    int sRow = 7, sCol = 4;
    cout << "Specific Row and Col output[" << sRow << "," << sCol << "]"
            << endl;
    cout << "a1D [" << sRow << "] [" << sCol << "]=" << a1D[sRow * COL + sCol]
            << endl;
    cout << "a2D [" << sRow << "] [" << sCol << "]=" << a2D[sRow][sCol] << endl;
    
    //Deallocate memory
    delete []a1D;
    //Row arrays first
    for (int i = 0; i < ROW; i++) {
        delete []a2D[i];
    }
    delete []a2D;
    
    //Exit Stage right!
    return 0;
}

void prntAry(int **a, int r, int c) {
    cout << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " "; //Random 2 digit numbers

        }
        cout << endl;
    }
    cout << endl;
}

void prntAry(int *a, int n, int perLine) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        {
            cout << a[i] << " "; //Random 2 digit numbers
            if (i % perLine == (perLine - 1))cout << endl;

        }
        cout << endl;
    }
}

int** fillAry(int r, int c) {
    //allocate
    int **a = new int*[r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a[i][j] = rand() % 90 + 10; //Random 2 digit numbers
        }
    }
}

    int* fillAry(int n) {
        //allocate
        int *a = new int[n];
        for (int i = 0; i < n; i++) {

        }
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 90 + 10; //Random 2 digit numbers
        }
        return a;
    }

