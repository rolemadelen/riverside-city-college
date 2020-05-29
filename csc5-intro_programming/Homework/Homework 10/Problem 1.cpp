/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW10 - Problem 1
* I certify this is my own work and code.
*/

//Write a program that takes an integer from the user
//and creates a dynamic array of that size.
//Store the array with random values and output
//the values after they have all been stored.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//output dynamic array
void output(int arr[], int size)
{
	for(int i = 0; i < size; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));

	int user_size = 0;
	int *arr;

	//get user value that creates a 
	//dynamic array of that size
	cout << "Enter a size of Dynamic array.\n";
	cin >> user_size;

	arr = new int[user_size];

	cout << "BEFORE" << endl;
	output(arr,user_size);

	//store randVal to each array element
	for(int i = 0; i < user_size; i ++)
	{
		arr[i] = rand()%100+1;
	}

	//output array
	cout << "AFTER" << endl;
	output(arr,user_size);

	cout << endl;
	delete[] arr;
	return 0;
}


