/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 2, 2017, 10:47 AM
 * Purpose: Calculate Retirement with vectors
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const int COLS = 2;
//Function Prototypes
void savings(float [][COLS], float, float, float, int);
void prntAry(float [][COLS], int);


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {   
    //Declare Variables
    const int SIZE = 144;
    int nYears = SIZE/2 + 1;
    float balance[SIZE][COLS] = {};
    
    //Input Values
    float intRate=0.06f;
    float gift = 2.0e4f;
    float salary = 1.2e5f;
    float percSav = 0.15f;
    
    //Process by mapping inputs to outputs
    float savReq = salary/intRate;  //Savings Required
    float yDep = percSav*salary;
    
    savings(balance, gift, intRate, yDep, nYears);
    
    //Output values
    cout<<"Our Salary = $"<<salary<<endl;
    cout<<"Yearly Savings Deposit = $"<<yDep<<endl;
    cout<<"Savings Goal = $"<<savReq<<endl;
    prntAry(balance, nYears);
    
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void prntAry(float balance[][COLS], int n) {
    cout<<"Year Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for (int i = 0; i<n; i++) {
        cout<<setw(3)<<static_cast<int>(balance[i][0])<<"  $"<<setw(10)<<balance[i][1]<<endl;
    }
    cout<<endl;
}

void savings(float b[][COLS], float p, float intRate, float yDep, int nYears) {
    //Initialize array
    b[0][0]=0;      //Year in Column 1 which is index 0
    b[0][1] = p;    //Balance in column 2   which is index 1 

    //Loop each year to fill the array
    for (int year = 1;year < nYears; year++) {
        b[year][0]=year;
        b[year][1]=b[year-1][1]*(1+intRate);
        b[year][1]+=yDep;
    }
    
}

