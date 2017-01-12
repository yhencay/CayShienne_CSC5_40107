
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 3, 2017, 12:19 PM
 * Purpose: Homework Word Game
 *     Problem: Write a program that plays a word game with the user. The
 * program should ask the user to enter the following:
 *          His or her name         The name of a college       A pet’s name
 *          His or her age          A profession
 *          The name of a city      A type of animal
 *      After the user has entered these items, the program should display the 
 * following story, inserting the user’s input into the appropriate locations:
 *      There once was a person named NAME who lived in CITY . At the age of
 *   AGE , NAME went to college at COLLEGE . NAME graduated and went to work
 *   as a PROFESSION . Then, NAME adopted a(n) ANIMAL named PETNAME . They
 *   both lived happily ever after!
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
    string name,          //Name input
           age,           //Age input
           city,          //City input
           college,       //College input
           career,        //Profession input
           animal,        //Animal input 
           petname;       //Pet name input
            
    //Input Values
    cout<<"Please enter a name: ";
    getline(cin, name);
    cout<<"Please enter age: ";
    getline(cin, age);
    cout<<"Please enter a city: ";
    getline(cin, city);
    cout<<"Please enter a college: ";
    getline(cin, college);
    cout<<"Please enter a profession: ";
    getline(cin, career);
    cout<<"Please enter an animal: ";
    getline(cin, animal);
    cout<<"Please enter a pet name: ";
    getline(cin, petname);
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"\nThere once was a person named "<<name<<" who live in "<<city<<". At the age of "<<endl
        <<age<<", "<<name<<" went to college at "<<college<<". "<<name<<" graduated and went to work "<<endl
        <<"as a "<<career<<". Then, "<<name<<" adopted a\(n) "<<animal<<" named "<<petname<<". They"<<endl
        <<"both lived happily ever after!"<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

