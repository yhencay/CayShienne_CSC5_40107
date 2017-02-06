/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 6, 2017, 12:04 PM
 * Purpose: Sorting Routine
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

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=200;
    const int utilize=SIZE/2;
    int array[utilize]={};
    int perLine = 10;
    int value = 0;
    
    for (int count = 0; count < utilize; count++) {
        array[count] = rand()%90+10;
        cout<<array[count]<<" ";
        if(count%perLine==perLine-1)cout<<endl;
    }
    
    for (int i = 0; i < utilize-1; i++) {
        for (int count = i+1; count < utilize; count++) {
            if (array[i]>array[count]) {
                array[i] = array[i]^array[count];
                array[count] = array[i]^array[count];
                array[i] = array[i]^array[count];
            }
        }
    }
    cout<<endl;
    
    for (int count = 0; count < utilize; count++) {
        cout<<array[count]<<" ";
        if(count%perLine==perLine-1)cout<<endl;
    }
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}