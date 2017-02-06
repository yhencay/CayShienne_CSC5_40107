/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 1, 2017, 1:35 PM
 * Purpose: Homework Lottery Application
 * 
 *      Problem: Write a program that simulates a lottery. The program should 
 * have an array of five integers named lottery and should generate a random 
 * number in the range of 0 through 9 for each element in the array. The user 
 * should enter five digits, which should be stored in an integer array named 
 * user . The program is to compare the corresponding elements in the two arrays 
 * and keep a count of the digits that match. For example, the following shows 
 * the lottery array and the user array with sample numbers stored in each. 
 * There are two matching digits (elements 2 and 4).
 * 
 *              lottery array:
 *                      7   4   9   1   3
 * 
 *              user array:
 *                      4   2   9   7   3
 * 
 *  The program should display the random numbers stored in the lottery array 
 * and the number of matching digits. If all of the digits match, display a 
 * message proclaiming the user as a grand prize winner.
 */

//System Libraries
#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE = 5;                         //Size of array
    int lottery[SIZE] = {};                     //Array for lottery result
    int user[SIZE] = {};                        //Array for user input
    int right[SIZE] = {};                       //Array for matched numbers
    short count,                                //Loop counter
          random,                               //Generated random number for lottery array 
          rAns = 0;                             //Matched numbers
    
    //Input Values
    cout<<"Input 5 numbers ranging from 1 to 9\n"<<endl;
    for (count = 0; count <SIZE; count++) {
        random = rand()%9+1;                    //Values from 1-9
        lottery[count] = random;                //Add the generated random number to the lottery array
    }
    
    for (count = 0;count<SIZE; count++) {       //Type in bet numbers
        do {
            cout<<"Number: ";                   //Loop if user input is less than 1 or greater than 9
            cin>>user[count];
            if (user[count]<1 ||user[count]>9) cout<<"\nNumbers can only be from 1 to 9. Try again!\n\n";
        } while (user[count]<1 ||user[count]>9);
    }    
    
    //Process by mapping inputs to outputs    
    for (count = 0; count < SIZE; count++) {        
        if (lottery[count] == user[count]) {    //Check if lottery and user numbers matched 
            rAns++;                             //Add matched number to the matched array
            right[count] = user[count];
        }
        else cout<<"\0";            //If numbers didn't match, void
    }
            
    //Output values
    cout<<"\nWINNING NUMBERS: \t";                                      //Display winning numbers that are in lottery array
    for (count = 0; count<SIZE; count++) cout<<lottery[count]<<" ";
    cout<<"\nYOUR NUMBERS: \t\t";                                       //Display user input  that are in user array
    for (count = 0; count<SIZE; count++) cout<<user[count]<<" ";
    
    cout<<endl;
    if (rAns == 6) cout<<"\nYOU WON THE GRAND PRIZE!\n"<<endl;          //If user got everything right, display grand prize win!
    else if (rAns > 0) {                                                //If user matched a number, display matched numbers
        cout<<"\nYou didn't win the grand prize but you have "<<rAns<<" matching numbers!"<<endl<<endl;
        cout<<"MATCHED: ";
        for (count = 0; count<SIZE; count++) {
            if (right[count] == 0) cout<<"\0";
            else cout<<right[count]<<" ";
        }
    }
    else cout<<"\nThere are no matching numbers!\n"<<endl;              //Display if there's no matching numbers
    
    cout<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

