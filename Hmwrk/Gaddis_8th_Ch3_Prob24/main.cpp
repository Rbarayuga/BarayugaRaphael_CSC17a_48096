/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose:Review
 * Created on September 21, 2016, 6:07 PM
 */

#include <iostream>
#include <string>
using namespace std;

/*
//Global Constants
//User Libraries
 */

int main(int argc, char** argv) {
//Declare Variables
string nameP, nameCit, nameCol, prof, animal, namePet;
int age;

//Input variables
cout << "What is your name? ";
cin >> nameP;
cout << "How old are you? ";
cin >> age;
cout << "Name a city: ";
getline(cin, nameCit);
cout << "Name a college: ";
cin >> nameCol;
cout << "Name a profession: ";
cin >> prof;
cout << "Name a type of animal: ";
cin >> animal;
cout << "Name of a pet: ";
cin >> namePet;

//Output variables
cout << "There once was a person named " << nameP;
cout << " who lived in " << nameCit << ".";
cout << " At the age of " << age << ", " << nameP;
cout << " went to the college of " << nameCol << ". ";
cout << nameP << " graduated and went to work as a ";
cout << prof << ". Then, " << nameP << " adopted an ";
cout << animal << " named " << namePet << ".";
cout << " They both lived happily ever after!";

//Exit stage Right!

return 0;
}

