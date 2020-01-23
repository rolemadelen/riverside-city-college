/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 10 - problem 4
*/

//Write a program that determines if a
//certain value, given by the user,
//is inside of the array. The program
//should call a function that does this checking,
//and it should determine whether or not
//the value is inside the array.

#include <iostream>
#include <ctime> //srand(time)
#include <cstdlib> //to use rand funtion

using namespace std;

/*
* checkArr function determines whether a certain
* value exist or not in array
*
* parameter is integer array, size, and user value;
*
* return boolean expression (TRUE OR FALSE)
*/
bool checkArr(int arr[], int size, int userVal);

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

int main()
{
	//declare const arr SIZE
	const int SIZE = 100;

	//declare integer array 
	int arr[SIZE];

	//fill in array with random numbers
	gen50(arr, SIZE);

	//declare integer var. for user input
	int userVal;
	
	//prompt user to enter a value
	cout << "Enter a value between 1 - 100" << endl << ": ";
	cin >> userVal;

	//call function checkArr to determine
	//whether a userVal is inside of an array.
	//if(checkArr) returns true
	if(checkArr(arr,SIZE,userVal) == true)
	{
		//output value exist in array.
		cout << "EXIST." << endl;
	}
	//otherwise
	else if(checkArr(arr,SIZE,userVal) == false)
	{
		//output value DNE in array
		cout << "Does Not Exist." << endl;
	}
}

bool checkArr(int arr[], int size, int userVal)
{
	//for loop start
	for(int i = 0; i < size; i++)
	{
		//if arr[i] = userVal
		if(arr[i] == userVal)
		{
			//return true;
			return true;
		}

	//for loop end
	}
	
	//if value is not in array return false
	return false;
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
		storeNum = randNum(1,100);

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