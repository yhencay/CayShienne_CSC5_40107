/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 2, 2017, 12:57 PM
 * Purpose: Homework Largest/Smallest Array Values
 * 
 *      Problem: Write a program that lets the user enter 10 values into an 
 * array. The program should then display the largest and smallest values stored 
 * in the array.
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
    const short SIZE = 10;
    int array[SIZE] = {};
    int input;
    
    for (input = 1; input <= SIZE; input++) {
        cout<<"Input Number "<<input<<": ";
        cin>>array[input];
    }
    
    cout<<"\nValues entered are: ";
    for (input = 1; input <=SIZE;input++)
        cout<<array[input]<<" ";
    
    int highest = array[0];

    for (input = 1; input <= SIZE; input++) {
        if (array[input]>highest)
            highest = array[input];
    }
    
    int lowest = array[1];

    for (input = 1; input <= SIZE; input++) {
        if (array[input]<lowest)
            lowest = array[input];
    }
    
    cout<<"\n\nHIGHEST: "<<highest<<endl;
    cout<<"LOWEST: "<<lowest<<endl;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

