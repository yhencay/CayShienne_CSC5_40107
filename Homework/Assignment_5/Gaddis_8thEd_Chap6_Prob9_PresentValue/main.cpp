/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 1:17 AM
 * Purpose: Homework Present Value
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
float presVal(float, float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float futVal, rate, numYear;

    //Input Values
    cout<<"Enter Future Value: $";
    cin>>futVal;
    cout<<"Enter Annual Interest Rate: ";
    cin>>rate;
    cout<<"Enter Number of Years: ";
    cin>>numYear;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    cout<<"Future Value Desired:\t $"<<futVal<<endl;
    cout<<"Annual Interest Rate:\t "<<rate<<"%"<<endl;
    cout<<"Number of Years:\t "<<numYear<<" years"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The amount you need to deposit is $"<<presVal(futVal, rate, numYear)<<endl;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float presVal(float futVal, float rate, float numYear) {
    float presVal;
    
    rate /= PERCENT;
    presVal = futVal/pow(1+rate, numYear);
    
    return presVal;
}
