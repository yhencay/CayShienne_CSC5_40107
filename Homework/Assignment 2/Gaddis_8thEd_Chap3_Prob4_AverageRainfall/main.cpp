
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 9, 2017, 01:24 PM
 * Purpose: Homework Average Rainfall
 */

//System Libraries
#include <iostream>
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
    char frsMnth[9],       //Name of first month
         scdMnth[9],       //Name of second month
         thdMnth[9];       //Name of third month
    float one,          //First month's amount of rain
          two,          //Second month's amount of rain
          three,        //Third month's amount of rain
          avrge;        //Average rainfall of three months put in
            
    //Input Values
    cout<<"Let's calculate the average rainfall for three months!"<<endl<<endl;
    cout<<"Enter the name of the 1st month: ";
    cin>>frsMnth;
    cout<<"Enter the name of the 2nd month: ";
    cin>>scdMnth;
    cout<<"Enter the name of the 3rd month: ";
    cin>>thdMnth;
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

