/*
* Jiwon Yoo
* Professor Ung
* Student ID : 2485776
* HW 6 : problem 7
* I certify that I did this work and this is my code
*/

// Write a program that reads in the length in feet
// and inches and outputs the equivalent length in
// meters and centimeters. Use at least three functions:
// one for input, one or more for calculating, and one for output.
// Include a loop that lets the user repeat this computation
// for new input values until the user says he or she wants
// to end the program.
// There are 0.3048 meters in a foot, 100 centimeters in a meter,
// and 12 inches in a foot.

#include <iostream>

using namespace std;

const double M_FT = 0.3048;
const double CM_M = 100.0;
const double IN_FOOT = 12.0;

// get user input feet and inch
// return type is void and parameter
// has two reference variable : num of feet and inches
void getFtIn(double &feet, double &inch);

// purpose of this function is to convert 
// user input value feet and inches to meters
// and centimeters.
// return type is void and paramter is reference
// : feet and inch
void convert(double &feet, double &inch);

// purpose of this function is to output
// the computed value of feet and inch.
// retrun type is void and paramter has
// two variable feet and inch
void output(double &meter, double &cm);

int main()
{
	double feet, in;
	
	//get length in ft and in;
	getFtIn(feet,in);
	
	//convert to meters and centimeters;
	//output equivalent length in meters and cm;
	convert(feet,in);
	
	return 0;
}

void getFtIn(double &feet, double &inch)
{
	cout << "Enter the length in feet : ";
	cin >> feet;
	cout << "Enter the length if inches : ";
	cin >> inch;
	return ;
}

void convert(double &feet, double&inch)
{
	double meter, cm;
	meter = feet * M_FT;
	cm = meter * CM_M;
	//helper function ;output();
	cout << feet << " foot is same as \n";
	output(meter,cm);
	
	meter = (inch / 12) * M_FT;
	cm = meter * CM_M;
	cout << inch << " inches are same as \n";
	output(meter,cm);
	return ;
}
void output(double &meter, double &cm)
{
	cout << meter << " meters and " 
		 << cm << " centimeters.\n";
		 
 return ;
}