/* 
 * File:   Utilities.h
 * Author: Raphael M.B. Barayuga
 * 
 * Created on December 8, 2016, 12:13 PM
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
using namespace std;

class Utilities {
public:
    static void intro(){
        cout << "Welcome to Dungeon Crawler!" << endl;
        cout << "Each class has a different dungeon, monsters, and difficulty" << endl;
        cout << "What is your class choice?" << endl;
        cout << "________________________________________________" << endl;
        cout << "Fighter  : Easy    : Sword    : High   |  Health" << endl;
        cout << "________________________________________________" << endl;
        cout << "Mage     : Normal  : Fire     : Medium |  Health" << endl;
        cout << "________________________________________________" << endl;
        cout << "Rogue    : Hard    : 2xDagger : Low    |  Health" << endl;
        cout << "________________________________________________" << endl;
    };
   
    
private:

};

#endif /* UTILITIES_H */

