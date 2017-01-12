
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 9, 2017, 12:34 PM
 * Purpose: Homework to calculate Miles Per Gallon 
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
    float numGas,   //Number of gallons of gas that a car can hold 
          numMls,   //Number of miles before running out of gas
          numMpg;   //Number of miles per gallon of gas
    
    //Input Values
    cout<<"How many gallons of gas can your car hold? ";
    cin>>numGas;
    cout<<"How many miles can your car be driven on a full tank? ";
    cin>>numMls;
    
    //Process by mapping inputs to outputs
    numMpg = numMls/numGas;
    
    //Output values
    cout<<endl
        <<"The number of miles that your car can drive per gallon of gas is "
        <<numMpg<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

