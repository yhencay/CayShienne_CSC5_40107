
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  6:41 PM
 * Purpose: Homework Distance Traveled
 *      Problem: The distance a vehicle travels can be calculated as follows:
 *                      distance = speed * time
 * For example, if a train travels 40 miles per hour for 3 hours, the distance 
 * traveled is 120 miles.
 * Write a program that asks the user for the speed of a vehicle (in miles per 
 * hour) and how many hours it has traveled. The program should then use a loop 
 * to display the distance the vehicle has traveled for each hour of that time 
 * period.
 *      What is the speed of the vehicle in mph? 40
 *      How many hours has it traveled? 3
 *  Hour        Distance Traveled
 * --------------------------------
 *   1                40
 *   2                80
 *   3               120
 * Input Validation: Do not accept a negative number for speed and do not accept 
 * any value less than 1 for time traveled.
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
    int spdIn,              //User input for speed 
        hrsTrv,             //User input for hours traveled
        dstnce;             //Distance per mile
    
    cout<<"Calculate the distance you traveled by entering the hours and speed for your travel!\n"
        <<"REMINDER: Minimum of hours input is 1 and no '0' for speed. Doing otherwise will get you an INVALID INPUT!"
        <<endl<<endl;
    cout<<"What is the speed of your vehicle in mph? ";
    cin>>spdIn;
    cout<<"How many hours has it traveled? ";
    cin>>hrsTrv;
    cout<<endl;
    
    if ((hrsTrv >= 1) && (spdIn > 0)) {
        
        cout<<"Hour\t  Distance Traveled\n"
            <<"----------------------------------\n";
        
        for (int hrs = 1; hrs <= hrsTrv; hrs++) {
            dstnce = spdIn * hrs;
            cout<<hrs<<"\t\t"<<dstnce<<endl;
        }
    }
    else {
        cout<<"INVALID INPUT!"<<endl;
    }

    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

