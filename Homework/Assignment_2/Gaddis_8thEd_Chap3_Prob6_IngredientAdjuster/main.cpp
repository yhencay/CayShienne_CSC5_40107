
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017, 6:06 PM
 * Purpose: Homework Ingredient Adjuster
 *     Problem: A cookie recipe calls for the following ingredients:
 *                  - 1.5 cups of sugar
 *                  - 1 cup of butter
 *                  - 2.75 cups of flour
 *     The recipe produces 48 cookies with this amount of the ingredients.
 * Write a program that asks the user how many cookies he or she wants to make,
 * and then displays the number of cups of each ingredient needed for the 
 * specified number of cookies. 
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

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float cupsSgr = 1.5,        //Required cups of sugar per 48 pcs. of cookies
          cupBttr = 1,          //Required cups of butter per 48 pcs. of cookies
          cupsFlr = 2.75,       //Required cups of flour per 48 pcs. of cookies
          reqSgr,                //Sugar needed from cookie count input
          reqBttr,               //Butter needed from cookie count input
          reqFlr;                //Flour needed from cookie count input
    unsigned short cookie;       //Input cookies planning to make
    unsigned char bchCkie = 48;  //Number of cookies in complete given ingredients
    
    //Input Values
    cout<<"How many cookies do you want to make? ";
    cin>>cookie;
    
    //Process by mapping inputs to outputs
    reqSgr = (cookie/static_cast<float>(bchCkie))*cupsSgr;
    reqBttr = (cookie/static_cast<float>(bchCkie))*cupBttr;
    reqFlr = (cookie/static_cast<float>(bchCkie))*cupsFlr;
    
    //Output values
    
    cout<<endl<<fixed<<setprecision(2)
        <<" The ingredients you need to make "<<cookie<<" cookie\(s) are:"<<endl<<endl;
    cout<<"     - "<<reqSgr<<" cup\(s) of Sugar"<<endl;
    cout<<"     - "<<reqBttr<<" cup\(s) of Butter"<<endl;
    cout<<"     - "<<reqFlr<<" cup\(s) of Flour"<<endl<<endl;
    cout<<" Good luck making it! ^_^"<<endl;
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

