/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 4 - Problem 1
* I certify this is my own work and code
*/
// Write a program that accepts a year written as a four-digit
// Arabic (ordinary) numeral and outputs the year written in 
// Roman numerals. Important Roman numerals are V for 5, 
// X for 10, L for 50, C for 100, D for 500, and M for 1000. 
// Recall that some numbers are formed by using a kind of 
// subtraction of one Roman “digit”; for example, IV is 4
// produced as V minus I, XL is 40, CM is 900, and so on. 
// A few sample years: MCM is 1900, MCML is 1950, MCMLX is 1960,
// MCMXL is 1940, MCMLXXXIX is 1989. Assume the year is between
// 1000 and 3000. Your program should include a loop that lets 
// the user repeat this calculation until the user says she or 
// he is done.

#include <iostream>

using namespace std;

int main()
{
	while(true)
	{
	char respond;

	// get four-digit arabic numeral
	int year;
	
	cout << "Enter a year between 1000 - 3000.\n> ";
	cin >> year;
	
	while(year < 1000 || year > 3000)
	{
		cout << endl << "Value must be between 1000 - 3000.\n";
		cout << "Enter a year between 1000 - 3000.\n> ";
		cin >> year;
	}
	
	int i = year % 10; // gets the value of 'one'
	// V = 5 when 5 modulus of 'i' == 0 
	// output 'IV' when 'i' == 4
	
	int x = (year % 100) / 10; // gets the value of 'ten'
	// L = 50 when 5 modulus of 'x' == 0;
	// output 'XL' whn 'x' == 4
	
	int c = (year % 1000) / 100; // gets the value of 'hundred'
	// D = 500 when 5 modulus of 'c' == 0
	// output 'CD' when 'c' == 4;
	
	int m = year / 1000; // gets the value of "thousand"
	
	//output 'thousand'
	while(m > 0 && m <= 3)
	{
		cout << "M";
		m --;
	}

	//output 'hundered'
	while(c >= 1 && c <= 9)
	{
		if(c <= 4)
		{
			cout << "C";

			// output 'CD' when 'c' == 4;
			if(c == 4)
			{
			cout << "D";
			c = 0;
			}
		}
		else if(c >= 5 && c < 9)
		{
			cout << "D";

			// output 'D' when 'c' == 5
			while(c > 5 && c < 9)
			{
				cout << "C";
				c --;
			}
			c = 0;
		}
		if(c == 9)
		{
			cout << "CM";
			c = 0;
		}
		c --;
	}

	//output 'ten'
	while(x >= 1 && x <= 9)
	{
		if(x <= 4)
		{
			cout << "X";

			// output 'XL' when 'x' == 4;
			if(x == 4)
			{
			cout << "L";
			x = 0;
			}
		}
		else if(x >= 5 && x < 9)
		{
			cout << "L";

			// output 'L' when 'x' == 5
			while(x > 5 && x < 9)
			{
				cout << "X";
				x --;
			}
			x = 0;
		}
		if(x == 9)
		{
			cout << "XC";
			x = 0;
		}
		x --;
	}

	//output 'one'
	while(i >= 1 && i <= 9)
	{
		if(i <= 4)
		{
			cout << "I";

			// output 'IV' when 'i' == 4;
			if(i == 4)
			{
			cout << "V";
			i = 0;
			}
		}
		else if(i >= 5 && i < 9)
		{
			cout << "V";

			// output 'V' when 'i' == 5
			while(i > 5 && i < 9)
			{
				cout << "I";
				i --;
			}
			i = 0;
		}
		if(i == 9)
		{
			cout << "IX";
			i = 0;
		}
		i --;
	}
	
	cout << endl << "Do you want to try again? (Y \ N) : ";
	cin >> respond;
	if(respond == 'y' || respond == 'Y')
	{
		cout << "alright.\n\n";
	}
	else
	{
		cout << "That's it !\n\n";
		return 0;
	}
	
	}
}	