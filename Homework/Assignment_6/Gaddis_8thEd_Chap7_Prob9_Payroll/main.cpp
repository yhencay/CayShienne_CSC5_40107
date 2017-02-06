/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 4:00 PM
 * Purpose: Homework Payroll
 * 
 *      Problem: Write a program that uses the following arrays:
 * 
 *    • empId : an array of seven long integers to hold employee identification 
 *      numbers. The array should be initialized with the following numbers:
 *          5658845 4520125 7895122 8777541 8451277 1302850 7580489
 *    • hours : an array of seven integers to hold the number of hours worked
 *      by each employee
 *    • payRate : an array of seven double s to hold each employee’s hourly pay 
 *      rate
 *    • wages : an array of seven double s to hold each employee’s gross wages
 * 
 *  The program should relate the data in each array through the subscripts. For 
 * example, the number in element 0 of the hours array should be the number of 
 * hours worked by the employee whose identification number is stored in element 
 * 0 of the empId array. That same employee’s pay rate should be stored in 
 * element 0 of the payRate array. The program should display each employee 
 * number and ask the user to enter that employee’s hours and pay rate. It 
 * should then calculate the gross wages for that employee (hours times pay 
 * rate) and store them in the wages array. After the data has been entered for 
 * all the employees, the program should display each employee’s identification 
 * number and gross wages.
 * 
 *          Input Validation: Do not accept negative values for hours or 
 *              numbers less than 15.00 for pay rate.
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
    const int SIZE = 7;                 //Size for array
    int empID[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};      //ID number for each employee set in array
    int hours[SIZE] = {};               //Array for hours worked
    float payRate[SIZE] = {};           //Array for pay rate
    float wages[SIZE] = {};             //Array for wages 
    int count;                          //Loop counter
    
    //Input Values
    cout<<"Input hours and pay rate for each employee!"<<endl;          
    for (count = 0; count < SIZE; count++) {
        cout<<"\nEmployee "<<empID[count]<<endl;            //Prompt user to input name
        do {                                                //Prompt user to input scores for each 4 tests
            cout<<"Hours: ";                                //Loop if input is invalid (hours less than 0) or (pay rate less than 15)
            cin>>hours[count];
            if (hours[count] < 0) cout<<"\nNo negative input allowed. Try again!"<<endl<<endl;
        } while (hours[count] < 0);
        do {
            cout<<"Pay Rate: ";
            cin>>payRate[count];
            if (payRate[count]<15) cout<<"\nPay rate must be greater than $15. Try again!"<<endl<<endl;
        } while (payRate[count]<15);
        
        //Process by mapping inputs to outputs        
        wages[count] = hours[count] * payRate[count];           //Calculate gross wages      
    }
    
    //Output values
    cout<<endl<<"\tRESULTS"<<endl<<endl<<fixed<<setprecision(2)<<showpoint;     //Display result
    
    for (count = 0; count< SIZE; count++) {                    
        cout<<"Employee "<<empID[count]<<endl;
        cout<<"Gross Wage: $"<<wages[count]<<endl<<endl;
    }
      
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

