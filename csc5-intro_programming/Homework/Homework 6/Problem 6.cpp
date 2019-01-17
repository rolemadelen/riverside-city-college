/*
* Jiwon Yoo
* Student ID : 2485776
* October 11, 2013
* Homework : 6
* Problem : 6
* I certify this is my own work and code!
*/

// Write a program that reads in a weight in pounds
// and ounces and outputs the equivalent weight in
// kilograms and grams. Use at least three funtions:
// one for input, one or more for calculating, and one
// for input. Include a loop that lets the user repeat
// this computation for new input value until the user
// says he or she wants to end the program. Thre are
// 2.2046 lbs in kg, 1000gs in kg, and 15oz in a lb.

#include <iostream>
#include <iomanip>

using namespace std;

const double LB_PER_KG = 2.2046; //lbs in kg
const double G_PER_KG = 1000; //grams in kg
const double OZ_PER_LB = 15; // ounces in a lb

// purpose of this function is to get input
// for the weight in pounds
// return type is void and paramter is 
// weight in pound
void getPound(double &lb);

// purpose of this function is to get input
// for the weight in ounces
// return type is void and parameter is
// reference variable, number of ounces
void getOunce(double &oz);

// purpose of this function is to convert
// pounds and ounces in kilograms and grams.
// return type is void and parameter is
// reference variable, weight in pounds and ounces
void convert(double &lb, double &oz);

int main()
{
	double lb, oz;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// get weight in pounds and ounces
	// using functions. Use reference variable
	getPound(lb);
	getOunce(oz);
	
	// call convert function that convert
	// pounds and ounces in Kgram and grams.
	convert(lb, oz);
}

void getPound(double &lb)
{
	double pound;
	cout << "How much do you weight in pounds?\n";
	cin >> pound;
	lb = pound;
	
	return ;
}

void getOunce(double &oz)
{
	double ounce;
	cout << "How much do you weight in ounces?\n"
		 << "1 lb = 15 oz.\n> ";
	cin >> ounce;
	oz = ounce;
	
	return ;
}

void convert(double &lb, double &oz)
{
	double kg, g, kg2, g2;
	kg = lb / LB_PER_KG;
	g = kg * G_PER_KG;
	
	kg2 = (oz / OZ_PER_LB) / LB_PER_KG;
	g2 = kg2 * G_PER_KG;
	cout << lb << " pounds are equivalent to \n"
	     << kg << " kilograms and " << g << " grams.\n\n";
	cout << oz << " ounces are equivalent to \n"
		 << kg2 << " kilograms and " << g2 << " grams.\n\n";
	
	return ;
}