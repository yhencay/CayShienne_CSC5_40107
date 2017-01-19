
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework Ocean Levels
 *      Problem: Assuming the ocean’s level is currently rising at about 1.5 
 * millimeters per year, write a program that displays a table showing the 
 * number of millimeters that the ocean will have risen each year for the next 
 * 25 years. 
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
    float lvl = 0;          //Ocean level per year

    //Loop ocean level til 25 years
    for (unsigned short yrs = 1; yrs <= 25; yrs++) {   
        lvl += 1.5;
        cout<<"Year "<<yrs<<": "<<lvl<<" millimeters."<<endl;
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

