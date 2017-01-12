
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Homework Average of Values
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
    unsigned char one = 28,   //First given number
          two = 32,   //Second given number
          three = 37, //Third given number
          four = 24,  //Fourth given number
          five = 33,  //Fifth given number
          sum,        //Sum of the given numbers
          avrge;      //Average of the given numbers
    
    //Input Values
    
    //Process by mapping inputs to outputs
    sum = one+two+three+four+five;
    avrge = sum/5;
    //Output values
    cout<<"The sum of "<<static_cast<int>(one)<<", "<<static_cast<int>(two)
        <<", "<<static_cast<int>(three)<<", "<<static_cast<int>(four)<<", "
        <<static_cast<int>(five)<<" is "<<static_cast<int>(sum)<<endl;
    cout<<"The average of these numbers is "<<static_cast<int>(avrge)<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

