
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017,  7:50 PM
 * Purpose: Homework Calculate Male and Female Percentages
 *      Problem: Write a program that asks the user for the number of males and 
 * the number of females registered in a class. The program should display the 
 * percentage of males and females in the class. 
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
    unsigned short numMale,     //number of males in class
                   numFem,      //number of females in class
                   student;     //total number of students in class
    float perMale,              //percentage of each male students in class
          perFem;               //percentage of each female students in class
    
    //Input Values
    cout<<"Let's calculate the percentage of male and female in a class!"<<endl<<endl;
    cout<<"How many in class are male? ";
    cin>>numMale;
    cout<<"How many in class are female? ";
    cin>>numFem;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    student = numMale + numFem;
    perMale = (static_cast<float>(numMale)/student)*100;
    perFem = (static_cast<float>(numFem)/student)*100;
    
    //Output values
    cout<<fixed<<setprecision(2);
    cout<<"The class consists of "<<student<<" students!"<<endl;
    cout<<"     > "<<perMale<<"% male"<<endl;
    cout<<"     > "<<perFem<<"% female"<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

