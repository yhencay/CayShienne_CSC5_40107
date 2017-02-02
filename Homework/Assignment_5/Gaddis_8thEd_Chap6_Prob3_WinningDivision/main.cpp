/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 31, 2017, 8:19 PM
 * Purpose: Homework Winning Division
 * 
 *      Problem: Write a program that determines which of a company’s four 
 * divisions (Northeast, Southeast, Northwest, and Southwest) had the greatest 
 * sales for a quarter. It should include the following two functions, which are 
 * called by main.
 *  • double getSales() is passed the name of a division. It asks the user for 
 * a division’s quarterly sales figure, validates the input, then returns it. 
 * It should be called once for each division.
 *  • void findHighest() is passed the four sales totals. It determines which is 
 * the largest and prints the name of the high grossing division, along with its 
 * sales figure. 
 *      Input Validation: Do not accept dollar amounts less than $0.00.
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
float sales();          //User input of sales figure
void hiesP3(float, float, float, float);       //find division with highest sales figure

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float slsNE, slsSE, slsNW, slsSW;       //Sales for Northeast, Southeast, Northwest and Southwest
    
    //Input Values
    cout<<"Northeast Division"<<endl;       //Prompt user to input sales figure for each division
    slsNE = sales();                        //Call function to do that
    cout<<"Southeast Division"<<endl;
    slsSE = sales();
    cout<<"Northwest Division"<<endl;
    slsNW = sales();
    cout<<"Southwest Division"<<endl;
    slsSW = sales();
    
    //Process by mapping inputs to outputs
    //Output values
    
    cout<<fixed<<setprecision(2)<<showpoint;        //Set format
    
    cout<<"Northeast Division: "<<setw(5)<<"$"<<slsNE<<endl;
    cout<<"Southeast Division: "<<setw(5)<<"$"<<slsSE<<endl;        //Display Sales figure of each division based on
    cout<<"Northwest Division: "<<setw(5)<<"$"<<slsNW<<endl;        //user input
    cout<<"Southwest Division: "<<setw(5)<<"$"<<slsSW<<endl;
    cout<<endl;
    
    hiesP3(slsNE, slsSE, slsNW, slsSW);         //Display result from hiesP3 function
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//************************ Sales Figure Input **********************************
//Description: Prompt user to input values for each division
//Inputs:   float - since money-based figures need decimal points
//Outputs:  Outputs invalidity for input and loops until right value is entered
//******************************************************************************

float sales() {
    float sales;
    cout<<"Enter Sales: $";
    cin>>sales;                 //Input value by division based on main
    cout<<endl;
    
    while (sales < 0) {                 //Continue loop until input is valid
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Enter Sales: $";
        cin>>sales;
        cout<<endl;
    }
    return sales;
}

//************************ Getting Largest Sales *******************************
//Description: Determine which division has largest sales figure
//Inputs:   No inputs but uses value passed by sales function
//Outputs:  Displays result along with the value of winning division figure
//******************************************************************************

void hiesP3(float a, float b, float c, float d) {
    float largest = 0.0f;                           //Determined highest sales figure
    string ne = "Northeast Division Wins!",         
           se = "Southeast Division Wins!", 
           nw = "Northwest Division Wins!", 
           sw = "Southwest Division Wins!";
    
    largest = (a>largest)?a:largest;
    largest = (b>largest)?b:largest;        //Compare values to each one
    largest = (c>largest)?c:largest;
    largest = (d>largest)?d:largest;
   
    if (largest == a)cout<<ne;
    if (largest == b)cout<<se;
    if (largest == c)cout<<nw;          //Whichever is the highest will output equivalent string
    if (largest == d)cout<<sw;
    
    cout<<"\n$"<<largest<<endl;         //Display amount won!
}

