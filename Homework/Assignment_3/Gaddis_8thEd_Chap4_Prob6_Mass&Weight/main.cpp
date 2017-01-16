
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 15, 2017, 10:21 PM
 * Purpose: Homework Mass and Weight calculation 
 *      Problem: Scientists measure an object’s mass in kilograms and its weight 
 * in newtons. If you know the amount of mass that an object has, you can 
 * calculate its weight, in newtons, with the following formula:
 *          Weight = mass x 9.8
 * Write a program that asks the user to enter an object’s mass, and then 
 * calculates and displays its weight. If the object weighs more than 1,000 
 * newtons, display a message indicating that it is too heavy. If the object 
 * weighs less than 10 newtons, display a message indicating that the object is 
 * too light.
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
const float GRAVITY = 9.8f;
//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float mass,         //User input of object's mass
          weight;       //Result of mass multiplied by gravity
    
    //Input Values
    cout<<"Let's calculate an object's weight in newton based on the amount of \n"
        <<"mass it has. Remember to input the object's mass in kilograms to avoid\n"
        <<"inaccurate result!"<<endl<<endl;
    cout<<"Enter the object's mass: ";
    cin>>mass;
    cout<<endl<<fixed<<setprecision(2);
    
    //Process by mapping inputs to outputs
    weight = mass * GRAVITY;
    
    //Output values
    cout<<"The weight of the object is "<<weight<<" newtons!"<<endl;
    if (weight > 1000)
        cout<<"The object is too heavy!\n";
    else if((weight < 10) && (weight > 0))
        cout<<"The object is too light!\n";
    else cout<<endl;
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

