/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 8, 2017, 7:49 PM
 * Purpose: PROJECT 2 SLOT MACHINE
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT = 100;      //Percentage Conversion  
const int ROWS = 25, COLS = 4;  //Two Dimensional Arrays

//Function Prototypes
void resetA(int &, int &, int &, float &, float &, float &, float &, float &, float &, float &, float&);  //Function to reset all variables for use to 0 after one cancels game
void gameRep(string, char, int, int, int, float, float, float, float, float, float, float);  //View game report after a game
void gameRep(string, int, int, int, float, float, float, float, float, float, float);   //View game report from previous play
float bonCash(float, float, float, float, float, float, int, int, float = 0);   //Bonus cash calculation from number of spins reached
void find(int [], int, int &, int);        //Search a number
void voucher(string, float);               //Display voucher
void filAray(int [], int);                 //Fill array with random number elements
void mrkSrt(int [], int);                  //Sorting array for easier win clarification
void prntAry(int [], int);                 //Print the array or the random numbers in mini-game
void status(float, string);                //Name and current money
bool valPass(string, string);              //Password validation for administrator settings
float rndOffB(float, int);                 //Round off Budget
float insert(float &, string);             //Insert budget/money
void winPat();                             //Display Winning Patterns
void askRep();                             //Prompt for game report

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random seed using time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables    
    const int SIZE = 25;                //Array Size for number of play times 
    const int MINSIZE = 200;            //Size for array in Mini game
    string name,                        //Player name
           dummy;                       //Dummy string
    string names[SIZE] = {};            //Array for player names
    string input, empName;              //Access personnel settings to view player data - Password/Username
    const float bonCsh1 = 0.05f,        
                bonCsh2 = 0.10f,        //Cash bonus percentage per spin play reached
                bonCsh3 = 0.15f,
                bonCsh4 = 0.25f,
                bonCshP = 0.01f,        //Bonus cash for playing the game
                minVal = 0;             //Minimum Value set for comparison
    float budget = 0,                       //Player's capital for the game
          add,                          //User option to add money if capital went down 0
          bet,                          //How much the player is willing to wager
          loss = 0,                     //Total loss amount
          win = 0,                      //Total win amount
          bonWin = 0,                   //Total bonus win
          cshIns = 0,                   //Total amount of cash inserted in the game
          minCsh = 0,                   //Total mini game win
          totCash,                      //Total money involved including win, cash insert and bonus win
          winPer,                       //Number of games won percentage
          lossPer,                      //Number of games lost percentage
          data[ROWS][COLS] = {};        //2D Array for database to be accessed by staff
    int numWin = 0,                     //Number of win within total times played
        numLose = 0,                    //Number of loss within total times played
        play = 0,                       //Total number of plays
        g8mBon = 10,                    //Game bonus when number of plays reached!
        rndOff = 100,                   //Round off to two decimal places
        array[MINSIZE] = {},            //Array for Mini-game
        found = 0;                      //Count for a number found in mini game
    int count = 0, plCount = 0;         //Array store count & player accessed count
    char begin,                         //User input to play the game
         load,                          //User adds money if you wants to play again
         choice,                        //User input to continue playing or not
         report,                        //User choice to print out game report
         start,                         //Determine if user is new or returning
         game,                          //User input for mini game play
         reset;                         //End game - accessed only by staff
    unsigned short rn1, rn2, rn3,
                   rn4, rn5, rn6,       //Random numbers for slot machine
                   rn7, rn8, rn9;
    bool w = true;          //Loop for start and overall
    bool x = true;          //Loop for budget
    bool y = true;          //Loop for game play
    bool z = true;          //Loop for inserting additional cash decision
    bool rep = true;        //Loop for game report

    //Input Values    
    //Process by mapping inputs to outputs
    do {
        winPat();                                                   //Display Winning patterns
        cout<<"\nPlayers Listed: "<<plCount<<endl;                  //Display times played count
        cout<<"Current Money: "<<budget<<endl;                      //Money so far added from mini-game
        cout<<"\nWould you like to play the game? "<<endl;          //Prompt user to play game or not
        cout<<"      Y - YES    N - NO"<<endl;
        cout<<"        M - MINI GAME"<<endl<<endl;
        cout<<"Note: Casino Staff access S for settings."<<endl<<endl;    //A setting to access database
        cout<<"CHOICE: ";
        cin>>begin;                                                 //Character variable for beginning choice
        getline(cin, dummy);                                        //Dummy string to accept cin & getline

        do {
            if (plCount>=SIZE) {           //If players count is greater than size for array, prompt administrator for reset
            cout<<"\nMaximum number of players reached. \nAdministrator must login!"<<endl;
            begin = 'S';
            }
            switch (begin) {                                            //Case statement for choice in variable Begin
                case 'y':                                               //Only accepts 'Y', 'N', 'M', 'S' as input
                case 'Y': { 
                    cout<<endl;                                         //If user chooses to play the game
                    cout<<"Enter Player Name: ";                        //Prompt user for name to be used later for cashout voucher
                    getline(cin, name);                                 //using string datatype
                    ifstream in;                                        //If user played before, retrieve play count from game report saved on file
                    in.open(name+".dat");
                    in>>play;                   //File from play                
                    in.close();

                    if (play>0) {                                       //Prompt returning user if he/she wants to see previous game report
                        cout<<"\nWelcome back, "<<name<<"!"<<endl<<endl;
                        cout<<"Would you like to see your previous game report?"<<endl;
                        cout<<"      Y - YES    N - NO"<<endl<<endl;    //If yes, retrieve whole game report and display
                        cout<<"CHOICE: ";
                        cin>>report;
                        if (report == 'Y' || report == 'y') gameRep(name,play,numWin,numLose,cshIns,win,bonWin,totCash,loss,winPer,lossPer);
                        resetA(play, numWin, numLose, cshIns, win, bonWin, totCash, loss, winPer, lossPer, budget); //Upon displaying, reset all retrieved data back to 0
                        names[count] = name;     //Add player's name to players list   
                    }
                    else if (play<=0){           //If user is a new player, add player's name to list
                        names[count] = name;     //Welcome user
                        cout<<"\nYou are a new player. Welcome "<<name<<"!"<<endl;
                    }

                    budget = insert(budget, dummy);         //Prompt for cash deposit/insert
                    cshIns += (budget-minCsh);              //Add the amount inserted to total cash inserted but subtract money from mini-game

                    float cshBon = (budget<=1000)?pow((budget*bonCshP), 2):         //Give cash bonus if Player decided to play
                                   (budget>1000&&budget<=2000)?budget*bonCsh2:      //If inserted amount is below 1000, get 1% of cash and multiply by itself
                                   (budget>=2000)?budget*bonCsh1:minVal;            //If inserted amount is >1000 but <=2000, get 10% of cash
                                                                                    //If over 2000, get 5% of cash and add to the cash of user
                    if (budget >= 0 && budget <= 20000) {   
                        float exCshBn = cshBon*rndOff+0.5;
                        cshBon = exCshBn/100.0f;            //Round off Cash Bonus to two decimal places to get exact value

                        budget += cshBon;
                        cout<<"\nThank you for choosing to play the game!"<<endl;       //Tell the user that the system added cash bonus to account
                        cout<<"We added $"<<cshBon<<" to your capital as cash bonus."<<endl<<endl;
                        cout<<"Good luck ^_^"<<endl;
                        bonWin+=cshBon;                     //Add the cash bonus to overall cash bonus in record
                    }

                    budget = rndOffB(budget, rndOff);       //Round off money     
                    status(budget, name);                   //Display status

                    do {                                                //Start loop for budget condition. If bool x for budget is true, continue loop.
                        if (budget > minVal) {                          //If budget is greater than 0, start loop.
                            do {
                                cout<<"\tPLAY"<<endl<<endl;                     //Prompt user to Spin or Cancel game
                                cout<<"S - SPIN   C - CANCEL"<<endl<<endl;      //Any other input will not be accepted
                                cout<<"CHOICE: ";
                                cin>>choice;                        

                                if ((choice == 'S' || choice == 's') && budget>minVal) {       //If user chose to spin and budget is greater than 0   
                                    do {                        
                                        cout<<endl<<"BET: $";               //Prompt user for betting amount
                                        cin>>bet;                      

                                        while (cin.fail()) {                                        //User input validation of float datatype
                                            cout<<"\nYou must only enter a number!"<<endl<<endl;    //for bet amount
                                            cout<<"Bet: $";
                                            cin.clear();
                                            getline(cin, dummy);
                                            cin>>bet;
                                        }

                                        if (bet>budget) {                   //If bet is greater than the budget, display invalidity
                                            cout<<"\nYour bet cannot be higher than your capital!"<<endl;
                                            cout<<"Your remaining cash is $"<<budget<<endl<<endl;
                                        }
                                        else if (bet<=minVal) {             //If bet is equal to 0, display invalidity
                                            cout<<"\nBet must be greater than 0!"<<endl;
                                            cout<<"Your remaining cash is $"<<budget<<endl<<endl;
                                        }                              
                                        else if (bet<=budget && bet>minVal) {     //If bet is less than or equal to budget and budget is greater than 0
                                            play++;                               //Increment total number of spins 

                                            rn1 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn2 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn3 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn4 = (rand()%(8-4+1))+4;   //Value range from 4 to 8       //Start rolling and generating numbers for the slot machine
                                            rn5 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn6 = (rand()%(8-4+1))+4;   //Value range from 4 to 8       //9 random generators for slot machine game
                                            rn7 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn8 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                            rn9 = (rand()%(8-4+1))+4;   //Value range from 4 to 8

                                            cout<<endl;
                                            cout<<"\t"<<rn1<<"  "<<rn2<<"  "<<rn3<<endl;                //Display the generated numbers
                                            cout<<"\t"<<rn4<<"  "<<rn5<<"  "<<rn6<<endl;
                                            cout<<"\t"<<rn7<<"  "<<rn8<<"  "<<rn9<<endl<<endl;          //Bet is deducted first before game generate wins or loss

                                            if (rn1==rn2 && rn2==rn3 && rn3==rn4 && rn4 == rn5 
                                                    && rn5==rn6 && rn6 == rn7 && rn7 == rn8 && rn8 == rn9) {    //If all number patterns come out, display win
                                                if (rn1 == 7) {                                                 
                                                    budget += (bet*99);                                         //If all 777s come out, user wins 100x bet
                                                    cout<<"All 777s earn 100x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*100)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*99);                                              //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += (bet*49);                                         //If all same numbers come out, user wins 50x bet
                                                    cout<<"All same number earns 50x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*50)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*49);                                              //Add winning amount to total amount of wins for record
                                                }
                                            }
                                            else if (rn1==rn2 && rn2==rn3 && rn3==rn4 && rn4 == rn6             //If square pattern comes out, display win
                                                    && rn7==rn8 && rn8 == rn9) {    
                                                if (rn1 == 7) {                                                 //if 777s come out in square, user wins 15x bet
                                                    budget += (bet*14);                                     
                                                    cout<<"Square Pattern 777s earn 15x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*15)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*14);                                              //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += (bet*9);                                          //If normal numbers come out in square, user wins 10x bet
                                                    cout<<"Square Pattern number earns 10x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*9);                                               //Add winning amount to total amount of wins for record
                                                }
                                            }                                        
                                            else if (rn2==rn4 && rn4==rn5 && rn5==rn6 && rn6==rn8) {            //If cross pattern comes out, display win
                                                if (rn2 == 7) {                             
                                                    budget += (bet*14);                                          //If cross pattern 777s come out, user wins 10x bet
                                                    cout<<"Cross Pattern 777s earn 15x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*15)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*14);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += (bet*9);                                          //If cross pattern normal numbers come out, user wins 5x bet
                                                    cout<<"Cross Pattern number earns 10x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*9);                                               //Add winning amount to total amount of wins for record
                                                }
                                            }
                                            else if (rn1==rn5 && rn5==rn9 && rn9==rn3 && rn3 == rn7) {          //If X Pattern comes out, display win
                                                if (rn1 == 7) {                 
                                                    budget += (bet*9);                                          //If X pattern 777s come out, user wins 10x bet
                                                    cout<<"X Pattern 777s earn 10x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*9);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += (bet*4);                                          //If X pattern normal numbers come out, user wins 5x bet
                                                    cout<<"X Pattern number earns 5x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*5)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*4);                                               //Add winning amount to total amount of wins for record
                                                }
                                            } 
                                            else if (rn4==rn5 && rn5==rn6) {                                    //If straight horizontal pattern in middle comes out, display win
                                                if (rn4 == 7) {                     
                                                    budget += (bet*9);                                          //If straight 777s in middle come out, user wins 10x bet
                                                    cout<<"Straight 777s in the middle earn 10x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*9);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += bet;                                              //If normal straight numbers come out, user wins 2x bet
                                                    cout<<"Straight number earns 2x bet!"<<endl;                
                                                    cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=bet;                                                   //Add winning amount to total amount of wins for record
                                                }
                                            }
                                            else if (rn1==rn2 && rn2==rn3) {                                    //If straight horizontal pattern comes out, display win
                                                if (rn1 == 7) {
                                                    budget += (bet*2);                                          //If straight 777s come out on top, user wins 3x bet
                                                    cout<<"Straight 777s earn 3x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*2);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += bet;                                              //If normal number come out on top, user wins 2x bet
                                                    cout<<"Straight number earns 2x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=bet;                                                   //Add winning amount to total amount of wins for record
                                                }
                                            }                                        
                                            else if (rn7==rn8 && rn8==rn9) {                                    //If straight horizontal pattern comes out, display win
                                                if (rn7 == 7) {
                                                    budget += (bet*2);                                          //If straight 777s come out below, user wins 3x bet
                                                    cout<<"Straight 777s earn 3x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*2);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += bet;                                              //If normal number come out below, user wins 2x bet
                                                    cout<<"Straight number earns 2x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=bet;                                                   //Add winning amount to total amount of wins for record
                                                }
                                            }
                                            else if (rn1==rn5 && rn5==rn9) {                                    //If diagonal pattern comes out, display win
                                                if (rn1 == 7) {                                                 
                                                    budget += (bet*2);                                          //If 777s diagonal pattern come out, user wins 3x bet
                                                    cout<<"Diagonal 777s earn 3x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*2);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += bet;                                              //If normal number diagonal pattern come out, user wins 2x bet
                                                    cout<<"Diagonal number earns 2x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=bet;                                                   //Add winning amount to total amount of wins for record
                                                }
                                            }
                                            else if (rn7==rn5 && rn5==rn3) {                                    //If diagonal pattern comes out, display win
                                                if (rn7 == 7) {
                                                    budget += (bet*2);                                          //If 777s diagonal pattern come out, user wins 3x bet
                                                    cout<<"Diagonal 777s earn 3x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=(bet*2);                                               //Add winning amount to total amount of wins for record
                                                }
                                                else {
                                                    budget += bet;                                              //If normal number diagonal pattern come out, user wins 2x bet
                                                    cout<<"Diagonal number earns 2x bet!"<<endl;
                                                    cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                    numWin++;                                                   //Increment number of wins
                                                    win+=bet;                                                   //Add winning amount to total amount of wins for record
                                                }
                                            }                                                                             
                                            else {
                                                budget -= bet;                                                  //If no winning pattern comes out, display bet deduction
                                                cout<<"Sorry, you lost $"<<bet<<endl;
                                                numLose++;                                                      //Increment number of loss
                                                loss+=bet;                                                      //Add loss amount to total amount of wins for record
                                            }    

                                            if (play==g8mBon) {                                            
                                                float added = bonCash(added,bonCsh1,bonCsh2,bonCsh3,bonCsh4,loss,g8mBon,play,minVal);
                                                budget+=added;
                                                cout<<"\nCongratulations!\n"                            //Let user know that he/she won cash bonus for reaching specific number of
                                                    <<"You earned game bonus for reaching "<<g8mBon<<" number of spins!"<<endl;    //spins that the game requires
                                                cout<<"$"<<added<<" is added to your cash amount!"<<endl;
                                                g8mBon+=g8mBon;                                         //Add game bonus spins by itself or multiply required by 2 for next bonus
                                                bonWin+=added;
                                            }

                                            budget = rndOffB(budget, rndOff);       //Round off money
                                            status(budget, name);                   //Display status                                                              
                                        }
                                        else {                                                              
                                            cout<<"\nYou can only enter numbers!\n"<<endl;
                                        }
                                    } while (budget>minVal && bet<minVal && budget!=minVal);                //Loop for spin or cancel if budget>0, bet is less than 0 and                                 
                                }                                                                           //budget is > 0.

                                else if (choice == 'C' || choice == 'c')  {                           //If user chose 'C' to cancel game
                                    if (play == minVal) {                                             //If total spin count is 0 and user chose not to play game after money inserted
                                        budget -= cshBon;                                             //Deduct cash bonus from inserted amount
                                        bonWin -=cshBon;                                              //Deduct cash bonus added for total record
                                        cout<<"\nNOTICE: Cash bonus is deducted because you have not played yet!"<<endl;
                                        x = false;                                                    //Exit loop for spin
                                    }
                                    else x=false;                                                     //If spin count is >1, exit loop
                                }
                                else { cout<<"\nWarning: Enter only either 'S' or 'C' \n"<<endl; }    //If user input is not 'S' or 'C', display invalidity, ask again
                            } while ((choice == 'S' || choice == 's') && x && budget != minVal);      //Continue loop til budget is 0, choice is not to spin
                        }                                                                             //and boolean for boolean for budget remains true

                        else if (budget==minVal) {                                      //If budget is 0 or turns 0, or if cash is used up
                            do {                                                        //Start loop for cash insert
                                cout<<"You have used up all your funds. Would you like to insert again? "<<endl;    //Prompt user if players wants to insert more cash to continue playing
                                cout<<"     Y - Yes     N - No  "<<endl<<endl;
                                cout<<"CHOICE: ";
                                cin>>load;

                                switch (load) {
                                    case 'y':                                                           //If yes, ask how much
                                    case 'Y': {
                                        do {                                                            //Start loop for add amount
                                            cout<<"\nInsert Cash: $";
                                            cin>>add;

                                            while (cin.fail()) {                                        //User input validation of float datatype
                                                cout<<"\nYou must only enter a number!"<<endl<<endl;    //for adding funds
                                                cout<<"Insert Cash: $";
                                                cin.clear();
                                                getline(cin, dummy);
                                                cin>>add;
                                            }                                        

                                            if (add > minVal)  budget += add;                           //If add amount is is greater than 0, add to budget or current money
                                            else cout<<"Value must be greater than 0!"<<endl;           //If add amount is <= 0, diplay invalidity

                                            cshIns+=add;                                                //Amount inserted is added into total cash inserted record

                                            budget = rndOffB(budget, rndOff);
                                            status(budget, name);

                                        } while (add <= minVal);                                        //Continue loop if added inserted cash input is less than 0
                                        z = false;                                                  //Boolean for add game turns false.. exit loop for add cash
                                    } break;

                                    case 'n':                                                       //If choice is 'n' or 'N'
                                    case 'N': z = false;                                            //Boolean for add game turns false.. exit loop for add cash
                                              x = false;                                            //Boolean for budget turns false, exit game play loop
                                              break;

                                    default: cout<<"\nYou can only enter 'Y' or 'N'\n"<<endl;       //If user input is not 'Y' or 'N', display invalidity
                                             break;
                                }
                            } while (z);                                                        //Continue loop if bool z for add cash remains true      
                        }                    

                        else x=false;                       //If no conditions are met exit game play loop

                    } while (x);                            //Continue loop if bool x for budget remains true or budget is greater than 0, continue loop
                    y = false;                              //Exit game play
                } break;
                
                case 'm':                       //If user chose Mini game, welcome user and explain rules
                case 'M': {
                    cout<<"\nWELCOME TO THE NUMBER GUESS MINI-GAME!\n"<<endl;
                    cout<<"Rules: You must input a number and if it exists in the array for\n"
                        <<"  3 times, you win $5 to be added to your current money. You will\n"
                        <<"  be able to cash it out if you proceed to play the slot machine\n"
                        <<"  after the mini-game. If you don't, the money will remain unless\n"
                        <<"  you choose not to play the game."<<endl<<endl;
                    do {
                    cout<<"PLAY?     P - PLAY     C - CANCEL"<<endl<<endl;      //Prompt user to play or cancel/exit mini game
                    cout<<"CHOICE: ";
                    cin>>game; 
                    
                    filAray(array, MINSIZE);            //Start to fill array
                    
                    int findN;                          //User input for number guess
                    
                    if (game == 'p' || game == 'P') {
                        cout<<"\nInput a number from 10-99!\n\n";       //Prompt user to input number
                        cout<<"Number: ";
                        cin>>findN;
                        
                        while (cin.fail()) {                                        //User input validation of float datatype
                            cout<<"\nYou must only enter a number!"<<endl<<endl;    //for number
                            cout<<"Number: ";
                            cin.clear();
                            getline(cin, dummy);
                            cin>>findN;
                        } 
                        
                        mrkSrt(array, MINSIZE);                 //Sort the filled array
                        find(array, MINSIZE, found, findN);     //Find out how many times user input's number appeared
                        cout<<endl;
                        prntAry(array, MINSIZE);                //Print sorted array
                        
                        cout<<"\nNumber "<<findN<<" occured "<<found<<" times.\n"<<endl;       //Display result
                        
                        if (found>=3) {             //If user input occurred 3 times or more, add $5 to money
                            cout<<"Congratulations! $5 is added to the current money!\n"<<endl;
                            budget+=5;
                            minCsh+=5;
                            bonWin+=minCsh;     //Add cash won from mini-game to total cash bonus
                        }
                        else {
                            cout<<"Sorry, you didn't win. Try again!\n"<<endl;
                            budget=budget;      //If user didn't win, money remains 0
                        }
                        
                        found = 0;      //reset found count
                    }
                    
                    else if (game == 'C' || game == 'c') {          //If user chooses to cancel game, exit mini-game and back to main menu
                        cout<<"\nExiting mini game..."<<endl<<endl;
                    }
                    else cout<<"\n\nWarning: You can only enter 'P' or 'C'!\n"<<endl;     //Else, warn user to input right character. Goes back to main menu
                    
                    } while (game == 'p' || game == 'P');       //Continue mini-game as long as user chooses to play
                    
                    y=false;    //Exit mini-game back to main menu
                } break;

                case 'n':
                case 'N': {
                    cout<<"\nGoodbye!"<<endl;               //If begin is 'n' or 'N', exit game prompt 
                    budget = 0;                             //Set money to 0 if player did not choose to play even if player won in mini game
                    y = false;                              //Game play exit, back to main menu
                } break; 

                case 's':
                case 'S': {                 //If user enters staff login access
                    cout<<endl;                         //Prompt user for username and password to log in
                    cout<<"Staff Login"<<endl<<endl;    //and access player's important records
                    cout<<"Employee Name: ";
                    cin>>empName;
                    cout<<"Input Password: ";
                    cin>>input;
                    cout<<"\nAccessing database..."<<endl<<endl;

                    if (valPass(input, empName)) {          //If logged in, display game player's information
                        cout<<"\n\tPlayer List \t      Total Cash \t  Cash Bonus \t        Cash Won \t   Cash Loss"<<endl;
                        cout<<"\t--------------------------------------------------------------------------------------------"<<endl;
                        for (int cHere = 0; cHere < ROWS; cHere++) {
                            cout<<setw(19);
                            cout<<names[cHere]<<setw(21);                       //Game can only hold 25 players before it prompts for admin reset
                            for (int iHere = 0; iHere < COLS; iHere++) {
                                cout<<data[cHere][iHere]<<setw(20);
                            }
                            cout<<endl;
                        }
                        cout<<"\nRESET?   Y - YES     N - NO"<<endl<<endl;      //Prompt for reset after viewing records
                        cout<<"CHOICE: ";
                        cin>>reset;
                        if (reset == 'Y' || reset == 'y') {                     //If chose to reset, end game
                            cout<<"\nResetting everything!"<<endl;
                            y=false;
                            w=false;
                            x=true;
                        }
                        else if (reset == 'N' || reset == 'n') {
                            cout<<"\nExiting staff settings..."<<endl<<endl;       //If not, back to main menu
                            y=false;
                            x=true;
                        }
                        else cout<<"\nWarning: You can only enter 'Y' or 'N'!\nRepeat process to access!"<<endl;    //If user input is not Y or N, repeat process
                    }
                    else {
                        cout<<"Log in failed!\n\n";         //If employee name and password is wrong, display login failed. Go back to main menu
                        x=true; y=false; }
                } break;
                
                default: {
                    cout<<"\nWarning: You can only enter 'Y' or 'N' or 'M'!\n"<<endl; y=false;    //If begin is not 'N' or 'Y', display invalidity            
                } break;     
            } 
        } while (y);                            //If game play remains true, continue loop

        //Output values
        cout<<fixed<<setprecision(2)<<showpoint;       

        if (x == false) {                                   //Start loop exit condition
            int num=0;                                      //Loop count for 2d array
            totCash = cshIns + bonWin + win;                //Calculate total money involved
            data[count][num] = totCash; num++; 
            data[count][num] = bonWin; num++;               //Add important information to database for staff settings
            data[count][num] = win; num++;
            data[count][num] = loss; num++;
            count++;                                        //Increase row
            num-=4;                                         //Decrease column back to 0        
            plCount++;                                      //Increment total player count

            for (int p = 1; p <= 1; p++) {                  //Loop voucher one time
                if (budget>minVal) {                        //If chosen to exit game and there's money left on account
                    voucher(name, budget);                  //Display voucher
                    do {                   
                    askRep();                               //Prompt user for game report
                    cin>>report;                

                        if (report == 'Y' || report == 'y') {                                   //If yes, display report
                            gameRep(name, report, play, numWin, numLose, cshIns, win, bonWin, totCash,
                                    loss, winPer, lossPer);                        //Save report to file
                            rep = false;
                            x = true;   
                            resetA(play, numWin, numLose, cshIns, win, bonWin, totCash, loss, winPer, lossPer, budget); //Reset all data and back to main menu
                        }                    
                        else if (report == 'N' || report == 'n') {                          //If user does not want to see game report
                            gameRep(name, report, play, numWin, numLose, cshIns, win, bonWin, totCash,
                                        loss, winPer, lossPer);                    //Save report to file
                            rep = false;
                            x=true;
                            resetA(play, numWin, numLose, cshIns, win, bonWin, totCash, loss, winPer, lossPer, budget); //Reset all data and back to main menu
                        }
                        else cout<<"\nWarning: You can only enter 'Y' or 'N'!"<<endl;        //If user input is not either 'Y' or 'N', display invalidity 
                    } while (rep);
                }
                
                else if (budget <=0) {                                                          //If no money left on account                
                    cout<<"\nSorry, you didn't win any amount this time."<<endl;

                        do { 
                        askRep();                                                  //Prompt user to see game report
                        cin>>report;                

                        if (report == 'Y' || report == 'y') {                                       //If yes, display report
                            gameRep(name, report, play, numWin, numLose, cshIns, win, bonWin, totCash,
                                    loss, winPer, lossPer);                        //Save report to file
                            rep = false;
                            x=true;
                            resetA(play, numWin, numLose, cshIns, win, bonWin, totCash, loss, winPer, lossPer, budget); //Reset all data and back to main menu
                        }
                        
                        else if (report == 'N' || report == 'n') {                          //If user does not want to see game report
                            gameRep(name, report, play, numWin, numLose, cshIns, win, bonWin, totCash,
                                    loss, winPer, lossPer);                        //Save report to file
                            rep = false;
                            x = true;
                            resetA(play, numWin, numLose, cshIns, win, bonWin, totCash, loss, winPer, lossPer, budget); //Reset all data and back to main menu
                        }
                        else cout<<"\nWarning: You can only enter 'Y' or 'N'!"<<endl;        //If user input is not either 'Y' or 'N', display invalidity 
                    } while (rep);
                }                                                       //Once condition reached, end game.
            }       
        }
        
        else if (begin == 'n' || begin == 'N' || begin == 'y' || begin == 'Y'&&play<=0) {
            cout<<"\nPlay the game next time!\n"<<endl;                  //If user decides not to play game, back to main menu and reset earned money from mini-game if there is
        }
    } while (w);
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*************************** Reset All Info ***********************************
//Description: Reset all values from a retrieved data if a user comes back 
//      before starting to play again.
//Inputs:  None
//Outputs:  None
//******************************************************************************

void resetA(int &play, int &numWin, int &numLose, float &cshIns, float &win, 
        float &bonWin, float &totCash, float &loss, float &winPer, float &lossPer, float &budget) {
    play = 0;           numWin = 0;         numLose = 0;        cshIns = 0; 
    win = 0;            bonWin = 0;         totCash = 0;        loss = 0; winPer = 0; 
    lossPer = 0;        budget = 0;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//********************* Game Report After Playing The Game *********************
//Description: Display game report if user chooses to do so. This function saves
//      user game report to a file and available for retrieval later.
//Inputs:  Calculations - mostly float are saved to a file.
//Outputs:  Only if the user chooses to view will the report be displayed
//******************************************************************************

void gameRep (string name, char report, int play, int numWin, int numLose, float cshIns, float win, 
        float bonWin, float totCash, float loss, float winPer, float lossPer) {
    if (report == 'Y' || report == 'y') {
        cout<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
        cout<<"Number of games played: "<<play<<endl;
        cout<<"Number of wins: "<<numWin<<endl;
        cout<<"Number of losses: "<<numLose<<endl<<endl;
        cout<<"Total amount of cash inserted: $"<<cshIns<<endl;
        cout<<"Total amount of cash won: $"<<win<<endl;
        cout<<"Total amount of cash bonus: $"<<bonWin<<endl<<endl;
        cout<<"Total amount of cash involved: $"<<totCash<<endl;
        cout<<"Total amount of cash loss: $"<<loss<<endl<<endl;

        winPer = (static_cast<float>(numWin)/play)*PERCENT;                 //Calculate percentage of loss and win based on 
        lossPer = (static_cast<float>(numLose)/play)*PERCENT;               //total number of spins

        cout<<"Win Percentage: "<<winPer<<"%"<<endl;   
        cout<<"Loss Percentage: "<<lossPer<<"%"<<endl;                      //Display percentage result                      
    }
    ofstream out;                                                   //Save report to a file
    out.open(name+".dat");
    out<<play<<endl;
    out<<numWin<<endl;
    out<<numLose<<endl;
    out<<cshIns<<endl;
    out<<win<<endl;
    out<<bonWin<<endl;
    out<<totCash<<endl;
    out<<loss<<endl;

    winPer = (static_cast<float>(numWin)/play)*PERCENT;
    lossPer = (static_cast<float>(numLose)/play)*PERCENT;

    out<<winPer<<endl;   
    out<<lossPer<<endl;    
    out.close(); 
    
    cout<<"\nGame report is saved to a file."<<endl;
    cout<<"\nThank you for playing! See you again!\n"<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//********************** Game Report From Previous Game ************************
//Description: Display game report if user chooses to do so. This function 
//      retrieves game report from a previous game.
//Inputs:  Retrieve data from file.
//Outputs:  Display said data or the whole game report.
//******************************************************************************

void gameRep(string name, int play, int numWin, int numLose, float cshIns, float win, 
        float bonWin, float totCash, float loss, float winPer, float lossPer) {
    ifstream in;
    in.open(name+".dat");
    in>>play;                   //File from play
    in>>numWin;
    in>>numLose;
    in>>cshIns;
    in>>win;
    in>>bonWin;
    in>>totCash;
    in>>loss;
    in>>winPer;   
    in>>lossPer;
    in.close();
    cout<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
    cout<<"Number of games played: "<<play<<endl;
    cout<<"Number of wins: "<<numWin<<endl;
    cout<<"Number of losses: "<<numLose<<endl<<endl;
    cout<<"Total amount of cash inserted: $"<<cshIns<<endl;
    cout<<"Total amount of cash won: $"<<win<<endl;
    cout<<"Total amount of cash bonus: $"<<bonWin<<endl<<endl;
    cout<<"Total amount of cash involved: $"<<totCash<<endl;
    cout<<"Total amount of cash loss: $"<<loss<<endl<<endl;
    cout<<"Win Percentage: "<<winPer<<"%"<<endl;   
    cout<<"Loss Percentage: "<<lossPer<<"%"<<endl;                      //Display percentage result   
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//************************** Bonus Cash Calculation ****************************
//Description: If the player/user reaches a certain number of spins/plays, bonus
//      cash is to be added. This function calculates the amount to be added.
//Inputs:  None
//Outputs:  Returns a float value
//******************************************************************************

float bonCash(float added, float bonCsh1, float bonCsh2, float bonCsh3, 
        float bonCsh4, float loss, int g8mBon, int play, float minVal) {
    added = (g8mBon<=50)?(loss*bonCsh1):             //If spin cash bonus is triggered, calculate amount to be added
            (g8mBon<=100)?(loss*bonCsh2):            //based on same conditions for cash addition above
            (g8mBon<=300)?(loss*bonCsh3):
            (g8mBon>=301)?(loss*bonCsh4):minVal;
    return added;                                    //If no conditions are met, cash amount remains the same
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//***************************** Finding Numbers ********************************
//Description: In the mini-game, this function looks for the number of times the
//      user input occurred stored in the array filled with random numbers.
//Inputs:  Integer - user input as argument as well as the array and found count
//Outputs:  Only if user input is invalid - displays invalidity
//******************************************************************************

void find(int array[], int MINSIZE, int &found, int findN) {
    if (findN>=10&&findN<=99) {                             //If user input is within limits
        for (int count = 0; count < MINSIZE; count++) {     //Count how many times the number occured
            if (array[count] == findN) found++;             //in the array
            else found = found;
        }
    }
    else cout<<"\nInvalid input!\n";
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//******************************* Voucher **************************************
//Description: Display voucher if user is left with money when quitting the game.
//Inputs:  Using name and money from main       //Use random numbers for design
//Outputs:  Voucher look-a-like for money cash out
//******************************************************************************

void voucher(string name, float budget) {
    //Set local time and date
    time_t now = time(0);
    char* dt = ctime(&now);
    
    cout<<"\nCashout voucher printing..."<<endl<<endl;                //Start printing vouchers
                
    unsigned short ticket = (rand()%(9999-1000+1))+1000;                //Ticket number for voucher generator
    unsigned short v1 = (rand()%(99-10+1))+10;              
    unsigned short v2 = (rand()%(9999-1000+1))+1000;
    unsigned short v3 = (rand()%(9999-1000+1))+1000;                    //Number generator for validation code of voucher
    unsigned short v4 = (rand()%(9999-1000+1))+1000;
    unsigned short v5 = (rand()%(9999-1000+1))+1000;
    unsigned int mNum = (rand()%(4294967294-1000000000+1))+1000000000;  //Number generator for machine number

    cout<<"\t------------------------------------------------------"<<endl;
    cout<<"\t CSC5 CASINO RIVERSIDE, CA"<<setw(27)<<ticket<<endl<<endl;
    cout<<"\t\t\t   CASHOUT VOUCHER"<<endl<<endl;                                       //Display voucher in a specific set of format
    cout<<"\t\t\tFOR "<<name<<endl<<endl;
    cout<<"\t\t  Validation"<<setw(5)<<v1<<"-"<<v2<<"-"<<v3<<"-"<<v4<<"-"<<v5<<endl;
    cout<<"\t\t       "<<dt<<endl<<fixed<<setprecision(2)<<showpoint;                   //Set iomanip/header format
    cout<<"\t\t\t   "<<setw(5)<<"$"<<budget<<endl<<endl;
    cout<<"\t Ticket void after 30 days"<<setw(17)<<"Machine #"<<mNum<<endl;
    cout<<"\t------------------------------------------------------"<<endl<<endl;
    cout<<"\tNOTE: Bring your ID with you to cash it out to verify \n"
        <<"\t name in the voucher."<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//***************************** Array Fill *************************************
//Description: Fill array with generated random number.
//Inputs:  Using array and size as argument
//Outputs:  None.
//******************************************************************************

void filAray(int array[], int MINSIZE) {
    for (int index = 0; index < MINSIZE; index++) array[index] = rand()%(99-10+1)+10;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//****************************** Mark Sort *************************************
//Description: Sort the filled array for display and easier clarification of win
//       or loss.
//Inputs:  Using array and size as argument
//Outputs:  None.
//******************************************************************************

void mrkSrt(int array[], int MINSIZE) {
    for(int j=0;j<MINSIZE-1;j++){
        for(int i=j+1;i<MINSIZE;i++){
            if(array[j]>array[i]){              //Swap
                array[j]=array[j]^array[i];
                array[i]=array[j]^array[i];
                array[j]=array[j]^array[i];
            }
        }        
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//****************************** Print Array ***********************************
//Description: Display sorted array for win clarification.
//Inputs:  Using array and size as argument
//Outputs:  Output the stored numbers in array.
//******************************************************************************

void prntAry(int a[], int s) {
    for (int c = 0; c<s; c++) {
        cout<<a[c]<<" ";
        if (c%20==19) cout<<endl;
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//******************************** Status **************************************
//Description: Display sorted array for win clarification.
//Inputs:  Using budget and name as argument
//Outputs:  Output the current money of the player after a spin.
//******************************************************************************

void status(float budget, string name) {
    cout<<endl
        <<"----------------------------------------"<<endl;
    cout<<"Player: "<<name<<endl;                                   //Display current progress
    cout<<"Current Money: $"<<budget<<endl;                         //Name and current amount of money on system
    cout<<"----------------------------------------"<<endl<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//************************** Password Validation *******************************
//Description: Validates for staff login.
//Inputs:  User input of password and employee name
//Outputs:  Returns true if right and false if wrong
//******************************************************************************

bool valPass(string input, string empName) {
    string pass = "password", username = "username";
    if (input == pass && empName == username) return true;
    else return false;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//**************************** Money Round Off *********************************
//Description: This function is to round off money for exact value.
//Inputs:  Uses the money as argument
//Outputs:  Returns budget calculation to main
//******************************************************************************

float rndOffB(float budget, int rndOff) {
    int exBud = budget*rndOff+0.5f;
    budget = exBud/100.0f;                  //Round off Cash amount of user to get exact cash value
    return budget;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//***************************** Cash Insert ************************************
//Description: Passes the original value for the first cash insertion upon user
//      decision to play the game.
//Inputs:  Uses user input of budget as argument
//Outputs:  Returns the budget value after validation
//******************************************************************************

float insert(float &budget, string dummy) {
    float addFrst;
    do {                                                  //Start loop
        cout<<"\nInsert Cash: $";                         //Prompt user to insert cash amount for the game
        cin>>addFrst;               

        while (cin.fail()) {                                        //User input validation of float datatype
            cout<<"\nYou must only enter a number!"<<endl<<endl;    //for cash insertion
            cout<<"Insert Cash: $";
            cin.clear();
            getline(cin, dummy);
            cin>>addFrst;
        }  

        if (addFrst < 1) cout<<"\nCash amount inserted cannot be less than 1!\n"<<endl;      
        else if (addFrst > 20000) { 
            cout<<"\nCash inserted is above the limit!"<<endl;       //Loop if cash amount inserted is less than 1
            cout<<"Cash amount cannot go above $20000\n"<<endl;      //or above the limit $20000
        }
        else budget+=addFrst;

    } while ((budget < 1) || budget > 20000);           //Continue loop while budget/cash inserted <1 or >20000
    return budget;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//**************************** Winning Pattern *********************************
//Description: Display Winning pattern in the beginning and every time system
//      goes back to main menu.
//Inputs:  None
//Outputs:  Winning Pattern
//******************************************************************************

void winPat() {
    cout<<"\t      CSC5 CASINO RIVERSIDE"<<endl<<endl;
    cout<<"\tSLOT MACHINE 2017 (C++) Version"<<endl<<endl;
    cout<<"   Winning Patterns:                JACKPOT:       "<<endl<<endl;        //Normal winning patterns ear twice the best
    cout<<" X X X   - - -   - - -       X - X   - - -   X X X "<<endl;              //Winning pattern 777s wins thrice the bet
    cout<<" - - -   X X X   - - -       - X -   7 7 7   X - X "<<endl;              //Middle straight 777s pattern wins 10x the bet
    cout<<" - - -   - - -   X X X       X - X   - - -   X X X "<<endl<<endl;        //Normal Number Jackpot winning varies by pattern
    cout<<"     X - -   - - x               - X -   X X X     "<<endl;              //777s Pattern Jackpot has higher price win
    cout<<"     - X -   - X -               X X X   X X X     "<<endl;              
    cout<<"     - - X   x - -               - X -   X X X     "<<endl<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//************************ Game Report Prompt **********************************
//Description: Display game report prompt
//Inputs:  None
//Outputs:  Prompt
//******************************************************************************

void askRep() {
    cout<<"\nWould you like to see your game report?"<<endl                     //Prompt user if he/she wants to see game report
        <<"         Y - YES      N - NO"<<endl<<endl;
    cout<<"CHOICE: ";
}























