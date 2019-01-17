/*
* Jiwon Yoo
* Student ID :  2485776
* Sept 20, 2013.
* HW 3 Problem 2
* I certify this is my own work and code
*/

// The user wants to bring the same number of apples, oranges, and pears
// on his/her tip. However, the fruits came in bulk when he bought them at 
// supermarket. Write a program that prompts the user for the number of 
// apples, oranges, and pears he/she has and the outputs the number of
// apples, oranges, and pears he/she should leave over.

#include <iostream>
using namespace std;

int main()
{
	int apple, orange, pear;
	int least;

	// get number of apples;
	cout << "Enter the number of apples : ";
	cin >> apple;

	// get number of oranges;
	cout << "Enter the number of oranges : ";
	cin >> orange;

	// get number of pears;
	cout << "Enter the number of pears : ";
	cin >> pear;

	// find which fruit is least
	while(true)
	{// a = 2, o = 4, p = 3;
		if(apple < orange && apple < pear) 
			least = apple;
		else if(orange < apple && orange < pear)
			least = orange;
		else
			least = pear;
		break;
	}
	// output number of apples you should leave;
	cout << "The number of apples you should leave : "
		 << apple - least << endl;

	// output number of oranges you should leave;
	cout << "The number of oranges you should leave : "
		 << orange - least << endl;

	// output number of pears you should leave;
	cout << "The number of peras you should leave : "
	 	 << pear - least << endl;

	return 0;
}
