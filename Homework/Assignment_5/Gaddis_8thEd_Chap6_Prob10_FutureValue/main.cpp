/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:15 AM
 * Purpose: Homework Future Value
 * 
 *      Problem: Suppose you have a certain amount of money in a savings account 
 * that earns compound monthly interest, and you want to calculate the amount 
 * that you will have after a specific number of months. The formula, which is 
 * known as the future value formula, is:
 *          F = P x (1 + i)^t
 * The terms in the formula are as follows:
 *  • F is the future value of the account after the specified time period.
 *  • P is the present value of the account.
 *  • i is the monthly interest rate.
 *  • t is the number of months .
 *  Write a program that prompts the user to enter the account’s present value, 
 * monthly interest rate, and the number of months that the money will be left 
 * in the account. The program should pass these values to a function named 
 * futureValue that returns the future value of the account, after the specified 
 * number of months. The program should display the account’s future value.
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
float futVal(float, float, float);      //Function to determine future value

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float presVal, mRate, nMonth;       //Present Value, Monthly Rate, Number of Months

    //Input Values
    cout<<"Enter Present Value: $";             //Prompt user to enter values needed
    cin>>presVal;                               //to output answer
    cout<<"Enter Monthly Interest Rate: ";
    cin>>mRate;
    cout<<"Enter Number of Months: ";
    cin>>nMonth;
    
    //Process by mapping inputs to outputs    
    //Output values
    cout<<endl;
    cout<<"Present Value Amount:\t $"<<presVal<<endl;           //Display values entered
    cout<<"Monthly Interest Rate:\t "<<mRate<<"%"<<endl;
    cout<<"Number of Months:\t "<<nMonth<<" months"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The account's future value is $"<<futVal(presVal, mRate, nMonth)<<endl; //Call futVal function to return calculation
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//*********************** Future Value Calculator ******************************
//Description: Calculate future value based on the formula given
//Inputs:  Passed to function futVal from main - float values
//Outputs:  Future value amount
//******************************************************************************

float futVal(float presVal, float mRate, float nMonth) {
    float futVal;
    
    mRate /= PERCENT;                           //Calculation of future value
    futVal = presVal*pow(1+mRate, nMonth);
    
    return futVal;
}
