/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 7, 2017, 12:16 PM
 * Purpose: Timing Comparison between Mark Sort and Bubble Sort
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
void markSrt (int [], int);
void BubSort (int [], int);
void filAray (int [], int);
void prntAry (int [], int, int);
void copyF(int [],int [],int);
void mrkSrt3(int [],int);
void smalst(int [],int,int);
void swap(int &,int &);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE = 200000;
    const int utilize = SIZE/2;
    int array[utilize] = {};
    int copyA[utilize] = {};
    int copyB[utilize] = {};
    
    filAray(array, utilize);
    copyF(array, copyA, utilize);
    copyF(array, copyB, utilize);
    
 //   prntAry(array, utilize, 10);
 //   prntAry(copyA, utilize, 10);
    
    //Input Values
    unsigned int begM = static_cast<unsigned int>(time(0));
    markSrt(array, utilize);
    unsigned int endM = static_cast<unsigned int>(time(0));
    cout<<"Total Time for 1 Mark sort = "<<endM-begM<<" sec"<<endl;
    
  //  prntAry(array, utilize, 10);
    
    unsigned int beg3=static_cast<unsigned int>(time(0));
    mrkSrt3(copyA,utilize);
    unsigned int end3=static_cast<unsigned int>(time(0));
    cout<<"Total Time for 3 Mark sort = "<<end3-beg3<<" sec"<<endl;

    unsigned int begB = static_cast<unsigned int>(time(0));
    BubSort(copyB, utilize);
    unsigned int endB = static_cast<unsigned int>(time(0));
    cout<<"Total Time for Bubble sort = "<<endB-begB<<" sec\n"<<endl;
    
 //   prntAry(copyA, utilize, 10);
    cout<<"Time savings between 1 Mark and 3 Mark is = "<<(1.0f*(end3-beg3)/(endM-begM)-1)*100<<"%"<<endl;
    cout<<"Time savings between 1 Mark and Bubble is = "<<(1.0f*(endB-begB)/(endM-begM)-1)*100<<"%"<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

void copyF(int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void markSrt(int a[],int n){
    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            if(a[j]>a[i]){
                a[j]=a[j]^a[i];
                a[i]=a[j]^a[i];
                a[j]=a[j]^a[i];
            }
        }        
    }
}

void BubSort (int a[], int n) {
    bool swap;
    int temp;
    do {
        swap = false;
        for (int count = 0; count < n-1; count++) {
            if (a[count] > a[count+1]) {
                temp = a[count];
                a[count] = a[count+1];
                a[count+1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

void filAray(int a[],int n) {
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}

void prntAry(int a[], int n, int perLine) {
    cout<<endl;
    for (int i = 0; i<n; i++) {
        cout<<a[i]<<" ";
        if (i%perLine == perLine-1) cout<<endl;
    }
    cout<<endl;
}

void mrkSrt3(int a[],int n){
    for(int i=0;i<n-1;i++){
        smalst(a,n,i);
    }    
}

void smalst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

void swap(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}




