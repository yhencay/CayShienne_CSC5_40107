/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 8:19 PM
 * Purpose: Homework Winning Division
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
float sales();
void highest(float, float, float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float slsNE, slsSE, slsNW, slsSW;
    
    //Input Values
    cout<<"Northeast Division"<<endl;
    slsNE = sales();
    cout<<"Southeast Division"<<endl;
    slsSE = sales();
    cout<<"Northwest Division"<<endl;
    slsNW = sales();
    cout<<"Southwest Division"<<endl;
    slsSW = sales();
    
    cout<<fixed<<setprecision(2)<<showpoint;
    
    cout<<"Northeast Division: "<<setw(5)<<"$"<<slsNE<<endl;
    cout<<"Southeast Division: "<<setw(5)<<"$"<<slsSE<<endl;
    cout<<"Northwest Division: "<<setw(5)<<"$"<<slsNW<<endl;
    cout<<"Southwest Division: "<<setw(5)<<"$"<<slsSW<<endl;
    cout<<endl;
    
    highest(slsNE, slsSE, slsNW, slsSW);
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float sales() {
    float sales;
    cout<<"Enter Sales: $";
    cin>>sales;
    cout<<endl;
    
    while (sales < 0) {
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Enter Sales: $";
        cin>>sales;
        cout<<endl;
    }
    
    return sales;
}

void highest(float a, float b, float c, float d) {
    float largest = 0.0f;
    string ne = "Northeast Division Wins!", 
           se = "Southeast Division Wins!", 
           nw = "Northwest Division Wins!", 
           sw = "Southwest Division Wins!";
    
    largest = (a>largest)?a:largest;
    largest = (b>largest)?b:largest;
    largest = (c>largest)?c:largest;
    largest = (d>largest)?d:largest;
   
    if (largest == a)cout<<ne;
    if (largest == b)cout<<se;
    if (largest == c)cout<<nw;
    if (largest == d)cout<<sw;
    
    cout<<"\n$"<<largest<<endl;
}

