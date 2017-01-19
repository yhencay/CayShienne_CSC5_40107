
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Penny Doubling for salary and pay
 *          31 days good for using integers
 *      Problem: Write a program that calculates how much a person would earn 
 * over a period of time if his or her salary is one penny the first day and two 
 * pennies the second day, and continues to double each day. The program should 
 * ask the user for the number of days. Display a table showing how much the 
 * salary was for each day, and then show the total pay at the end of the period. 
 * The output should be displayed in a dollar amount, not the number of pennies.
 *      Input Validation: Do not accept a number less than 1 for the number 
 *                      of days worked.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
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
    int salary = 1, totPay = 0, maxDays = 30; //Salary and pay in pennies
    
    for (int day=1;day<=maxDays;day++,salary*=2) {
        int cents = salary%100; //last 2 digits for penny
        int dollars = (salary-cents)/100; //2 digits less
        //Format the output for dollars and cents
        cout<<"Salary for day "<<day<<" = $"<<dollars<<"."
            <<(cents<10?'0':'\0')<<cents<<endl;
        totPay+=salary; //Sum the salary
        cents=totPay%100;
        dollars = (totPay-cents)/100;
        cout<<"Total pay for day "<<day<<" = $"<<dollars<<"."
            <<(cents<10?'0':'\0')<<cents<<endl<<endl;              
    }
        //Predicting result
        double salLDay = (pow(2,maxDays-1))/100;
        double totLDay = (pow(2,maxDays)-1)/100;
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<"Final Salary Predicted = $"<<salLDay<<endl;
        cout<<"Final Salary Predicted = $"<<totLDay<<endl;
    /*
    int daysIn;             //User input of working days
    float penny = 0.01f,    //Starting salary
          totSal = 0;         //Total salary based on number of days
    
    cout<<"How many days are you going to work? ";
    cin>>daysIn;
    cout<<endl<<fixed<<setprecision(2)<<showpoint;
    
    if (daysIn >=1 ) {
        cout<<"     SALARY\n";
        for (int day = 1; day <= daysIn; day++) {
            penny*=2;    
            totSal += penny;
            cout<<"Day "<<day<<":   $ "<<penny<<endl;
        }
        cout<<endl;
        cout<<"Days Worked:   "<<daysIn<<endl;
        cout<<"Total Salary:  $ "<<totSal<<endl;
    }
    else {
        cout<<"INVALID INPUT!"<<endl;
    }
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
     * */
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

