
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework Payroll Report
 *      Problem: Write a program that displays a weekly payroll report. A loop 
 * in the program should ask the user for the employee number, gross pay, state 
 * tax, federal tax, and FICA withholdings. The loop will terminate when 0 is 
 * entered for the employee number. After the data is entered, the program should 
 * display totals for gross pay, state tax, federal tax, FICA withholdings, and 
 * net pay.
 *          Input Validation: Do not accept negative numbers for any of the 
 * items entered. Do not accept values for state, federal, or FICA withholdings 
 * that are greater than the gross pay. If the sum state tax + federal tax + 
 * FICA withholdings for any employee is greater than gross pay, print an error 
 * message and ask the user to reenter the data for that employee.
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
    int empNum;
    float grsPay,
          st8Tax,
          fedTax,
          widFICA,
          netPay,
          sum;
    
    cout<<"REMINDERS: Entering 0 is exiting the program!"<<endl<<endl;    
    cout<<"PLEASE ENTER!"<<endl<<endl<<fixed<<setprecision(2)<<showpoint;
                
    do {
        cout<<"Employee Number: ";
        cin>>empNum;
        if (empNum > 0) {
            cout<<"Gross Pay: $ ";
            cin>>grsPay;
            cout<<"State Tax: $ ";
            cin>>st8Tax;
            cout<<"Federal Tax: $ ";
            cin>>fedTax;
            cout<<"FICA Withholdings: $ ";
            cin>>widFICA;
            cout<<endl;
            
            sum = st8Tax + fedTax + widFICA;
            netPay = grsPay - sum;
            
                if ((st8Tax > grsPay) || (fedTax > grsPay) || (widFICA > grsPay)) {
                    cout<<"Values for State Tax, Federal Tax or FICA withholdings \ncannot be greater than gross pay!"<<endl; 
                    cout<<"\nPlease re-enter the data!\n"<<endl;
                } 
                else if (sum > grsPay) {
                    cout<<"The sum of State Tax, Federal Tax and FICA Withholdings cannot be larger than Gross pay!\n"<<endl
                        <<"Please re-enter the data!\n"<<endl;;
                }
                else {
                    cout<<"-----------------------------------"<<endl;
                    cout<<"              RESULTS            "<<endl;
                    cout<<"-----------------------------------"<<endl;
                    cout<<"Employee Number: "<<empNum<<endl;
                    cout<<"Gross Pay: $ "<<grsPay<<endl;
                    cout<<"State Tax: $ "<<st8Tax<<endl;
                    cout<<"Federal Tax: $ "<<fedTax<<endl;
                    cout<<"FICA Withholdings: $ "<<widFICA<<endl<<endl;
                    cout<<"Total Deductions: $ "<<sum<<endl;
                    cout<<"NET PAY: $ "<<netPay<<endl;
                    cout<<"-----------------------------------"<<endl;
                    cout<<endl;
                }
        }
        else if (empNum == 0) {
            cout<<"\nEXITING..."<<endl<<endl;
            cout<<"Thank you for using the system!"<<endl;
        }
        else {
            cout<<"\nINVALID INPUT! We do not accept negative numbers!"<<endl;
        }
    } while (empNum > 0);

    
        
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

