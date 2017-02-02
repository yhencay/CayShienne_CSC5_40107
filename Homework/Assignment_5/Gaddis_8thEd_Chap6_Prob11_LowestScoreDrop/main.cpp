/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:33 PM
 * Purpose: Homework Lowest Score Drop
 * 
 *      Problem: Write a program that calculates the average of a group of test 
 * scores, where the lowest score in the group is dropped. It should use the 
 * following functions:
 *  • void getScore() should ask the user for a test score, store it in a 
 * reference parameter variable, and validate it. This function should be called 
 * by main once for each of the five scores to be entered.
 *  • void calcAverage() should calculate and display the average of the four 
 * highest scores. This function should be called just once by main and should 
 * be passed the five scores.
 *  • int findLowest() should find and return the lowest of the five scores 
 * passed to it. It should be called by calcAverage , which uses the function 
 * to determine which of the five scores to drop.
 *      Input Validation: Do not accept test scores lower than 0 or higher 
 *                  than 100.
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
void getScor(float &);      //Get value from user for the test scores
void calcAvg(float, float, float, float, float);    //Calculate average for test scores
float lwstP11(float, float, float, float, float);   //Find lowest value for prob 11

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float sc1, sc2, sc3, sc4, sc5;     //Scores from Test 1 - 5

    //Input Values    
    cout<<"Test 1"<<endl;
    getScor(sc1);
    cout<<"Test 2"<<endl;
    getScor(sc2);
    cout<<"Test 3"<<endl;           //Call function to pass value as reference to
    getScor(sc3);                   //main for each test scores
    cout<<"Test 4"<<endl;
    getScor(sc4);
    cout<<"Test 5"<<endl;
    getScor(sc5);
    
    //Process by mapping inputs to outputs      //This is both the process
    //Output values                             //and the output values
    calcAvg(sc1, sc2, sc3, sc4, sc5);       //Display result
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//************************* Getting Scores  ************************************
//Description: Get scores and pass the value by reference to main
//Inputs:   float - tests scores not less than 0 and greater than 100
//Outputs:  Input validation - only if input is invalid
//******************************************************************************

void getScor(float &score) {    
    do {
        cout<<"Enter Test Score: ";     //Prompt user to enter the test score
        cin>>score;                     //Loop until input is valid
        cout<<endl;
        
        if (score<0 || score>100) cout<<"Score cannot be less than 0 or greater than 100!\n"<<endl;
        
    } while (score<0 || score>100);   
}

//*********************** Getting Lowest Score *********************************
//Description: Determine lowest score out of all input values
//Inputs:   No inputs but uses value passed by getScor function
//Outputs:  No outputs but return the value of the lowest score
//******************************************************************************

float lwstP11(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float lowest = sc1;
    
    lowest = (sc2<lowest)?sc2:lowest;
    lowest = (sc3<lowest)?sc3:lowest;       //Determines lowest score using values from
    lowest = (sc4<lowest)?sc4:lowest;       //main that was passed by reference by getScor
    lowest = (sc5<lowest)?sc5:lowest;       //function
    
    return lowest;                  //Return lowest value
}

//************************* Calculate Average **********************************
//Description: Calculate the average score of the four highest grades
//Inputs:   No inputs but utilizes values from main to calculate scores
//Outputs:  Output the test that dropped and the final average score with lowest
//      grade dropped.
//******************************************************************************

void calcAvg(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float avg, lowsc;
    
    lowsc = lwstP11(sc1,sc2,sc3,sc4,sc5);   //Assign lowest value by calling lwstP11 function which determines lowest value
    avg = (sc1+sc2+sc3+sc4+sc5-lowsc)/4;    //Calculate average
    
    if (lowsc == sc1) cout<<"Test 1 Dropped!"<<endl;
    else if (lowsc == sc2) cout<<"Test 2 Dropped!"<<endl;   
    else if (lowsc == sc3) cout<<"Test 3 Dropped!"<<endl;       //Test drops conditions
    else if (lowsc == sc4) cout<<"Test 4 Dropped!"<<endl;
    else cout<<"Test 5 Dropped!"<<endl;
    
    cout<<"The average of the test scores is "<<avg<<endl;      //Display result
}

