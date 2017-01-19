
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
    short inLine;
    
    cout<<"Input: ";
    cin>>inLine;
    cout<<endl;
    
    for (int line = 1; line <= (inLine*inLine); line++) {
        if ((inLine >= 1) && (inLine <= 15)) {
            cout<<show;
            if ((line%inLine)==0) cout<<endl;
        }
        else cout<<"INVALID INPUT!";
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

