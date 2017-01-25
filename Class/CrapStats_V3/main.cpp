/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017, 10:35 AM
 * Purpose: Statistics for Craps Version 2
 */

//System Libraries
#include <iostream> //Input Output Library
#include <cstdlib>  //Random numbers
#include <ctime>    //Time to set the seed
#include <fstream> //File Stream Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT = 100; //Percentage conversion
const int MILLION = 1e6; //Million
const int HUNTHSD = 1e5; //100 Thousand

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Instantiate and Open files
    ifstream in;
    ofstream out;
    in.open("NumberOfGames.dat");
    out.open("ResultsOfGames.dat:");
    
    
    //Declare Variables
    unsigned int nGames = 1000000000; //Number of throws for the pair of dice
    unsigned int wins = 0, losses = 0, maxThrw = 0;
    unsigned int avgThrw = 0;
    
    //Input the number of games
    //Last line will be number of games
    while (in>>nGames);
    nGames = nGames>MILLION?HUNTHSD:nGames;

    //Loop and take dice statistics
    for (int game = 1;game<=nGames;game++) {
        //Call random generator from the dice
        char die1 = rand()%6+1; //Value from 1 to 6
        char die2 = rand()%6+1; //Value from 1 to 6
        char sum = die1 + die2;
        unsigned int cntThrw = 1;
        avgThrw++;
        
        //Now determine wins or losses
        if (sum == 2 || sum == 3 || sum == 12) losses++;
        else if (sum == 7 || sum == 11) wins++;
        else {
            bool kpThrw = true;
            do {
                die1 = rand()%6+1; //Value from 1 to 6
                die2 = rand()%6+1; //Value from 1 to 6
                avgThrw++; cntThrw++;
                char sumAgn = die1 + die2;
                if (sumAgn == 7) {
                    losses++;
                    kpThrw = false;
                }
                else if (sumAgn == sum) {
                    wins++;
                    kpThrw = false;
                }
            } while(kpThrw);
        }
        if (maxThrw < cntThrw) maxThrw = cntThrw;
    }
    //Calculate the average throw
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"Hey";
    out<<fixed<<setprecision(2)<<showpoint<<endl;
    out<<"The total number of Crap games played = "<<nGames<<endl;
    out<<"The total wins = "<<wins<<endl;
    out<<"The total losses = "<<losses<<endl;
    out<<"The total number of Crap games played = "<<wins+losses<<endl;
    out<<"Percentage wins = "<<static_cast<float>(PERCENT)*wins/nGames<<endl;
    out<<"Percentage losses = "<<static_cast<float>(PERCENT)*losses/nGames<<endl;
    out<<"Average number of throws per game = "
       <<static_cast<float>(avgThrw)/nGames<<endl;
    out<<"Maximum number of throws in a game = "<<maxThrw<<endl;
        
    //Exit stage right! - This is the 'return 0' call
    in.close();
    out.close();
    
    return 0;
}

