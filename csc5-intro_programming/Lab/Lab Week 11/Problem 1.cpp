/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 11 - problem 1
*/

//Write a function to fill both a vector and array
//with 10 random numbers. Print the values of both
//the vector and array to the screen.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
* fillNum function fills in number to array and vector.
*
* parameter : vector, array, and size for array
*
* pseudo-returns
*/
void fillNum(vector<int>& v, int arr[], int size);

/*
* output function outputs the vector and array to the screen
*
* parameter : const int vector, array, and integer size
*
* pseudo-returns.
*/
void output(const vector<int>& v,const int arr[], int size);

int main()
{
	const int SIZE = 10;

	vector<int> v(SIZE);
	int arr[SIZE];

	cout << "BEFORE" << endl;
	output(v,arr,SIZE);

	//fill in numbers in array and vector
	fillNum(v, arr, SIZE);

	cout << "AFTER" << endl;
	//output vector and array
	output(v,arr,SIZE);

	return 0;
}

void fillNum(vector<int>& v, int arr[], int size)
{
	//seed new rand number
	srand(unsigned int(time(NULL)));

	for(int i = 0; i < size; i ++)
	{
		arr[i] = (rand() % 100) + 1;
		v[i] = (rand()%100)+1;
	}
}

void output(const vector<int>& v,const int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "vector[" << i << "]: " << v[i] << "\t" 
			<< "arr[" << i << "]: " << arr[i] << endl;
	}
}