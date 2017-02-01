/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:34 AM
 * Purpose: Homework Coin Toss
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void cnToss(int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int toss;
    
    //Input Values
    cout<<"Number of Toss: ";
    cin>>toss;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"----------------------"<<endl;
    cout<<"TOSS\t\tRESULT"<<endl;
    cout<<"----------------------"<<endl;
    cnToss(toss);       
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void cnToss(int toss) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    string a = "Heads!", b = "Tails!", result;
    for (int count = 1; count<=toss; count++) {
        unsigned short coin = rand()%2+1; //value from 1-2
        result = (coin == 2)?b:a;
        cout<<count<<"\t\t"<<result<<endl;
    }
}
