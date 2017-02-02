/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 10:44 PM
 * Purpose: Homework Celsius Temperature Table
 * 
 *      Problem: The formula for converting a temperature from Fahrenheit to 
 * Celsius is C = 5/9 (F-32).
 * where F is the Fahrenheit temperature and C is the Celsius temperature. Write 
 * a function named celsius that accepts a Fahrenheit temperature as an argument. 
 * The function should return the temperature, converted to Celsius. Demonstrate 
 * the function by calling it in a loop that displays a table of the Fahrenheit 
 * temperatures 0 through 20 and their Celsius equivalents.
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
float celsius(short);       //Celsius Table

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables  
    //Input Values    
    //Process by mapping inputs to outputs
    
    cout<<fixed<<setprecision(2)<<showpoint;        //Display celsius to farenheit conversion table from 0-20
    cout<<"-----------------------"<<endl;
    cout<<"Farenheit\tCelsius"<<endl;
    cout<<"-----------------------"<<endl;
    for (short frnhyt = 0; frnhyt <= 20; frnhyt++) {        //Loop to display calculation
        cout<<frnhyt<<"\t\t"<<celsius(frnhyt)<<endl;
    }
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//******************* Farenheit to Celsius Conversion **************************
//Description: Convert 0-20 degree farenheit to celsius
//Inputs:   No inputs but utilizes values from the loop in main to calculate
//      temperature conversion
//Outputs:  No outputs but return the value of the conversion
//******************************************************************************

float celsius(short frnhyt) {       //Calculation of farenheit to celsius
    float celsius;
            
    celsius = 5*(static_cast<float>(frnhyt)-32)/9;
    
    return celsius;
}
