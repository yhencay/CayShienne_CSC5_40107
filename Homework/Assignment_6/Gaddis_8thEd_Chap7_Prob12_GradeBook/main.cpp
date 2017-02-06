/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 4, 2017, 5:30 PM
 * Purpose: Homework Grade Book
 * 
 *      Problem: A teacher has five students who have taken four tests. The 
 * teacher uses the following grading scale to assign a letter grade to a 
 * student, based on the average of his or her four test scores.
 * 
 *              Test Score              Letter Grade
 *                90–100                     A
 *                80–89                      B
 *                70–79                      C
 *                60–69                      D
 *                0–59                       F
 * 
 *  Write a program that uses an array of string objects to hold the five 
 * student names, an array of five characters to hold the five students’ letter 
 * grades, and five arrays of four double s to hold each student’s set of test
 *  scores. The program should allow the user to enter each student’s name and 
 * his or her four test scores. It should then calculate and display each 
 * student’s average test score and a letter grade based on the average.
 * 
 *      Input Validation: Do not accept test scores less than 0 or greater 
 *                  than 100.
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
        
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

