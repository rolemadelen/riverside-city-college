/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 10 - problem 3
*/

//Write a function that randomly stores values,
//between 50-100, into an array of size 50.

//generate 50 numbers that is 50-100. into an array.

#include <iostream>
#include <ctime>//to seed new randValue;
#include <cstdlib>// to use rand function;
#include <iomanip>

using namespace std;

/*
* gen50 function generates random 1000 values
* and stores to array and output array;
*
* parameter : array that user wants to store a value
				and the size of an array
				> Array, pseudo-reference;
*
* pseudo-returns;
*/
void gen50(int arr[], int size);

/*
* randNum(min,max) function generates random numbers between
* min and max.
*
* parameter : minimum # and maximum #: min and max
*
* returns generated integer value.
*/
int randNum(int min, int max);

/*
* output function outputs values in array;
*
*parameter : array that user created
			and the size
*
* pseudo-returns;
*/
void output(const int arr[], int size);

int main()
{
	//declare constant size for an array = 50;
	const int SIZE = 50;

	//declare array
	int arr[SIZE];

	//call function to generate 50 numbers
	//and output all those numbers;
	gen50(arr,SIZE);

	//call function 'output()' to output array
	output(arr,SIZE);

}

void gen50(int arr[], int size)
{
	//seed new number
	srand(time(NULL));

	//for loop start
	for(int i = 0; i < size; i++)
	{
		//declare integer variable 'storeNum' to store randNum;
		int storeNum;

		//call randNum(min,max) function
		//storeNum = randNum(50,100);
		storeNum = randNum(50,100);

		//change values in array to 'storeNum'
		arr[i] = storeNum;
	}
	//for loop end
}

int randNum(int min, int max)
{
	//return numbers between 50 and 100
	return rand() % (max - min + 1) + min;
}

void output(const int arr[],int size)
{
	int cnt = 0;
	//for loop start
	for(int i = 0; i < size; i++)
	{
		cnt ++;
		//output arr[0] to arr[49]
		cout << left << setw(2) << "arr[" << i
			<< "]:  " << setw(3) << arr[i] << " ";
		if(cnt % 5 == 0)
			cout << endl << endl;
	}
	//for loop end
	cout << endl;
}