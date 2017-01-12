
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017,  8:50 PM
 * Purpose: Homework Calorie Count
 *      Problem: A bag of cookies holds 30 cookies. The calorie information on 
 * the bag claims that there are 10 “servings” in the bag and that a serving 
 * equals 300 calories. Write a program that asks the user to input how many 
 * cookies he or she actually ate and then reports how many total calories were 
 * consumed. 
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
    unsigned char cksServ = 3;      //3 cookies per serving of a bag of cookies that contain 30 pieces
    unsigned short calorie = 300,   //calorie count per serving. There are 10 servings in a bag.
                   intake;          //how many cookies user ate
             float totCal;          //total calories consumed
    
    //Input Values
    cout<<"There are 30 cookies in one bag with a calorie information of having\n"
        <<"10 servings containing 300 calories per serving."<<endl<<endl;
    cout<<"How many cookies did you eat? ";
    cin>>intake;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    totCal = ( intake / static_cast<float>(cksServ) ) * calorie;
    
    //Output values
    cout<<"After eating "<<intake<<" cookies, you consumed "<<totCal<<" calories in total."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

