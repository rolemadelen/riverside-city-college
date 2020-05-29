/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 19, 2013.
* HW: 3
* Problem: 4
* I certify this is my own work and code
*/

// Write a program that determines whether a meeting room is in
// violation of fire law regulations regarding the maximum room
// capacity. The program will read in the maximum room capacity
// and the number of people attending the meeting. If the number
// of people is less than or equal to the maximum room capacity,
// the program announces that it is legal to hold the meeting
// and tells how many additional peolple may legally attend. If
// the number of people exceeds the maximum room capacity, the
// program announces that the meeting cannot be held as planned
// due to fire regulations and tells how many people must be
// excluded in order to meet fire rgulations.


#include <iostream>

using namespace std;

int main()
{
	const int SQFT_PER_PERSON = 30;
	
	int people, additionalPpl, excludePpl, maxCapacity, ppleCapacity;
	
	// step 1: read in the max room capacity in sqft
	cout << "Enter the Maximum Room Capacity in square feet.\n> "; 
	cin >> maxCapacity;
	
	// step 2: read in the number of people attending
	cout << "How many people are attending?.\n> ";
	cin >> people;
	
	ppleCapacity = people * SQFT_PER_PERSON;
	
	// setp 3: if number of people attending <= max room capacity
	if(ppleCapacity <= maxCapacity)
	{
		additionalPpl = (maxCapacity - ppleCapacity) / SQFT_PER_PERSON;
		
		// announce that it is legal to hold the meeting
		// and tells how many people additional people may attend.
		cout << "You may hold the meeting.\n"
			<< "and " << additionalPpl
			<< " additional people may attend.\n";
	}
	
	// step 4:if number of people > max room capacity
	else
	{
		excludePpl = (ppleCapacity - maxCapacity) / SQFT_PER_PERSON;
		
		// announce that the meeting cannot be held and 
		// announce how many people must be excluded		
		if(excludePpl == 1)
		{
			cout << "I'm sorry, but this meeting cannot be held.\n"
			<< "If you want to hold the meeting, exclude\n"
			<< "one person from the meeting.\a\n";
		}
		else
		{
		cout << "I'm sorry, but this meeting cannot be held.\a\n"
			<< "If you want to hold the meeting, exclude "
			<< excludePpl << " people\a" << endl << endl;
		}
	}
		
	return 0;
}