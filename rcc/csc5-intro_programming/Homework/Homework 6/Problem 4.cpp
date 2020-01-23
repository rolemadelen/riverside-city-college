/*
* Jiwon Yoo
* Student ID : 2485776
* October 11, 2013
* Homework : 6
* Problem : 4
* I certify this is my own work and code!
*/

#include <iostream>
#include <iomanip>

using namespace std;

// The function 'Max' is an overloading function.
// It compares two to three number
// and returns the largest value.
// Return type is double and takes in
// has two to three double type parameters.
double max(double num1, double num2);
double max(double num1, double num2, double double3);

// The function 'Icecream' gets the value of the
// customer and the weight of an icecream then
// calculates the number of an icecream each cust.
// will receive.
// return type is double
// parameter has integer and double
double icecream(int cust, double IcecreamWeight);

// Purpose of this function is to run the selected
// program that is selected by a user.
// return type is void
// parameter is an integer
void runProgram(int choice);

int main()
{
	int choice;
	
	cout << "1. Max funtion.\n"
		 << "2. Icecream funtion.\n"
		 << "3. Exit.\n> ";
		 
	cin >> choice;
	
	runProgram(choice);
	
	return 0;
}

double max(double num1, double num2)
{
	if(num1 > num2)
		return num1;
	else
		return num2;
}

double max(double num1, double num2, double num3)
{
	if(num1 >= num2 && num1 >= num3)
		return num1;
	else if(num2 >= num1 && num2 >= num3)
		return num2;
	else
		return num3;
}

double icecream(int cust, double icecreamWeight)
{
	if(cust <= 0)
	{
		cout << "You have 0 customer..\n";
		return 0;
	}
	return icecreamWeight / cust;
}

void runProgram(int choice)
{
	switch(choice)
	{
		case 1:
		{
			double a = 5, b = 6, c = 15;
			cout << "MAX PROGRAM.\n\n";
			cout << "first number : ";
			cin >> a;
			cout << "second number : ";
			cin >> b;
			cout << "third number : ";
			cin >> c;

			cout << "between " << a << " and " << b 
				 << ".\n" << max(a,b) << " is larger.\n";

			cout << "between " << a << ", " << b 
				 << ", and " << c << ".\n"
				 <<  max(a,b,c) << " is larger.\n";
			return;
		}
		case 2:
		{
			int cust;
			double weight;
			
			cout << "ICECREAM PROGRAM.\n"
				 << "How many customers? : ";
			cin >> cust;
			cout << "How many oz of ice creams do you have ? : ";
			cin >> weight;
			
			icecream(cust,weight);
			
			return;
		}
	}
}