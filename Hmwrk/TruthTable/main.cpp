
/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga    
 * Purpose: Truth Table
 * Created on September 21, 2016, 6:40 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    bool x[] = {true, true, false, false};
    
    bool y[] = {true, false, true, false};
    
    for (int i = 0; i < 4; i++) 
    {
        
        cout << ((x[i] && y[i]) ? 't' : 'f') << " ";
                
        cout << ((x[i] || y[i]) ? 't' : 'f')<<endl;
        
    }
    
    
    
    
    
    
    
    
return 0;
}

