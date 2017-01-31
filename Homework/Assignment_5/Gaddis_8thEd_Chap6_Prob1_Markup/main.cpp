/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 12:58 PM
 * Purpose: Homework Markup
 *      Problem: 
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
const short PERCENT = 100; //Percentage conversion

//Function Prototypes
float calRt8l(float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float cost, markup;
    
    //Input Values
    cout<<"Enter wholesale cost: $";
    cin>>cost;
    while (cost < 0) {
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter wholesale cost: $";
        cin>>cost;
    }
    cout<<"Enter markup percentage: ";
    cin>>markup;
    while (markup < 0) {
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter markup percentage: ";
        cin>>markup;
    }
    
    //Process by mapping inputs to outputs
    
    
    //Output values
    cout<<endl;
    cout<<"The whole sale cost is $"<<cost<<endl;
    cout<<"The markup percentage is "<<markup<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The cost of the item now is $"<<calRt8l(cost, markup)<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float calRt8l(float cost, float markup) {
    float answer, add;
    
    add = cost*(markup/PERCENT);
    answer = cost+add;
    
    return answer;
}
