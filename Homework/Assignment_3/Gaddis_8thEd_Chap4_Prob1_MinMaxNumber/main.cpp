
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 12, 2017, 12:57 PM
 * Purpose: Homework identifying bigger/smaller number in two user input
 *      Problem: Write a program that asks the user to enter two numbers. The 
 * program should use the conditional operator to determine which number is the 
 * smaller and which is the larger. 
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
    float num1,       //Input first number
          num2;       //Input second number
    
    //Input Values
    cout<<"Let's compare two different numbers and see which is "<<endl
        <<"smaller and bigger!"<<endl<<endl;
    cout<<"Input first number: ";
    cin>>num1;
    cout<<"Input second number: ";
    cin>>num2;
    cout<<endl<<fixed<<setprecision(2);
    
    //Process by mapping inputs to outputs
    //& Output Values
    if (num1>num2) cout<<num1<<" is larger than "<<num2<<endl
                       <<num2<<" is smaller than "<<num1<<endl;
    else if(num2>num1) cout<<num2<<" is larger than "<<num1<<endl
                           <<num1<<" is smaller than "<<num2<<endl;
    else if(num2==num1) cout<<num1<<" and "<<num2<<" are the same numbers!"<<endl;
    else cout<<"Do it again!"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

