
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Homework Miles Per Gallon
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
    unsigned char gallons = 15;   //Number of gallons of gasoline a car can hold
    unsigned short mlstrvl = 375; //Miles a car can travel before refueling
    unsigned char nummpg;         //Miles per gallon                  
    
    //Input Values
    
    //Process by mapping inputs to outputs
    nummpg = mlstrvl/gallons;
    
    //Output values
    cout<<"Miles traveled: "<<mlstrvl<<" miles"<<endl;
    cout<<"Gallons used: "<<static_cast<int>(gallons)<<" gallons"<<endl;
    cout<<"\nThe number of miles per gallon is "<<static_cast<int>(nummpg)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

