
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 10, 2017, 11:21 PM
 * Purpose: Homework Box Office
 *     Problem: A movie theater only keeps a percentage of the revenue earned from ticket sales.
 *          The remainder goes to the movie distributor. Write a program that calculates a theater’s
 *          gross and net box office profit for a night. The program should ask for the name of the
 *          movie, and how many adult and child tickets were sold. (The price of an adult ticket is
 *          $10.00 and a child’s ticket is $6.00.) It should display a report similar to
 *                 Movie Name:                    “Wheels of Fury”
 *                 Adult Tickets Sold:                  382
 *                 Child Tickets Sold:                  127
 *                 Gross Box Office Profit:          $ 4582.00
 *                 Net Box Office Profit:             $ 916.40
 *                 Amount Paid to Distributor:       $ 3665.60
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    string movie;                   //Movie title Input
    unsigned char adPrice = 10,     //Ticket price for adult
                  chPrice = 6;      //Ticket price for a child
    unsigned short adltSld,         //Number of adult ticket sold
                   chldSld;         //Number of child ticket sold
    int gboProf;                    //Gross Box Office Profit
    float netBox,                   //Net Box Office Profit
          pdAmnt;                   //Amount Paid to Distributer
    
    //Input Values
    cout<<"What is the name of the movie? ";
    getline(cin, movie);
    cout<<"How many adult tickets were sold? ";
    cin>>adltSld;
    cout<<"How many child tickets were sold? ";
    cin>>chldSld;
    
    //Process by mapping inputs to outputs
    gboProf = (adltSld*static_cast<int>(adPrice)) + (chldSld*static_cast<int>(chPrice));
    netBox = gboProf * 0.20;
    pdAmnt = gboProf - netBox;
    
    //Output values
    cout<<endl<<fixed<<setprecision(2);
    cout<<"Movie Name:                       "<<"\""<<movie<<"\""<<endl;
    cout<<"Adult Tickets Sold: "<<setw(20)<<adltSld<<endl;
    cout<<"Child Tickets Sold: "<<setw(20)<<chldSld<<endl;
    cout<<"Gross Box Office Profit:  "<<setw(10)<<"$ "<<right<<setw(3)<<static_cast<float>(gboProf)<<endl;
    cout<<"Net Box Office Profit:  "<<setw(12)<<"$ "<<right<<setw(3)<<netBox<<endl;
    cout<<"Amount Paid to Distributor:  "<<setw(7)<<"$ "<<right<<setw(3)<<pdAmnt<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

