/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 6
*/

// Implement the swap function. The swap
// function does not return any value, and
// uses two doubles as input.

#include <iostream>

using namespace std;

//this function swaps two variable using
//referenced parameter.
//paramter : two double type variable
//pseudo-returns.
void swap(double &x, double &y)
{
	double temp;
	
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	cout << "Enter two numbers : ";
	int x ,y;
	cin >> x >> y;
	
	cout << "BEFORE num : " << x << " " << y << endl;
	swap(x,y);
	cout << "AFTER num : " << x << " " << y << endl;
	
	return 0;
}


