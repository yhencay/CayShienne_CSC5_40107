
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 4, 2017, 01:00 PM
 * Purpose: Land Calculation
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

const int CNVACRFT=43560; //Conversions acres to feet

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nAcres, //Number of Acres
        nFt2; //Equivalent to feet squared
    //Input Values
    cout<<"This is a conversion program "<<endl;
    cout<<"from number of Acres to Feet squared"<<endl;
    cout<<"Input Number of Acres"<<endl;
    cin>>nAcres;
    
    //Process by mapping inputs to outputs
    nFt2=nAcres*CNVACRFT;
    
    //Output values
    cout<<"The number of Acres input = "<<nAcres<<endl;
    cout<<"Equivalent to "<<nFt2<<"(ft^2)"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

