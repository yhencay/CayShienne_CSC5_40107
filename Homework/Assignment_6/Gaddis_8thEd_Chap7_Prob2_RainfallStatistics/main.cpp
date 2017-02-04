/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 12:58 PM
 * Purpose: Homework Rainfall Statistics
 * 
 *      Problem: Write a program that lets the user enter the total rainfall for 
 * each of 12 months into an array of doubles. The program should calculate and 
 * display the total rainfall for the year, the average monthly rainfall, and 
 * the months with the highest and lowest amounts.
 *          Input Validation: Do not accept negative numbers for monthly 
 *       rainfall figures.
 */

//System Libraries
#include <iostream>
#include <string>
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
    const int SIZE = 12;
    string months[] = {"January", "February", "March", "April",
                       "May", "June", "July", "August", "September",
                       "October", "November", "December" };
    float rFall[SIZE] = {};
    int count;
    
    cout<<"Input Rainfall for: "<<endl<<endl;
    
    for (count = 0; count < SIZE; count++) {
        cout<<months[count]<<": ";
        cin>>rFall[count];
    }
    
    cout<<endl;
    
    for (count = 0; count<SIZE;count++) {
        cout<<months[count]<<"\t\t"<<rFall[count]<<endl;
    }
    
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

