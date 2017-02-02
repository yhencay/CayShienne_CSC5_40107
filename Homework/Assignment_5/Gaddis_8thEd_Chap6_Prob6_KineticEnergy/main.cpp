/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 10:24 PM
 * Purpose: Homework Kinetic Energy
 * 
 *      Problem: In physics, an object that is in motion is said to have kinetic 
 * energy. The following formula can be used to determine a moving object’s 
 * kinetic energy:
 *                  KE = 1/2 mv^2
 * The variables in the formula are as follows: KE is the kinetic energy, m is 
 * the object’s mass in kilograms, and v is the object’s velocity, in meters per 
 * second. Write a function named kineticEnergy that accepts an object’s mass 
 * (in kilograms) and velocity (in meters per second) as arguments. The function 
 * should return the amount of kinetic energy that the object has. Demonstrate 
 * the function by calling it in a program that asks the user to enter values 
 * for mass and velocity.
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
float kinEngy(float, float);        //kinetic energy

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float mass, vlocity;        
    
    //Input Values
    cout<<"Enter Object's Mass (in kg): ";      //Prompt user for input value
    cin>>mass;
    
    cout<<"Enter Object's Velocity (in meter per seconds): ";
    cin>>vlocity;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    cout<<"Object's Mass: "<<mass<<" kilograms"<<endl;          //Display input values
    cout<<"Object's Velocity: "<<vlocity<<" meter(s) per second"<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The object's amount of kinetic energy is "<<kinEngy(mass, vlocity)<<endl;        //Output result from kinEngy function
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//********************** Calculate Kinetic Energy ******************************
//Description: Calculate the kinetic energy based on user input of mass and 
//          velocity.
//Inputs:   No inputs but utilizes values from main to calculate kinetic energy
//Outputs:  No outputs but return the value of the kinetic energy to main
//******************************************************************************

float kinEngy(float mass, float vlocity) {
    float kinEngy;
    
    kinEngy = mass*(vlocity*vlocity)/2;
    
    return kinEngy;
}
