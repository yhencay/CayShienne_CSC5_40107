/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 12:58 PM
 * Purpose: Homework Markup
 * 
 *      Problem: Write a program that asks the user to enter an item’s wholesale 
 * cost and its markup percentage. It should then display the item’s retail price. 
 * For example:
 *      • If an item’s wholesale cost is 5.00 and its markup percentage is 100%, 
 * then the item’s retail price is 10.00.
 *      • If an item’s wholesale cost is 5.00 and its markup percentage is 50%, 
 * then the item’s retail price is 7.50.
 *   The program should have a function named calculateRetail that receives the
 * wholesale cost and the markup percentage as arguments and returns the retail 
 * price of the item.
 *   Input Validation: Do not accept negative values for either the wholesale 
 * cost of the item or the markup percentage.
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
const short PERCENT = 100; //Percentage conversion

//Function Prototypes
float calRt8l(float, float);        //Calculate Retail

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float cost, markup;     //Cost value and markup percentage
    
    //Input Values
    cout<<"Enter wholesale cost: $";
    cin>>cost;                              //Prompt user to input values
    while (cost < 0) {                      //Wholesale cost and Markup percentage
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter wholesale cost: $";        //Loop each prompt until input is valid
        cin>>cost;
    }
    cout<<"Enter markup percentage: ";
    cin>>markup;
    while (markup < 0) {
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter markup percentage: ";
        cin>>markup;
    }
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    cout<<endl;
    cout<<"The whole sale cost is $"<<cost<<endl;
    cout<<"The markup percentage is "<<markup<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The cost of the item now is $"<<calRt8l(cost, markup)<<endl;         //Display value returned by calRt8l
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//********************** Calculate Markup Amount *******************************
//Description: Calculate the markup amount based on markup percentage and add it
//          to the original cost
//Inputs:   No inputs but utilizes values from main to calculate final cost
//Outputs:  No outputs but return the value of the final cost with markup amount
//      added to original cost
//******************************************************************************

float calRt8l(float cost, float markup) {
    float answer, add;
    
    add = cost*(markup/PERCENT);        //Calculate markup amount
    answer = cost+add;                  //Add markup amount to original cost
    
    return answer;      //Return result
}
