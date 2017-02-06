/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on February 5, 2017, 1:08 AM
  Purpose:  Homework 6 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string> //String Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> 
#include <ctime>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void hProb1();
void hProb2();
void hProb3();
void hProb4();
void call(int [], int, int);
void hProb5();
void hProb6();
void hProb7();
void hProb8();
void hProb9();
void hProb10();

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"-----------------------------------------"<<endl;
        cout<<"           CHOOSE FROM THE LIST          "<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Type A : Homework - ARRAY VALUES"<<endl;
        cout<<"Type B : Homework - RAINFALL STATISTICS"<<endl;
        cout<<"Type C : Homework - CHIPS & SALSA"<<endl;
        cout<<"Type D : Homework - LARGER THAN N"<<endl;
        cout<<"Type E : Homework - MONKEY BUSINESS"<<endl;
        cout<<"Type F : Homework - NUMBER ANALYSIS"<<endl;
        cout<<"Type G : Homework - PAYROLL"<<endl;
        cout<<"Type H : Homework - DRIVER'S LICENSE EXAM"<<endl;
        cout<<"Type I : Homework - GRADE BOOK"<<endl;
        cout<<"Type J : Homework - LOTTERY APPLICATION"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;

        //Switch to determine the Problem
        switch(choice){
            case 'j':
            case 'J': {hProb10();break;}
            case 'i':
            case 'I': {hProb9();break;}
            case 'h':
            case 'H': {hProb8();break;}            
            case 'g':
            case 'G': {hProb7();break;}
            case 'f':
            case 'F': {hProb6();break;}
            case 'e': 
            case 'E': {hProb5();break;}
            case 'd':
            case 'D': {hProb4();break;}
            case 'c':
            case 'C': {hProb3();break;}
            case 'b': 
            case 'B': {hProb2();break;}
            case 'a':
            case 'A': {hProb1();break;}
            
            default: {
                cout<<"You are exiting the program!"<<endl;
                x=false;
            } 
        }
    } while(x);
    
    //Exit stage right!
    return 0;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 1 ***********************************
//Description: Write a program that lets the user enter 10 values into an 
//   array. The program should then display the largest and smallest values 
//   stored in the array.
//Inputs:  integers - to store in array
//Outputs:   highest and lowest value of numbers stored in array
//******************************************************************************

void hProb1(){
    cout<<"Homework - ARRAY VALUES"<<endl<<endl;    
    //Declare Variables
    const short SIZE = 10;                      //Size for array
    int array[SIZE] = {};                       //Array for storing user input number
    int input;                                  //User input
    
    //Input Values    
    cout<<"Type 10 integer numbers!"<<endl<<endl;
    for (input = 1; input <= SIZE; input++) {       //Prompt user to type in integer number
        cout<<"Input Number "<<input<<": ";
        cin>>array[input];                          //Store user input to the array
    }
    
    cout<<"\nValues entered are: ";
    for (input = 1; input <=SIZE;input++)           //Display user input
        cout<<array[input]<<" ";

    //Process by mapping inputs to outputs    
    int highest = array[0];                         //Initialize highest number variable in array

    for (input = 1; input <= SIZE; input++) {       
        if (array[input]>highest)
            highest = array[input];
    }
    
    int lowest = array[1];                          //Initialize lowest number variable in array

    for (input = 1; input <= SIZE; input++) {       //Test each number stored for lowest number
        if (array[input]<lowest)
            lowest = array[input];
    }
   
    //Output values    
    cout<<"\n\nHIGHEST: "<<highest<<endl;           //Display highest and lowest value in array
    cout<<"LOWEST: "<<lowest<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
//Description: Write a program that lets the user enter the total rainfall for
//      each of 12 months into an array of doubles. The program should calculate 
//      and display the total rainfall for the year, the average monthly 
//      rainfall, and the months with the highest and lowest amounts.
//Inputs:  float - rainfall per month
//Outputs:  Total and average rainfall, lowest and highest
//******************************************************************************

void hProb2(){
    cout<<"Homework - RAINFALL STATISTICS"<<endl<<endl;     
    //Declare Variables
    const int SIZE = 12;            //Size for array
    string months[] = {"January", "February", "March", "April",         //Assign values for string array
                       "May", "June", "July", "August", "September",
                       "October", "November", "December" };
    string high, low;               //String to display which has highest and lowest rainfall for month
    float rFall[SIZE] = {};         //Array for rainfall
    int count;                      //Loop counter
    float total = 0, average;       //Variable for total and average rainfall

    //Input Values    
    cout<<"Input Rainfall for: "<<endl<<endl;           //Prompt user to input rainfall for each month 
    
    for (count = 0; count < SIZE; count++) {
        do {
            cout<<months[count]<<": ";                  //Loop if user input is less than 0
            cin>>rFall[count];
            if (rFall[count] < 0) cout<<"\nNo negative numbers allowed. Try again!\n"<<endl;
        } while (rFall[count] < 0);
        total += rFall[count];                  //Add input to total rainfall
    }
    
    //Process by mapping inputs to outputs
    average = total/12;                         //Caluclate average
    
    float highest = 0;
    for (count = 0;count < SIZE; count++) {     //Determine highest value by comparing each
        if (rFall[count]>highest) {             //array stored value
            highest = rFall[count];
            high = months[count];
        }
    }
    
    float lowest = highest;    
    for (count = 0;count < SIZE; count++) {     //Determine lowest value by comparing each
        if (rFall[count]<lowest) {              //array stored value
            lowest = rFall[count];
            low = months[count];
        }
    }
    
    //Output values
    cout<<endl<<fixed<<setprecision(2);
    cout<<"MONTHS\t\tRAINFALL"<<endl;               //Display user input
    cout<<"------------------------"<<endl;
    
    for (count = 0; count<SIZE;count++) {        
        if (count == 1) cout<<months[1]<<"\t"<<rFall[1]<<endl;
        else if (count == 8) cout<<months[8]<<"\t"<<rFall[8]<<endl;         
        else if (count == 10) cout<<months[10]<<"\t"<<rFall[10]<<endl;
        else if (count == 11) cout<<months[11]<<"\t"<<rFall[11]<<endl;
        else cout<<months[count]<<"\t\t"<<rFall[count]<<endl;
    }
    
    cout<<"\nThe total rainfall for the year is "<<total<<endl;
    cout<<"The average monthly rainfall is "<<average<<endl<<endl;          //Display results
    cout<<"HIGHEST: "<<highest<<", "<<high<<endl;                           //Total, Average, Highest and Lowest
    cout<<"LOWEST: "<<lowest<<", "<<low<<endl;
       
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
//Description: Write a program that accepts input and stores in array. Calculate
//      total sales. Determine highest lowest sold number of jars.
//Inputs:  Integer - number of jars sold
//Outputs:  Total sales, highest and lowest sales
//******************************************************************************

void hProb3(){
    cout<<"Homework - CHIPS & SALSA"<<endl<<endl;
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
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
//Description: write a function that accepts three arguments: an array, the size 
//      of the array, and a number n. Assume that the array contains integers. 
//      The function should display all of the numbers in the array that are 
//      greater than the number n.
//Inputs:  Integer - number of toss
//Outputs:  Result if it's heads or tails
//******************************************************************************

void hProb4() {
    cout<<"Homework - LARGER THAN N"<<endl<<endl;
    //Declare Variables
    const int SIZE = 5;             //Size name for array
    int array[SIZE] = {};           //Array for generated number
    int n, count;                   //User input and loop counter
    
    //Input Values
    cout<<"Input a number from 1-10 and see if there's any number greater than\n"
        <<"the typed number in the array.\n"<<endl;                                 //Prompt user to enter values from 1-10
    
    do {
        cout<<"Number: ";           //Loop until user input is valid
        cin>>n;
        
        if (n>10 || n<1) cout<<"\nNo value less than 1 and greater than 10 is accepted! Try again!\n"<<endl;
    } while (n>10 || n<1);
        
    //Process by mapping inputs to outputs
    //Output values
    call(array, SIZE, n);           //Call function
    cout<<endl;
}

//**************************** Call Function ***********************************
//Description: Generate random numbers and determine greater number than user
//          input.
//Inputs:   No inputs but utilizes input from main for n
//Outputs:  Output values greater than user input
//******************************************************************************

void call(int array[], const int SIZE, int n) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    int random;         //Variable for random numbers
    
    for (int count = 0; count<SIZE; count++) {
        random = rand()%10+1;   //Values from 1-10
        array[count] = random;      //Add random number to array
    }
    
    cout<<"\nValues greater than "<<n<<" are: ";
    
    for (int count = 0; count<SIZE; count++) {              //Display if there is any values greater than user input
            if (array[count]>n) cout<<array[count]<<" ";
            else cout<<"";
    }
    
    cout<<endl<<"\nNOTE: If nothing appeared, there is none!"<<endl;
    
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
//Description: Write a program that stores information in a two-dimensional 
//      3 × 5 array, where each row represents a different monkey and each 
//      column represents a different day of the week.
//Inputs:  float - amount of food eaten by monkeys
//Outputs:  Average, greatest, least amount of food taken by monkeys
//******************************************************************************

void hProb5(){
    cout<<"Homework - MONKEY BUSINESS"<<endl<<endl;
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

    cout<<endl;    
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
//Description: Write a program that asks the user for a file name. The program 
//      should read the contents of the file into an array and then display
//      lowest, highest, total and average number in the array, 
//Inputs:  Input from file - numbers.txt
//Outputs:  Output - lowest, highest, total and average number in the array
//******************************************************************************

void hProb6(){
    cout<<"Homework - NUMBER ANALYSIS"<<endl<<endl;
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
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 7 ***********************************
//Description: A program that stores hours, pay rate in an array. Then calculate
//      gross wage for each employee initialized in array string.
//Inputs:  int & float - hours and pay rate
//Outputs:  output - gross wages per employee
//******************************************************************************

void hProb7(){
    cout<<"Homework - PAYROLL"<<endl<<endl;
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
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 8 **********************************
//Description: Compare arrays. Check test answers.
//Inputs:  char - letter answer per number
//Outputs:  score, mistakes, number of wrong answer and its right answer
//******************************************************************************

void hProb8(){
    cout<<"Homework - DRIVER'S LICENSE EXAM"<<endl<<endl;
    //Declare Variables
    const int SIZE = 21;        //Set array size to 21-1
    char right[SIZE]= { '0', 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C',   //Array for the right answers
                        'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 
                        'D', 'B' };     //Set 0 to Subscript 0
    char answers[SIZE];                 //Array for user's answers
    int wrongs[SIZE] = {};              //Array for storing mistakes
    short rAns = 0,             //Count of right answers
          wAns = 0,             //Count of wrong answers
          count,                //Loop counter
          total;                //Count for mistakes and right answers
    
    cout<<"Type in your answer for the corresponding number in the exam."<<endl<<endl;
    
    //Input Values
    for (count = 1; count <SIZE; count++) {
        do {
            cout<<count<<". ";                  //Prompt user to input answers from 1-20
            cin>>answers[count];                //Loop until user input is not A, B, C or D
            
            if (!(answers[count] == 'A' || answers[count] == 'B' || 
                answers[count] == 'C' || answers[count] == 'D')) {
                cout<<"\nYou can only answer with capital letters A, B, C or D. Try again!\n\n";
            } 
        } while (!(answers[count] == 'A' || answers[count] == 'B' || answers[count] == 'C' || answers[count] == 'D'));
    }
    
    //Process by mapping inputs to outputs
    for (count = 1; count < SIZE; count++) {            //Compare array elements
        if (right[count] == answers[count]) rAns++;     //If right answers and user answer matched, increment right answers
        else {              
            wAns++;                                     //If not, increment wrong answers
            wrongs[count] = count;                      //Store number of wrong answer to wrongs array
        }            
    }
    
    total = (rAns >= 15)?(SIZE-1)-rAns:(SIZE-1)-wAns;      //Calculate total mistake and/or total score if score is greater than 15 or not

    //Output values    
    if (rAns >= 15) {           //Display Passed if array matched are greater than or equal to 15. 
        cout<<"\nCongratulations! You passed with a score of "<<rAns<<" out of "<<(SIZE-1)<<" questions!"<<endl; 
        cout<<"You have "<<total<<" mistake(s)!"<<endl<<endl;   //Display mistakes if there are some
    }
    else {          //Display Failed if array matched is less than 15
        cout<<"\nSorry! You failed. Your score is "<<total<<" out of "<<(SIZE-1)<<" questions."<<endl;               
        cout<<"You got "<<wAns<<" wrong answers out of "<<(SIZE-1)<<" questions."<<endl<<endl; //Display mistakes
    }
    
    if (wAns > 0) {  //Display the numbers user got wrong and display the right answer corresponding to that number
        cout<<"Here are the correct answers for the numbers you missed: "<<endl<<endl;
        for (count = 0; count<SIZE;count++) {
            if (wrongs[count] == 0) cout<<"\0";
            else cout<<wrongs[count]<<" "<<right[count]<<endl;        
        }
    }
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 9 **********************************
//Description: Write a program that uses an array of string objects to hold the 
//     five student names, an array of five characters to hold the five students’ 
//     letter grades, and five arrays of four double s to hold each student’s set 
//     of test scores.
//Inputs:  strings - for names, float - test scores
//Outputs:  name, average and letter grade
//******************************************************************************

void hProb9(){
    cout<<"Homework - GRADE BOOK"<<endl<<endl;
    //Declare Variables             //Set array size
    const int SIZE = 5;             //Size for names
    const int TEST = 4;             //Size for test
    string names[SIZE] = {};        //Array for names
    float s1[TEST] = {};            //Student 1 Scores
    float s2[TEST] = {};            //Student 2 Scores
    float s3[TEST] = {};            //Student 3 Scores
    float s4[TEST] = {};            //Student 4 Scores
    float s5[TEST] = {};            //Student 5 Scores
    char grades[SIZE] = {'A', 'B', 'C', 'D', 'F'}; //Grades stored in the array
    int count, index;           //Loop counters
    float st1=0, st2=0, st3=0, st4=0, st5=0;     //Total scores for every student
    
    //Input Values    
    for (count = 0; count<SIZE; count++) {
        cout<<"Student Name: ";                         //Prompt user for student name
        cin>>names[count];
        if (count == 0) {
            for (index = 0;index <TEST;index++) {       //Input test score per student name
                do {
                    cout<<"Test "<<(index+1)<<": ";
                    cin>>s1[index];                     //Loop if score is less than 0 and greater than 100until user input is valid
                    if (s1[index]<0||s1[index]>100) cout<<"\nINVALID INPUT\n\n";
                } while (s1[index]<0||s1[index]>100);
                st1+=s1[index];                         //Add input to total scores 
            }                   
        }                                               //Repeat process until 5th Student
        else if (count == 1) {
            for (index = 0;index <TEST;index++) {
                do {
                    cout<<"Test "<<(index+1)<<": ";
                    cin>>s2[index];
                    if (s2[index]<0||s2[index]>100) cout<<"\nINVALID INPUT\n\n";
                } while (s2[index]<0||s2[index]>100);
                st2+=s2[index];
            }
        }
        else if (count == 2) {
            for (index = 0;index <TEST;index++) {
                do {
                    cout<<"Test "<<(index+1)<<": ";
                    cin>>s3[index];
                    if (s3[index]<0||s3[index]>100) cout<<"\nINVALID INPUT\n\n";
                } while (s3[index]<0||s3[index]>100);
                st3+=s3[index];
            }
        }
        else if (count == 3) {
            for (index = 0;index <TEST;index++) {
                do {
                    cout<<"Test "<<(index+1)<<": ";
                    cin>>s4[index];
                    if (s4[index]<0||s4[index]>100) cout<<"\nINVALID INPUT\n\n";
                } while (s4[index]<0||s4[index]>100);
                st4+=s4[index];
            }
        }
        else {  // if (count == 1) {
            for (index = 0;index <TEST;index++) {
                do {
                    cout<<"Test "<<(index+1)<<": ";
                    cin>>s5[index];
                    if (s5[index]<0||s5[index]>100) cout<<"\nINVALID INPUT\n\n";
                } while (s5[index]<0||s5[index]>100);
                st5+=s5[index];
            }
        }
        cout<<endl;
    }
    
    //Process by mapping inputs to outputs
    float ave1 = st1/4, ave2 = st2/4, ave3 = st3/4, ave4 = st4/4, ave5 = st5/4;     //Calculate average per student
    
    //Output values
    for (count = 0; count<SIZE;count++) {
        cout<<names[count]<<endl<<"Average: ";                      //Display results
        if (count == 0) {               
            cout<<ave1<<endl<<"Grade: ";                                
            if (ave1>=90&&ave1<=100) cout<<grades[0]<<endl;         //Display letter grade based on average
            else if (ave1>=80&&ave1<=89) cout<<grades[1]<<endl;
            else if (ave1>=70&&ave1<79) cout<<grades[2]<<endl;
            else if (ave1>=60&&ave1<=69) cout<<grades[3]<<endl;
            else cout<<grades[4]<<endl;
        }
        if (count == 1) {
            cout<<ave2<<endl<<"Grade: ";
            if (ave2>=90&&ave2<=100) cout<<grades[0]<<endl;
            else if (ave2>=80&&ave2<=89) cout<<grades[1]<<endl;
            else if (ave2>=70&&ave2<79) cout<<grades[2]<<endl;
            else if (ave2>=60&&ave2<=69) cout<<grades[3]<<endl;
            else cout<<grades[4]<<endl;
        }
        if (count == 2) {
            cout<<ave3<<endl<<"Grade: ";
            if (ave3>=90&&ave3<=100) cout<<grades[0]<<endl;
            else if (ave3>=80&&ave3<=89) cout<<grades[1]<<endl;
            else if (ave3>=70&&ave3<79) cout<<grades[2]<<endl;
            else if (ave3>=60&&ave3<=69) cout<<grades[3]<<endl;
            else cout<<grades[4]<<endl;
        }     
        if (count == 3) {
            cout<<ave4<<endl<<"Grade: ";
            if (ave4>=90&&ave4<=100) cout<<grades[0]<<endl;
            else if (ave4>=80&&ave4<=89) cout<<grades[1]<<endl;
            else if (ave4>=70&&ave4<79) cout<<grades[2]<<endl;
            else if (ave4>=60&&ave4<=69) cout<<grades[3]<<endl;
            else cout<<grades[4]<<endl;
        }        
        if (count == 4) {
            cout<<ave5<<endl<<"Grade: ";
            if (ave5>=90&&ave5<=100) cout<<grades[0]<<endl;
            else if (ave5>=80&&ave5<=89) cout<<grades[1]<<endl;
            else if (ave5>=70&&ave5<79) cout<<grades[2]<<endl;
            else if (ave5>=60&&ave5<=69) cout<<grades[3]<<endl;
            else cout<<grades[4]<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 10 **********************************
//Description: Write a program that simulates a lottery.
//Inputs:  integer - ranging 1-9
//Outputs:  matching numbers with array, result
//******************************************************************************

void hProb10() {
    cout<<"Homework - GRADE BOOK"<<endl<<endl;
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
    
    cout<<endl<<endl;
}