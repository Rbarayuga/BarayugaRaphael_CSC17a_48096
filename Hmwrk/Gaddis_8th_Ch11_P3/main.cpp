
/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Homework
 * Created on October 5, 2016, 7:54 PM
 */

//System Library
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;



struct SalesData {
    string divname; //Name of the Division
    float fiquart; //First Quarter
    float sequart; //Second Quarter
    float thquart; //Third Quarter
    float foquart; //Fourth Quarter
    float total; //Total Annual Sales
    float avgqt; //Average Quarterly Sales 
};
void print(SalesData);

int main(int argc, char** argv) {

    SalesData north;
    SalesData east;
    SalesData south;
    SalesData west;
    
    short count = 0; //counter

    //Loop for 
    do {
        if (count > 0) {
       cout << "Please input Division's Values" << endl;
        }
        
        cout << "North Division: " << endl;
        north.divname = "North";
        cout << "What are the first quarter sales?" << endl;
        cin >> north.fiquart;
        cout << "What are the second quarter sales?" << endl;
        cin >> north.sequart;
        cout << "What are the third quarter sales?" << endl;
        cin >> north.thquart;
        cout << "What are the fourth quarter sales?" << endl;
        cin >> north.foquart;

        count++;
        
    } while (north.fiquart <= 0 || north.sequart <= 0 ||
             north.thquart <= 0 || north.foquart <= 0);

    north.total = (north.fiquart + north.sequart +
                   north.thquart + north.foquart);

    north.avgqt = (north.total / 4);
    
    count = 0;

    do {
          //User Input for Division
        if (count > 0) {
            
               cout << "Please input Division's Values" << endl;
               
        }
        
        cout << "East Division: " << endl;
        
        east.divname = "East";
        
        cout << "What are the first quarter sales?" << endl;
        cin >> east.fiquart;
        
        cout << "What are the second quarter sales?" << endl;
        cin >> east.sequart;
        
        cout << "What are the third quarter sales?" << endl;
        cin >> east.thquart;
        
        cout << "What are the fourth quarter sales?" << endl;
        cin >> east.foquart;
        count++;
    } while (east.fiquart <= 0 || east.sequart <= 0 ||
            east.thquart <= 0 || east.foquart <= 0);

    east.total = (east.fiquart+ east.sequart + 
                  east.thquart + east.foquart);
    east.avgqt = (east.total / 4);
    count = 0;

    do {
        //User Input for Division
        if (count > 0) {
            cout << "Please input Division's Values" << endl;
        }
        cout << "South Division: " << endl;
        south.divname = "South";
        
        cout << "What are the first quarter sales?" << endl;
        cin >> south.fiquart;
        
        cout << "What are the second quarter sales?" << endl;
        cin >> south.sequart;
        
        cout << "What are the third quarter sales?" << endl;
        cin >> south.thquart;
        
        cout << "What are the fourth quarter sales?" << endl;
        cin >> south.foquart;
        count++;
        
    } while (south.fiquart <= 0 || south.sequart <= 0 ||
             south.thquart <= 0 || south.foquart <= 0);
 

    south.total = (south.fiquart + south.sequart +
                   south.thquart + south.foquart);
    
    south.avgqt = (south.total / 4);
    
    count = 0;

    do {
          //User Input for Division
        if (count > 0) {
            
               cout << "Please input Division's Values" << endl;
               
        }
        cout << "West Division: " << endl;
        
        west.divname = "West";
        
        cout << "What are the first quarter sales?" << endl;
        cin >> west.fiquart;
        
        cout << "What are the second quarter sales?" << endl;
        cin >> west.sequart;
        
        cout << "What are the third quarter sales?" << endl;
        cin >> west.thquart;
        
        cout << "What are the fourth quarter sales?" << endl;
        cin >> west.foquart;
        
        count++;
        
    } while (west.fiquart <= 0 || west.sequart <= 0 ||
            west.thquart <= 0 || west.foquart  <= 0);

    west.total = (west.fiquart + west.sequart +
                  west.thquart + west.foquart);
    west.avgqt = (west.total / 4);
    
    count = 0;

    print(north);

    print(east);

    print(south);

    print(west);
   
    return 0;
}

void print(SalesData corp) {

    cout << endl;
    
    cout << "********************************" << endl;
    
    cout << corp.divname << " division." << endl;
    
    cout << "Earned a total of : $ " << corp.total << endl;
    
    cout << "And has an average quarter sale of " << corp.avgqt << endl;
    
    cout << "********************************" << endl;

}


