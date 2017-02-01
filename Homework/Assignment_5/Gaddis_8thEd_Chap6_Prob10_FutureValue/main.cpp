/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:15 AM
 * Purpose: Homework Future Value
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT = 100; //Percentage conversion

//Function Prototypes
float futVal(float, float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float presVal, mRate, nMonth;

    //Input Values
    cout<<"Enter Present Value: $";
    cin>>presVal;
    cout<<"Enter Monthly Interest Rate: ";
    cin>>mRate;
    cout<<"Enter Number of Months: ";
    cin>>nMonth;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    cout<<"Present Value Amount:\t $"<<presVal<<endl;
    cout<<"Monthly Interest Rate:\t "<<mRate<<"%"<<endl;
    cout<<"Number of Months:\t "<<nMonth<<" months"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The account's future value is $"<<futVal(presVal, mRate, nMonth)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float futVal(float presVal, float mRate, float nMonth) {
    float futVal;
    
    mRate /= PERCENT;
    futVal = presVal*pow(1+mRate, nMonth);
    
    return futVal;
}
