
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  5:22 PM
 * Purpose: Homework Calories Burned
 *      Problem: Running on a particular treadmill you burn 3.6 calories per 
 * minute. Write a program that uses a loop to display the number of calories 
 * burned after 5, 10, 15, 20, 25, and 30 minutes.
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
    float calBurn = 0;
    
    cout<<"Calories Burned After Running: "<<endl<<endl;
    
    for (unsigned char cal = 5; cal <= 30; cal+=5) {
        calBurn += (3.6*5);
        cout<<static_cast<int>(cal)<<" minutes  =  "<<calBurn<<" calories burned."<<endl;
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

