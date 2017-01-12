
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 12, 2017, 12:19 PM
 * Purpose: Grade Independent Ifs 
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
    if (score>=90)          grade= 'A';
    if(score>=80&&score<90) grade= 'B';
    if(score>=70&&score<80) grade= 'C';
    if(score>=60&&score<70) grade= 'D';
    if(score<60)            grade= 'F';
    
    //Output values
    cout<<"Your score of "<<score<<" = "<<grade<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

