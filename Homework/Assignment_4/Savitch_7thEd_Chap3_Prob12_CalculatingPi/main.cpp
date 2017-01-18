
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017, 12:19 PM
 * Purpose: Calculating Pi
 *      pi = 4 [ 1 - 1/3 + 1/5 - 1/7 + 1/9 ... + ((-1)^n/2n+1) ]
 */

//System Libraries
#include <iostream>
#include <cmath>
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
    unsigned int numTerm = 100;
    float pi = 0.0;
    
    for (int n = 0; n < numTerm; ++n) {
        pi += 4 * pow(-1, n) / (2*n + 1);
        cout<<"n  = "<<n<<"     "<<pi<<endl;
    }
    
    cout<<"\n  PI =    "<<pi <<endl;
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

