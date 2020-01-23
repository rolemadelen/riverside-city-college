/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #5
* I certify this is my own work and code.
*/

//Repeat number 3, but with an array.
//Remember the array needs a variable
//to hold its size as the array changes value.

#include <iostream>

using namespace std;

/*
* output function outputs vector integer;
*
* parmaeter : integer array and size;
*
* pseudo-returns.
*/
void output(int arr[], int size);

/*
* remove function removes a number from a 
* number given by the user. (Not a location).
*
* Parameter : array, size, and number to remove
*
* pseudo-returns.
*/
void remove(int arr[], int size, int del);

/*
* errCheck function performs error checking on
* the number provide by the user. It outputs a 
* message whether a value exist or not.
*
* parameter is user value, array size and vector
*
* pseudo-returns
*/
void errCheck(int arr[], int size, int& userVal);

/*
* storeArr function stores non negative numbers to
* new array.
*
* parameter is old array and size
*
* returns void.
*/
void outputNew(int arr[], int size);

int main()
{	
	const int SIZE = 5;
	int arr[SIZE] = {1,2,6,6,3};

	//number that user wants to remove
	int a_del;

	//output vector
	output(arr,SIZE);

	cout << "Which number do you want to remove? ";
	cin >> a_del;
	
	errCheck(arr,SIZE,a_del);

	//call function remove
	remove(arr,SIZE, a_del);

	//output results
	outputNew(arr,SIZE);

	return 0;
}

void output(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "Arr[" << i << "]: "
			<< arr[i] << endl;
	}
}

void remove(int arr[], int size, int del)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == del)
		{
			for(int j = i; j < size-1; j++)
			{
				arr[j] = arr[j+1];
			}
			arr[size-1] = -1;
			//if there is two or more same numbers,
			//call function again to delete all
			remove(arr,size,del);
		}
	}
}

void errCheck(int arr[], int size, int& userVal)
{
	int check = -1;

	while(true)
	{
		for(int i = 0; i < size; i++)
		{
			if(arr[i] == userVal)
			{
				check ++;
			}
		}
		if(check == -1)
		{
			cout << endl << "Sorry, I couldn't find number "
				<< userVal << endl;
			cout << "Enter another number: ";
			cin >> userVal;
		}
		else
		{
			cout << endl;
			return;
		}
	}
}

void outputNew(int arr[], int size)
{
	int num[10];
	
	for(int i = 0; i < size; i++)
	{
		if(arr[i] != -1)
		{
			num[i] = arr[i];
			cout << "Arr[" << i << "]: "
			<< arr[i] << endl;
		}
	}
}
