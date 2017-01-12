
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 5, 2017, 01:12 PM
 * Purpose: Free Fall
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const float GRAVITY = 3.2174e1f;

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float time,     //Time in seconds
          distnce; //Distance in feet
    int rndOff;
    
    //Input Values
    cout<<"This problem solves the distance traveled"<<endl;
    cout<<"in free fall under earth gravity"<<endl;
    cout<<"Input the time during Free-Fall in seconds"<<endl;
    cin>>time;
    cout<<"How many decimal places 0, 1, 2 or 3 for the answer?"<<endl;
    cin>>rndOff;
    
    //Process by mapping inputs to outputs
    distnce = GRAVITY*time*time/2;
    int id=distnce*pow(10, rndOff)+0.5; //Rounding to 2 decimals
    distnce=id/pow(10, rndOff);
    
    
    //Output values
    cout<<"The distance fallen = "<<distnce<<" ft"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

