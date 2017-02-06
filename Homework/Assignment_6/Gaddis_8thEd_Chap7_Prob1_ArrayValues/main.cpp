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
    const short SIZE = 10;                      //Size for array
    int array[SIZE] = {};                       //Array for storing user input number
    int input;                                  //User input
    
    //Input Values    
    cout<<"Type 10 integer numbers!"<<endl<<endl;
    for (input = 1; input <= SIZE; input++) {       //Prompt user to type in integer number
        cout<<"Input Number "<<input<<": ";
        cin>>array[input];                          //Store user input to the array
    }
    
    cout<<"\nValues entered are: ";
    for (input = 1; input <=SIZE;input++)           //Display user input
        cout<<array[input]<<" ";

    //Process by mapping inputs to outputs    
    int highest = array[0];                         //Initialize highest number variable in array

    for (input = 1; input <= SIZE; input++) {       
        if (array[input]>highest)
            highest = array[input];
    }
    
    int lowest = array[1];                          //Initialize lowest number variable in array

    for (input = 1; input <= SIZE; input++) {       //Test each number stored for lowest number
        if (array[input]<lowest)
            lowest = array[input];
    }
   
    //Output values    
    cout<<"\n\nHIGHEST: "<<highest<<endl;           //Display highest and lowest value in array
    cout<<"LOWEST: "<<lowest<<endl;
         
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

