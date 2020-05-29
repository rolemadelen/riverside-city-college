/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW10 - Problem 2
* I certify this is my own work and code.
*/

//Create three functions that do the tasks outlined in problem 1.
//Create a function that creates the array,
//one that stores random values into the array,
//and one that outputs all the array values.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function that stores randVal to array
void storeRand(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100+1;
	}
}

//fucntion that outputs an array
void output(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//create a function that creates an array
void createArr(int *arr,int size)
{
	arr = new int[size];
	cout << "BEFORE" << endl;
	output(arr,size);
	storeRand(arr,size);
	cout << "AFTER" << endl;
	output(arr,size);

	delete[] arr;
}

int main()
{
	int arr;
	int size;

	cout << "Enter a size of an array.\n";
	cin >> size;

	createArr(&arr,size);
	return 0;
}