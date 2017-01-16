
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 15, 2017, 10:34 PM
 * Purpose: Homework Body Mass Index Calculator
 *      Problem: Write a program that calculates and displays a person’s body 
 * mass index (BMI). The BMI is often used to determine whether a person with a 
 * sedentary lifestyle is overweight or underweight for his or her height. A 
 * person’s BMI is calculated with the following formula:
 *              BMI = weight x 703 / height2
 * where weight is measured in pounds and height is measured in inches. The 
 * program should display a message indicating whether the person has optimal 
 * weight, is underweight, or is overweight. A sedentary person’s weight is 
 * considered to be optimal if his or her BMI is between 18.5 and 25. If the BMI 
 * is less than 18.5, the person is considered to be underweight. If the BMI 
 * value is greater than 25, the person is considered to be overweight.
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
    float BMI,          //Rssult
          weight,       //User input of weight in pounds
          height;       //User input of height in inches
    
    //Input Values
    cout<<"We're going to calculate your BMI (Body Mass Index) for you.\n"
        <<"Only type your height in inches and your weight in pounds.\n"
        <<"Otherwise, result will get an inaccurate answer or an ERROR!\n"
        <<endl;
    cout<<"Enter height (in inches): ";
    cin>>height;
    cout<<"Enter weight (in pounds): ";
    cin>>weight;
    cout<<endl<<fixed<<setprecision(2);
    
    //Process by mapping inputs to outputs
    BMI = (weight * 703) / (height*height);
    
    //Output values
    if ((BMI >= 18.5) && (BMI <= 25))
        cout<<"Your BMI is "<<BMI<<"\nIt is considered optimal weight!"<<endl;
    else if ((BMI < 18.5) && (BMI >0))
        cout<<"Your BMI is "<<BMI<<"\nIt is considered underweight!"<<endl;
    else if ((BMI > 25) && (BMI <= 30))
        cout<<"Your BMI is "<<BMI<<"\nIt is considered overweight!"<<endl;
    else if (BMI > 30)
        cout<<"Your BMI is "<<BMI<<"\nIt is considered obese!"<<endl;
    else 
        cout<<"INVALID INPUT!"<<endl;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

