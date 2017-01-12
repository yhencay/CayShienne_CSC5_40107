
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 11, 2017,  8:54 PM
 * Purpose: Homework Automobile Cost
 *      Problem: Write a program that asks the user to enter the monthly costs
 * or the following expenses incurred from operating his or her automobile: loan
 * payment, insurance, gas, oil, tires, and maintenance. The program should then
 * display the total monthly cost of these expenses, and the total annual cost 
 * of these expenses.
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
    float loan,         //Input loan payment
          insrnce,      //Input insurance cost
          gas,          //Input gas expense
          oil,          //Input oil cost
          tires,        //Input tires cost
          mntnnce,      //Input maintenance cost
          mnthly,       //Total monthly bill/cost of all expense
          annual;       //Total annual bill/cost of all expense          
    
    //Input Values
    cout<<"Let's calculate your monthly and annual expense from operation your automobile!"<<endl;
    cout<<"\nEnter monthly loan payment: $ ";
    cin>>loan;
    cout<<"Enter monthly insurance payment: $ ";
    cin>>insrnce;
    cout<<"Enter monthly gas expense: $ ";
    cin>>gas;  
    cout<<"Enter monthly oil expense: $ ";
    cin>>oil; 
    cout<<"Enter monthly tires cost: $ ";
    cin>>tires; 
    cout<<"Enter monthly maintenance cost: $ ";
    cin>>mntnnce;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    mnthly = (loan + insrnce + gas + oil + tires + mntnnce);
    annual = mnthly * 12;
    
    //Output values
    cout<<fixed<<setprecision(2);
    cout<<"Your total Monthly Expense is: $ "<<mnthly<<endl;
    cout<<"Your total Annual Expense is:  $ "<<annual<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

