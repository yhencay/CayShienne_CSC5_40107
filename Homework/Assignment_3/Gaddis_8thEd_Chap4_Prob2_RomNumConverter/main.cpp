
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 12, 2017,  1:40 PM
 * Purpose: Homework Roman Numeral Converter
 *      Problem: Write a program that asks the user to enter a number within the range 
 * of 1 through 10. Use a switch statement to display the Roman numeral version 
 * of that number. Input Validation: Do not accept a number less than 1 or greater 
 * than 10.
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
    short input;                    //Input range from 1-10
    string roman;                     //Result of conversion
    
    //Input Values
    cout<<"Let's convert your number to roman numerals! "<<endl
        <<"You can only pick from 1 to 10!"<<endl<<endl;
    cout<<"What is your number? ";
    cin>>input;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    roman = (input == 1)?"I":
            (input == 2)?"II":
            (input == 3)?"III":
            (input == 4)?"IV":
            (input == 5)?"V":
            (input == 6)?"VI":
            (input == 7)?"VII":
            (input == 8)?"VIII":
            (input == 9)?"IX":
            (input == 10)?"X":
                "INVALID INPUT!";
    

    
    //Output values
    cout<<"The equivalent of number "<<input<<" in Roman Numeral is "<<roman<<endl;    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

