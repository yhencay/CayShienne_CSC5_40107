
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
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
    string show = "*";
    int store1,
        store2,
        store3,
        store4,
        store5,
            bar,
            store = 1,
    stores;
    
    cout<<"Enter today's sales for store 1: ";
    cin>>store1;
    cout<<"Enter today's sales for store 2: ";
    cin>>store2;
    cout<<"Enter today's sales for store 3: ";
    cin>>store3;
    cout<<"Enter today's sales for store 4: ";
    cin>>store4;
    cout<<"Enter today's sales for store 5: ";
    cin>>store5;
    
    for (int store = 1; store <= 5; store++) {
        cout<<"Store "<<store<<": ";
        cout<<show;
        if ((store1%100)==0) cout<<endl;
            
        }
    

    

    
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

