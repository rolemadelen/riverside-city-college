/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 8
*/

// Using number 6, add a static variable that counts
// how many times the swap function has been used.
// Output the total times the variable has been
// used each time it is called.

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

//this function keep track of how many times
//swap function has been used using static variable.
//parameter : none.
//return type : pseudo-returns.
void countSwap()
{
	static int cnt = 1;
	cout << "Swap function used : "
		 << cnt << endl << endl;
	cnt ++;
}

int main()
{
	int x ,y;
	while(true)
	{
	cout << "Enter two numbers (999 to quit): ";
	cin >> x >> y;
	//if x or y is 999, quit program.
	if(x == 999 || y == 999)
	{
		return 0;
	}
	cout << "BEFORE num : " << x << " " << y << endl;
	swap(x,y);
	cout << "AFTER num : " << x << " " << y << endl;
	countSwap();
	}
}


