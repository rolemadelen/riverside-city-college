/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 8
*/

// Using recursion, implement number 5.
// (#5 factorial problem)

#include <iostream>
using namespace std;

// this function computes the factorial of a number
// and outputs the decimal value to hundreth.
// return type is long long integer to express
// a number larger than 12!.
// reads in one integer number
long long int factRecur(int num);

int main()
{
    int num = 0, t;
	//long long allows number up to 20!
	long long int factorial;

    cout << "FACTORIAL CALCULATOR\n";
	cout << "This program will run how many times? : ";
	cin >> t;

	int n = t;

	//program run 't' amount times.
	for(int i=0; i<t; i++)
	{
		cout << ": ";
		cin >> num;

		while(num > 20)
		{
			cout << "Only up to 20!!\n: ";
			cin >> num;
		}

		factorial = factRecur(num);
		cout << factorial << endl;

		n--;
	}
   
}
long long int factRecur(int num)
{
	if(num==0)
		return 1;
	else
		return num*factRecur(num-1);
}

