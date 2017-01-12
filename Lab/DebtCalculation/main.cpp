
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 10, 2017, 01:00 PM
 * Purpose: Calculate Debt per Person using
 *          Given:
 *              US Population (2008) = 304 Million (http://www.multpl.com/united-states-population/table)
 *                            (2016) = 324 Million (http://www.worldometers.info/world-population/us-population/)
 *              US Federal Debt (2008) = 10 Trillion (http://www.polidiotic.com/by-the-numbers/us-national-debt-by-year/)
 *                              (2016) = 19.3 Trillion (http://www.polidiotic.com/by-the-numbers/us-national-debt-by-year/)
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
    long int usPopBe = 304e6,       //US Population 2008
             usPopNo = 324e6,       //US Population 2016
             usDebtB = 10e12,       //US Debt 2008
             usDebtN = 19.3e12;     ////US Debt 2016
    float befDebt, nowDebt;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    befDebt = (static_cast<float>(usDebtB)/usPopBe);
    nowDebt = (static_cast<float>(usDebtN)/usPopNo);
    
    //Output values
    cout<<"Here we calculate the debt per person in United States "<<endl
        <<"last 2008 versus 2016! "<<endl<<endl<<"----------------------------------------"<<endl
        <<"               2016 Report"<<endl<<"----------------------------------------"<<endl<<fixed
        <<"2008 US Population:     $      "<<usPopBe<<endl
        <<"2008 US Federal Debt:   $ "<<usDebtB<<endl
        <<"2016 US Population:     $      "<<usPopNo<<endl
        <<"2016 US Federal Debt:   $ "<<usDebtN<<endl<<endl;
    
    cout<<"The debt per person last 2008 is $ "<<setprecision(2)<<befDebt<<endl;
    cout<<"The debt per person last 2016 is $ "<<setprecision(2)<<nowDebt<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

