/* 
 * File:   main.cpp
 * Author: Raphael M.B. Barayuga
 * Purpose: Homework
 * Created on October 5, 2016, 9:01 AM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct MovieProfit
{
    string title;
    string direct;   //Direcctor of the film
    int release;     //Year Released
    int mins;        //Time of the movie
    int cost;        //Production cost of the movie
    int revenue;     //
};

void print(MovieProfit);

//Program Execution Begins Here

int main(int argc, char** argv) {
    
    MovieProfit movie;
   
    cout << "What is the Title of the movie?"<<endl;
    getline(cin, movie.title);
    
    cout <<"Who is the director?"<<endl;
    getline(cin, movie.direct);
    
    cout <<"When was it released?"<<endl;
    cin >>movie.release;
    
    cout <<"How long was the movie in minutes?"<<endl;
    cin >>movie.mins;
    
    cout <<"How much was the production cost of the movie?"<<endl;
    cin >> movie.cost;
    
    cout<<"What was the first years profit or loss?"<<endl;
    cin>>movie.revenue;
    
    cin.ignore(10,'\n');
 
    print(movie);
       
    //Exit
    return 0;
}

void print( MovieProfit md ){
    cout <<endl;
    cout <<"***************************"<<endl;
    cout <<"Title: "<<md.title<<endl;
    cout <<"Director: "<<md.direct<<endl;
    cout <<"Year released: "<<md.release<<endl;
    cout <<"Length: "<<md.mins<<endl;
    cout <<"First year's profit or loss."<<md.revenue<<endl;
    cout <<"***************************"<<endl;
}