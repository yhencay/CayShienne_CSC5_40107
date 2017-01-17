
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 16, 2017, 6:31 PM
 * Purpose: Homework Book Club Points
 *      Problem: Serendipity Booksellers has a book club that awards points to 
 * its customers based on the number of books purchased each month. The points 
 * are awarded as follows:
 *          • If a customer purchases 0 books, he or she earns 0 points.
 *          • If a customer purchases 1 book, he or she earns 5 points.
 *          • If a customer purchases 2 books, he or she earns 15 points.
 *          • If a customer purchases 3 books, he or she earns 30 points.
 *          • If a customer purchases 4 or more books, he or she earns 60 points.
 *   Write a program that asks the user to enter the number of books that he or 
 * she has purchased this month and then displays the number of points awarded. 
 */

//System Libraries
#include <iostream>
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
    short book;        //How many books were bought
    
    //Input Values
    cout<<"Let's calculate the number of points rewarded based on the number of \n"
        <<"books you purchased this month!"<<endl<<endl;
    cout<<"How many books did you buy this month? ";
    cin>>book;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    //Output values
    
    if (book == 0) cout<<"You get 0 points!\n";
    else if (book == 1) cout<<"You get 5 points!\n";
    else if (book == 2) cout<<"You get 15 points!\n";
    else if (book == 3) cout<<"You get 30 points!\n";
    else if (book >= 4) cout<<"You get 60 points!\n";
    else cout<<"ERROR! INVALID INPUT!"<<endl;

        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

