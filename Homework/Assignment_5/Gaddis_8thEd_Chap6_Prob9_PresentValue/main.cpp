/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 1:17 AM
 * Purpose: Homework Present Value
 * 
 *      Problem: Suppose you want to deposit a certain amount of money into a 
 * savings account and then leave it alone to draw interest for the next 10 
 * years. At the end of 10 years you would like to have $10,000 in the account. 
 * How much do you need to deposit today to make that happen? You can use the 
 * following formula, which is known as the present value formula, to find out:
 *          P =  F / (1 + r)^n
 *      The terms in the formula are as follows:
 *  • P is the present value , or the amount that you need to deposit today.
 *  • F is the future value that you want in the account. (In this case, F is 
 * $10,000.)
 *  • r is the annual interest rate .
 *  • n is the number of years that you plan to let the money sit in the account.
 *  Write a program that has a function named presentValue that performs this 
 * calculation. The function should accept the future value, annual interest 
 * rate, and number of years as arguments. It should return the present value, 
 * which is the amount that you need to deposit today. Demonstrate the function 
 * in a program that lets the user experiment with different values for the 
 * formula’s terms.
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT = 100; //Percentage conversion

//Function Prototypes
float presVal(float, float, float); //Present Value

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float futVal, rate, numYear;        //Future Value, Annual Rate, Number of Years

    //Input Values
    cout<<"Enter Future Value: $";          //User input for future value, annual rate,
    cin>>futVal;                            //number of years
    cout<<"Enter Annual Interest Rate: ";
    cin>>rate;
    cout<<"Enter Number of Years: ";
    cin>>numYear;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;                                                 //Display user input
    cout<<"Future Value Desired:\t $"<<futVal<<endl;
    cout<<"Annual Interest Rate:\t "<<rate<<"%"<<endl;
    cout<<"Number of Years:\t "<<numYear<<" years"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The amount you need to deposit is $"<<presVal(futVal, rate, numYear)<<endl;      //Display result from function
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//********************** Calculate Present Value *******************************
//Description: Calculate the present value based on user input of given in the
//      formula for Present Value.
//Inputs:   No inputs but utilizes values from main to calculate present value
//Outputs:  No outputs but return the value of the calculated present value.
//******************************************************************************

float presVal(float futVal, float rate, float numYear) {
    float presVal;                          
    
    rate /= PERCENT;                            //Calculate present value
    presVal = futVal/pow(1+rate, numYear);
    
    return presVal;
}
