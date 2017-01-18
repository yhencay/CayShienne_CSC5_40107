/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017, 10:35 AM
 * Purpose: Statistics for throwing  2 dices
 */

//System Libraries
#include <iostream> //Input Output Library
#include <cstdlib>  //Random numbers
#include <ctime>    //Time to set the seed
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int nThrows = 36000; //Number of throws for the pair of dice
    unsigned int n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0,
            n10 = 0, n11 = 0, n12 = 0;
    
    //Loop and take dice statistics
    for (int toss = 1;toss<nThrows;toss++) {
        //Call random generator from the dice
        char die1 = rand()%6+1; //Value from 1 to 6
        char die2 = rand()%6+1; //Value from 1 to 6
        char sum = die1 + die2;
        switch (sum) {
            case 2:n2++;break;
            case 3:n2++;break;
            case 4:n2++;break;
            case 5:n2++;break;
            case 6:n2++;break;
            case 7:n2++;break;
            case 8:n2++;break;
            case 9:n2++;break;
            case 10:n2++;break;
            case 11:n2++;break;
            case 12:n2++;break;
            default: cout<<"You are in error!"<<endl;
        }
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

