/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 8:08 PM
 * Purpose: Homework Star Search
 * 
 *      Problem: A particular talent competition has five judges, each of whom 
 * awards a score between 0 and 10 to each performer. Fractional scores, such as 
 * 8.3, are allowed. A performer’s final score is determined by dropping the 
 * highest and lowest score received, then averaging the three remaining scores. 
 * Write a program that uses this method to calculate a contestant’s score. It 
 * should include the following functions: 
 *  • void getJudgeData() should ask the user for a judge’s score, store it in a 
 * reference parameter variable, and validate it. This function should be called 
 * by main once for each of the five judges.
 *  • void calcScore() should calculate and display the average of the three 
 * scores that remain after dropping the highest and lowest scores the performer 
 * received. This function should be called just once by main and should be 
 * passed the five scores. The last two functions, described below, should be 
 * called by calcScore , which uses the returned information to determine which 
 * of the scores to drop.
 *  • int findLowest() should find and return the lowest of the five scores 
 * passed to it.
 *  • int findHighest() should find and return the highest of the five scores 
 * passed to it.
 *      Input Validation: Do not accept judge scores lower than 0 or higher 
 *                  than 10.
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
void jdgData(float &);  //Get user input
void calScor(float, float, float, float, float);    //Display result
float hiesP12(float, float, float, float, float);   //Calculate highest score
float lwstP12(float, float, float, float, float);    //Calculate lowest score

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float j1, j2, j3, j4, j5;   //Scores from Judges 1-5
 
    //Input Values
    cout<<"Judge 1"<<endl;
    jdgData(j1);
    cout<<"Judge 2"<<endl;
    jdgData(j2);
    cout<<"Judge 3"<<endl;          //Prompt user to input scores from each judge
    jdgData(j3);
    cout<<"Judge 4"<<endl;
    jdgData(j4);
    cout<<"Judge 5"<<endl;
    jdgData(j5);
    
    //Process by mapping inputs to outputs
    //Output values
    calScor(j1, j2, j3, j4, j5);        //Display result
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//************************* Getting Scores *************************************
//Description: Get scores and pass the value by reference to main
//Inputs:   float - tests scores not less than 0 and greater than 10
//Outputs:  Input validation - only if input is invalid
//*****************************************************************************

void jdgData(float &score) {
    do {
        cout<<"Score: ";
        cin>>score;             //Get value from user input
        cout<<endl;             //Loop until input is valid
        
        if (score<0 || score>10) cout<<"Score cannot be less than 0 or greater than 10!\n"<<endl;
    } while (score<0 || score>10);    
}

//************************ Getting Highest Score *******************************
//Description: Determine highest score out of all input values
//Inputs:   No inputs but uses value passed by jdgData function
//Outputs:  No outputs but return the value of the highest score
//******************************************************************************

float hiesP12(float j1, float j2, float j3, float j4, float j5) {
    float highest = j1;
    
    highest = (j2>highest)?j2:highest;
    highest = (j3>highest)?j3:highest;
    highest = (j4>highest)?j4:highest;      //Determine highest number by comparing each one
    highest = (j5>highest)?j5:highest;
    
    return highest;    //return highest number
}

//*********************** Getting Lowest Score *********************************
//Description: Determine lowest score out of all input values
//Inputs:   No inputs but uses value passed by jdgData function
//Outputs:  No outputs but return the value of the lowest score
//******************************************************************************

float lwstP12(float j1, float j2, float j3, float j4, float j5) {
    float lowest = j1;
    
    lowest = (j2<lowest)?j2:lowest;
    lowest = (j3<lowest)?j3:lowest;         //Determine lowest number by comparing each one
    lowest = (j4<lowest)?j4:lowest;
    lowest = (j5<lowest)?j5:lowest;
    
    return lowest;      //return lowest number
}

//************************* Calculate Average **********************************
//Description: Calculate the average score of the three scores
//Inputs:  No inputs but utilizes values from main to calculate scores
//Outputs:  Output the test final average score with lowest and highest score
//     dropped.
//******************************************************************************

void calScor(float j1, float j2, float j3, float j4, float j5) {
    float hscore, lscore, avg;
    
    hscore = hiesP12(j1, j2, j3, j4, j5);           //Assign lowest and highest number to a variable to
    lscore = lwstP12(j1, j2, j3, j4, j5);           //calculate average
    
    avg = (j1+j2+j3+j4+j5-hscore-lscore)/3;         //Calculate average. Subtract highest and lowest score
    
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The average score is "<<avg<<endl;       //Display result
}