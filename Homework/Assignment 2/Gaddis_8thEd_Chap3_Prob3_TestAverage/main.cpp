
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 9, 2017, 12:49 PM
 * Purpose: Homework to calculate Test Average 
 *      Problem: Write a program that asks for five test scores. The program 
 * should calculate the average test score and display it. The number displayed 
 * should be formatted in fixed-point notation, with one decimal point of 
 * precision.
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
        float one,      //First test score
              two,      //Second test score
              three,    //Third test score
              four,     //Fourth test score
              five,     //Fifth test score
              avrge;    //Average of the five test scores

    //Input Values
        cout<<"Let's calculate your average test score!"<<endl<<endl
            <<"What is your first test score? ";
        cin>>one;
        cout<<"What is your second test score? ";
        cin>>two;
        cout<<"What is your third test score? ";
        cin>>three;
        cout<<"What is your fourth test score? ";
        cin>>four;
        cout<<"What is your fifth test score? ";
        cin>>five;
    
    //Process by mapping inputs to outputs
        avrge = (one+two+three+four+five)/5;
    
    //Output values
        cout<<endl<<"--------------"<<endl<<"   Results"
            <<endl<<"--------------"<<endl;
        cout<<" Score 1: "<<setw(3)<<one<<endl;
        cout<<" Score 2: "<<setw(3)<<two<<endl;        
        cout<<" Score 3: "<<setw(3)<<three<<endl;        
        cout<<" Score 4: "<<setw(3)<<four<<endl; 
        cout<<" Score 5: "<<setw(3)<<five<<endl<<endl;        
        cout<<" Average: "<<setprecision(3)<<avrge<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

