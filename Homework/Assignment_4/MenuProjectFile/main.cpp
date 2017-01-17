
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
        switch (choice){
            case '1': {
                cout<<"We are in Problem 1!"<<endl;
                break;
            }
            case '2': {                
                cout<<"We are in Problem 2!"<<endl;
                break;
            }
            case '3': {
                cout<<"We are in Problem 3!"<<endl;
                break;
            }
            default: cout<<"You are exiting the program!"<<endl;
        }
    } while (choice>='1' && choice <='3');
        
        
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

