/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 6, 2017, 11:07 AM
 * Purpose: Linear Search
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
int linSrch(int [], int, int);

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
    
    //Find the element
    int find;
    cout<<"Value to find? Type a number between 10-99.\n"<<endl;
    cin>>find;
    cout<<find<<" was found at "<<linSrch(array, utilize, find)<<endl;
    
    //Output values
    prntAry(array, utilize, 10);
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}



int linSrch(int a[], int n, int val) {
    for (int i= 0; i<n;i++) {
        if(a[i]==val) return i;
    }
    return -1;
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