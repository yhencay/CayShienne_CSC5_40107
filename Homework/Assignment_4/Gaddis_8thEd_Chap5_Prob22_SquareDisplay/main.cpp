
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
 */

//System Libraries
#include <iostream>
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
    string show = "X";
    short inLine;       //User input in how many lines to use
 
    
    cout<<"REMINDER: Only input positive integers not greater than 15! Doing otherwise"<<endl
        <<"will give you an INVALID INPUT! Minimum input is 1."<<endl<<endl;
    cout<<"Input: ";
    cin>>inLine;
    cout<<endl;
      
    //Loop and process with if-else statement
    if ((inLine >= 1) && (inLine <= 15)) {    
        for (int line = 1; line <= (inLine*inLine); line++) {        
            cout<<show;
            if ((line%inLine)==0) cout<<endl;       //Counter so output will go on the next line    
      }
    }
    else cout<<"INVALID INPUT!"<<endl;

    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

