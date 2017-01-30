
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 18, 2017,  1:21 PM
 * Purpose: Homework 
 *      Problem: 
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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
    time_t now = time(0);
    char* dt = ctime(&now);
    int amount = 165;
    
    string name = "Mark Lehr";

    srand(static_cast<unsigned int>(time(0)));

    unsigned short ticket = (rand()%(9999-1000+1))+1000;
    unsigned short v1 = (rand()%(99-10+1))+10;
    unsigned short v2 = (rand()%(9999-1000+1))+1000;
    unsigned short v3 = (rand()%(9999-1000+1))+1000;
    unsigned short v4 = (rand()%(9999-1000+1))+1000;
    unsigned short v5 = (rand()%(9999-1000+1))+1000;
    unsigned int mNum = (rand()%(4294967294-1000000000+1))+1000000000;
    
            cout<<"\t------------------------------------------------------"<<endl;
            cout<<"\t CSC5 CASINO RIVERSIDE, CA"<<setw(27)<<ticket<<endl<<endl;
            cout<<"\t\t\t   CASHOUT VOUCHER"<<endl<<endl;
            cout<<"\t\t\tFOR "<<name<<endl<<endl;
            cout<<"\t\t  Validation"<<setw(5)<<v1<<"-"<<v2<<"-"<<v3<<"-"<<v4<<"-"<<v5<<endl;
            cout<<"\t\t       "<<dt<<endl<<fixed<<setprecision(2)<<showpoint;
            cout<<"\t\t\t   "<<setw(5)<<"$"<<static_cast<float>(amount)<<endl<<endl;
            cout<<"\t Ticket void after 30 days"<<setw(17)<<"Machine #"<<mNum<<endl;
            cout<<"\t------------------------------------------------------"<<endl;
            
            
            cout<<"\n\tSLOT MACHINE GAME REPORT"<<endl<<endl;
            cout<<"Number of games played: "<<endl;
            cout<<"Number of wins: "<<endl;
            cout<<"Number of losses: "<<endl<<endl;
            cout<<"Total amount of cash inserted: $"<<endl;
            cout<<"Total amount of cash win: $"<<endl;
            cout<<"Total amount of cash loss: $"<<endl;
        
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

