
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 16, 2017, 6:19 PM
 * Purpose: Homework Software Sales
 *      Problem: A software company sells a package that retails for $99. 
 * Quantity discounts are given according to the following table.
 *         Quantity            Discount
 *          10–19                 20%
 *          20–49                 30%
 *          50–99                 40%
 *          100 or more           50%
 *      Write a program that asks for the number of units sold and computes the 
 * total cost of the purchase.
 *      Input Validation: Make sure the number of units is greater than 0. 
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    const float dis1 = 0.20f,       //Discounts applied if conditions are met
                dis2 = 0.30f,
                dis3 = 0.40f,
                dis4 = 0.50f;
    float units,        //User input how many units sold
          cost,         //Total cost
          dscnt;        //Discounted price
          
    //Input Values
    cout<<"A package is $99 per unit. Discounts are applied when you buy in quantity!\n"<<endl;
    cout<<"------------------------------\n"
        <<" Quantity            Discount \n"
        <<"------------------------------\n"
        <<"  10–19                 20%   \n"
        <<"  20–49                 30%   \n"
        <<"  50–99                 40%   \n"  
        <<"  100 or more           50%   \n";
    cout<<endl;
    cout<<"How many units would you like to buy? ";
    cin>>units;
    cout<<endl<<fixed<<setprecision(2);
            
    //Process by mapping inputs to outputs    
    //Output values
    if ((units >= 10) && (units <= 19)) {
        dscnt = (units * 99)*dis1;
        cost = (units * 99) - dscnt;
        cout<<"The total cost of purchase is: $ "<<cost<<endl;
        cout<<"You saved $ "<<dscnt<<" with the discount.\n"<<endl;
        cout<<"Come back again!"<<endl;
    }
    else if ((units >= 20) && (units <= 49)) {
        dscnt = (units * 99)*dis2;
        cost = (units * 99) - dscnt;
        cout<<"The total cost of purchase is: $ "<<cost<<endl;
        cout<<"You saved $ "<<dscnt<<" with the discount.\n"<<endl;
        cout<<"Come back again!"<<endl;
    }
    else if ((units >= 50) && (units <= 99)) {
        dscnt = (units * 99)*dis3;
        cost = (units * 99) - dscnt;
        cout<<"The total cost of purchase is: $ "<<cost<<endl;
        cout<<"You saved $ "<<dscnt<<" with the discount.\n"<<endl;
        cout<<"Come back again!"<<endl;
    }
    else if (units >= 100) {
        dscnt = (units * 99)*dis4;
        cost = (units * 99) - dscnt;
        cout<<"The total cost of purchase is: $ "<<cost<<endl;
        cout<<"You saved $ "<<dscnt<<" with the discount.\n"<<endl;
        cout<<"Come back again!"<<endl;
    }
    else if (units > 0) {
        cost = (units * 99);
        cout<<"The total cost of purchase is: $ "<<cost<<endl;
        cout<<"No available discount for this purchase!\n"<<endl;
        cout<<"Come back again!"<<endl;        
    }
    else cout<<"ERROR! INVALID INPUT!";
        
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

