
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 15, 2017, 11:16 PM
 * Purpose: Homework Time Calculator
 *      Problem: Write a program that asks the user to enter a number of seconds.
 *          • There are 60 seconds in a minute. If the number of seconds entered 
 * by the user is greater than or equal to 60, the program should display the 
 * number of minutes in that many seconds.
 *          • There are 3,600 seconds in an hour. If the number of seconds 
 * entered by the user is greater than or equal to 3,600, the program should 
 * display the number of hours in that many seconds.
 *          • There are 86,400 seconds in a day. If the number of seconds 
 * entered by the user is greater than or equal to 86,400, the program should 
 * display the number of days in that many seconds.
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
    float numSec,       //Number of seconds user input
          numMin,       //Number of minutes per 60 seconds
          numHrs,       //Number of hours per 3600 seconds
          numDays;      //Number of days per 86400 seconds
    
    //Input Values
    cout<<"Let's calculate how many minutes, hours or days are there in user\n"
        <<"input's number of seconds! Reminder: Entering a negative number will\n"
        <<"give you an INVALID INPUT result."<<endl<<endl;
    cout<<"Enter Number of Seconds: ";
    cin>>numSec;
    cout<<endl<<fixed<<setprecision(1);
    
    //Process by mapping inputs to outputs
    //Output values
    if ((numSec >= 60) && (numSec < 3600)) {
        numMin = numSec/60;
        cout<<"There is/are "<<numMin<<" minute(s) in "<<numSec<<" second(s).\n";
    }
    else if ((numSec >= 3600) && (numSec < 86400)) {
        numHrs = numSec/3600;
        cout<<"There is/are "<<numHrs<<" hour(s) in "<<numSec<<" second(s).\n";
    }
    else if (numSec >= 86400) {
        numDays = numSec/3600;
        cout<<"There is/are "<<numDays<<" day(s) in "<<numSec<<" second(s).\n";
    }
    else if ((numSec >= 0) && (numSec < 60)) {
        cout<<"You entered "<<numSec<<" second(s). It's not enough to complete a whole minute!\n";
    }
    else {
        cout<<"INVALID INPUT!\n";
    }
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

