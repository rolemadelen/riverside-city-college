/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 11 - problem 3
*/

//Write a function to find the minimum value
//in an array. The minimum value should be print to the screen.

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

//output all values in array
//parameter : array and index
//pseudo-returns
void output(int arr[], int index);

/*
* findMin function finds the minimum value
* among values in array.
*
* parameter : array and size.
*
* return type is void
*/
void findMin(const int arr[], int index);

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

	cout << endl << "MINIMUM VALUE." << endl;
	//after done entering numbers. find Min
	findMin(arr,index);	
	
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

void findMin(const int arr[], int index)
{
	//set initial value for min
	int min = 1000000;
	int loc = 0;

	if(index == 0)
	{
		cout << "Array is empty.\n";
		return;
	}

	for(int i = 0; i < index; i++)
	{
		if(arr[i] != -1 && arr[i] < min)
		{
			min = arr[i];
			loc = i;
		}
	}
	cout << "Arr[" << loc << "]: "
		<< min << endl;
}
