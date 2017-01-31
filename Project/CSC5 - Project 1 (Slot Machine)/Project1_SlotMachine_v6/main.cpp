
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 30, 2017, 7:57 PM
 * Purpose: PROJECT 1 SLOT MACHINE
 * Problem: 
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
const short PERCENT = 100; //Percentage Conversion  

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random seed using time
    srand(static_cast<unsigned int>(time(0)));
    
    //Set local time and date
    time_t now = time(0);
    char* dt = ctime(&now);
    
    //Declare Variables    
    string name,                        //Player name
           dummy;                       //Dummy string
    const float bonCsh1 = 0.05f,        
                bonCsh2 = 0.10f,        //Cash bonus percentage per spin play reached
                bonCsh3 = 0.15f,
                bonCsh4 = 0.25f,
                bonCshP = 0.01f,        //Bonus cash for playing the game
                minVal = 0;             //Minimum Value set for comparison
    float budget,                       //Player's capital for the game
          add,                          //User option to add money if capital went down 0
          bet,                          //How much the player is willing to wager
          loss = 0,                     //Total loss amount
          win = 0,                      //Total win amount
          bonWin = 0,                   //Total bonus win
          cshIns = 0,                   //Total amount of cash inserted in the game
          totCash,                      //Total money involved including win, cash insert and bonus win
          winPer,                       //Number of games won percentage
          lossPer;                      //Number of games lost percentage    
    int numWin = 0,                     //Number of win within total times played
        numLose = 0,                    //Number of loss within total times played
        play = 0,                       //Total number of plays
        g8mBon = 10,                    //Game bonus when number of play reached!
        rndOff = 100;                   //Round off to two decimal places
    char begin,                         //User input to play the game
         load,                          //User adds money if you wants to play again
         choice,                        //User input to continue playing or not
         report;                        //User choice to print out game report
    unsigned short rn1, rn2, rn3,
                   rn4, rn5, rn6,       //Random numbers for slot machine
                   rn7, rn8, rn9;
    bool x = true;          //Loop for budget
    bool y = true;          //Loop for game play
    bool z = true;          //Loop for inserting additional cash decision
    bool rep = true;        //Loop for game report
    
    
    //Input Values
    cout<<"\t      CSC5 CASINO RIVERSIDE"<<endl<<endl;
    cout<<"\tSLOT MACHINE 2017 (C++) Version"<<endl<<endl;
    cout<<"   Winning Patterns:                JACKPOT:       "<<endl<<endl;        //Normal winning patterns ear twice the best
    cout<<" X X X   - - -   - - -       X - X   - - -   X X X "<<endl;              //Winning pattern 777s wins thrice the bet
    cout<<" - - -   X X X   - - -       - X -   7 7 7   X - X "<<endl;              //Middle straight 777s pattern wins 10x the bet
    cout<<" - - -   - - -   X X X       X - X   - - -   X X X "<<endl<<endl;        //Normal Number Jackpot winning varies by pattern
    cout<<"     X - -   - - x               - X -   X X X     "<<endl;              //777s Pattern Jackpot has higher price win
    cout<<"     - X -   - X -               X X X   X X X     "<<endl;              
    cout<<"     - - X   x - -               - X -   X X X     "<<endl<<endl;
    
    //Process by mapping inputs to outputs
    do {
        cout<<"Would you like to play the game? "<<endl;            //Prompt user to play game or not
        cout<<"      Y - YES    N - NO"<<endl<<endl;
        cout<<"CHOICE: ";
        cin>>begin;                                                 //Character variable for beginning choice
        getline(cin, dummy);                                        //Dummy string to accept cin & getline

        switch (begin) {                                            //Case statement for choice in variable Begin
            case 'y':                                               //Only accepts 'Y' and 'N' as input
            case 'Y': {
                cout<<endl;                                         //If user chooses to play the game
                cout<<"Enter Player Name: ";                        //Prompt user for name to be used later for cashout voucher
                getline(cin, name);                                 //using string datatype

                do {                                                //Start loop
                    cout<<"Insert Cash: $";                         //Prompt user to insert cash amount for the game
                    cin>>budget;
                    getline(cin, dummy);                    

                    while (cin.fail()) {                                        //User input validation of float datatype
                        cout<<"\nYou must only enter a number!"<<endl<<endl;    //for cash insertion
                        cout<<"Insert Cash: $";
                        cin.clear();
                        getline(cin, dummy);
                        cin>>budget;
                    }  
                    
                    if (budget < 1) cout<<"\nCash amount inserted cannot be less than 1!\n"<<endl;      
                    else if (budget > 20000) { 
                        cout<<"\nCash inserted is above the limit!"<<endl;       //Loop if cash amount inserted is less than 1
                        cout<<"Cash amount cannot go above $20000\n"<<endl;      //or above the limit $20000
                    }
                    
                } while ((budget < 1) || budget > 20000);           //Continue loop while budget/cash inserted <1 or >20000
                
                cshIns += budget;                               //Add the amount inserted to total cash inserted
                
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
                
                int exBud = budget*rndOff+0.5;
                budget = exBud/100.0f;                  //Round off Cash amount of user to get exact cash value
                
                cout<<endl
                    <<"----------------------------------------"<<endl;
                cout<<"Player: "<<name<<endl;                                   //Display current progress
                cout<<"Current Money: $"<<budget<<endl;                         //Name and current amount of money on system
                cout<<"----------------------------------------"<<endl<<endl;

                do {                                                //Start loop for budget condition. If bool x for budget is true, continue loop.
                    if (budget > minVal) {                          //If budget is greater than 0, start loop.
                        do {
                            cout<<"\tPLAY"<<endl<<endl;                     //Prompt user to Spin or Cancel game
                            cout<<"S - SPIN   C - CANCEL"<<endl<<endl;
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
                                        
                                        budget = (play==g8mBon && g8mBon<=50)?budget+=(loss*bonCsh1):           //If number of spin cash bonus is reached, add
                                                 (play==g8mBon && g8mBon<=100)?budget+=(loss*bonCsh2):          //5% of amount loss for <=50 spins reached. 10% for
                                                 (play==g8mBon && g8mBon<=300)?budget+=(loss*bonCsh3):          //<=100 spins, 15% for <=300 spins reached and 25% for
                                                 (play==g8mBon && g8mBon>=301)?budget+=(loss*bonCsh4): budget;  //25% for >=301 spins.
                                                                                                                //If no conditions are met, cash amount remains the same
                                        if (play==g8mBon) {                                            
                                            float amount = (g8mBon<=50)?(loss*bonCsh1):             //If spin cash bonus is triggered, calculate amount to be added
                                                           (g8mBon<=100)?(loss*bonCsh2):            //based on same conditions for cash addition above
                                                           (g8mBon<=300)?(loss*bonCsh3):
                                                           (g8mBon>=301)?(loss*bonCsh4):'\n';
                                            
                                            cout<<"\nCongratulations!\n"                            //Let user know that he/she won cash bonus for reaching specific number of
                                                <<"You earned game bonus for reaching "<<g8mBon<<" number of spins!"<<endl;    //spins that the game requires
                                            cout<<"$"<<amount<<" is added to your cash amount!"<<endl;
                                            g8mBon+=g8mBon;                                         //Add game bonus spins by itself or multiply required by 2 for next bonus
                                            bonWin+=(g8mBon<=50)?(loss*bonCsh1):
                                                    (g8mBon<=100)?(loss*bonCsh2):                   //Add the cash bonus earned to total cash bonus for record
                                                    (g8mBon<=300)?(loss*bonCsh3):
                                                    (g8mBon>=301)?(loss*bonCsh4):minVal;
                                        }
                                                                                                                        
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
                                                budget += (bet*9);                                          //If cross pattern 777s come out, user wins 10x bet
                                                cout<<"Cross Pattern 777s earn 10x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                numWin++;                                                   //Increment number of wins
                                                win+=(bet*9);                                               //Add winning amount to total amount of wins for record
                                            }
                                            else {
                                                budget += (bet*4);                                          //If cross pattern normal numbers come out, user wins 5x bet
                                                cout<<"Cross Pattern number earns 5x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*5)<<endl;
                                                numWin++;                                                   //Increment number of wins
                                                win+=(bet*4);                                               //Add winning amount to total amount of wins for record
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
                                        
                                        exBud = budget*rndOff+0.5;                                     //Round off budget to get exact value
                                        budget = exBud/100.0f;
                                        
                                        cout<<"\n"
                                            <<"-----------------------------------"<<endl;             //Display Name and current money
                                        cout<<"Player: "<<name<<endl;
                                        cout<<"Current Money: $"<<budget<<endl;
                                        cout<<"-----------------------------------"<<endl<<endl;                                                                               
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
										
                                        exBud = budget*rndOff+0.5;                                  //Round off budget for exact value
                                        budget = exBud/100.0f;
                                        
                                        cout<<"\n"
                                            <<"-----------------------------------"<<endl;          //Display name and current money
                                        cout<<"Player: "<<name<<endl;
                                        cout<<"Current Money: $"<<budget<<endl;
                                        cout<<"-----------------------------------"<<endl<<endl;
                                        
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

            case 'n':
            case 'N': {
                cout<<"\nGoodbye!"<<endl;               //If begin is 'n' or 'N', exit game prompt 
                y = false;                              //Game play exit
            } break; 

            default: {
                cout<<"\nWarning: You can only enter 'Y' or 'N'!\n"<<endl;    //If begin is not 'N' or 'Y', display invalidity            
            } break;     
        }  
    } while (y);                            //If game play remains true, continue loop
    
    //Output values
    cout<<fixed<<setprecision(2)<<showpoint;
    
    if (x == false) {                                   //Start loop exit condition
 
        totCash = cshIns + bonWin + win;                //Calculate total money involved
        
        for (int p = 1; p <= 1; p++) {                  //Loop voucher one time
            if (budget>minVal) {                                                  //If chosen to exit game and there's money left on account
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
                
                do {                   
                cout<<"\nWould you like to see your game report?"<<endl                 //Prompt user if wants to see game report
                    <<"         Y - YES      N - NO"<<endl<<endl;
                cout<<"CHOICE: ";
                cin>>report;                
   
                    if (report == 'Y' || report == 'y') {                                   //If yes, display report
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
                        
                        cout<<"\nThank you for playing the game! See you again next time!"<<endl<<endl;
                        
                        rep = false;
                    }                    
                    else if (report == 'N' || report == 'n') {                          //If user does not want to see game report
                    ofstream out;                                                   //Save report to a file
                    out.open(name+".dat");
                    
                    out<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
                    out<<"Number of games played: "<<play<<endl;
                    out<<"Number of wins: "<<numWin<<endl;
                    out<<"Number of losses: "<<numLose<<endl<<endl;
                    out<<"Total amount of cash inserted: $"<<cshIns<<endl;
                    out<<"Total amount of cash won: $"<<win<<endl;
                    out<<"Total amount of cash bonus: $"<<bonWin<<endl<<endl;
                    out<<"Total amount of cash involved: $"<<totCash<<endl;
                    out<<"Total amount of cash loss: $"<<loss<<endl<<endl;

                    winPer = (static_cast<float>(numWin)/play)*PERCENT;
                    lossPer = (static_cast<float>(numLose)/play)*PERCENT;

                    out<<"Win Percentage: "<<winPer<<"%"<<endl;   
                    out<<"Loss Percentage: "<<lossPer<<"%"<<endl; 
                    cout<<"\nGame report is saved to a file."<<endl;
                    cout<<"\nThank you for playing! See you again!\n"<<endl;
                    
                    out.close();
                    rep = false;
                    }
                
                    else cout<<"\nWarning: You can only enter 'Y' or 'N'!"<<endl;        //If user input is not either 'Y' or 'N', display invalidity 
                } while (rep);
            }
            
            else if (budget <=0) {                                                          //If no money left on account                
                cout<<"\nSorry, you didn't win any amount this time."<<endl;
                
                    do { 
                    cout<<"\nWould you like to see your game report?"<<endl                     //Prompt user if he/she wants to see game report
                        <<"         Y - YES      N - NO"<<endl<<endl;
                    cout<<"CHOICE: ";
                    cin>>report;                

                    if (report == 'Y' || report == 'y') {                                       //If yes, display report
                        cout<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
                        cout<<"Number of games played: "<<play<<endl;
                        cout<<"Number of wins: "<<numWin<<endl;
                        cout<<"Number of losses: "<<numLose<<endl<<endl;
                        cout<<"Total amount of cash inserted: $"<<cshIns<<endl;
                        cout<<"Total amount of cash won: $"<<win<<endl;
                        cout<<"Total amount of cash bonus: $"<<bonWin<<endl<<endl;
                        cout<<"Total amount of cash involved: $"<<totCash<<endl;
                        cout<<"Total amount of cash loss: $"<<loss<<endl<<endl;

                        winPer = (static_cast<float>(numWin)/play)*PERCENT;
                        lossPer = (static_cast<float>(numLose)/play)*PERCENT;

                        cout<<"Win Percentage: "<<winPer<<"%"<<endl;   
                        cout<<"Loss Percentage: "<<lossPer<<"%"<<endl; 

                        cout<<"\nThank you for playing the game! See you again next time!"<<endl<<endl;

                        rep = false;
                    }
                    else if (report == 'N' || report == 'n') {                          //If user does not want to see game report
                        ofstream out;                                                   //Save report to a file
                        out.open(name+".dat");

                        out<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
                        out<<"Number of games played: "<<play<<endl;
                        out<<"Number of wins: "<<numWin<<endl;
                        out<<"Number of losses: "<<numLose<<endl<<endl;
                        out<<"Total amount of cash inserted: $"<<cshIns<<endl;
                        out<<"Total amount of cash won: $"<<win<<endl;
                        out<<"Total amount of cash bonus: $"<<bonWin<<endl<<endl;
                        out<<"Total amount of cash involved: $"<<totCash<<endl;
                        out<<"Total amount of cash loss: $"<<loss<<endl<<endl;

                        winPer = (static_cast<float>(numWin)/play)*PERCENT;
                        lossPer = (static_cast<float>(numLose)/play)*PERCENT;

                        out<<"Win Percentage: "<<winPer<<"%"<<endl;   
                        out<<"Loss Percentage: "<<lossPer<<"%"<<endl; 
                        cout<<"\nGame report is saved to a file."<<endl;
                        cout<<"\nThank you for playing! See you again!\n"<<endl;

                        out.close();
                        rep = false;
                    }
                     else cout<<"\nWarning: You can only enter 'Y' or 'N'!"<<endl;        //If user input is not either 'Y' or 'N', display invalidity 
                } while (rep);
            }                                                       //Once condition reached, end game.
        }       
    }
    else cout<<"\nPlay the game next time!"<<endl;                  //If user decides not to play game, end game
     
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

