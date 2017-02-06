/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 12:07 PM
 * Purpose: Homework Monekey Business
 * 
 *      Problem: A local zoo wants to keep track of how many pounds of food each 
 * of its three monkeys eats each day during a typical week. Write a program that 
 * stores this information in a two-dimensional 3 × 5 array, where each row 
 * represents a different monkey and each column represents a different day of 
 * the week. The program should first have the user input the data for each 
 * monkey. Then it should create a report that includes the following 
 * information:
 * 
 *   • Average amount of food eaten per day by the whole family of monkeys.
 *   • The least amount of food eaten during the week by any one monkey.
 *   • The greatest amount of food eaten during the week by any one monkey.
 * 
 *      Input Validation: Do not accept negative numbers for pounds of food 
 *                  eaten.
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
    const int ROWS = 3, COLS = 5;       //Size for two dimensional arrays
    float food[3][5] = {};              //Array for food eaten by moneys
    int monkey, days;                   //Loop counters
    float total = 0, ave1, ave2, ave3, ave4, ave5;      //Total and average for food eaten per day of monkeys
    float high1 = 0, high2 = 0, high3 = 0;      //Highest amount food eaten by the monkeys
    
    //Input Values
    cout<<"Input amount of food taken by 3 monkeys (in lbs) for 5 days!"<<endl<<endl; 
    
    for (monkey = 0; monkey<ROWS; monkey++) {                   //Prompt user to input values per monkey and the
        for (days = 0; days<COLS; days++) {                     //food eaten from day 1-3
            do {
                cout<<"Monkey "<<(monkey+1);
                cout<<", Day "<<(days+1)<<": ";                 //Loop until value is valid
                cin>>food[monkey][days];
                if (food[monkey][days] < 0) cout<<"\nNo negative number allowed. Try again!\n"<<endl;                               
            } while (food[monkey][days] < 0);       
        }
        cout<<endl;
    }
    
    //Process by mapping inputs to outputs
    //Calculate average of food eaten per monkey per day
    ave1 = ((food[0][0]) + (food[1][0]) + (food[2][0]))/3;      //Day 1
    ave2 = ((food[0][1]) + (food[1][1]) + (food[2][1]))/3;      //Day 2  
    ave3 = ((food[0][2]) + (food[1][2]) + (food[2][2]))/3;      //Day 3
    ave4 = ((food[0][3]) + (food[1][3]) + (food[2][3]))/3;      //Day 4
    ave5 = ((food[0][4]) + (food[1][4]) + (food[2][4]))/3;      //Day 5
    
    for (int count = 0; count < COLS; count++) {                    //Determine greatest amount of food taken per day per monkey
        high1 = (food[0][count] > high1)?food[0][count]:high1;
        high2 = (food[1][count] > high2)?food[1][count]:high2;
        high3 = (food[2][count] > high3)?food[2][count]:high3;
    }
    
    float low1 = high1, low2 = high2, low3 = high3;                 //Set variable for lowest to highest
    
    for (int count = 0; count < COLS; count++) {                    //Determine least amount of food taken per day per monkey
        low1 = (food[0][count] < low1)?food[0][count]:low1;
        low2 = (food[1][count] < low2)?food[1][count]:low2;
        low3 = (food[2][count] < low3)?food[2][count]:low3;
    }
    
    //Output values
    cout<<fixed<<setprecision(2);                                   //Display results
    
    cout<<"REPORT"<<endl<<endl;
    cout<<"AVERAGE AMOUNT OF FOOD EATEN PER DAY BY THE WHOLE FAMILY OF MONKEYS"<<endl<<endl;
    cout<<"Day 1: "<<ave1<<" lbs."<<endl;
    cout<<"Day 2: "<<ave2<<" lbs."<<endl;
    cout<<"Day 3: "<<ave3<<" lbs."<<endl;
    cout<<"Day 4: "<<ave4<<" lbs."<<endl;
    cout<<"Day 5: "<<ave5<<" lbs."<<endl<<endl;
    
    cout<<"GREATEST AMOUNT OF FOOD TAKEN DURING THE WEEK BY:"<<endl<<endl;
    cout<<"Monkey 1: "<<high1<<" lbs."<<endl;
    cout<<"Monkey 2: "<<high2<<" lbs."<<endl;
    cout<<"Monkey 3: "<<high3<<" lbs."<<endl<<endl;
    
    cout<<"LEAST AMOUNT OF FOOD TAKEN DURING THE WEEK BY:"<<endl<<endl;
    cout<<"Monkey 1: "<<low1<<" lbs."<<endl;
    cout<<"Monkey 2: "<<low2<<" lbs."<<endl;
    cout<<"Monkey 3: "<<low3<<" lbs."<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

