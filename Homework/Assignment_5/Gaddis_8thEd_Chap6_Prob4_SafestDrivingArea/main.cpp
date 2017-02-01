/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 9:48 PM
 * Purpose: Homework Safest Driving Area
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
float axident();
void lowest(int, int, int, int, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int nr, sr, wr, er, cr;
    
    //Input Values
    cout<<"North Region"<<endl;
    nr = axident();
    cout<<"South Region"<<endl;
    sr = axident();
    cout<<"West Region"<<endl;
    wr = axident();
    cout<<"East Region"<<endl;
    er = axident();
    cout<<"Central Region"<<endl;
    cr = axident();
    
    cout<<"North Region: "<<setw(7)<<nr<<endl;
    cout<<"South Region: "<<setw(7)<<sr<<endl;
    cout<<"West Region: "<<setw(8)<<wr<<endl;
    cout<<"East Region: "<<setw(8)<<er<<endl;
    cout<<"Central Region: "<<setw(5)<<cr<<endl;
    cout<<endl;
    
    lowest(nr, sr, wr, er, cr);
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float axident() {
    int axident;
    cout<<"Reported Number of Accidents: ";
    cin>>axident;
    cout<<endl;
    
    while (axident < 0) {
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Reported Number of Accidents: ";
        cin>>axident;
        cout<<endl;
    }
    
    return axident;
}

void lowest(int a, int b, int c, int d, int e) {
    int lowest;
    string nr = "North Region", 
           sr = "South Region", 
           wr = "West Region", 
           er = "East Region",
           cr = "Central Region";
    
    lowest = a;
    
    lowest = (b<lowest)?b:lowest;
    lowest = (c<lowest)?c:lowest;
    lowest = (d<lowest)?d:lowest;
    lowest = (e<lowest)?e:lowest;
   
    cout<<"The safest driving area is ";
    if (lowest == a)cout<<nr;
    if (lowest == b)cout<<sr;
    if (lowest == c)cout<<wr;
    if (lowest == d)cout<<er;
    if (lowest == e)cout<<cr;
    
    cout<<" with only "<<lowest<<" number of reported accidents!"<<endl;
}

