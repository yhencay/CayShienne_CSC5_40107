
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017, 10:44 PM
 * Purpose: Template to be used for all programming projects 
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
    bool x, y;
    
    //Input Values
    x=true;
    y=true;
    
    //Output header
    cout<<"--------------------------------------------------------------------------------------------- "<<endl;
    cout<<"X | Y | !X | !Y | X&&Y | X||Y | X^Y | (X^Y)^Y | (X^Y)^X | !X(X&&Y) | !X||!Y | !(X||Y) | !X&&Y "<<endl
        <<"--------------------------------------------------------------------------------------------- "
        <<endl;
    
    //Process and output for the first row
    cout<<(x?'T':'F')<<" | ";            
    cout<<(y?'T':'F')<<" |  ";    
    cout<<(!x?'T':'F')<<" |  ";            
    cout<<(!y?'T':'F')<<" |   ";
    cout<<(x&&y?'T':'F')<<"  |   ";
    cout<<(x||y?'T':'F')<<"  |  ";
    cout<<(x^y?'T':'F')<<"  |    ";
    cout<<((x^y)^y?'T':'F')<<"    |    ";
    cout<<((x^y)^x?'T':'F')<<"    |    ";
    cout<<(!(x&&y)?'T':'F')<<"     |   ";
    cout<<(!x||!y?'T':'F')<<"    |    ";
    cout<<(!(x||y)?'T':'F')<<"    |   ";
    cout<<(!x&&!y?'T':'F')<<" ";
    cout<<endl;
    
    //Process and output for the second row
    y=false;
    cout<<(x?'T':'F')<<" | ";            
    cout<<(y?'T':'F')<<" |  ";    
    cout<<(!x?'T':'F')<<" |  ";            
    cout<<(!y?'T':'F')<<" |   ";
    cout<<(x&&y?'T':'F')<<"  |   ";
    cout<<(x||y?'T':'F')<<"  |  ";
    cout<<(x^y?'T':'F')<<"  |    ";
    cout<<((x^y)^y?'T':'F')<<"    |    ";
    cout<<((x^y)^x?'T':'F')<<"    |    ";
    cout<<(!(x&&y)?'T':'F')<<"     |   ";
    cout<<(!x||!y?'T':'F')<<"    |    ";
    cout<<(!(x||y)?'T':'F')<<"    |   ";
    cout<<(!x&&!y?'T':'F')<<" ";
    cout<<endl;
    
    //Process and output for the third row
    x=false;
    y=true;
    cout<<(x?'T':'F')<<" | ";            
    cout<<(y?'T':'F')<<" |  ";    
    cout<<(!x?'T':'F')<<" |  ";            
    cout<<(!y?'T':'F')<<" |   ";
    cout<<(x&&y?'T':'F')<<"  |   ";
    cout<<(x||y?'T':'F')<<"  |  ";
    cout<<(x^y?'T':'F')<<"  |    ";
    cout<<((x^y)^y?'T':'F')<<"    |    ";
    cout<<((x^y)^x?'T':'F')<<"    |    ";
    cout<<(!(x&&y)?'T':'F')<<"     |   ";
    cout<<(!x||!y?'T':'F')<<"    |    ";
    cout<<(!(x||y)?'T':'F')<<"    |   ";
    cout<<(!x&&!y?'T':'F')<<" ";
    cout<<endl;
    
        //Process and output for the fourth row
    x=false;
    y=false;
    cout<<(x?'T':'F')<<" | ";            
    cout<<(y?'T':'F')<<" |  ";    
    cout<<(!x?'T':'F')<<" |  ";            
    cout<<(!y?'T':'F')<<" |   ";
    cout<<(x&&y?'T':'F')<<"  |   ";
    cout<<(x||y?'T':'F')<<"  |  ";
    cout<<(x^y?'T':'F')<<"  |    ";
    cout<<((x^y)^y?'T':'F')<<"    |    ";
    cout<<((x^y)^x?'T':'F')<<"    |    ";
    cout<<(!(x&&y)?'T':'F')<<"     |   ";
    cout<<(!x||!y?'T':'F')<<"    |    ";
    cout<<(!(x||y)?'T':'F')<<"    |   ";
    cout<<(!x&&!y?'T':'F')<<" ";
    cout<<endl;
    
//Process by mapping inputs to outputs
    //Output values
    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

