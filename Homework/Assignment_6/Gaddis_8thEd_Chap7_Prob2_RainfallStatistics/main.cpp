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
 * 
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
    const int SIZE = 12;            //Size for array
    string months[] = {"January", "February", "March", "April",         //Assign values for string array
                       "May", "June", "July", "August", "September",
                       "October", "November", "December" };
    string high, low;               //String to display which has highest and lowest rainfall for month
    float rFall[SIZE] = {};         //Array for rainfall
    int count;                      //Loop counter
    float total = 0, average;       //Variable for total and average rainfall

    //Input Values    
    cout<<"Input Rainfall for: "<<endl<<endl;           //Prompt user to input rainfall for each month 
    
    for (count = 0; count < SIZE; count++) {
        do {
            cout<<months[count]<<": ";                  //Loop if user input is less than 0
            cin>>rFall[count];
            if (rFall[count] < 0) cout<<"\nNo negative numbers allowed. Try again!\n"<<endl;
        } while (rFall[count] < 0);
        total += rFall[count];                  //Add input to total rainfall
    }
    
    //Process by mapping inputs to outputs
    average = total/12;                         //Caluclate average
    
    float highest = 0;
    for (count = 0;count < SIZE; count++) {     //Determine highest value by comparing each
        if (rFall[count]>highest) {             //array stored value
            highest = rFall[count];
            high = months[count];
        }
    }
    
    float lowest = highest;    
    for (count = 0;count < SIZE; count++) {     //Determine lowest value by comparing each
        if (rFall[count]<lowest) {              //array stored value
            lowest = rFall[count];
            low = months[count];
        }
    }
    
    //Output values
    cout<<endl<<fixed<<setprecision(2);
    cout<<"MONTHS\t\tRAINFALL"<<endl;               //Display user input
    cout<<"------------------------"<<endl;
    
    for (count = 0; count<SIZE;count++) {        
        if (count == 1) cout<<months[1]<<"\t"<<rFall[1]<<endl;
        else if (count == 8) cout<<months[8]<<"\t"<<rFall[8]<<endl;         
        else if (count == 10) cout<<months[10]<<"\t"<<rFall[10]<<endl;
        else if (count == 11) cout<<months[11]<<"\t"<<rFall[11]<<endl;
        else cout<<months[count]<<"\t\t"<<rFall[count]<<endl;
    }
    
    cout<<"\nThe total rainfall for the year is "<<total<<endl;
    cout<<"The average monthly rainfall is "<<average<<endl<<endl;          //Display results
    cout<<"HIGHEST: "<<highest<<", "<<high<<endl;                           //Total, Average, Highest and Lowest
    cout<<"LOWEST: "<<lowest<<", "<<low<<endl;
       
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

