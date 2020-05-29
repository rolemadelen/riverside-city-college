/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 5 - Problem 7
* I certify this is my own work and code
*/

// Modify your program from number 5 so that
// it will take input data, from a file called
// "data.dat"

#include <iostream>
#include <fstream>
using namespace std;

// this function calculates and outputs
// the number of miles per gallon
// return type is double
// parameter has two double type : miles and gallons
double milesPerGallon(double miles, double liters);

const double GALLONS_PER_LITERS = 0.264179;

int main()
{
    double litersOfGasln = 70;
    double milesTraveled = 300;
    char respond;
 
	ifstream inStream;
    ofstream outStream;

    inStream.open("data.dat"); //take input from a file
    outStream.open("outfile.txt");

    // get the number of liters of gasoline consumed
    // by the user's car
    // get the number of miles traveled by the car.

   inStream >> litersOfGasln >> milesTraveled;
   
    // call function = output the # of miles/gallon
    outStream << "Your MPG is " 
	<< milesPerGallon(milesTraveled, litersOfGasln)	<< endl;

     inStream.close();
     outStream.close();
      return 0;
}

double milesPerGallon(double miles, double liters)
{

double MPG, gas;
gas = liters * GALLONS_PER_LITERS;
MPG = (miles / gas);
return MPG;
}
