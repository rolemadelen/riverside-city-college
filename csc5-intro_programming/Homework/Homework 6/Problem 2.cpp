/*
* Jiwon Yoo
* Student ID : 2485776
* October 11, 2013
* Homework : 6
* Problem : 2
* I certify this is my own work and code!
*/

// Write a function that calculates the portion size
// of ice cream a group of customers will receive.
// The function should receive the number of customers,
// and the weight of the icecream. The function should
// also output the portion of each customer.

#include <iostream>
using namespace std;

// The function 'Icecream' gets the value of the
// customer and the weight of an icecream then
// calculates the number of an icecream each cust.
// will receive.
// return type is double
// parameter has integer and double
double icecream(int cust, double IcecreamWeight);

int main()
{
	int cust;
	double icecreamWeight;
	
	cout << "How many customers : ";
	cin >> cust;
	cout << "How many oz of an icecream leftover? : ";
	cin >> icecreamWeight;
	
	icecream(cust,icecreamWeight);
	
	return 0;	
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