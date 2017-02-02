/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:34 AM
 * Purpose: Homework Coin Toss
 * 
 *      Problem: Write a function named coinToss that simulates the tossing of a 
 * coin. When you call the function, it should generate a random number in the 
 * range of 1 through 2. If the random number is 1, the function should display 
 * “heads.” If the random number is 2, the function should display “tails.” 
 * Demonstrate the function in a program that asks the user how many times the 
 * coin should be tossed and then simulates the tossing of the coin that number 
 * of times.
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void cnToss(int);       //Coin Toss

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int toss;
    
    //Input Values
    cout<<"Number of Toss: ";
    cin>>toss;                  //Input number of toss
    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"----------------------"<<endl;
    cout<<"TOSS\t\tRESULT"<<endl;
    cout<<"----------------------"<<endl;
    cnToss(toss);                               //Display result from function
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//**************************** Coin Toss ***************************************
//Description: Toss coin for a specific number of times and display result
//Inputs:   No inputs but utilizes value from main to determine number of toss
//Outputs:  Outputs result whether coin tossed is head or tails
//******************************************************************************

void cnToss(int toss) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));      
    
    string a = "Heads!", b = "Tails!", result;
    for (int count = 1; count<=toss; count++) {     //Loop count until number of toss input
        unsigned short coin = rand()%2+1; //value from 1-2, Generate random number every loops
        result = (coin == 2)?b:a;               //2 means Tails, 1 means heads
        cout<<count<<"\t\t"<<result<<endl;
    }
}
