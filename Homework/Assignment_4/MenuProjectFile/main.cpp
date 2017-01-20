
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 17, 2017, 12:12 PM
 * Purpose: Assignment_4
 */

//System Libraries
#include <iostream>     //Input Output Library
#include <cstdlib>      //Random number generator
#include <ctime>        //Time Library
#include <iomanip>      //Format Library
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
    char choice;
    
    //Loop on the menu
    do { 
        //Input Values    
        cout<<"------------------------------------------------"<<endl;
        cout<<"              CHOOSE FROM THE LIST"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Type 1 : Homework Problem Sum Of Numbers"<<endl;
        cout<<"Type 2 : Homework Problem Ocean Levels"<<endl;
        cout<<"Type 3 : Homework Problem Calories Burned"<<endl;
        cout<<"Type 4 : Homework Problem Membership Fee Increase"<<endl;
        cout<<"Type 5 : Homework Problem Distance Traveled"<<endl;
        cout<<"Type 6 : Homework Problem Pennies For Pay"<<endl;
        cout<<"Type 7 : Homework Problem Payroll Report"<<endl;
        cout<<"Type 8 : Homework Problem Guessing Game"<<endl;
        cout<<"Type 9 : Homework Problem Square Display"<<endl<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;
        
        //Switch to determine problem
        switch (choice){
            case '1': {
                cout<<"TITLE: SUM OF NUMBERS"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob1"<<endl<<endl;
                cout<<"Problem: Write a program that asks the user for a positive integer value.\n"
                    <<"The program should use a loop to get the sum of all the integers from 1 up to\n"
                    <<"the number entered. For example, if the user enters 50, the loop will find the\n"
                    <<"sum of 1, 2, 3, 4, … 50.!"<<endl<<endl;
                
                // -------------------------------------------------------------
                
                //Declare Variables
                int numIn,         //User input of a positive integer
                    sum = 0,       //Sum of all numbers to user input
                    num = 1;       //Number starts from 1 to user input
                
                //Input Values
                cout<<"Enter a positive Integer Number: ";
                cin>>numIn;
                cout<<endl;
                cout<<"Count\t"<<"\tSum"<<endl;
                
                //Loop and Process
                do {
                    if (numIn >= 1) {
                        sum+=num;
                        num++;
                        cout<<num-1<<"\t\t"<<sum<<endl;
                    }
                    else {
                        cout<<"Only enter a positive number!"<<endl;
                    }
                } while (num <= numIn);
                
                //Output values
                if (numIn >= 1) cout<<"\nThe sum of "<<numIn<<" is "<<sum<<endl<<endl;                
                break;
            }
            
            case '2': {                
                cout<<"TITLE: OCEAN LEVELS"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob3"<<endl<<endl;
                cout<<"Problem: Assuming the ocean’s level is currently rising at about 1.5 millimeters\n"
                    <<"per year, write a program that displays a table showing the number of millimeters\n"
                    <<"that the ocean will have risen each year for the next 25 years."<<endl<<endl;
                
                // -------------------------------------------------------------
                
                //Declare Variables
                float lvl = 0;          //Ocean level per year

                cout<<"--------------------------------"<<endl;
                cout<<"             TABLE"<<endl;
                cout<<"--------------------------------"<<endl;
                //Loop ocean level til 25 years
                for (unsigned short yrs = 1; yrs <= 25; yrs++) {   
                    lvl += 1.5;
                    cout<<"Year "<<yrs<<": ";
                    cout<<"\t";
                    cout<<lvl<<" millimeters."<<endl;
                }    
                cout<<endl;
                break;
            }
            
            case '3': {
                cout<<"TITLE: SUM OF NUMBERS"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob1"<<endl<<endl;
                cout<<"Problem: Running on a particular treadmill you burn 3.6 calories per minute.\n"
                    <<"Write a program that uses a loop to display the number of calories burned after\n"
                    <<"5, 10, 15, 20, 25, and 30 minutes."<<endl<<endl;
                                
                // -------------------------------------------------------------
                
                //Declare Variables
                float calBurn = 0;      //Total Calories burned per 5 minutes

                cout<<"Calories Burned After Running: "<<endl<<endl;
                //Loop and Process
                for (unsigned char cal = 5; cal <= 30; cal+=5) {
                calBurn += (3.6*5);
                cout<<static_cast<float>(cal)<<" minutes\t=   "<<calBurn<<" calories burned."<<endl;
                }
                cout<<endl;                
                break;
            }
            
            case '4': {
                cout<<"TITLE: MEMBERSHIP FEE INCREASE"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob5"<<endl<<endl;
                cout<<"Problem: A country club, which currently charges $2,500 per year for membership, has\n"
                    <<"announced it will increase its membership fee by 4% each year for the next six years.\n"
                    <<"Write a program that uses a loop to display the projected rates for the next six years."<<endl<<endl;
                                
                // -------------------------------------------------------------
                
                //Declare Variables
                float fee = 2500,          //Starting fee before it increase for the next five years
                      inc = 0.04;          //Increase Percentage

                cout<<"       COUNTRY CLUB "<<endl<<endl;
                cout<<"    CURRENT FEE: $ "<<fee<<endl<<endl;
                cout<<"---------------------------\n"
                    <<"      Yearly Increase\n"
                    <<"---------------------------\n"<<endl;

                for (unsigned char yrs = 1; yrs <= 6; yrs++) {
                    fee += (fee*inc);
                    cout<<fixed<<setprecision(2)<<showpoint;
                    cout<<"    Year "<<static_cast<int>(yrs)<<":  $ "<<fee<<endl;
                }
                cout<<endl;
                break;
            }
            
            case '5': {
                cout<<"TITLE: DISTANCE TRAVELED"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob6"<<endl<<endl;
                cout<<"Problem: The distance a vehicle travels can be calculated as follows:\n"
                    <<"                 distance = speed * time\n"
                    <<"Write a program that asks the user for the speed of a vehicle (in miles per\n"
                    <<"hour) and how many hours it has traveled. The program should then use a loop\n"
                    <<"to display the distance the vehicle has traveled for each hour of that time period.\n"
                    <<"     Input Validation: Do not accept a negative number for speed and do not accept\n"
                    <<"any value less than 1 for time traveled."<<endl<<endl;
                               
                // -------------------------------------------------------------
                
                //Declare Variables
                int spdIn,              //User input for speed 
                    hrsTrv,             //User input for hours traveled
                    dstnce;             //Distance per mile

                cout<<"Calculate the distance you traveled by entering the hours and speed for your travel!\n"
                    <<"REMINDER: Minimum of hours input is 1 and no '0' for speed. Doing otherwise will get you an INVALID INPUT!"
                    <<endl<<endl;
                cout<<"What is the speed of your vehicle in mph? ";
                cin>>spdIn;
                cout<<"How many hours has it traveled? ";
                cin>>hrsTrv;
                cout<<endl;

                if ((hrsTrv >= 1) && (spdIn > 0)) {

                    cout<<"Hour\t  Distance Traveled\n"
                        <<"----------------------------------\n";

                    for (int hrs = 1; hrs <= hrsTrv; hrs++) {
                        dstnce = spdIn * hrs;
                        cout<<hrs<<"\t\t"<<dstnce<<endl;
                    }
                }
                else {
                    cout<<"INVALID INPUT!"<<endl;
                }
                cout<<endl;
                break;
            }
            
            case '6': {
                cout<<"TITLE: PENNIES FOR PAY"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob7"<<endl<<endl;
                cout<<"Problem: Write a program that calculates how much a person would earn over a period\n"
                    <<"of time if his or her salary is one penny the first day and two pennies the second day,\n"
                    <<"and continues to double each day. The program should ask the user for the number of days.\n"
                    <<"Display a table showing how much the salary was for each day, and then show the total pay\n"
                    <<"at the end of the period. The output should be displayed in a dollar amount, not the number \n"
                    <<"of pennies.\n"
                    <<"    Input Validation: Do not accept a number less than 1 for the number of days worked."<<endl<<endl;
                
                // -------------------------------------------------------------
                
                //Declare Variables
                int daysIn;             //User input of working days
                float penny = 0.01f;    //Starting salary
                double totSal = 0;      //Total salary based on number of days

                cout<<"REMINDER: Minimum work day is 1."
                    <<"\nMaximum work day is 53.\nAny other input will result to invalid input!"<<endl<<endl;
                cout<<"How many days are you going to work? ";
                cin>>daysIn;
                cout<<endl<<fixed<<setprecision(2)<<showpoint;
                
                //Loop in if-else statement
                if ((daysIn >=1) && (daysIn <= 53)  ) {
                cout<<"     SALARY\n";
                for (int day = 1; day <= daysIn; day++) {
                    if (day >=2) {
                        penny*=2;
                    }
                    totSal += penny;
                    cout<<"Day "<<day<<":\t$ "<<penny<<endl;
                }
                cout<<endl;
                cout<<"Days Worked:\t"<<daysIn<<" days"<<endl;
                cout<<"Total Salary:\t$ "<<totSal<<endl;
                }
                else {
                    cout<<"INVALID INPUT!"<<endl;
                }                
                cout<<endl;
                break;
            }
            
            case '7': {
                cout<<"TITLE: PAYROLL REPORT"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob15"<<endl<<endl;
                cout<<"Problem: Write a program that displays a weekly payroll report. A loop in the program\n"
                    <<"should ask the user for the employee number, gross pay, state tax, federal tax, and FICA\n"
                    <<"withholdings. The loop will terminate when 0 is entered for the employee number. After the\n"
                    <<"data is entered, the program should display totals for gross pay, state tax, federal tax,\n"
                    <<"FICA withholdings, and net pay.\n"
                    <<"     Input Validation: Do not accept negative numbers for any of the items entered. Do not\n"
                    <<" accept values for state, federal, or FICA withholdings that are greater than the gross pay.\n"
                    <<"If the sum state tax + federal tax + FICA withholdings for any employee is greater than gross\n"
                    <<"pay, print an error message and ask the user to reenter the data for that employee."<<endl<<endl;
                                
                //--------------------------------------------------------------
                
                //Declare Variables
                int empNum;         //User input for employee number
                float grsPay,       //Gross pay
                      st8Tax,       //State tax
                      fedTax,       //Federal Tx
                      widFICA,      //FICA Withholdings
                      netPay,       //Net pay or deductions
                      sum;          //sum of state tax, federal tax and FICA Withholdings

                cout<<"REMINDERS: Entering 0 is exiting the program!"<<endl<<endl;    
                cout<<"PLEASE ENTER!"<<endl<<endl<<fixed<<setprecision(2)<<showpoint;

                //Loop and process
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
                cout<<endl;
                break;
            }
            
            case '8': {
                cout<<"TITLE: RANDOM NUMBER GUESSING GAME"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob20&21"<<endl<<endl;
                cout<<"Write a program that generates a random number and asks the user to guess what the\n"
                    <<"number is. If the user’s guess is higher than the random number, the program should\n"
                    <<"display “Too high, try again.” If the user’s guess is lower than the random number,\n"
                    <<"the program should display “Too low, try again.” The program should use a loop that\n"
                    <<"repeats until the user correctly guesses the random number. When the user correctly\n"
                    <<"guesses the random number, the program should display the number of guesses.\n"<<endl<<endl;
                                
                // -------------------------------------------------------------
                
                //Declare Variables
                srand(static_cast<unsigned int>(time(0)));       //Set random number seed using time
                short guess,        //User input of guess
                      loss = 0,     //Count of losing guesses 
                      number;       //Random Number

                number = rand()%100+1;  //Value range from 1 to 100
                cout<<"Ranging from 1 to 100"<<endl;
                cout<<"The number is..."<<endl<<endl;

                //Loop and process
                do {
                    cout<<"What's your guess? ";
                    cin>>guess;
                    cout<<endl;

                    if ((guess > number) && (guess > 0) && (guess < 101)) {
                        cout<<"The number is too high! Try again!"<<endl;
                        loss++;
                        cout<<"Guesses so far: "<<loss<<endl<<endl;
                    }
                    else if ((guess < number) && (guess > 0) && (guess < 101)) {
                        cout<<"The number is too low! Try again!"<<endl;
                        loss++;
                        cout<<"Guesses so far: "<<loss<<endl<<endl;
                    }
                    else if (guess == number) {
                        cout<<"The right answer is "<<number<<" and your answer is "<<guess<<endl;
                        cout<<"Congratulations! You got the right answer!\n";  
                        cout<<"Total Number of Guesses: "<<loss<<endl;
                    }
                    else if ((guess < 1) || (guess > 100)) {
                        cout<<"INVALID INPUT! This guess is not counted."<<endl<<endl;
                    }
                } while (guess != number);
                cout<<endl;
                break;
            }
            
            case '9': {
                cout<<"TITLE: SQUARE DISPLAY"<<endl;
                cout<<"BOOK: Gaddis_8thEd_Chap5_Prob22"<<endl<<endl;
                cout<<"Write a program that asks the user for a positive integer no greater than 15. The\n"
                    <<"program should then display a square on the screen using the character ‘X’. The number\n"
                    <<"entered by the user will be the length of each side of the square."<<endl<<endl;
                
                //--------------------------------------------------------------
                
                //Declare Variables
                string show = "X";
                short inLine;       //User input in how many lines to use


                cout<<"REMINDER: Only input positive integers not greater than 15! Doing otherwise"<<endl
                    <<"will give you an INVALID INPUT! Minimum input is 1."<<endl<<endl;
                cout<<"Input: ";
                cin>>inLine;
                cout<<endl;

                //Loop and process with if-else statement
                if ((inLine >= 1) && (inLine <= 15)) {    
                    for (int line = 1; line <= (inLine*inLine); line++) {        
                        cout<<show;
                        if ((line%inLine)==0) cout<<endl;       //Counter so output will go on the next line    
                  }
                }
                else cout<<"INVALID INPUT!"<<endl;                
                cout<<endl;
                break;
            }
            default: cout<<"You are exiting the program!"<<endl;
        }
    } while (choice>='1' && choice <='9');

        
        
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
    
}
