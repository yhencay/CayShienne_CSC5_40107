
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 16, 2017, 2:19 PM
 * Purpose: Homework Mobile Service Provider
 *      Problem: A mobile phone service provider has three different 
 * subscription packages for its customers:
 *    Package A: For $39.99 per month 450 minutes are provided. Additional 
 * minutes are $0.45 per minute.
 *    Package B: For $59.99 per month 900 minutes are provided. Additional 
 * minutes are $0.40 per minute.
 *    Package C: For $69.99 per month unlimited minutes provided.
 * Write a program that calculates a customer’s monthly bill. It should ask 
 * which package the customer has purchased and how many minutes were used. It 
 * should then display the total amount due.
 *  Input Validation: Be sure the user only selects package A, B, or C.
 */

//System Libraries
#include <iostream>
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
    const float packA = 39.99f,     //Amount per package
                packB = 59.99F,
                packC = 69.99f;
    int minUsed;                    //User input for minutes used
    char package;                   //Purchased package
    float bill;                     //Monthly bill of customer
    
    //Input Values
    cout<<"Let's calculate your monthly bill based on the Package you purchased with\n"
        <<"with your Mobile Service Provider."<<endl<<endl;
    cout<<"Package A: For $39.99 per month 450 minutes are provided. \n"
        <<"     Additional minutes are $0.45 per minute.\n"<<endl;
    cout<<"Package B: For $59.99 per month 900 minutes are provided. \n"
        <<"     Additional minutes are $0.40 per minute.\n"<<endl;
    cout<<"Package C: For $69.99 per month unlimited service provided. \n"
        <<endl;
    cout<<"REMINDER: Minutes are calculated as whole numbers. Decimal and negative \n"
        <<"input will give an error or result in a program crash!"<<endl<<endl;
    cout<<"How many minutes have you used up this month? ";
    cin>>minUsed;
    cout<<"Which package did you purchase? ";
    cin>>package;
    cout<<endl;
    
    //Process by mapping inputs to outputs    
    //Output values
    if (minUsed >= 0) {
    switch (package) {
        case 'a':
        case 'A': if (minUsed>450){
            bill = ((minUsed-450)* 0.45)+packA;
            cout<<"Because you have exceeded "<<minUsed-450<<" minutes, your total bill is $ "<<bill<<endl;
        }
        else cout<<"You have not exceeded the provided limit. Your total bill is $ "<<packA<<endl;
        break;
        
        case 'b':
        case 'B': if (minUsed>900){
            bill = ((minUsed-900)* 0.40)+packB;
            cout<<"Because you have exceeded "<<minUsed-900<<" minutes, your total bill is $ "<<bill<<endl;
        }
        else cout<<"You have not exceeded the provided limit. Your total bill is $ "<<packB<<endl;
        break;
        
        case 'c':
        case 'C': cout<<"You purchased the unlimited package. Your total bill is $ "<<packC<<endl;
        break;
        
        default: cout<<"You can only choose from Package A, B, C!"<<endl;
    }
    }
    else cout<<"ERROR! INVALID INPUT!"<<endl;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

