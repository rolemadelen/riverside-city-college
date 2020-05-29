/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 5 - Problem 9
* I certify this is my own work and code
*/      

// Modify number 7 in which data for 2 cars will be input.
// Output the number of miles per gallon delivered by each car.
// Your program will also announce which car has the best fuel
// effciency. This problem does not require the user to perform
// the calculation as many times as they wish.

#include <iostream>
#include <fstream>
using namespace std;

// this function calculates and outputs the number of miles per gallon
// return type is double
// parameter has two double type : miles and gallons
double milesPerGallon(double miles, double liters);

const double GALLONS_PER_LITERS = 0.264179;


int main()
{
    double litersOfGasln, litersOfGasln2;
    double milesTraveled, milesTraveled2;
    ifstream inStream;

    inStream.open("infile.txt");

    inStream >> litersOfGasln >> litersOfGasln2
            >> milesTraveled >> milesTraveled2;

    // call function = output the # of miles/gallon
    double MPG1 = milesPerGallon(milesTraveled, litersOfGasln);
    double MPG2 = milesPerGallon(milesTraveled2, litersOfGasln2);

    cout << "Your MPG is " << MPG1 << endl;
    cout << "MPG for the second car is " << MPG2 << endl;
    if(MPG1 > MPG2)
            cout << "The first car has better fuel efficiency..\n";
    else
            cout << "The second car has better fuel efficiency..\n";

    inStream.close();
}

double milesPerGallon(double miles, double liters)
{
        double MPG, gas;
        gas = liters * GALLONS_PER_LITERS;

        MPG = (miles / gas);
        return MPG;
}
