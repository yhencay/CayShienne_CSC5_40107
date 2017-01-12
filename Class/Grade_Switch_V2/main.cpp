
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 12, 2017, 12:19 PM
 * Purpose: Grade Switch - Case 
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
    unsigned short score;
    char grade;
    
    //Input Values
    cout<<"This program takes the score and outputs the grade"<<endl;
    cout<<"Input the score 0 to 100"<<endl;
    cin>>score;
    
    //Process by mapping inputs to outputs
    switch(score) {
        case 95 ... 100: grade = 'A';break;
        case 88 ... 94: grade = 'B';break;
        case 80 ... 87: grade = 'C';break;
        case 75 ... 79: grade = 'D';break;
        default: grade='F';
    }
    
    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

