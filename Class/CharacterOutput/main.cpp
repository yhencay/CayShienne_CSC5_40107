
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 23, 2017,  11:37 PM
 * Purpose: Investigate character cout
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
    
    //Input Values
    
    //Process by mapping inputs to outputs
    for(char c=0; c<127;c++) {
        cout<<c;
        if(c%16==15) cout<<endl;
    }
    //Output a triangle
    //Declare the base
    cout<<endl<<endl;
    int base = 15;
    for(int nLines = 1; nLines <= base; nLines++) {
        for (int nCols = 1; nCols<=nLines;nCols++) {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    
    for(int nLines = 1; nLines <= base; nLines++) {
        for (int nCols = base-nLines+1; nCols>=1;nCols--) {
            cout<<"*";
        }
        cout<<endl;
    }
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

