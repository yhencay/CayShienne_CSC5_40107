/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework Membership Fee Increase
 *      Problem: A country club, which currently charges $2,500 per year for 
 * membership, has announced it will increase its membership fee by 4% each year 
 * for the next six years. Write a program that uses a loop to display the 
 * projected rates for the next six years.
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
    float fee = 2500,          //Starting fee before it increase for the next five years
          inc = 0.04;          //Increase Percentage
    
    cout<<"       COUNTRY CLUB "<<endl<<endl;
    cout<<"    CURRENT FEE: $ "<<fee<<endl<<endl;
    cout<<"---------------------------\n"
        <<"      Yearly Increase\n"
        <<"---------------------------\n"<<endl;
    
    for (unsigned char yrs = 1; yrs <= 6; yrs++) {
        fee += (fee*inc);
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"    Year "<<static_cast<int>(yrs)<<":  $ "<<fee<<endl;
    }
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

