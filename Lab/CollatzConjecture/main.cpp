
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 30, 2017, 12:21 PM
 * Purpose: COLLATZ CONJECTURE 
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
    const int series = 50;
    int array[series];
    
    int input, res = 0;
    bool x = true;
    
    cout<<"Input number: ";
    cin>>input;
    
    cout<<input<<" ";
    

    do {    
        do {
            if (input%2 == 0) {
                res = input/2;
                cout<<res<<" ";
                x=false;
            }
            else {
                res = 3*input +1;
                cout<<res<<" ";
                x=false;
            }
        }while (x);
        
        while (res!=1) {
        if (res%2 == 0) {
            res = res/2;
            cout<<res<<" ";
        }
        else if (res%2 == 1) {
            res = 3*res+1;
            cout<<res<<" ";
        }
  //      count++;
        }
    } while (res!=1);
    
    
    
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

