
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));       //Set random number seed using time
    short guess,        //User input of guess
          loss = 0,     //Count of losing guesses 
          number;       //Random Number
    
    number = rand()%100+1;  //Value range from 1 to 100
    cout<<"Ranging from 1 to 100"<<endl;
    cout<<"The number is..."<<endl<<endl;
    
    //Loop and process
    do {
        cout<<"What's your guess? ";
        cin>>guess;
        cout<<endl;
        
        if ((guess > number) && (guess > 0) && (guess < 101)) {
            cout<<"The number is too high! Try again!"<<endl;
            loss++;
            cout<<"Guesses so far: "<<loss<<endl<<endl;
        }
        else if ((guess < number) && (guess > 0) && (guess < 101)) {
            cout<<"The number is too low! Try again!"<<endl;
            loss++;
            cout<<"Guesses so far: "<<loss<<endl<<endl;
        }
        else if (guess == number) {
            cout<<"The right answer is "<<number<<" and your answer is "<<guess<<endl;
            cout<<"Congratulations! You got the right answer!\n";  
            cout<<"Total Number of Guesses: "<<loss<<endl;
        }
        else if ((guess < 1) || (guess > 100)) {
            cout<<"INVALID INPUT! This guess is not counted."<<endl<<endl;
        }
    } while (guess != number);
        
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

