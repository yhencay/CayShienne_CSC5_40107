
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 24, 2017, 1:35 PM
 * Purpose: Query the digits
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another


//Function Prototypes
bool qryDigt(int, int); //Query the digits

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char digit; // See and understand how and why this works
    int number; //Number is any random number in the range
    
    //Input Values
    cout<<"This program finds a digit"<<endl;
    cout<<"Input a single digit"<<endl;
    cin>>digit;
    
    //Generate a random number
    number=rand();
    
    //Output to Roman Numeral
    if(qryDigt(number,digit-48)) { //Remember digit is an ASCII Character
        cout<<digit<<" was found in "<<number<<endl;
    }
    else{
        cout<<digit<<" was not found in "<<number<<endl;
    }
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000000111111111122222222223333333334444444445555555555666666666677777777778
//345678901234567890123456789012346578901234567890123456789012345678901234657890
//********************Find a Digit in a Number**********************************
//Description: Query a number and compare results
//Inputs:
//    number -> Year from 1000 to 3000
//Outputs:
//    true -> if the digit is found
//******************************************************************************

bool qryDigt(int number, int digit) {
    //Loop until you find the digit or exit
    do{
        char digCmp = number%10;
        if (digCmp==digit) return true;
        number/=10;
        
    }while (number!=0);
    return false;
    
}