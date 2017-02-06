/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 2:55 PM
 * Purpose: Homework Number Analysis Program
 * 
 *      Problem: Write a program that asks the user for a file name. Assume the 
 * file contains a series of numbers, each written on a separate line. The 
 * program should read the contents of the file into an array and then display 
 * the following data:
 * 
 *          • The lowest number in the array
 *          • The highest number in the array
 *          • The total of the numbers in the array
 *          • The average of the numbers in the array
 * 
 * If you have downloaded this book’s source code from the companion Web site, 
 * you will find a file named numbers.txt in the Chapter 07 folder. You can use 
 * the file to test the program. (The companion Web site is at 
 * www.pearsonhighered.com/gaddis .)
 */

//System Libraries
#include <iostream>
#include <fstream>
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
    const int SIZE = 12;                //Size for array
    int numbers[SIZE] = {};             //Array for numbers to bet taken from file
    int count = 0;                      //Loop counter
    int highest = 0, total = 0;         //Variable for highest and total
    float average;                      //Variable for average
    
    //Input Values
    ifstream in;                        
    in.open("numbers.txt");             //Get values from file
    
    while (count < SIZE && in>>numbers[count]) count++;
    
    in.close();
    
    //Process by mapping inputs to outputs
    for (count = 0; count <SIZE;count++) {          //Loop to determine highest from values in number file
        highest = (numbers[count]>highest)?numbers[count]:highest;
        total += numbers[count];                    //Add value to total
    }
    
    int lowest = highest;                           //Set lowest to highest
    for (count = 0; count <SIZE;count++) {          //Loop to determine lowest from values in number file
        lowest = (numbers[count]<lowest)?numbers[count]:lowest;
    }
    
    average = total/12.0f;                          //Calculate average
    
    //Output values
    cout<<"The numbers are: ";                      //Display numbers from file
    for (count = 0;count<SIZE;count++) {
        cout<<numbers[count]<<" ";
    }
    cout<<"\n\nHighest Number: "<<highest<<endl;                //Display results
    cout<<"Lowest Number: "<<lowest<<endl<<endl;
    cout<<"The total is "<<total<<endl<<fixed<<setprecision(2);
    cout<<"The average is "<<average<<endl;
   
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

