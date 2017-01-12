/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12:20 PM
 * Purpose: Paycheck
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values as well as conversions
//from system of units to another

//Function Prototypes

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    float hrsWrkd, //Hours worked in (hrs)
          payRate, //Pay rate in $'s
          payChck; //Pay Check in $'s
    
    //Input Values
    cout<<"This program calculates your Paycheck"<<endl;
    cout<<"Your hours worked and pay rate are required"<<endl;
    cout<<"Input your hours worked in hours"<<endl;
    cin>>hrsWrkd;
    cout<<"Input your payRate in $'s/hr"<<endl;
    cin>>payRate;
    
    //Process by mapping inputs to outputs
    payChck = hrsWrkd * payRate;
    
    //Output Values
    cout<<"Your paycheck = $"<<payChck<<endl;
    
    //Exit stage right!

    return 0;
}

