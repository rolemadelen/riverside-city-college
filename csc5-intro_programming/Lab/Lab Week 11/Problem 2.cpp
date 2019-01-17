/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 11 - problem 2
*/

//Write a function to fill an array of size 5
//with values given by the user. The user can
//stop entering values prematurely by entering -1.
//Print the values back to the user after they
//have finished writing values.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
* fillArr function add value to array until
* array is full which is 5 or when user enters -1
*
* parameter : array, size, and index;
*
* pseudo-returns
*/
void fillArr(int arr[], int size, int& index);

void output(int arr[], int index);

int main()
{
	const int SIZE = 5;
	int arr[SIZE];
	int userVal = 0;
	int index = 0;

	cout << "BEFORE FUNCTION CALL." << endl;
	output(arr,index);

	//call function to store a userVal;
	fillArr(arr,SIZE,index);

	cout << "AFTER FUNCTION CALL." << endl;
	output(arr,index);

	return 0;
}

void fillArr(int arr[], int size, int& index)
{
	int userVal = 0;
	index = 0;

	//prompt user to enter a value
	cout << "Enter five or less value." << endl
		<< "Place -1 after done entering." << endl;

	//loop start
	do
	{
		//get value
		cin >> userVal;

		//if value = -1
		if(userVal == -1 || index > size)
		{
			//return;
			return;
		}
		//otherwise
		else
			//add value to array
			arr[index] = userVal;

		index ++;
	//loop end
	}while(userVal != -1 && index < size);
}

void output(int arr[], int index)
{
	if(index == 0)
		cout << "Array is empty." << endl << endl;

	for(int i = 0; i < index; i ++)
	{
		cout << "ARRAY [" << i << "]: " << arr[i] << endl;
	}
}
