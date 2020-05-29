/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 2 - problem 3
*/

// write a simple max() function.
// It takes in two int values, and returns another int.
// the purpose of max() is to figure out what value is
// the largest, and return it. Here is what the header
// should look like..
//
// int max(int num1, int num2)
// {
//		your code
// }

#include <iostream>
using namespace std;

int max(int num1, int num2)
{
	if(num1 > num2)
		return num1;
	else
		return num2;
}

int main()
{
	int num1, num2;
	
	cout << "Enter two numbers.\n> ";
	cin >> num1 >> num2;
	
	cout << "The larger number is : " << max(num1,num2) << endl;
	return 0;
}