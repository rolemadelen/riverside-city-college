*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 5 - Problem 5
* I certify this is my own work and code
*/      

// A liter is 0.264179 gallons. Write a program that
// will read in the number of liters of gasoline
// consumed by the user's car and the number of miles
// traveled by the car. Then, output the number of miles 
// per gallon the car delievered. Your program should
// allow the user to repeat this calculation as often
// as the user wishes. Define a function to compute the
// number of miles per gallon. Your program should use a
// globally defined constant for the number of liters per gallon.

#include <iostream>
using namespace std;

// this function calculates and outputs the number of miles per gallon
// return type is double
// parameter has two double type : miles and gallons
double milesPerGallon(double miles, double liters);

// this function determines to end the program or not.
// return type is true
// parameter have one data type: char
bool tryAgain(char respond);

// add 50 empty lines to clear a screen.
// no return value
// no parameter
void clrScr();

const double GALLONS_PER_LITERS = 0.264179;


int main()
{
    double litersOfGasln;
    double milesTraveled;
    char respond;

    while(true)
    {
        // get the number of liters of gasoline consumed
        // by the user's car
        cout << "Enter the number of liters of gasoline\n"
        << "consumed by your car(1 Liter = 0.27 Gallon).\n> ";
        cin >> litersOfGasln;

        // get the number of miles traveled by the car.
        cout << "Enter the number of miles traveled by the car.\n> ";
        cin >> milesTraveled;

        // call function = output the # of miles/gallon
        cout << "Your MPG is " 
		<< milesPerGallon(milesTraveled, litersOfGasln)
        << endl;

        cout << "Do you want to try again? (Y / N)";
        cin >> respond;
        if(tryAgain(respond))
                clrScr();
        else
        {
            cout << "That's it.\n";
            return 0;
        }
    }
}

double milesPerGallon(double miles, double liters)
{
        double MPG, gas;
        gas = liters * GALLONS_PER_LITERS;

        MPG = (miles / gas);
        return MPG;
}

bool tryAgain(char respond)
{
        return (respond == 'y' || respond == 'Y');
}

void clrScr()
{
        for(int i=0; i < 50; i ++)
        cout << endl;
}
