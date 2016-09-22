/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Homework
 * Created on September 21, 9:46 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Variables
    float x, y;
   
    //Input two numbers
    cout << "Please enter two numbers" << endl;
    cin >> x;
    cin >> y;
    
    //Determines which is smaller or larger
    if(x > y ) { 
        cout << "This number is larger: "<< x <<endl;
       cout << "This number is smaller: " << y <<endl; 
    }
    
    else{ 
        cout << "This number is larger: " << y << endl;
       cout << "This number is smaller: " << x << endl; 
    }
    
    return 0;
}

