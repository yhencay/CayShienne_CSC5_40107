
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12: PM
 * Purpose: Output Big C
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
    char c; //Variable to build the Big C with
    
    //Input Values
    cout<<"This program outputs a large C"<<endl;
    cout<<"With a letter the user chooses"<<endl;
    cout<<"What letter would you like?"<<endl;
    cin>>c;
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl<<"A Big C with the letter "<<c<<endl<<endl;
    cout<<"   "<<c<<" "<<c<<" "<<c<<endl;
    cout<<"  "<<c<<"     "<<c<<endl;
    cout<<" "<<c<<endl;
    cout<<" "<<c<<endl;
    cout<<" "<<c<<endl;
    cout<<" "<<c<<endl;
    cout<<" "<<c<<endl;
    cout<<"  "<<c<<"     "<<c<<endl;
    cout<<"   "<<c<<" "<<c<<" "<<c<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

