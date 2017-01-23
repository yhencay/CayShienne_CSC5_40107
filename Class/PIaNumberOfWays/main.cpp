
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 23, 2017,  11:00 AM
 * Purpose: PI Function Comparison *    
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const float PI = 4*atan(1); //Geometric identity
const int MAXRND = pow(2,31)-1; //Largest random number

//Function Prototypes
float piSeres(int);
float piRand(int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nTerms;
    float piRnd, piSrs, pCntErC, pCntErS;
    
    /*int max = 0;
    for (int i=1;i<=1000000000;i++) {
        int random=rand();
        if (max<random) max = random;
    }
    cout<<"The largest random number = "<<max<<endl;
    cout<<"Max Random constant = "<<MAXRND<<endl;
    */
    
    //Input Values
    cout<<"Estimate PI"<<endl;
    cout<<"Input the number of Terms">>endl;
    cin>>nTerms;
    
    //Process by mapping inputs to outputs
    piSrs = piSeres(nTerms);
    pCntErS = (PI=piSrs)/PI*100;
    piRnd = piRand(nTerms);
    pCntErC = (PI-piRnd)/PI*100;
    
    //Output values
    cout<<"Pi from the Math Library = "<<PI<<endl;
    cout<<<<"PI approximated using random numbers = "<<piRnd<<endl;
    cout<<"PI Error = "<<pCntErC<<"%"<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

float piSerres(int nTerms) {
    //Declare Variables
    int sign =-1;
    float pi = 1;
    //Loop the series
    for (int term = 2, div = 3; term<=nTerms;term++,div+=2)
    {
        pi+=(sign/static_cast<float>(div));
        sign*=-1;
    }
    return 4*pi;
}

float piRand(int nDarts) {
    //Declare Variables
    int inCircl = 0;
    //Loop and count how many darts fell inside circle
    for (int dart = 1; dart<=nDarts;dart++) {
        float x =static_cast<float>(rand())/MAXRND; //Random number (0, 1)
        float y =static_cast<float>(rand())/MAXRND; //Random number (0, 1)
        if (x*x+y*y<1) inCircl++;;
    }
    //Return pi estimate
    return 4.0f*inCircl/nDarts;
}

