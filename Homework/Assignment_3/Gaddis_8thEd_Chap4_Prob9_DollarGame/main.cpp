
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 16, 2017, 12:32 PM
 * Purpose: Homework Change for a Dollar
 *      Problem: Create a change-counting game that gets the user to enter the 
 * number of coins required to make exactly one dollar. The program should ask 
 * the user to enter the number of pennies, nickels, dimes, and quarters. If the 
 * total value of the coins entered is equal to one dollar, the program should 
 * congratulate the user for winning the game. Otherwise, the program should 
 * display a message indicating whether the amount entered was more than or less 
 * than one dollar.
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
    const float penny = 0.01,       //Coins equivalent value
                nickel = 0.05,
                dime = 0.10,
                quart = 0.25;
    unsigned short numPen,          //User input
                   numNic,
                   numDim,
                   numQrt;
    float total;                    //Total value of coins input
    
    //Input Values
    cout<<"This is a Change for a Dollar Game!\n"
        <<"The objective of the game is to enter a specific number of coins to make exactly a dollar. \n"
        <<"User will be prompted to input the number of pennies, nickels, dimes, and quarters he/she has in mind.\n"
        <<"\nReminder: You cannot enter a negative number and a decimal number. \nDoing so will result to an ERROR and inaccurate and immediate result!!\n"
        <<endl;
    cout<<"Pennies: ";
    cin>>numPen;
    cout<<"Nickels: ";
    cin>>numNic;
    cout<<"Dimes: ";
    cin>>numDim;
    cout<<"Quarters: ";
    cin>>numQrt;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    total = (penny*numPen) + (nickel*numNic) + (dime*numDim) + (quart*numQrt);
    
    //Output values
    if (total == 1) cout<<"The total is: $ "<<total<<"\nCongratulations! You won!\n";
    else if ((total < 1) && (total > 0)) cout<<"The total is: $ "<<total<<"\nSorry, it is less than a dollar!\n";
    else if (total > 1) cout<<"The total is: $ "<<total<<"\nSorry, it is greater than a dollar!\n";
    else cout<<"ERROR! INVALID INPUT\n";
 
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

