
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 17, 2017, 12:12 PM
 * Purpose: Example Menu to be used in homework 
 */

//System Libraries
#include <iostream>     //Input Output Library
#include <cstdlib>      //Random number generator
#include <ctime>        //Time Library
#include <iomanip>      //Format Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void prob1();
void prob2();
void prob3();

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop on the menu
    do { 
        //Input Values    }
        cout<<"Choose from the list"<<endl;
        cout<<"Type 1 for Problem with Do-While"<<endl;
        cout<<"Type 2 for Problem with While"<<endl;
        cout<<"Type 3 for Problem with For"<<endl;
        cin>>choice;
        
        //Switch to determine problem
        switch (choice) {
            case '1': {
                prob1();
                break; 
            }            
            case '2': {
                prob2();
                break;
            }
            case '3': {
                prob3();
                break;
            }
            default: cout<<"You are exiting the program!"<<endl;
    } while (choice>='1' && choice <='3');
        
        
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Problem 1 ********************************************
//Description: What is the process, i.e. mapping from inputs to outputs
//Inputs:       datatypes, range/validity, units, descriptions
//Outputs:      datatypes, range/validity, units, descriptions
//******************************************************************************
void prob1() {
    cout<<"Inside Problem 1 function"<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Problem 2 ********************************************
//Description: What is the process, i.e. mapping from inputs to outputs
//Inputs:       datatypes, range/validity, units, descriptions
//Outputs:      datatypes, range/validity, units, descriptions
//******************************************************************************
void prob2() {
    cout<<"Inside Problem 2 function"<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Problem 3 ********************************************
//Description: What is the process, i.e. mapping from inputs to outputs
//Inputs:       datatypes, range/validity, units, descriptions
//Outputs:      datatypes, range/validity, units, descriptions
//******************************************************************************
void prob3() {
    cout<<"Inside Problem 3 function"<<endl;
}