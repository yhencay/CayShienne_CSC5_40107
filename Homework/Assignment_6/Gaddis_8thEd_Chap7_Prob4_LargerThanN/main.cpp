/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 11:07 PM
 * Purpose: Homework Larger Than N
 * 
 *      Problem: In a program, write a function that accepts three arguments: an 
 * array, the size of the array, and a number n. Assume that the array contains 
 * integers. The function should display all of the numbers in the array that 
 * are greater than the number n.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void call(int [], int, int);    //Generate random numbers and determine larger number than input

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {    
    //Declare Variables
    const int SIZE = 5;             //Size name for array
    int array[SIZE] = {};           //Array for generated number
    int n, count;                   //User input and loop counter
    
    //Input Values
    cout<<"Input a number from 1-10 and see if there's any number greater than\n"
        <<"the typed number in the array.\n"<<endl;                                 //Prompt user to enter values from 1-10
    
    do {
        cout<<"Number: ";           //Loop until user input is valid
        cin>>n;
        
        if (n>10 || n<1) cout<<"\nNo value less than 1 and greater than 10 is accepted! Try again!\n"<<endl;
    } while (n>10 || n<1);
        
    //Process by mapping inputs to outputs
    //Output values
    call(array, SIZE, n);           //Call function
   
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//**************************** Call Function ***********************************
//Description: Generate random numbers and determine greater number than user
//          input.
//Inputs:   No inputs but utilizes input from main for n
//Outputs:  Output values greater than user input
//******************************************************************************

void call(int array[], const int SIZE, int n) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    int random;         //Variable for random numbers
    
    for (int count = 0; count<SIZE; count++) {
        random = rand()%10+1;   //Values from 1-10
        array[count] = random;      //Add random number to array
    }
    
    cout<<"\nValues greater than "<<n<<" are: ";
    
    for (int count = 0; count<SIZE; count++) {              //Display if there is any values greater than user input
            if (array[count]>n) cout<<array[count]<<" ";
            else cout<<"";
    }
    
    cout<<endl<<"\nNOTE: If nothing appeared, there is none!"<<endl;
    
}

