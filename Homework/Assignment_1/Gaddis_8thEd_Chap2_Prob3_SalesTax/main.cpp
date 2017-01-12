
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Homework Sales Tax
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
    float prchse = 95;          //Total amount of purchase
    float st8tax = 4.0e-2f;     //Percentage of State Tax
    float cntytax = 2.0e-2f;    //Percentage of County Tax
    float st8sls,               //Amount of State Sales based on State Tax
          cntysls,              //Amount of County Sales based on County Tax
          totSls;               //Total amount of sales
    //Input Values
    
    //Process by mapping inputs to outputs
    st8sls = prchse*st8tax;
    cntysls = prchse*cntytax;
    totSls = st8sls+cntysls;
    
    //Output values
    cout<<"The amount of purchase is $ "<<prchse<<endl;
    cout<<"The states sales tax is $ "<<st8sls<<endl;
    cout<<"The county sales tax is $ "<<cntysls<<endl;
    cout<<"\nThe total sales tax on the purchase is $ "<<totSls<<endl;    
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

