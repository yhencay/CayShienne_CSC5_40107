
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 4, 2017, 12:13 PM
 * Purpose: Stock Calculation
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const unsigned char PERCENT=100; //Conversion to percent

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    unsigned char stkPrce = 35; //Units of $'s/share
    unsigned short nShares = 750; //Number of Shares
    unsigned char comishn = 2; //Percent Commission
    unsigned short stkPaid, comPaid, totPaid;
    //Input Values
    
    //Process by mapping inputs to outputs
    
    stkPaid=stkPrce*nShares; //Amount paid for the Stock Purchases
    comPaid=stkPaid*comishn/PERCENT; //Commission on Stock Purchases
    totPaid=stkPaid+comPaid; // Total Paid $'s
    
    //Output values
    
    cout<<"Stock Price/Share = $    "<<static_cast<int>(stkPrce)<<"/share"<<endl;
    cout<<"Number of Shares  =     "<<nShares<<" shares"<<endl;
    cout<<"Commission        =       "<<static_cast<int>(comishn)<<"%\n"<<endl;
    cout<<"Stock Price Paid  = $ "<<stkPaid<<endl;
    cout<<"Commission Paid   = $   "<<comPaid<<endl;
    cout<<"Total Paid        = $ "<<totPaid<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

