
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017, 12:31 PM
 * Purpose: Paycheck Calculation with Double time
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

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float rate,         //Input rate per hour
          hrs,          //Input hours worked
          payChck;      //Paycheck for work
    
    //Input Values
    cout<<"Input hours worked: ";
    cin>>hrs;    
    cout<<"Input your pay rate: ";
    cin>>rate;

    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    
    if (hrs > 40) {
        payChck = (40*rate) + (((hrs-40)*2)* rate);
        cout<<fixed<<setprecision(2)<<"Your salary is $ "<<payChck;
    }
    else {
        payChck = rate * hrs;
        cout<<fixed<<setprecision(2)<<"Your salary is $ "<<payChck;
    } 
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

