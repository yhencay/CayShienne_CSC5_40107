
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
 */

//System Libraries
#include <iostream> //Input and Output Library
#include <iomanip>  //Formatting
#include <cmath>    //Math Library
#include <fstream>  //File I/O
#include <string>   //String Object
#include <ctime>    //Time for random seed
#include <cstdlib>  //Setting random seed
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
char gBoard[3][3]= { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} }, //Game board output
     turn;       //Player turns
bool DRAW=false, //Game Won
     gOver();    //Game over
void dBoard();   //Display Board
void pTurn();    //Player switching turns

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    string first1,last1, //First and last name (Player 1)
           first2,last2; //First and last name (Player 2)
        
    //Main Menu
    cout<<"              Welcome Players."<<endl; //Introducing the Game
    cout<<endl;
    cout<<"We're about to play a game called Tic Tac Toe.\nPlease enter your "
            "first and last name"
            " as Player 1 and Player 2."<<endl;
    cout<<endl;
    cout<<"Player 1: [X]"<<endl; //Player 1's name [X]
    cin>>first1>>last1;
    cout<<"Player 2: [O]"<<endl; //Player 2's name [O]]
    cin>>first2>>last2;
    
    //Mapping out the game
    turn='X'; //Player 1's turn
    while (!gOver()) {
          dBoard();
          pTurn();
          gOver();
    }
    if (turn=='O'&&!DRAW) {
        dBoard(); //Board Display
        cout<<endl<<endl<<"Player 1 [X] "<<first1<<" "<<last1<<" Wins!\n";
    }
    else if (turn=='X'&&!DRAW) {
        dBoard(); //Board Display
        cout<<endl<<endl<<"Player 2 [O] "<<first2<<" "<<last2<<" Wins!\n";
    }
    else {
        dBoard(); //Board Display
        cout<<endl<<endl<<"[X] and [O] ==> DRAW!\n";
    }
    return 0;
}
//******************************************************************************
//*****************************DISPLAY THE BOARD********************************
//*********************MAKE CHOICES, WINNER, LOOSER, DRAW***********************
//******************************************************************************
void dBoard () {
    //Game Board Output
    cout<<"\n\t\tTIC-TAC-TOE\n   ";
    cout<<"Player 1 (X):  -  Player 2 (O):  "<<endl;
    cout<<" ---------------------------------"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<gBoard[0][0]<<"  |  "<<gBoard[0][1]<<"  |  "<<gBoard[0][2]<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<gBoard[1][0]<<"  |  "<<gBoard[1][1]<<"  |  "<<gBoard[1][2]<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<gBoard[2][0]<<"  |  "<<gBoard[2][1]<<"  |  "<<gBoard[2][2]<<endl;
    cout<<"\t     |     |     "<<endl<<endl;
}

void pTurn() {
    //Declare Variables
    int choice; //Choices to make from 1 to 9
    int row=0,col=0; //Rows and Columns on the Board
   
    //Players Turns 
    if (turn=='X') { //Player 1
        cout<<"Player 1 turn [X]: ";
    }
    else if (turn=='0') { //Player 2
        cout<<"Player 2 turn [O]: ";
    }
    cin>>choice;
    
    //Mapping out
    switch (choice) {
        case 1: row=0;col=0;break;
        case 2: row=0;col=1;break;
        case 3: row=0;col=2;break;
        case 4: row=1;col=0;break;
        case 5: row=1;col=1;break;
        case 6: row=1;col=2;break;
        case 7: row=2;col=0;break;
        case 8: row=2;col=1;break;
        case 9: row=2;col=2;break;
        default:
            cout<<"You did not enter a correct number! Try again!\n";
            pTurn();
    }
    
    //Player turns on the game
    if (turn=='X'&&gBoard[row][col]!='X'&&gBoard[row][col]!='O') {
        gBoard[row][col]='X';
        turn='O';
    }
    else if (turn=='O'&&gBoard[row][col]!='X'&&gBoard[row][col]!='O') {
        gBoard[row][col]='O';
        turn='X';
    }
    else {
        cout<<"The cell you chose is used! Try again\n";
        pTurn;
    }
}

//Game Over
bool gOver() {
    for (int i=0;i<3;i++) { //Check for a winner
        if ((gBoard[i][0]==gBoard[i][1]&&gBoard[i][1]==gBoard[i][2])||
                (gBoard[0][i]==gBoard[1][i]&&gBoard[1][i]==gBoard[2][i])|| 
                (gBoard[0][0]==gBoard[1][1]&&gBoard[1][1]==gBoard[2][2])|| 
                (gBoard[0][2]==gBoard[1][1]&&gBoard[1][1]==gBoard[2][0])) {
            return true;
        }  
    }
    for (int i=0;i<3;i++) { //Check for draw
        for (int j=0;j<3;j++) {
            if (gBoard[i][j]!='X'&&gBoard[i][j]!='O') {
                return false;
            }
        }
    }
    DRAW=true;
    return true; //Exit Stages Right
}
