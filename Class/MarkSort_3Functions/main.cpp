/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 6, 2017, 10:43 AM
 * Purpose: Mark Sort with 3 functions
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
void filAray(int [], int);
void prntAry(int [], int, int);
void swap(int &, int &);
void smalst(int [], int, int);
void markSrt(int [], int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE = 200;
    const int utilize = SIZE/2;
    int array[utilize] = {};
    
    //Input Values
    filAray (array, utilize);
    prntAry(array, utilize, 10);
    
    //Process by mapping inputs to outputs
    smalst(array, utilize, 0);
    markSrt(array,utilize);
    
    //Output values
    prntAry(array, utilize, 10);
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void markSrt(int a[], int n) {
    for(int i = 0; i<n;i++) {
        smalst(a, n, i);
    }
}

void smalst(int a[], int n, int pos) {
    for (int i= pos+1; i<n;i++) {
        if(a[pos]>a[i])swap(a[pos], a[i]);
    }
}

void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
    
}

void prntAry(int a[], int n, int perLine) {
    cout<<endl;
    for(int i = 0; i<n;i++) {
        cout<<a[i]<<" ";
        if (i%perLine == perLine-1) cout<<endl;
    }
}

void filAray (int a[], int n) {
    for (int i= 0; i<n;i++) {
        a[i]=rand()%90+10;
    }
}