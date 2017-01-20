
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017, 12:44 PM
 * Purpose: Homework Sum Of Numbers
 *      Problem: Write a program that asks the user for a positive integer value. 
 * The program should use a loop to get the sum of all the integers from 1 up to 
 * the number entered. For example, if the user enters 50, the loop will find the 
 * sum of 1, 2, 3, 4, … 50.  
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
    int numIn,         //User input of a positive integer
        sum = 0,           //Sum of all numbers to user input
        num = 1;       //Number starts from 1 to user input
    
    cout<<"Enter a positive Integer Number: ";
    cin>>numIn;
    cout<<endl;
    cout<<"Count\t"<<"\tSum"<<endl;
    
    do {
        if (numIn >= 1) {
            sum+=num;
            num++;
            cout<<num-1<<"\t\t"<<sum<<endl;
        }
        else {
            cout<<"Only enter a positive number!"<<endl;
        }
    } while (num <= numIn);
    
    if (numIn >= 1) cout<<"\nThe sum of "<<numIn<<" is "<<sum<<endl;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

