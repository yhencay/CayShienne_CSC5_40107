/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on January 26, 2017, 7:44 PM
  Purpose:  Midterm Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string> //String Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> 
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const short PERCENT = 100; 					//Percentage conversion

//Function Prototypes
void hProb1();
float calRt8l(float, float);        		//Calculate Retail
void hProb2();
float sales();          					//User input of sales figure
void hiesP3(float, float, float, float);    //find division with highest sales figure
void hProb3();
int axident();                        		//Input number of accidents per region
void lwstP4(int, int, int, int, int);   	//Calculate and display lowest number of accidents
void hProb4();
float kinEngy(float, float);        		//kinetic energy
void hProb5();
float celsius(short);       				//Celsius Table
void hProb6();
void cnToss(int);       					//Coin Toss
void hProb7();
float presVal(float, float, float); 		//Present Value
void hProb8();
float futVal(float, float, float);      	//Function to determine future value
void hProb9();
void getScor(float &);      						//Get value from user for the test scores
void calcAvg(float, float, float, float, float);    //Calculate average for test scores
float lwstP11(float, float, float, float, float);   //Find lowest value for prob 11
void hProb10();
void jdgData(float &);  							//Get user input
void calScor(float, float, float, float, float);    //Display result
float hiesP12(float, float, float, float, float);   //Calculate highest score
float lwstP12(float, float, float, float, float);   //Calculate lowest score

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"----------------------------------------"<<endl;
        cout<<"          CHOOSE FROM THE LIST          "<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"Type A : Homework - MARKUP"<<endl;
        cout<<"Type B : Homework - WINNING DIVISION"<<endl;
        cout<<"Type C : Homework - SAFEST DRIVING AREA"<<endl;
        cout<<"Type D : Homework - KINETIC ENERGY"<<endl;
        cout<<"Type E : Homework - TEMPERATURE TABLE"<<endl;
        cout<<"Type F : Homework - COIN TOSS"<<endl;
        cout<<"Type G : Homework - PRESENT VALUE"<<endl;
        cout<<"Type H : Homework - FUTURE VALUE"<<endl;
        cout<<"Type I : Homework - LOWEST SCORE DROP"<<endl;
        cout<<"Type J : Homework - STAR SEARCH"<<endl;
        cout<<"----------------------------------------"<<endl;
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
//Description: Write a program that asks the user to enter an item’s wholesale 
//    cost and its markup percentage. It should then display the item’s retail 
//    price.
//Inputs:  float - cost and markup percentage
//Outputs:   'X' equivalent using integer input countdown
//******************************************************************************

void hProb1(){
    cout<<"Homework - MARKUP"<<endl<<endl;    
    //Declare Variables
    float cost, markup;     //Cost value and markup percentage
    
    //Input Values
    cout<<"Enter wholesale cost: $";
    cin>>cost;                              //Prompt user to input values
    while (cost < 0) {                      //Wholesale cost and Markup percentage
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter wholesale cost: $";        //Loop each prompt until input is valid
        cin>>cost;
    }
    cout<<"Enter markup percentage: ";
    cin>>markup;
    while (markup < 0) {
        cout<<"\nINVALID INPUT!\n"<<endl;
        cout<<"Enter markup percentage: ";
        cin>>markup;
    }
    
    //Process by mapping inputs to outputs    
    //Output values
    cout<<endl;
    cout<<"The whole sale cost is $"<<cost<<endl;
    cout<<"The markup percentage is "<<markup<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The cost of the item now is $"<<calRt8l(cost, markup)<<endl;         //Display value returned by calRt8l
}

//********************** Calculate Markup Amount *******************************
//Description: Calculate the markup amount based on markup percentage and add it
//          to the original cost
//Inputs:   No inputs but utilizes values from main to calculate final cost
//Outputs:  No outputs but return the value of the final cost with markup amount
//      added to original cost
//******************************************************************************

float calRt8l(float cost, float markup) {
    float answer, add;
    
    add = cost*(markup/PERCENT);        //Calculate markup amount
    answer = cost+add;                  //Add markup amount to original cost
    
    return answer;      //Return result
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
//Description: Write a program that determines which of a company’s four 
//  divisions (Northeast, Southeast, Northwest, and Southwest) had the greatest 
//  sales for a quarter.
//Inputs:  float - sales figure for every region
//Outputs:  Winning division with the highest sales figure
//******************************************************************************

void hProb2(){
    cout<<"Homework - WINNING DIVISION"<<endl<<endl;     
    //Declare Variables
    float slsNE, slsSE, slsNW, slsSW;       //Sales for Northeast, Southeast, Northwest and Southwest
    
    //Input Values
    cout<<"Northeast Division"<<endl;       //Prompt user to input sales figure for each division
    slsNE = sales();                        //Call function to do that
    cout<<"Southeast Division"<<endl;
    slsSE = sales();
    cout<<"Northwest Division"<<endl;
    slsNW = sales();
    cout<<"Southwest Division"<<endl;
    slsSW = sales();
    
    //Process by mapping inputs to outputs
    //Output values
    
    cout<<fixed<<setprecision(2)<<showpoint;        //Set format
    
    cout<<"Northeast Division: "<<setw(5)<<"$"<<slsNE<<endl;
    cout<<"Southeast Division: "<<setw(5)<<"$"<<slsSE<<endl;        //Display Sales figure of each division based on
    cout<<"Northwest Division: "<<setw(5)<<"$"<<slsNW<<endl;        //user input
    cout<<"Southwest Division: "<<setw(5)<<"$"<<slsSW<<endl;
    cout<<endl;
    
    hiesP3(slsNE, slsSE, slsNW, slsSW);         //Display result from hiesP3 function
}

//************************ Sales Figure Input **********************************
//Description: Prompt user to input values for each division
//Inputs:   float - since money-based figures need decimal points
//Outputs:  Outputs invalidity for input and loops until right value is entered
//******************************************************************************

float sales() {
    float sales;
    cout<<"Enter Sales: $";
    cin>>sales;                 //Input value by division based on main
    cout<<endl;
    
    while (sales < 0) {                 //Continue loop until input is valid
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Enter Sales: $";
        cin>>sales;
        cout<<endl;
    }
    return sales;
}

//************************ Getting Largest Sales *******************************
//Description: Determine which division has largest sales figure
//Inputs:   No inputs but uses value passed by sales function
//Outputs:  Displays result along with the value of winning division figure
//******************************************************************************

void hiesP3(float a, float b, float c, float d) {
    float largest = 0.0f;                           //Determined highest sales figure
    string ne = "Northeast Division Wins!",         
           se = "Southeast Division Wins!", 
           nw = "Northwest Division Wins!", 
           sw = "Southwest Division Wins!";
    
    largest = (a>largest)?a:largest;
    largest = (b>largest)?b:largest;        //Compare values to each one
    largest = (c>largest)?c:largest;
    largest = (d>largest)?d:largest;
   
    if (largest == a)cout<<ne;
    if (largest == b)cout<<se;
    if (largest == c)cout<<nw;          //Whichever is the highest will output equivalent string
    if (largest == d)cout<<sw;
    
    cout<<"\n$"<<largest<<endl;         //Display amount won!
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
//Description: Write a program that determines which of five geographic regions 
//      within a major city (north, south, east, west, and central) had the
//      fewest reported automobile accidents last year.
//Inputs:  Integer - number of accidents per region
//Outputs:  Safest driving area with the fewest number of accidents
//******************************************************************************

void hProb3(){
    cout<<"Homework - SAFEST DRIVING AREA"<<endl<<endl;
    //Declare Variables
    int nr, sr, wr, er, cr;         //North Region, South Region, West Region, East Region and Central Region
    
    //Input Values
    cout<<"North Region"<<endl;
    nr = axident();                 //Prompt user to input data per region
    cout<<"South Region"<<endl;     //which are passed by axident function
    sr = axident();
    cout<<"West Region"<<endl;
    wr = axident();
    cout<<"East Region"<<endl;
    er = axident();
    cout<<"Central Region"<<endl;
    cr = axident();
  
    //Process by mapping inputs to outputs
    //Output values
    cout<<"North Region: "<<setw(7)<<nr<<endl;
    cout<<"South Region: "<<setw(7)<<sr<<endl;
    cout<<"West Region: "<<setw(8)<<wr<<endl;       //Display input values
    cout<<"East Region: "<<setw(8)<<er<<endl;
    cout<<"Central Region: "<<setw(5)<<cr<<endl;
    cout<<endl;
    
    lwstP4(nr, sr, wr, er, cr);         //Display result
}

//******************** Getting Number of Accidents *****************************
//Description: Get user input for reported number of accidents
//Inputs:   int - input must not be less than 0
//Outputs:  Input validation - only if input is invalid
//******************************************************************************

int axident() {
    int axident;
    cout<<"Reported Number of Accidents: ";
    cin>>axident;                           //User input per region
    cout<<endl;
    
    while (axident < 0) {                   //Loop until data entered is greater than or equal to 0
        cout<<"Invalid Input!\n"<<endl;
        cout<<"Reported Number of Accidents: ";
        cin>>axident;
        cout<<endl;
    }    
    return axident;         //return values to each region in main
}

//************************** Safe Driving Area *********************************
//Description: Determine region lowest number of reported accidents 
//Inputs:   No inputs but uses value passed by axident function
//Outputs:  Output the safest driving area along with its reported number of
//      accidents.
//******************************************************************************

void lwstP4(int a, int b, int c, int d, int e) {
    int lowest = a;
    string nr = "North Region",             //Assigned string to regions
           sr = "South Region", 
           wr = "West Region", 
           er = "East Region",
           cr = "Central Region";
    
    lowest = (b<lowest)?b:lowest;
    lowest = (c<lowest)?c:lowest;       //Compare eache value to determine lowest
    lowest = (d<lowest)?d:lowest;
    lowest = (e<lowest)?e:lowest;
   
    cout<<"The safest driving area is ";
    if (lowest == a)cout<<nr;               //Output lowest number of accidents with its area
    if (lowest == b)cout<<sr;
    if (lowest == c)cout<<wr;
    if (lowest == d)cout<<er;
    if (lowest == e)cout<<cr;
    
    cout<<" with only "<<lowest<<" number of reported accidents!"<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
//Description: Write a function named kineticEnergy that accepts an object’s mass
//  (in kilograms) and velocity (in meters per second) as arguments. The function
//  should return the amount of kinetic energy that the object has. Demonstrate
//  the function by calling it in a program that asks the user to enter values 
//  for mass and velocity.
//Inputs:  float - for mass and velocity
//Outputs:  Kinetic Energy
//******************************************************************************

void hProb4(){
    cout<<"Homework - KINETIC ENERGY"<<endl<<endl;
    //Declare Variables
    float mass, vlocity;        
    
    //Input Values
    cout<<"Enter Object's Mass (in kg): ";      //Prompt user for input value
    cin>>mass;
    
    cout<<"Enter Object's Velocity (in meter per seconds): ";
    cin>>vlocity;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;
    cout<<"Object's Mass: "<<mass<<" kilograms"<<endl;          //Display input values
    cout<<"Object's Velocity: "<<vlocity<<" meter(s) per second"<<endl<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The object's amount of kinetic energy is "<<kinEngy(mass, vlocity)<<endl;        //Output result from kinEngy function
}

//********************** Calculate Kinetic Energy ******************************
//Description: Calculate the kinetic energy based on user input of mass and 
//          velocity.
//Inputs:   No inputs but utilizes values from main to calculate kinetic energy
//Outputs:  No outputs but return the value of the kinetic energy to main
//******************************************************************************

float kinEngy(float mass, float vlocity) {
    float kinEngy;
    
    kinEngy = mass*(vlocity*vlocity)/2;
    
    return kinEngy;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
//Description: Write a function named celsius that accepts a Fahrenheit 
//  temperature as an argument. The function should return the temperature, 
//  converted to Celsius. Demonstrate the function by calling it in a loop that 
//  displays a table of the Fahrenheit temperatures 0 through 20 and their 
//  Celsius equivalents.
//Inputs:  No inputs but uses counting by loop
//Outputs:  Farenheit to Celsius conversion table from 0 through 20
//******************************************************************************

void hProb5(){
    cout<<"Homework - TEMPERATURE TABLE"<<endl<<endl;
    //Declare Variables  
    //Input Values    
    //Process by mapping inputs to outputs
    
    cout<<fixed<<setprecision(2)<<showpoint;        //Display celsius to farenheit conversion table from 0-20
    cout<<"-----------------------"<<endl;
    cout<<"Farenheit\tCelsius"<<endl;
    cout<<"-----------------------"<<endl;
    for (short frnhyt = 0; frnhyt <= 20; frnhyt++) {        //Loop to display calculation
        cout<<frnhyt<<"\t\t"<<celsius(frnhyt)<<endl;
    }
}

//******************* Farenheit to Celsius Conversion **************************
//Description: Convert 0-20 degree farenheit to celsius
//Inputs:   No inputs but utilizes values from the loop in main to calculate
//      temperature conversion
//Outputs:  No outputs but return the value of the conversion
//******************************************************************************

float celsius(short frnhyt) {       //Calculation of farenheit to celsius
    float celsius;
            
    celsius = 5*(static_cast<float>(frnhyt)-32)/9;
    
    return celsius;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
//Description: Write a function named coinToss that simulates the tossing of a
//  coin. When you call the function, it should generate a random number in the
//  range of 1 through 2. If the random number is 1, the function should display
//  “heads.” If the random number is 2, the function should display “tails.” 
//  Demonstrate the function in a program that asks the user how many times the
//  coin should be tossed and then simulates the tossing of the coin that number
//  of times.
//Inputs:  Integer - number of toss
//Outputs:  Result if it's heads or tails
//******************************************************************************

void hProb6(){
    cout<<"Homework - COIN TOSS"<<endl<<endl;
    //Declare Variables
    int toss;
    
    //Input Values
    cout<<"Number of Toss: ";
    cin>>toss;                  //Input number of toss
    cout<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<"----------------------"<<endl;
    cout<<"TOSS\t\tRESULT"<<endl;
    cout<<"----------------------"<<endl;
    cnToss(toss);                               //Display result from function     
}

//**************************** Coin Toss ***************************************
//Description: Toss coin for a specific number of times and display result
//Inputs:   No inputs but utilizes value from main to determine number of toss
//Outputs:  Outputs result whether coin tossed is head or tails
//******************************************************************************

void cnToss(int toss) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));      
    
    string a = "Heads!", b = "Tails!", result;
    for (int count = 1; count<=toss; count++) {     //Loop count until number of toss input
        unsigned short coin = rand()%2+1; 			//value from 1-2, Generate random number every loops
        result = (coin == 2)?b:a;              	    //2 means Tails, 1 means heads
        cout<<count<<"\t\t"<<result<<endl;
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 7 ***********************************
//Description: A program that determines the present value if you have future
//      value, annual rate and number of years
//Inputs:  float, money amount, annual rate percentage & number of years
//Outputs:  Calculated Present Value
//******************************************************************************

void hProb7(){
    cout<<"Homework - PRESENT VALUE"<<endl<<endl;
    //Declare Variables
    float futVal, rate, numYear;        //Future Value, Annual Rate, Number of Years

    //Input Values
    cout<<"Enter Future Value: $";          //User input for future value, annual rate,
    cin>>futVal;                            //number of years
    cout<<"Enter Annual Interest Rate: ";
    cin>>rate;
    cout<<"Enter Number of Years: ";
    cin>>numYear;
    
    //Process by mapping inputs to outputs
    
    //Output values
    cout<<endl;                                                 //Display user input
    cout<<"Future Value Desired:\t $"<<futVal<<endl;
    cout<<"Annual Interest Rate:\t "<<rate<<"%"<<endl;
    cout<<"Number of Years:\t "<<numYear<<" years"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The amount you need to deposit is $"<<presVal(futVal, rate, numYear)<<endl;      //Display result from function    
}

//********************** Calculate Present Value *******************************
//Description: Calculate the present value based on user input of given in the
//      formula for Present Value.
//Inputs:   No inputs but utilizes values from main to calculate present value
//Outputs:  No outputs but return the value of the calculated present value.
//******************************************************************************

float presVal(float futVal, float rate, float numYear) {
    float presVal;                          
    
    rate /= PERCENT;                            //Calculate present value
    presVal = futVal/pow(1+rate, numYear);
    
    return presVal;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 8 ***********************************
//Description: A program that determines the future value if you have present
//      value, monthly rate and number of months
//Inputs:  float, money amount, monthly rate percentage & number of months
//Outputs:  Calculated Future Value
//******************************************************************************

void hProb8(){
    cout<<"Homework - FUTURE VALUE"<<endl<<endl;
    //Declare Variables
    float presVal, mRate, nMonth;       //Present Value, Monthly Rate, Number of Months

    //Input Values
    cout<<"Enter Present Value: $";             //Prompt user to enter values needed
    cin>>presVal;                               //to output answer
    cout<<"Enter Monthly Interest Rate: ";
    cin>>mRate;
    cout<<"Enter Number of Months: ";
    cin>>nMonth;
    
    //Process by mapping inputs to outputs    
    //Output values
    cout<<endl;
    cout<<"Present Value Amount:\t $"<<presVal<<endl;           //Display values entered
    cout<<"Monthly Interest Rate:\t "<<mRate<<"%"<<endl;
    cout<<"Number of Months:\t "<<nMonth<<" months"<<endl<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"The account's future value is $"<<futVal(presVal, mRate, nMonth)<<endl; //Call futVal function to return calculation
}

//*********************** Future Value Calculator ******************************
//Description: Calculate future value based on the formula given
//Inputs:  Passed to function futVal from main - float values
//Outputs:  Future value amount
//******************************************************************************

float futVal(float presVal, float mRate, float nMonth) {
    float futVal;
    
    mRate /= PERCENT;                           //Calculation of future value
    futVal = presVal*pow(1+mRate, nMonth);
    
    return futVal;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 9 ***********************************
//Description: Write a program that calculates the average of a group of test
//      scores, where the lowest score in the group is dropped.
//Inputs:  float - test scores not lower than 0 or greater than 100
//Outputs:  Average Score of 4 test scores after the lowest is dropped
//******************************************************************************

void hProb9(){
    cout<<"Homework - LOWEST SCORE DROP"<<endl<<endl;
    //Declare Variables
    float sc1, sc2, sc3, sc4, sc5;     //Scores from Test 1 - 5

    //Input Values    
    cout<<"Test 1"<<endl;
    getScor(sc1);
    cout<<"Test 2"<<endl;
    getScor(sc2);
    cout<<"Test 3"<<endl;           //Call function to pass value as reference to
    getScor(sc3);                   //main for each test scores
    cout<<"Test 4"<<endl;
    getScor(sc4);
    cout<<"Test 5"<<endl;
    getScor(sc5);
    
    //Process by mapping inputs to outputs      //This is both the process
    //Output values                             //and the output values
    calcAvg(sc1, sc2, sc3, sc4, sc5);       	//Display result
}

//************************* Getting Scores *************************************
//Description: Get scores and pass the value by reference to main
//Inputs:   float - tests scores not less than 0 and greater than 100
//Outputs:  Input validation - only if input is invalid
//******************************************************************************

void getScor(float &score) {    
    do {
        cout<<"Enter Test Score: ";     //Prompt user to enter the test score
        cin>>score;                     //Loop until input is valid
        cout<<endl;
        
        if (score<0 || score>100) cout<<"Score cannot be less than 0 or greater than 100!\n"<<endl;
        
    } while (score<0 || score>100);   
}

//*********************** Getting Lowest Score *********************************
//Description: Determine lowest score out of all input values
//Inputs:   No inputs but uses value passed by getScor function
//Outputs:  No outputs but return the value of the lowest score
//******************************************************************************

float lwstP11(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float lowest = sc1;
    
    lowest = (sc2<lowest)?sc2:lowest;
    lowest = (sc3<lowest)?sc3:lowest;       //Determines lowest score using values from
    lowest = (sc4<lowest)?sc4:lowest;       //main that was passed by reference by getScor
    lowest = (sc5<lowest)?sc5:lowest;       //function
    
    return lowest;                  //Return lowest value
}

//************************* Calculate Average **********************************
//Description: Calculate the average score of the four highest grades
//Inputs:   No inputs but utilizes values from main to calculate scores
//Outputs:  Output the test that dropped and the final average score with lowest
//      grade dropped.
//******************************************************************************

void calcAvg(float sc1, float sc2, float sc3, float sc4, float sc5) {
    float avg, lowsc;
    
    lowsc = lwstP11(sc1,sc2,sc3,sc4,sc5);   //Assign lowest value by calling lwstP11 function which determines lowest value
    avg = (sc1+sc2+sc3+sc4+sc5-lowsc)/4;    //Calculate average
    
    if (lowsc == sc1) cout<<"Test 1 Dropped!"<<endl;
    else if (lowsc == sc2) cout<<"Test 2 Dropped!"<<endl;   
    else if (lowsc == sc3) cout<<"Test 3 Dropped!"<<endl;       //Test drops conditions
    else if (lowsc == sc4) cout<<"Test 4 Dropped!"<<endl;
    else cout<<"Test 5 Dropped!"<<endl;
    
    cout<<"The average of the test scores is "<<avg<<endl;      //Display result
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 10 **********************************
//Description: Determine final score by dropping lowest and highest score and
//      averaging the remaining three scores.
//Inputs:  float - judge scores not lower than 0 or greater than 10
//Outputs:  Average Score of 3 scores after highest and lowest scores are dropped
//******************************************************************************

void hProb10(){
    cout<<"Homework - LOWEST SCORE DROP"<<endl<<endl;
    //Declare Variables
    float j1, j2, j3, j4, j5;   //Scores from Judges 1-5
 
    //Input Values
    cout<<"Judge 1"<<endl;
    jdgData(j1);
    cout<<"Judge 2"<<endl;
    jdgData(j2);
    cout<<"Judge 3"<<endl;          //Prompt user to input scores from each judge
    jdgData(j3);
    cout<<"Judge 4"<<endl;
    jdgData(j4);
    cout<<"Judge 5"<<endl;
    jdgData(j5);
    
    //Process by mapping inputs to outputs
    //Output values
    calScor(j1, j2, j3, j4, j5);        //Display result
}

//************************* Getting Scores *************************************
//Description: Get scores and pass the value by reference to main
//Inputs:   float - tests scores not less than 0 and greater than 10
//Outputs:  Input validation - only if input is invalid
//*****************************************************************************

void jdgData(float &score) {
    do {
        cout<<"Score: ";
        cin>>score;             //Get value from user input
        cout<<endl;             //Loop until input is valid
        
        if (score<0 || score>10) cout<<"Score cannot be less than 0 or greater than 10!\n"<<endl;
    } while (score<0 || score>10);    
}

//************************ Getting Highest Score *******************************
//Description: Determine highest score out of all input values
//Inputs:   No inputs but uses value passed by jdgData function
//Outputs:  No outputs but return the value of the highest score
//******************************************************************************

float hiesP12(float j1, float j2, float j3, float j4, float j5) {
    float highest = j1;
    
    highest = (j2>highest)?j2:highest;
    highest = (j3>highest)?j3:highest;
    highest = (j4>highest)?j4:highest;      //Determine highest number by comparing each one
    highest = (j5>highest)?j5:highest;
    
    return highest;    //return highest number
}

//*********************** Getting Lowest Score *********************************
//Description: Determine lowest score out of all input values
//Inputs:   No inputs but uses value passed by jdgData function
//Outputs:  No outputs but return the value of the lowest score
//******************************************************************************

float lwstP12(float j1, float j2, float j3, float j4, float j5) {
    float lowest = j1;
    
    lowest = (j2<lowest)?j2:lowest;
    lowest = (j3<lowest)?j3:lowest;         //Determine lowest number by comparing each one
    lowest = (j4<lowest)?j4:lowest;
    lowest = (j5<lowest)?j5:lowest;
    
    return lowest;      //return lowest number
}

//************************* Calculate Average **********************************
//Description: Calculate the average score of the three scores
//Inputs:  No inputs but utilizes values from main to calculate scores
//Outputs:  Output the test final average score with lowest and highest score
//     dropped.
//******************************************************************************

void calScor(float j1, float j2, float j3, float j4, float j5) {
    float hscore, lscore, avg;
    
    hscore = hiesP12(j1, j2, j3, j4, j5);           //Assign lowest and highest number to a variable to
    lscore = lwstP12(j1, j2, j3, j4, j5);           //calculate average
    
    avg = (j1+j2+j3+j4+j5-hscore-lscore)/3;         //Calculate average. Subtract highest and lowest score
    
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The average score is "<<avg<<endl;       //Display result
}