/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 12:58 PM
 * Purpose: Homework Chips & Salsa
 * 
 *      Problem: Write a program that lets a maker of chips and salsa keep track 
 * of sales for five different types of salsa: mild, medium, sweet, hot, and zesty. 
 * The program should use two parallel 5-element arrays: an array of strings that 
 * holds the five salsa names and an array of integers that holds the number of 
 * jars sold during the past month for each salsa type. The salsa names should 
 * be stored using an initialization list at the time the name array is created. 
 * The program should prompt the user to enter the number of jars sold for each 
 * type. Once this sales data has been entered, the program should produce a 
 * report that displays sales for each salsa type, total sales, and the names of 
 * the highest selling and lowest selling products.
 * 
 *        Input Validation: Do not accept negative values for number of 
 *                  jars sold.
 */

//System Libraries
#include <iostream>
#include <string>
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
    const int SIZE = 5;             //Size for array
    string salsa[] = {"Mild Salsa", "Medium Salsa", "Sweet Salsa", "Hot Salsa", "Zesty Salsa" };   //Assign values for string array
    string high, low;               //String to display which has highest and lowest number of jars sold
    int sales[SIZE] = {};           //Array for number of jars sold sales
    int count;                      //Loop counter
    int total = 0;                  //Variable for total
    
    //Input Values
    cout<<"Input Number of Jars sold for: "<<endl<<endl;        //Prompt user to input values per salsa type
    
    for (count = 0; count < SIZE; count++) {
        do {                                        //Loop if user input is a negative number
            cout<<salsa[count]<<": ";
            cin>>sales[count];
            if (sales[count] < 0) cout<<"\nNo negative numbers allowed. Try again!\n"<<endl;
        } while (sales[count] < 0);
        total += sales[count];                      //Add sales to total per input
    }
    
    //Process by mapping inputs to outputs   
    int highest = 0;
    for (count = 0;count < SIZE; count++) {
        if (sales[count]>highest) {                 //Determine highest sales by comparing each array value to another
            highest = sales[count];
            high = salsa[count];
        }
    }
    
    int lowest = highest;                           //Assign lowest value to highest
    for (count = 0;count < SIZE; count++) {
        if (sales[count]<lowest) {                  //Determine lowest sales by comparing each array value to another
            lowest = sales[count];
            low = salsa[count];
        }
    }
    
    //Output values    
    cout<<"\nSALSA\t\tSALES"<<endl;                                 //Display results
    cout<<"-----------------------------"<<endl;
    
    for (count = 0; count<SIZE;count++) {                           
        cout<<salsa[count]<<"\t"<<sales[count]<<" jars"<<endl;
    }
    
    cout<<"\nHIGHEST: "<<highest<<" jars, "<<high<<endl;
    cout<<"LOWEST: "<<lowest<<" jars, "<<low<<endl;
    
    cout<<"\nTOTAL SALES: "<<total<<" jars"<<endl;
      
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

