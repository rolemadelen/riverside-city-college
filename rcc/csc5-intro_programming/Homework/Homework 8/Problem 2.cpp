/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #2
* I certify this is my own work and code.
*/

// Repeat problem 1, but with an array.
// Remember that arrays need to have
// the size as a parameter.

#include <iostream>
#include <string>

using namespace std;

/*
* Purpose of this function is to delete a number from
* an array from a given location. 
* 
* Parameter : array and a location
* 
* Pseudo-returns.
*/
void deleteLoc(int num[], int loc, int size);

/*
* Purpose of this function is to output 
* array integers.
*
* Parmater is array and size
*
* Pseudo-returns.
*/
void output(int num[], int size);

int main()
{
	const int SIZE = 4;
	int arr[SIZE] = {3,5,0,10};
	int loc;	

	//output initial vector
	cout << "BEFORE FUNCTION CALL." << endl;
	output(arr,SIZE);
	
	//get location of a number to delete
	cout << "Enter a location (0 ~ 3) of a"
		<< " number to delete." << endl;
	cin >> loc;

	//error check: prevent bound error
	while(loc < 0 || loc > 3)
	{
		cout << "Enter a location (0~3)." << endl;
		cin >> loc;
	}

	//call function deleteLoc
	deleteLoc(arr, loc, SIZE);

	//output vector after func() call.
	cout << "AFTER FUNCTION CALL." << endl;
	output(arr, SIZE);
}
void output(int num[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]: "
			<<  num[i] << endl;
	}
}

void deleteLoc(int num[], int loc, int size)
{
	for(int i = loc; i < size-1; i++)
	{
			num[i] = num[i + 1];
	}
	num[size-1] = -1;
}