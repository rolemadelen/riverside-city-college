/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 10 - problem 5
*/

//Modify program 4 to determine the
//duplicated numbers within the vector.

#include <iostream>
#include <vector> //to use vector
#include <ctime> //to seed new randVal
#include <cstdlib> //to use rand function

using namespace std;

/*
* putDataArr function stores random values
* until 'i < given SIZE'
*
* parameter : array and size;
*
* pseudo-returns
*/
void putDataArr(int arr[], int size);

/*
* moveToVec function transfer over elements in
* array to vector.
*
* parameter : integer vector, array, and size;
*
* pseudo-returns;
*/
void moveToVec(vector<int>& v, int arr[], int size);

/*
* checkDup function determines duplicate numbers
* in vector and output the numbers;
*
* parameter : constant integer vector because don't 
			want to change any values accidently;
*
* pseudo-returns;
*/
void checkDup(const vector<int>& v);

/*
* randNum functoin generates random number
* between min and max.
*
* parameter : minimum and maximum value
*
* returns integer value;
*/
int randNum(int min, int max);

int main()
{
	//declare const SIZE for array
	const int SIZE = 30;

	//declare array to store random value
	int arr[SIZE];

	//declare vector to store array elements
	vector<int> storeArr;

	//call function to store data in array
	putDataArr(arr,SIZE);

	//call function to move array elements in vector
	//and determine duplicates
	moveToVec(storeArr, arr, SIZE);

	return 0;
}

void putDataArr(int arr[], int size)
{
	//seed new random values
	srand(time(NULL));

	//for loop start
	for(int i = 0; i < size; i++)
	{
		//store random numbers
		arr[i] = randNum(50,100);
	//for loop end
	}
}

void moveToVec(vector<int>& v, int arr[], int size)
{
	//for loop start
	for(int i = 0; i < size; i++)
	{
		//move array to vector
		v.push_back(arr[i]);

	//for loop end
	}

	//determine duplicates in vector
	checkDup(v);
}

void checkDup(const vector<int>& v)
{
	vector<int> duplicate;

	//for loop start
	for(int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";
		//nested for loop start(to compare if
		//two value is same)
		for(int j = i+1; j < v.size(); j++)
		{
			//if duplicate number is found, store that
			//number index to vector 'duplicate'
			if(v[i] == v[j])
			{
				duplicate.push_back(v[i]);
			}
		//nested for loop end
		}
	//for loop end
	}

	cout << "\nDUPLICATE VECTOR SIZE : " << duplicate.size() << endl;
	for(int x = 0; x < duplicate.size(); x++)
	{
		cout << duplicate[x] << " ";
	}
}

int randNum(int min, int max)
{
	//return numbers between 50 and 100
	return rand() % (max - min + 1) + min;
}