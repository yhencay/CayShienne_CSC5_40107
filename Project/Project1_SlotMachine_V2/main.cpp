
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 27, 2017, 3:57 PM
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
                bonCshP = 0.01f;        //Bonus cash for playing the game
    float budget = 0,                       //Player's capital for the game
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
        g8mBon = 10;                    //Game bonus when number of play reached!
    char begin,                         //User input to play the game
         load,                          //User adds money if you wants to play again
         choice,                        //User input to continue playing or not
         report;                        //User choice to print out game report
    unsigned short rn1, rn2, rn3,
                   rn4, rn5, rn6,     //Random numbers for slot machine
                   rn7, rn8, rn9;
    bool x = true;          //Loop for budget
    bool y = true;          //Loop for game play
    bool z = true;          //Loop for inserting additional cash decision
    bool a = true;
    
    //Input Values
    cout<<"\t      CSC5 CASINO RIVERSIDE"<<endl<<endl;
    cout<<"\tSLOT MACHINE 2017 (C++) Version"<<endl<<endl;
    cout<<"   Winning Patterns:                JACKPOT:       "<<endl<<endl;
    cout<<" X X X   - - -   - - -       X - X   - - -   X X X "<<endl;
    cout<<" - - -   X X X   - - -       - X -   7 7 7   X - X "<<endl;
    cout<<" - - -   - - -   X X X       X - X   - - -   X X X "<<endl<<endl;
    cout<<"     X - -   - - x               - X -   X X X     "<<endl;
    cout<<"     - X -   - X -               X X X   X X X     "<<endl;
    cout<<"     - - X   x - -               - X -   X X X     "<<endl<<endl;
    
    do {
        cout<<"Would you like to play the game? "<<endl;
        cout<<"      Y - YES    N - NO"<<endl<<endl;
        cout<<"CHOICE: ";
        cin>>begin;
        getline(cin, dummy);

        cout<<fixed<<setprecision(2)<<showpoint;

        switch (begin) {
            case 'y':
            case 'Y': {
                cout<<endl;
                cout<<"Enter Player Name: ";
                getline(cin, name);

                do {
                    cout<<"Insert Cash: $";
                    cin>>budget;
                    getline(cin, dummy);
                    cshIns += budget;

                    if (budget < 1) cout<<"\nCash amount inserted cannot be less than 1!\n"<<endl;
                    else if (budget > 10000000) cout<<"\nCash inserted is above the limit!\n"<<endl;

                } while ((budget < 1) || budget > 10000000);    
                
                float cshBon = pow((budget*bonCshP), 2);
                
                if (budget >= 0 && budget <= 10000000) {                    
                    budget += cshBon;
                    cout<<"\nThank you for choosing to play the game!"<<endl;
                    cout<<"We added $"<<cshBon<<" to your capital as cash bonus."<<endl<<endl;
                    cout<<"Good luck ^_^"<<endl;
                    bonWin+=cshBon;
                }

                cout<<endl
                    <<"-----------------------------------"<<endl;
                cout<<name<<endl;
                cout<<"Current Money: $"<<budget<<endl;
                cout<<"-----------------------------------"<<endl<<endl;

                do {            
                    
                    if (budget<=0) {
                        do {
                            cout<<"You have used up all your funds. Would you like to insert again? "<<endl;
                            cout<<"     Y - Yes     N - No  "<<endl<<endl;
                            cout<<"CHOICE: ";
                            cin>>load;

                            switch (load) {
                                case 'y':
                                case 'Y': {
                                    do {
                                        cout<<"\nInsert Cash: $";
                                        cin>>add;
                                        cshIns+=add;
                                        cout<<endl;

                                        if (add > 0)  budget += add;
                                        else cout<<"Value must be greater than 0!"<<endl;
                                    } while (add <= 0);  
                                    z = false;
                                } break;
                                
                                case 'n':
                                case 'N': z = false;
                                          x=false; 
                                          break;
                                
                                default: cout<<"\nYou can only enter 'Y' or 'N'\n"<<endl;
                                         break;
                            }
                        } while (z);                         
                    }
                    
                    else if (budget > 0 && budget != 0) {
                        do {                           
                            cout<<"\tPLAY"<<endl<<endl;
                            cout<<"S - SPIN   C - CANCEL"<<endl<<endl;
                            cout<<"CHOICE: ";
                            cin>>choice;                        

                            if (budget == 0.00 && (choice == 'S' || choice == 's')) a=false;
                            
                            if (budget >= 0.01 && (choice == 'S' || choice == 's')) {                  
                                do {                        
                                    cout<<endl<<"BET: $";
                                    cin>>bet;     

                                    if (bet>budget && budget>0) {
                                        cout<<"\nYour bet cannot be higher than your capital!"<<endl;
                                        cout<<"Your remaining cash is $"<<budget<<endl<<endl;
                                    }
                                    else if (bet<=0 && budget>0) {
                                        cout<<"\nBet must be greater than 0!"<<endl;
                                        cout<<"Your remaining cash is $"<<budget<<endl<<endl;
                                    }
                                    else if (bet>0 && budget>0 && bet<=budget) {
                                        play++;   
                                        
                                        budget = (play==g8mBon && g8mBon<=50)?budget+=(loss*bonCsh1):
                                                 (play==g8mBon && g8mBon<=100)?budget+=(loss*bonCsh2):
                                                 (play==g8mBon && g8mBon<=300)?budget+=(loss*bonCsh3):
                                                 (play==g8mBon && g8mBon>=301)?budget+=(loss*bonCsh4): budget;
                                        
                                        if (play==g8mBon) {
                                            
                                            float amount = (g8mBon<=50)?(loss*bonCsh1):
                                                           (g8mBon<=100)?(loss*bonCsh2):
                                                           (g8mBon<=300)?(loss*bonCsh3):
                                                           (g8mBon>=301)?(loss*bonCsh4):'\n';
                                            
                                            cout<<"\nCongratulations!\n"
                                                <<"You earned game bonus for reaching "<<g8mBon<<" number of spins!"<<endl;
                                            cout<<"$"<<amount<<" is added to your cash amount!"<<endl;
                                            g8mBon+=g8mBon;  
                                            bonWin+=(g8mBon<=50)?(loss*bonCsh1):
                                                      (g8mBon<=100)?(loss*bonCsh2):
                                                      (g8mBon<=300)?(loss*bonCsh3):
                                                      (g8mBon>=301)?(loss*bonCsh4):0;
                                        }
                                                                                                                        
                                        rn1 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn2 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn3 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn4 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn5 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn6 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn7 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn8 = (rand()%(8-4+1))+4;   //Value range from 4 to 8
                                        rn9 = (rand()%(8-4+1))+4;   //Value range from 4 to 8

                                        cout<<endl;
                                        cout<<"\t"<<rn1<<"  "<<rn2<<"  "<<rn3<<endl;
                                        cout<<"\t"<<rn4<<"  "<<rn5<<"  "<<rn6<<endl;
                                        cout<<"\t"<<rn7<<"  "<<rn8<<"  "<<rn9<<endl<<endl;

                                        if (rn1==rn2 && rn2==rn3) {
                                            if (rn1 == 7) {
                                                budget += (bet*2);
                                                cout<<"Straight 777s earn 3x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                numWin++;
                                                win+=(bet*2);
                                            }
                                            else {
                                                budget += bet;
                                                cout<<"Straight number earns 2x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                numWin++;
                                                win+=bet;
                                            }
                                        }
                                        else if (rn4==rn5 && rn5==rn6) {
                                            if (rn4 == 7) {
                                                budget += (bet*9);
                                                cout<<"Straight 777s in the middle earn 10x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                numWin++;
                                                win+=(bet*9);
                                            }
                                            else {
                                                budget += bet;
                                                cout<<"Straight number earns 2x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                numWin++;
                                                win+=bet;
                                            }
                                        }
                                        else if (rn7==rn8 && rn8==rn9) {
                                            if (rn7 == 7) {
                                                budget += (bet*2);
                                                cout<<"Straight 777s earn 3x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                numWin++;
                                                win+=(bet*2);
                                            }
                                            else {
                                                budget += bet;
                                                cout<<"Straight number earns 2x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                numWin++;
                                                win+=bet;
                                            }
                                        }
                                        else if (rn1==rn5 && rn5==rn9) {
                                            if (rn1 == 7) {
                                                budget += (bet*2);
                                                cout<<"Diagonal 777s earn 3x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                numWin++;
                                                win+=(bet*2);
                                            }
                                            else {
                                                budget += bet;
                                                cout<<"Diagonal number earns 2x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                numWin++;
                                                win+=bet;
                                            }
                                        }
                                        else if (rn7==rn5 && rn5==rn3) {
                                            if (rn7 == 7) {
                                                budget += (bet*2);
                                                cout<<"Diagonal 777s earn 3x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*3)<<endl;
                                                numWin++;
                                                win+=(bet*2);
                                            }
                                            else {
                                                budget += bet;
                                                cout<<"Diagonal number earns 2x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*2)<<endl;
                                                numWin++;
                                                win+=bet;
                                            }
                                        }
                                        else if (rn1==rn5 && rn5==rn9 && rn9==rn3 && rn3 == rn7) {
                                            if (rn1 == 7) {
                                                budget += (bet*9);
                                                cout<<"X Pattern 777s earn 10x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                numWin++;
                                                win+=(bet*9);
                                            }
                                            else {
                                                budget += (bet*4);
                                                cout<<"X Pattern number earns 5x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*5)<<endl;
                                                numWin++;
                                                win+=(bet*4);
                                            }
                                        }
                                        else if (rn2==rn4 && rn4==rn5 && rn5==rn6 && rn6==rn8) {
                                            if (rn2 == 7) {
                                                budget += (bet*9);
                                                cout<<"Cross Pattern 777s earn 10x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                numWin++;
                                                win+=(bet*9);
                                            }
                                            else {
                                                budget += (bet*4);
                                                cout<<"Cross Pattern number earns 5x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*5)<<endl;
                                                numWin++;
                                                win+=(bet*4);
                                            }
                                        }
                                        else if (rn1==rn2 && rn2==rn3 && rn3==rn4 && rn4 == rn6 && rn7==rn8 && rn8 == rn9) {
                                            if (rn1 == 7) {
                                                budget += (bet*14);
                                                cout<<"Square Pattern 777s earn 15x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*15)<<endl;
                                                numWin++;
                                                win+=(bet*14);
                                            }
                                            else {
                                                budget += (bet*9);
                                                cout<<"Square Pattern number earns 10x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*10)<<endl;
                                                numWin++;
                                                win+=(bet*9);
                                            }
                                        }
                                        else if (rn1==rn2 && rn2==rn3 && rn3==rn4 && rn4 == rn5 
                                                && rn5==rn6 && rn6 == rn7 && rn7 == rn8 && rn8 == rn9) {
                                            if (rn1 == 7) {
                                                budget += (bet*99);
                                                cout<<"All 777s earn 100x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*100)<<endl;
                                                numWin++;
                                                win+=(bet*100);
                                            }
                                            else {
                                                budget += (bet*49);
                                                cout<<"All same number earns 50x bet!"<<endl;
                                                cout<<"Congratulations for winning $"<<(bet*50)<<endl;
                                                numWin++;
                                                win+=(bet*49);
                                            }
                                        }
                                        else {
                                            budget -= bet;
                                            cout<<"Sorry, you lost $"<<bet<<endl;
                                            numLose++;
                                            loss+=bet;
                                        }                                                                                
                                        cout<<"\n"
                                            <<"-----------------------------------"<<endl;   
                                        cout<<name<<endl;
                                        cout<<"Current Money: $"<<budget<<endl;
                                        cout<<"-----------------------------------"<<endl<<endl;                                        
                                    }
                                    else {
                                        cout<<"\nYou can only enter numbers!\n"<<endl;
                                    }
                                } while (bet<=0 && bet>budget && budget>0); //(bet>budget ||                                 
                            }
                            
                            else if (choice == 'C' || choice == 'c')  {
                                if (play == 0) {
                                    budget -= cshBon;
                                    bonWin -=cshBon;
                                    x = false;
                                }
                                else x=false; 
                            }
                            else { cout<<"\nWarning: Enter only either 'S' or 'C' \n"<<endl; }
                        } while (budget>0 && budget != 0 && x && a); //&& (choice == 'S' || choice == 's')
                    }  
                
                                        

                    else x=false;   

                } while (x);
                y = false;
            } break;

            case 'n':
            case 'N': {
                cout<<"\nGoodbye!"<<endl;
                y = false;
            } break; 

            default: {
                cout<<"\nWarning: You can only enter 'Y' or 'N'!\n"<<endl;                
            } break;     
        }  
    } while (y);
    
    if (x == false) {
 
        totCash = cshIns + bonWin + win;
        
        for (int p = 1; p <= 1; p++) {           
            if (budget>0) {
                cout<<"\nCashout voucher printing..."<<endl<<endl;
                
                unsigned short ticket = (rand()%(9999-1000+1))+1000;                //Ticket number for voucher generator
                unsigned short v1 = (rand()%(99-10+1))+10;              
                unsigned short v2 = (rand()%(9999-1000+1))+1000;
                unsigned short v3 = (rand()%(9999-1000+1))+1000;                    //Number generator for validation code of voucher
                unsigned short v4 = (rand()%(9999-1000+1))+1000;
                unsigned short v5 = (rand()%(9999-1000+1))+1000;
                unsigned int mNum = (rand()%(4294967294-1000000000+1))+1000000000;  //Number generator for machine number

                cout<<"\t------------------------------------------------------"<<endl;
                cout<<"\t CSC5 CASINO RIVERSIDE, CA"<<setw(27)<<ticket<<endl<<endl;
                cout<<"\t\t\t   CASHOUT VOUCHER"<<endl<<endl;
                cout<<"\t\t\tFOR "<<name<<endl<<endl;
                cout<<"\t\t  Validation"<<setw(5)<<v1<<"-"<<v2<<"-"<<v3<<"-"<<v4<<"-"<<v5<<endl;
                cout<<"\t\t       "<<dt<<endl<<fixed<<setprecision(2)<<showpoint;
                cout<<"\t\t\t   "<<setw(5)<<"$"<<budget<<endl<<endl;
                cout<<"\t Ticket void after 30 days"<<setw(17)<<"Machine #"<<mNum<<endl;
                cout<<"\t------------------------------------------------------"<<endl<<endl;
                cout<<"\tNOTE: Bring your ID with you to cash it out to verify name\n"
                    <<"\t  in the voucher."<<endl;

                cout<<"\nWould you like to see your game report?"<<endl
                    <<"         Y - YES      N - NO"<<endl<<endl;
                cout<<"CHOICE: ";
                cin>>report;
            
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

                        winPer = (static_cast<float>(numWin)/play)*PERCENT;
                        lossPer = (static_cast<float>(numLose)/play)*PERCENT;

                        cout<<"Win Percentage: "<<winPer<<"%"<<endl;   
                        cout<<"Loss Percentage: "<<lossPer<<"%"<<endl; 
                    }
                    else cout<<"\nThank you for playing! See you again!\n"<<endl;            
                }
            
            else if (budget <=0) {
                cout<<"\nSorry, you didn't win any amount this time."<<endl;
                
                cout<<"\nWould you like to see your game report?"<<endl
                    <<"         Y - YES      N - NO"<<endl<<endl;
                cout<<"CHOICE: ";
                cin>>report;
            
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

                    winPer = (static_cast<float>(numWin)/play)*PERCENT;
                    lossPer = (static_cast<float>(numLose)/play)*PERCENT;

                    cout<<"Win Percentage: "<<winPer<<"%"<<endl;   
                    cout<<"Loss Percentage: "<<lossPer<<"%"<<endl; 
                }
                else cout<<"\nThank you for playing! See you again!\n"<<endl;
            }
        }       
    }
    else cout<<"\nPlay the game next time!"<<endl;
       
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

