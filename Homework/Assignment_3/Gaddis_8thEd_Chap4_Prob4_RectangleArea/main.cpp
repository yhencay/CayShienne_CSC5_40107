
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 14, 2017, 11:36 PM
 * Purpose: Homework Area of Rectangle
 *      Problem: The area of a rectangle is the rectangle’s length times its 
 * width. Write a program that asks for the length and width of two rectangles. 
 * The program should tell the user which rectangle has the greater area, or if 
 * the areas are the same.
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
    float frsLeng,       //User input of the first rectangle's length
          frsWid,        //User input of the first rectangle's width
          area1,         //Area of the first rectangle
          scnLeng,       //User input of the second rectangle's length
          scnWid,        //User input of the second rectangle's width
          area2;         //Area of the second triangle  
    string result;
    
    //Input Values
    cout<<"Let's determine which rectangle between two input has a greater area \n"
        <<"or if it is the same! Input numbers cannot be less than 1."<<endl<<endl;
    cout<<"Give me the information on the first triangle.\n"
        <<"Length: ";
    cin>>frsLeng;
    cout<<"Width: ";
    cin>>frsWid;
    cout<<endl;
    cout<<"Give me the information on the second triangle.\n"
        <<"Length: ";
    cin>>scnLeng;
    cout<<"Width: ";
    cin>>scnWid;
    cout<<endl;    
    //Process by mapping inputs to outputs
    area1 = frsLeng * frsWid;
    area2 = scnLeng * scnWid;
    
    result = ((area1>area2) && (frsLeng > 0) && (frsWid > 0) && (scnLeng > 0) && (scnWid > 0))?
             "The first triangle has a greater area than the second one!":
             ((area2>area1) && (frsLeng > 0) && (frsWid > 0) && (scnLeng > 0) && (scnWid > 0))?
             "The second triangle has a greater area than the first one!":
             ((area1==area2) && (frsLeng > 0) && (frsWid > 0) && (scnLeng > 0) && (scnWid > 0))?
             "They have the same area!":
             "INVALID INPUT!";
    
    //Output values
    cout<<"---------------------\n"<<"       RESULTS\n"<<"---------------------\n"<<endl;
    cout<<result<<endl<<endl<<fixed<<setprecision(2);
    cout<<"Area of 1st Triangle: "<<area1<<endl
        <<"Area of 2nd Triangle: "<<area2<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

