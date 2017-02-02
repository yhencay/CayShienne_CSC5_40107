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

//Function Prototypes
void savings(vector<int> &, vector<float> &, float, float, float, int);
void prntAry(vector<int> &, vector<float> &, int);
void find(vector<int> &, vector <float> &, int, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {   
    //Declare Variables
    const int SIZE = 144;
    int nYears = SIZE/2 + 1;
    vector<int> year(SIZE); //Initialize the entire array to 0
    vector<float> balance(SIZE);
    
    //Input Values
    float intRate=0.06f;
    float gift = 2.0e4f;
    float salary = 1.2e5f;
    float percSav = 0.15f;
    
    //Process by mapping inputs to outputs
    float savReq = salary/intRate;  //Savings Required
    float yDep = percSav*salary;
    
    savings(year, balance, gift, intRate, yDep, nYears);
    
    //Output values
    cout<<"Our Salary = $"<<salary<<endl;
    cout<<"Yearly Savings Deposit = $"<<yDep<<endl;
    cout<<"Savings Goal = $"<<savReq<<endl;
    prntAry(year, balance, nYears);
    
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void find(vector<int> &year, vector<float> &balance, int n, int val) {
    for (int i = 1; i<=n; i++) {
        if (year[i]==val) {
            cout<<"Found val = "<<val<<"where balance = $ "<<balance<<endl;
        }
    }
}

void prntAry(vector<int> &year, vector<float> &balance, int n) {
    cout<<"Year Balance"<<endl;
    cout<<fixed<<setprecision(2);
    for (int i = 0; i<n; i++) {
        cout<<setw(3)<<year[i]<<"  $"<<setw(10)<<balance[i]<<endl;
    }
    cout<<endl;
}

void savings(vector<int> &y, vector<float> &b, float p, float intRate, float yDep, int nYears) {
    //Initialize array
    y[0]=0;
    b[0]=p;
    
    //Loop each year to fill the array
    for (int year = 1;year < nYears; year++) {
        y[year]=year;
        b[year]=b[year-1]*(1+intRate);
        b[year]+=yDep;
    }
    
}

