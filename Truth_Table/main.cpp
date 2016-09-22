/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga    
 * Purpose: Review
 * Created on September 21, 2016, 10:40 AM
 */

#include <iostream>

using namespace std;

/*
//Global Constants
//User Libraries 
 */

int main(int argc, char** argv) 
{
   
bool x=true;
bool y=true;

 for (int i = 0; i < 1; i++) {
     
cout<<(x?'T':'F')<<(y?'T':'F')<<(!x?'T':'F')<<(!y?'T':'F')<<(x&&y?'T':'F')<<
(x||y?'T':'F')<<(x^y?'T':'F')<<(x^y^y?'T':'F')<<(x^y^x?'T':'F')<<
(!(x&&y)?'T':'F')<<(!x||!y?'T':'F')<<(!x&&!y?'T':'F')<<endl;

 } 

x=true;
y=false;

 for (int i = 0; i < 1; i++) {
     
cout<<(x?'T':'F')<<(y?'T':'F')<<(!x?'T':'F')<<(!y?'T':'F')<<(x&&y?'T':'F')<<
(x||y?'T':'F')<<(x^y?'T':'F')<<(x^y^y?'T':'F')<<(x^y^x?'T':'F')<<
(!(x&&y)?'T':'F')<<(!x||!y?'T':'F')<<(!x&&!y?'T':'F')<<endl;

 }

x=false;
y=true;

 for (int i = 0; i < 1; i++) {
     
cout<<(x?'T':'F')<<(y?'T':'F')<<(!x?'T':'F')<<(!y?'T':'F')<<(x&&y?'T':'F')<<
(x||y?'T':'F')<<(x^y?'T':'F')<<(x^y^y?'T':'F')<<(x^y^x?'T':'F')<<
(!(x&&y)?'T':'F')<<(!x||!y?'T':'F')<<(!x&&!y?'T':'F')<<endl;

 }

x=false;
y=false;

 for (int i = 0; i < 1; i++) {
     
cout<<(x?'T':'F')<<(y?'T':'F')<<(!x?'T':'F')<<(!y?'T':'F')<<(x&&y?'T':'F')<<
(x||y?'T':'F')<<(x^y?'T':'F')<<(x^y^y?'T':'F')<<(x^y^x?'T':'F')<<
(!(x&&y)?'T':'F')<<(!x||!y?'T':'F')<<(!x&&!y?'T':'F')<<endl;

 }

//Exit Stage Right

    return 0;
}
