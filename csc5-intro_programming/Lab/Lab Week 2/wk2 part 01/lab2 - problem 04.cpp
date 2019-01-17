//Jiwon Yoo
//2013, September 3. Week 2
// Lab Worksheet problem 04
///////////////////////////////////////////////////////////////////
//Write a program that prompts the user for a measurement in meters
//and then converts it to miles, feet, and inches. Make the output 
//up to two decimal places.
//
//1 mile = 1609.344 meters
//1 meter = 3.281 feet
//1 feet = 12 inches
///////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
    //declare and initialize variables
    double meters = 0.0;
    double miles = 1609.344, feet = 3.281, inches = 12.0;
    
    // prompt the user for a measurement in meters
    cout << "Enter a measurement in meters." << endl;
    
    // get measurements
    cin >> meters;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // convert meters to miles, feet, and inches;
    miles = meters / miles;
    feet = meters * feet;
    inches = (inches * feet);
    
    // output conversions up two two decimal places.
    cout << meters << " meter is equivalent to " << endl
         << miles << " miles," << endl
         << feet << " foots, and" << endl
         << inches << " inches." << endl;
    
    return 0;
    
}
