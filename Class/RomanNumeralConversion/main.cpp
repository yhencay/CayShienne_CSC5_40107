
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 24, 2017, 10:54 AM
 * Purpose: Convert to Roman Numerals
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const int THOSNDS = 1000;   //Conversion to 1,000
const int HUNDRDS = 100;    //Conversion to   100
const int TENS = 10;        //Conversion to    10

//Function Prototypes
string cnvrtRN(int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short year;
    
    //Input Values
    cout<<"This program converts Years to Roman Numerals"<<endl;
    cout<<"Input a year between 1000AD to 3000AD"<<endl;
    cin>>year;
    
    //Output to Roman Numeral
    cout<<year<<" = "<<cnvrtRN(year)<<endl;
    
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//000000000111111111122222222223333333334444444445555555555666666666677777777778
//345678901234567890123456789012346578901234567890123456789012345678901234657890
//********************Roman Numeral Conversion**********************************
//Description: Convert numbers from 1000 to 3000
//Inputs:
//    year -> Year from 1000 to 3000
//Outputs:
//    romanYr -> Output to the
//******************************************************************************

string cnvrtRN(int year) {
    //Declare variables
    char n1000, n100, n10, n1; //The number of powers of 10
    string roman = "";
    
    //Parsing the year information
    n1000 = (year-year%THOSNDS)/THOSNDS; //Determines how many 1000's
    year = (year-n1000*THOSNDS);         //Year without 1000's
    
    n100 = (year-year%HUNDRDS)/HUNDRDS; //Determines how many 100's
    year = (year-n100*HUNDRDS);         //Year without 100's
    
    n10 = (year-year%TENS)/TENS;  //Determines how many 10's
    n1 = (year-n10*TENS);       //Year without 10's
     
    //Fill string with M's
    switch (n1000) {
        case 3:roman+='M';
        case 2:roman+='M';
        case 1:roman+='M'; break;
        default: cout<<"BAD YEAR!"<<endl;
    }
    
    //Fill string with C's
    switch (n100) {
        case 9:roman+="CM"; break;
        case 8:roman+="DCCC"; break;
        case 7:roman+="DCC"; break;
        case 6:roman+="DC";break;
        case 5:roman+="D";break;
        case 4:roman+="CD";break;
        case 3:roman+='C';
        case 2:roman+='C';
        case 1:roman+='C'; break;
        case 0:break;
        default: cout<<"BAD HUNDRED!"<<endl;
    }
    
    //Fill string with X's
    switch (n10) {
        case 9:roman+="XC"; break;
        case 8:roman+="LXXX"; break;
        case 7:roman+="LXX"; break;
        case 6:roman+="LX";break;
        case 5:roman+="L";break;
        case 4:roman+="XL";break;
        case 3:roman+='X';
        case 2:roman+='X';
        case 1:roman+='X'; break;
        case 0:break;
        default: cout<<"BAD TENS!"<<endl;
    }
    
    //Fill string with I's
    switch (n1) {
        case 9:roman+="IX"; break;
        case 8:roman+="VIII"; break;
        case 7:roman+="VII"; break;
        case 6:roman+="VI";break;
        case 5:roman+="V";break;
        case 4:roman+="IV";break;
        case 3:roman+='I';
        case 2:roman+='I';
        case 1:roman+='I'; break;
        case 0:break;
        default: cout<<"BAD ONES!"<<endl;
    }
    
    
    
    //Try    
    /*
    cout<<static_cast<int>(n1000);
    cout<<static_cast<int>(n100);
    cout<<static_cast<int>(n10);
    cout<<static_cast<int>(n1);
    */
    
    //Dummy string
    return roman;
    
}