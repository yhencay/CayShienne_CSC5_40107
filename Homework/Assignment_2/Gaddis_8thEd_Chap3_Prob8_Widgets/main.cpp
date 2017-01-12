
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017,  7:24 PM
 * Purpose: Homework Calculate Widget Count
 *      Problem: The Yukon Widget Company manufactures widgets that weigh 12.5 
 * pounds each. Write a program that calculates how many widgets are stacked on 
 * a pallet, based on the total weight of the pallet. The program should ask the 
 * user how much the pallet weighs by itself and with the widgets stacked on it. 
 * It should then calculate and display the number of widgets stacked on the pallet. 
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
    float widget = 12.5f,   //Weight of each widget in pounds
          totWght,          //User input of pallet's total weight
          numWidg;          //Number of each widget in a pallet
    
    //Input Values
    cout<<"Let's figure out how many widget there are in a pallet!"<<endl<<endl;
    cout<<"How much does the pallet weigh (in lbs.)? ";
    cin>>totWght;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    numWidg = totWght/widget;
    
    //Output values
    cout<<fixed<<setprecision(2);
    cout<<"There are "<<numWidg<<" widget(s) in a "<<totWght<<" pound(s) pallet!"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

