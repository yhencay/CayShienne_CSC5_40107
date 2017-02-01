/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 12:33 PM
 * Purpose: Homework Lowest Score Drop
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
void getScor(float &);
void calcAvg(float, float, float, float, float);
float lowest(float, float, float, float, float);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float sc1, sc2, sc3, sc4, sc5;
    
    cout<<"Test 1"<<endl;
    getScor(sc1);
    cout<<"Test 2"<<endl;
    getScor(sc2);
    cout<<"Test 3"<<endl;
    getScor(sc3);
    cout<<"Test 4"<<endl;
    getScor(sc4);
    cout<<"Test 5"<<endl;
    getScor(sc5);
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    if (sc1<0 || sc2<0 || sc3<0 || sc4<0 || sc5<0) cout<<"INVALID INPUT!"<<endl;
    else calcAvg(sc1, sc2, sc3, sc4, sc5);
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void getScor(float &score) {    
    cout<<"Enter Test Score: ";
    cin>>score;
    cout<<endl;
    
    if (score < 0) cout<<"INVALID INPUT!\n"<<endl;
}

float lowest(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float lowest = sc1;
    
    lowest = (sc2<lowest)?sc2:lowest;
    lowest = (sc3<lowest)?sc3:lowest;
    lowest = (sc4<lowest)?sc4:lowest;
    lowest = (sc5<lowest)?sc5:lowest;
    
    return lowest;
}

void calcAvg(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float avg, lowsc;
    
    lowsc = lowest(sc1,sc2,sc3,sc4,sc5);
    
 //   lowest = lowest;
    
    avg = (sc1+sc2+sc3+sc4+sc5-lowsc)/4;
    
    if (lowsc == sc1) cout<<"Test 1 Dropped!"<<endl;
    else if (lowsc == sc2) cout<<"Test 2 Dropped!"<<endl;
    else if (lowsc == sc3) cout<<"Test 3 Dropped!"<<endl;
    else if (lowsc == sc4) cout<<"Test 4 Dropped!"<<endl;
    else cout<<"Test 5 Dropped!"<<endl;
    
    cout<<"The average of the test scores is "<<avg<<endl;
}

