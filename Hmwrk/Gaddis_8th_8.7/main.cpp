/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga    
 * Purpose: Review Homework
 * Created on September 21, 2016, 7:49 PM
 */

//system libraries
#include <iostream>
#include <string>
using namespace std;


//Function Prototype

int binaryS(string[], int, string); //BinarySearch

void sortArray(string[], int); // Sort the array

int main(int argc, char** argv) {

    //Declare
    const int SIZE = 20;

    string person;

    int results;
    
    //8-8 Skeleton
    string names[SIZE] = {"Bill", "Bart", "Allen",
                           "Griffin ", " Marty", "Rose",
                           "Taylor ", "Johnson ",
                           "Allison", " Joe", "Wolfe", 
                           "Jean", "Weaver", "Pore ",
                           "Greg", "Javens",
                           "Harrison", "Cathy",
                           "Gordon", "Holland"};

    //Sort
    
    sortArray(names, SIZE);

    //Input
    
    //Can Only Pick from name list
    
    cout << " Who would you like to search for?  " << person << endl; 
    cin>>person;


    results = binaryS(names, SIZE, person);

    cout << "The name " << names[results] << " is located in the cell number "
            << results << " in the array" << endl;

    //Does not display any other names except for names inside 


    return 0;
}

//From Chapter's binarySearch
int binaryS(string a[], int n, string i) {
    int first = 0,
            last = n - 1,
            middle,
            position = -1;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (a[middle] == i) {
            found = true;
            position = middle;
        } else if (a[middle] > i)
            last = middle - 1;
        else first = middle + 1;
    }
    return position;
}

//Sort
void sortArray(string array[], int names) {
    bool swap = false;
    string y;
    do {
        swap = false;
        for (int count = 0; count < (names - 1); count++) {
            if (array[count] > array[count + 1]) {
                y = array[count];
                array[count] = array[count + 1];
                array[count + 1] = y;
                swap = true;
            }
        }
    } while (swap);
}