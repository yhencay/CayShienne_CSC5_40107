
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework Characters for the ASCII Codes
 *      Problem: Write a program that uses a loop to display the characters for 
 * the ASCII codes 0 through 127. Display 16 characters on each line. 
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
    for (int nChar = 0; nChar<=127; nChar++) {
        if (nChar%16==0) cout<<endl<<endl;
        cout<<static_cast<char>(nChar);
    }
    cout<<endl;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

