
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 9, 2017, 01:24 PM
 * Purpose: Homework Average Rainfall
 *      Problem: Write a program that calculates the average rainfall for three 
 * months. The program should ask the user to enter the name of each month, such
 * as June or July, and the amount of rain (in inches) that fell each month. The
 * program should display a message similar to the following:
 * 
 *      The average rainfall for June, July, and August is 6.72 inches.
 */

//System Libraries
#include <iostream>
#include <string>
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
    string frsMnth,       //Name of first month
           scdMnth,       //Name of second month
           thdMnth;       //Name of third month
    float one,          //First month's amount of rain
          two,          //Second month's amount of rain
          three,        //Third month's amount of rain
          avrge;        //Average rainfall of three months put in
            
    //Input Values
    cout<<"Let's calculate the average rainfall for three months!"<<endl<<endl;
    cout<<"Enter the name of the 1st month: ";
    getline(cin, frsMnth);
    cout<<"Enter the name of the 2nd month: ";
    getline(cin, scdMnth);
    cout<<"Enter the name of the 3rd month: ";
    getline(cin, thdMnth);
    cout<<endl;
    
    cout<<"How much rainfall is there on "<<frsMnth<<"? ";
    cin>>one;
    cout<<"How much rainfall is there on "<<scdMnth<<"? ";
    cin>>two;    
    cout<<"How much rainfall is there on "<<thdMnth<<"? ";
    cin>>three; 
    cout<<endl;
    
    //Process by mapping inputs to outputs
    avrge = (one+two+three)/3;
    
    //Output values
    cout<<"The average rainfall for "<<frsMnth<<", "<<scdMnth<<", and "<<thdMnth
        <<" is "<<avrge<<" inches."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

