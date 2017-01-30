
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 30, 2017, 10:32 AM
 * Purpose: SIN Series
 * Problem: 
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
float myWay(float, int);
float yourWay(float, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nTerms; //Number of terms in the series
    float x; //Value in the series
    float myRes;
    float yourRes;
    
    //Input Values
    cout<<"Calculate a series"<<endl;
    cout<<"Input 2 terms"<<endl;
    cout<<"The value and number of terms"<<endl;
    cin>>x>>nTerms;
    
    //Process by mapping inputs to outputs
    myRes=myWay(x,nTerms);
    yourRes=myWay(x,nTerms);
    
    //Output values
    cout<<"My Res = "<<myRes<<" compared to exact result = "<<sin(x)<<endl;
    cout<<"My Res = "<<yourRes<<" compared to exact result = "<<sin(x)<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float yourWay(float x, int nTerms) {
    //Declare variables
    float series = x;
    int sign = 1;
    
    //Series for loop
    for (int cnt = 2, n=3; cnt<nTerms; cnt++, n+=2) {     
        //Calculate the factorial
        int fact = 1;
        for (int i= 1; i <=n; i++) {
            fact*=i;
        }
        //Calculate the series
        series+=(sign*pow(x, n)/fact);
    }
}

float myWay(float rad, int nTerms) {
    //Declare variable
    float sin = rad, delta = rad;
    
    //Loop for the series
    for (int cnt = 2, fact = 3; cnt<=nTerms;cnt++, fact+=2) {
        float delt = -rad*rad/(fact*(fact-1)); // -x^2/(i*(i-1))
        delta*=delt;
        sin+=delta;
        
    }
    return sin;
}