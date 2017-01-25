
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
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
    unsigned int terms;
    float x, sum;
    int power = 1, factl = 1;
    
    cin>>x;
    cin>>terms;
    
    sum=x;
    
    for (int nt = 1; nt<terms;nt++) {
        for (int exp = 1; exp <= terms; exp++) {
            for (int div = 1; div <= terms; div++) {
                if ((terms%2)!=0) {
                    sum += (pow(x, power))/factl;
                    power+=2;
                    factl*=++factl;
                }
                else {
                    sum -= pow(x, power)/factl;
                    power+=2;
                    factl*=++factl; 
                }
            }
        }
    }
    
    cout<<"Sum = "<<sum<<endl;
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

