//Jiwon Yoo
//Homework 5
// Write a program that reads in two integers and then outputs
// both their sum and their product.

#include <iostream>
using namespace std;

int main()
{
	int value_one, value_two;
	int product, sum;

	cout << "Press return after entering a number.\n";
	cout << "Enter the number : ";
	cin >> value_one;
	cout << "Enter another number : ";
	cin >> value_two;

	product = value_one * value_two;
	sum = value_one + value_two;

	cout << "Sum of two numbers : " << sum << endl;
	cout << "Product of two number : " << product << endl;

	cout << "this is the end of the program\n";
	return 0;

}