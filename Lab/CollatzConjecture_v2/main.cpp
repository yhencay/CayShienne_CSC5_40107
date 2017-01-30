
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 30, 2017, 12:21 PM
 * Purpose: COLLATZ CONJECTURE 
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
    const int series = 200;
    int array[series];
    
    int input, res = 0, count = 0;

    
    cout<<"Input number: "<<endl;
    cin>>input;
    
 //   cout<<input<<" ";    

    array[0]=count;
    do { 
        if (input%2 == 0) {
            count++;
            res = input/2;
     //       cout<<res<<" ";
            array[count]=res;
        }
        if (input%2 == 1) {
            count++;
            res = 3*input +1;
      //      cout<<res<<" ";
            array[count]=res;
        }
    } while (res!=1);
    
    for (int i = 0; i<= count; i++) {
        cout<<array[i]<<" ";
    }
    
    
    
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

