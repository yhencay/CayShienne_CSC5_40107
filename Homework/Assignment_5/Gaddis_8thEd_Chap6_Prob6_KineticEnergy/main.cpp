/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 10:24 PM
 * Purpose: Homework Kinetic Energy
 *      Problem: 
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
float kinEngy(float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float mass, vlocity;
    
    //Input Values
    cout<<"Enter Object's Mass (in kg): ";
    cin>>mass;
    
    cout<<"Enter Object's Velocity (in meter per seconds): ";
    cin>>vlocity;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    cout<<"Object's Mass: "<<mass<<" kilograms"<<endl;
    cout<<"Object's Velocity: "<<vlocity<<" meter(s) per second"<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The object's amount of kinetic energy is "<<kinEngy(mass, vlocity)<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float kinEngy(float mass, float vlocity) {
    float kinEngy;
    
    kinEngy = mass*(vlocity*vlocity)/2;
    
    return kinEngy;
}
