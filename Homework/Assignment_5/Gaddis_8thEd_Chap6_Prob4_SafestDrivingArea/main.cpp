/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 9:48 PM
 * Purpose: Homework Safest Driving Area
 * 
 *      Problem: Write a program that determines which of five geographic 
 * regions within a major city (north, south, east, west, and central) had the 
 * fewest reported automobile accidents last year. It should have the following 
 * two functions, which are called by main.
 *  • int getNumAccidents() is passed the name of a region. It asks the user for 
 * the number of automobile accidents reported in that region during the last 
 * year, validates the input, then returns it. It should be called once for each 
 * city region.
 *  • void findLowest() is passed the five accident totals. It determines which 
 * is the smallest and prints the name of the region, along with its accident 
 * figure. 
 *      Input Validation: Do not accept an accident number that is less than 0.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int axident();                        //Input number of accidents per region
void lwstP4(int, int, int, int, int);   //Calculate and display lowest number of accidents

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nr, sr, wr, er, cr;         //North Region, South Region, West Region, East Region and Central Region
    
    //Input Values
    cout<<"North Region"<<endl;
    nr = axident();                 //Prompt user to input data per region
    cout<<"South Region"<<endl;     //which are passed by axident function
    sr = axident();
    cout<<"West Region"<<endl;
    wr = axident();
    cout<<"East Region"<<endl;
    er = axident();
    cout<<"Central Region"<<endl;
    cr = axident();
  
    //Process by mapping inputs to outputs
    //Output values
    cout<<"North Region: "<<setw(7)<<nr<<endl;
    cout<<"South Region: "<<setw(7)<<sr<<endl;
    cout<<"West Region: "<<setw(8)<<wr<<endl;       //Display input values
    cout<<"East Region: "<<setw(8)<<er<<endl;
    cout<<"Central Region: "<<setw(5)<<cr<<endl;
    cout<<endl;
    
    lwstP4(nr, sr, wr, er, cr);         //Display result
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//******************** Getting Number of Accidents *****************************
//Description: Get user input for reported number of accidents
//Inputs:   int - input must not be less than 0
//Outputs:  Input validation - only if input is invalid
//******************************************************************************

int axident() {
    int axident;
    cout<<"Reported Number of Accidents: ";
    cin>>axident;                           //User input per region
    cout<<endl;
    
    while (axident < 0) {                   //Loop until data entered is greater than or equal to 0
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Reported Number of Accidents: ";
        cin>>axident;
        cout<<endl;
    }    
    return axident;         //return values to each region in main
}

//************************** Safe Driving Area *********************************
//Description: Determine region lowest number of reported accidents 
//Inputs:   No inputs but uses value passed by axident function
//Outputs:  Output the safest driving area along with its reported number of
//      accidents.
//******************************************************************************

void lwstP4(int a, int b, int c, int d, int e) {
    int lowest = a;
    string nr = "North Region",             //Assigned string to regions
           sr = "South Region", 
           wr = "West Region", 
           er = "East Region",
           cr = "Central Region";
    
    lowest = (b<lowest)?b:lowest;
    lowest = (c<lowest)?c:lowest;       //Compare eache value to determine lowest
    lowest = (d<lowest)?d:lowest;
    lowest = (e<lowest)?e:lowest;
   
    cout<<"The safest driving area is ";
    if (lowest == a)cout<<nr;               //Output lowest number of accidents with its area
    if (lowest == b)cout<<sr;
    if (lowest == c)cout<<wr;
    if (lowest == d)cout<<er;
    if (lowest == e)cout<<cr;
    
    cout<<" with only "<<lowest<<" number of reported accidents!"<<endl;
}

