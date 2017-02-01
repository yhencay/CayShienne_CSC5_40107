/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 10:44 PM
 * Purpose: Homework Celsius Temperature Table
 *      Problem: 
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
float celsius(short);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"--------------------------------------"<<endl;
    cout<<"Farenheit\tCelsius"<<endl;
    cout<<"--------------------------------------"<<endl;
    for (short frnhyt = 0; frnhyt <= 20; frnhyt++) {
        cout<<frnhyt<<"\t\t"<<celsius(frnhyt)<<endl;
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float celsius(short frnhyt) {
    float celsius;
    
    celsius = 5*(static_cast<float>(frnhyt)-32)/9;
    
    return celsius;
}
