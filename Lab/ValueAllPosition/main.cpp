/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 6, 2017, 12:46 PM
 * Purpose: Value at all positions
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
    const int SIZE=400;
    const int utilize=SIZE/2;
    int array[utilize]={};
    int values[utilize] = {};
    int perLine = 10;
    int find, found;
    
    for (int count = 0; count < utilize; count++) {
        array[count] = rand()%90+10;
    }
    
    //Input Values
    cout<<"Input a number from 10-99 to find the value in the array!\n\n";
    cout<<"Number: ";
    cin>>find;
    
    //Process by mapping inputs to outputs
    for (int count = 0; count < utilize; count++) {
        if (array[count] == find) {
            values[count] = count;
            found++;
        }
        else values[count] = 0;
    }
    
    //Output values
    cout<<endl;
    cout<<find<<" was found at ";
    
    if (found > 0) {
        for (int count = 0; count<utilize; count++) {
        if (values[count] == 0) cout<<"\0";
        else cout<<values[count]<<" ";
        }
    }
    else cout<<"nowhere";
    
    cout<<endl<<endl;
    for (int count = 0; count < utilize; count++) {
        cout<<array[count]<<" ";
        if(count%perLine==perLine-1)cout<<endl;
    }
  
    //Exit stage right! - This is the 'return 0' call
    return 0;
}