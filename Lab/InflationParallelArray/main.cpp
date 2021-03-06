
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 2, 2017, 10:35 AM
 * Purpose: Calculate Inflation Rate
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void savings( int [], float [], float, float, int);
void prntAry(int [], float [], int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {   
    //Declare Variables
    const int SIZE = 102;
    int nYears = SIZE/2 + 1;
    int year[SIZE]= {}; //Initialize the entire array to 0
    float balance[SIZE] = {};
    
    //Input Values
    float infRate=0.065f;//Inflation Rate
    float item = 10000.0f;
    
    //Process by mapping inputs to outputs
    savings(year, balance, item, infRate, nYears);
    
    //Output values
    prntAry(year, balance, nYears);
    
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void prntAry(int year[], float balance[], int n) {
    cout<<"Year Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for (int i = 0; i<n; i++) {
        cout<<setw(3)<<year[i]<<"  $"<<setw(10)<<balance[i]<<endl;
    }
    cout<<endl;
}

void savings(int y[], float b[], float p, float infRate, int nYears) {
    //Initialize array
    y[0]=0;
    b[0]=p;
    
    //Loop each year to fill the array
    for (int year = 1;year < nYears; year++) {
        y[year]=year;
        b[year]=b[year-1]*(1+infRate);
    }
    
}

