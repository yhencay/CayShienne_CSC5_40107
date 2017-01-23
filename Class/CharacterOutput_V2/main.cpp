
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
void repeat(char, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output a triangle
    //Declare the base
    cout<<endl<<endl;
    int base = 15, seprshn = 15;
    for(int nLines = 1;nLines <= base;nLines++) {
            repeat('*',nLines);
            repeat(' ',base-nLines);
            repeat(' ',seprshn);
            repeat('*',base-nLines+1);
            cout<<endl;
    }
    cout<<endl;

    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}
void repeat(char c, int n) {
    for (int col = 1; col <= n; col++) {
        cout<<c;
    }
}
