
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on January 10, 2017, 12:04 PM
 * Purpose: Calculate the percentage of Military Budget and NASA Budget
 *          Given:
 *              Federal Budget = $3.54 Trillion (http://federal-budget.insidegov.com/l/119/2016-Estimate)
 *              Military Budget = 580 Billion (https://cit.com/thought-leadership/us-defense-spending-industry-outlook/?cmp=paidsearch&gclid=CPet5pm-uNECFQuAfgod9REM_w&jcpid=8a8ae4cd56581431015659d1200a185b&jsf=6b5514c6-2561-48b5-9fec-3a9e58b6d5a7:35584)
 *              NASA Budget = 19 Billion (https://www.theatlantic.com/science/archive/2015/12/nasa-budget-2016-mars-rover-europa-mission-planetary-science/420912/)
 */

//System Libraries
#include <iostream>
#include<iomanip>
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
    long int fedBudg = 3.54e12,   //2016 Federal Budget
             milBudg = 580e9,     //2016 Military Budget 
             nasBudg = 19e9;      //2016 NASA Budget
    float perMil,                 //Percentage of Military Budget
          perNasa;                //Percentage of NASA Budget         
    
    cout<<"Here we calculate the percentage of Military Budget and the NASA Budget "<<endl
        <<"based on 2016's Federal Budget."<<endl<<endl<<"---------------------------------"<<endl
        <<"           2016 Report"<<endl<<"---------------------------------"<<endl<<fixed
        <<"Federal Budget:   $ "<<setprecision(2)<<fedBudg<<endl
        <<"Military Budget:  $  "<<setprecision(2)<<milBudg<<endl
        <<"NASA Budget:      $   "<<setprecision(2)<<nasBudg<<endl<<endl;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    perMil = (static_cast<float>(milBudg)/fedBudg)*100;
    perNasa = (static_cast<float>(nasBudg)/fedBudg)*100;
    
    //Output values
    cout<<"The Military Budget is "<<perMil<<"% of the Federal Budget."<<endl;
    cout<<"The NASA Budget is "<<perNasa<<"% of the Federal Budget."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

