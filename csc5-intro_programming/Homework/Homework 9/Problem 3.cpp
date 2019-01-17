/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW9 - Problem 3
* I certify this is my own work and code.
*/

//Create an integer variable with the value 42
//and another integer variable assigned to the
//first one. Assign two different points to the
//address of the integer variable.
//Change the value three different ways.
//First change it to 12, using the variable.
//Then, change it to 25, using one of the
//pointers and then change it to 60 using the
//other pointer. Output the two integer variable
//every single time the value has been changed.

#include <iostream>

using namespace std;

void output(int *p, int v)
{
	cout << "v: " << *p << endl
		<< "v1: " << v << endl
		<< endl;
}
int main()
{
	int v = 42;
	int v1 = 42;
	
	int *p = &v;
	int *p1 = &v;
	output(p,v1);

	v = 12;
	output(p,v1);

	*p = 25;
	output(p,v1);

	*p1 = 60;
	output(p,v1);
}
