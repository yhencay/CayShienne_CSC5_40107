
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 17, 2017, 11:05 AM
 * Purpose: Grade with While Loop
 */

//System Libraries
#include <iostream>     //Input Output Library
#include <cstdlib>      //Random number generator
#include <ctime>        //Time Library
#include <iomanip>      //Format Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes


//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
            
    //Declare and Initialize Local Variables Variables
    char numStd = 20,
         student = 1;
    unsigned short average = 0;
    
    //Input Values
    cout<<"This program assigns the score and outputs the grade for "
        <<static_cast<int>(numStd)<<" students"<<endl;
    
    //Loop for each student
    while(++student <= numStd) {
        
        //Assign a grade and add the average
        //Score and grade are local to the while loop
        unsigned short score = rand()%50+50;
        average+=score;
        //Process by mapping inputs to outputs
        char grade = (score>=90)?'A':
                (score>=80)?'B':
                (score>=70)?'C':
                (score>=60)?'D':'F';

        //Output values
        cout<<"Student "<<setw(2)<<static_cast<int>(student)
            <<" has a score "<<score<<" = "<<grade<<endl;
    }
    
    //Calculate and output the average
    average/=numStd;
    cout<<"The average test score = "<<average<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

