/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 19, 2013.
* HW: 3
* Problem: 3
* I certify this is my own work and code
*/

// A metric ton is 35,273.92 ounces. Write a program
// that will read the weight of a package of breakfast
// cereal in ounces and output the weight in metric-ton
// as well as the number of boxes needed to yield one
// metric ton of cereal. Your program should allow the
// user to repeat this calculation as often as the 
// user wishes.

#include <iostream>

using namespace std;

int main()
{
	const double OUNCES_PER_METRICTON = 35273.92;
	
	double weightCereal, cerealInMetric;
	int boxNeeded;
	int yield = 1;
	char respond;
	
	while(true)
	{
		cout << "Enter the weight of a package"
			<< " of breakfast cereal in ounces.\n> ";
		cin >> weightCereal;
		
		cerealInMetric = weightCereal / OUNCES_PER_METRICTON;
		
		cout << "The weight of a package in Metric Ton is : "
			<< cerealInMetric << endl; 
			
		while(cerealInMetric <= 1)
		{
			double yieldOne = cerealInMetric * yield;
			yield ++;
		}
		
		cout << yield << " boxes are needed " 
					  << "to yield 1 Metric Ton of cereal.";
		
		cout << "Do you want to try again? (Y/N) : ";
		cin >> respond;
		if(respond == 'y' || respond == 'Y')
		{
			cout << "Sure!.\n";
		}
		else
		{
			cout << "Good-Bye!";
		}

	}
	
	return 0;
}