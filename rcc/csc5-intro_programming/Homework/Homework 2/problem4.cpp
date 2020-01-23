/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 12, 2013.
* HW: 2
* Problem: 4
* I certify this is my own work and code.
*/

// Write a program that plays the game of Mad Lib.
// Your program should prompt the user to enter the 
// following strings : (string character is < 10)
// A name,	antoher name,	a food
// a number between 100 and 120
// an adjective,	a color
// an animal

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// string name, another name, food, adj, color, animal
	// int number between 100 - 120;
	string name, another_name, food, adj, color, animal;
	int num;
	char ch;
	
	cout << setw(20) << "WELCOME TO THE MAD LIB" << endl << endl;
	
	// get name
	cout << "Enter a name : ";
	getline(cin, name);
	
	// get another name
	cout << "Enter another name: ";
	getline(cin, another_name);
	
	// get name of the food
	cout << "Enter name of the food (any kind) : ";
	getline(cin, food);
	
	// get an adjective
	cout << "Enter an adjective : ";
	getline(cin, adj);
	
	// get color
	cout << "Enter any color : ";
	getline(cin, color);
	
	// get animal
	cout << "Enter the name of an animal : ";
	getline(cin, animal);

	// get number between 100 - 120
	cout << "Enter the number between 100 - 120 : ";
	cin >> num;
	
	while(num < 100 || num > 120)
	{
		cout << "Invalid value was inputted in 'number'." << endl;
		cout << "Enter the number between 100 - 120: ";
		cin >> num;
	}
	
	cout << endl << endl;

	// output
	cout << "Dear [" << another_name << "]." << endl << endl;
	cout << "I am sorry that I am unable to turn in my homework at this time.\n"
		 << "First, I ate rotten " << food << " which made me turn " << color << endl
		 << " and extremly ill." << " I came down with a fever of " << num << ".\n"
		 << "Next, my " << adj << " pet " << animal << " must have smelled\n"
		 << "the remains of the " << food << " on my homework because he ate it.\n"
		 << "I am currently rewriting my homework and hope you will accept it late.\n\n";
		 
	cout << "Sincerely,\n" << name << endl;
	
	return 0;
}