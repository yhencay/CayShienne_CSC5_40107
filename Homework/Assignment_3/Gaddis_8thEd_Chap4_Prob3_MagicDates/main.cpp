
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 14, 2017, 11:03 PM
 * Purpose: Homework Magic Dates
 *      Problem: The date June 10, 1960 is special because when we write it in 
 * the following format, the month times the day equals the year.
 *              6/10/60
 * Write a program that asks the user to enter a month (in numeric form), a day, 
 * and a two-digit year. The program should then determine whether the month 
 * times the day is equal to the year. If so, it should display a message saying 
 * the date is magic. Otherwise it should display a message saying the date is 
 * not magic.
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
    unsigned short month,       //Month user input
                   day,         //Day user input
                   year,        //Year user input
                   factor;      //month & Day multiplied
    string result;                //Determine if it's a magic date
    
    //Input Values
    cout<<"Let's determine if the date you put in is a magic date!"<<endl
        <<"Type the month (1-12) and day (1-31) in numeric form."<<endl
        <<"Type the year in two-digit form. ex. 1996 = 96"<<endl<<endl;
    cout<<"Enter Month: ";
    cin>>month;
    cout<<"Enter Day: ";
    cin>>day;
    cout<<"Enter Year: ";
    cin>>year;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    factor = month * day;
    
    if (factor == year) result = "It is a Magic Date!";
    else if ((factor != year) && (month < 13) && (day < 32) && (year < 100)) result = "Sorry, it's not a magic date!";
    else result = "Invalid input!";
    
    //Output values
    cout<<"The date you entered is "<<month<<"/"<<day<<"/"<<year<<endl<<endl;
    cout<<"Result: "<<result<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

