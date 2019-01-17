/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #9
* I certify this is my own work and code.
*/

/*
* Write a function called delete_repeats that has a
* partially filled array of characters as a formal
* parameter and that deletes all repeated letters
* from the array. 
* Since a partially filled array required two arguments,
* the function will actually have 2 formal parameters:
* an array parameter and a parameter of type int that
* gives the number of array positions used.
* When the letter is deleted, the remaining letters are
* moved forward to fill in the gap.
* This will create empty positions at the end of the
* array so that less of the array is used.
*
* For example, consider the following code:
*
* Char a[10];
* a[0] = ‘a’;
* a[1] = ‘b’;
* a[2] = ‘a’;
* a[3] = ‘c’;
* int size = 4;
* delete_repeats(a, size);
*
* After this code is executed, the value of a[0] is ‘a’,
* the value of a[1] is ‘b’, the value of a[2] is ‘c’,
* and the value of size is 3.
* You may assume this partially filled array only
* contains lower case characters.
*/

#include <iostream>

using namespace std;

/*
* delete_repeats function deletes all
* repeated letters from an array.
*
* parameter : partially filled array and 
*			integer num_used;
*
* return type is void
*/
void delete_repeats(char arr[], int& num_used);

/*
* move function moves the repeated letter to very end.
*
* parameter : partially filled array, int location that
*			repeated value starts, and num_used
*
* returny type is void
*/
void move(char arr[], int repeat, int& num_used);

//outputs all the value in array
//parameter : partialFilled array and num_used
//pseudo-returns
void output(const char arr[], int& num_used);

int main()
{
	//create partially filled array
	char partialArr[10];
	
	//hardcode first 5 array
	partialArr[0] = 'a';
	partialArr[1] = 'b';
	partialArr[2] = 'a';
	partialArr[3] = 'c';
	partialArr[4] = 'a';
	
	int num_used = 5;

	cout << "BEFORE FUNCTION CALL.\n";
	output(partialArr,num_used);

	delete_repeats(partialArr, num_used);

	cout << "AFTER FUNCTION CALL.\n";
	output(partialArr,num_used);
}

void delete_repeats(char arr[], int& num_used)
{
	int repeat; //location of repeated value

	// i start from beginning, j start from back
	for(int i = 0; i < num_used; i++)
	{
		for(int j = num_used-1; j > i; j--)
		{
			//if repeated value is found
			//call function 'move'
			if(arr[j] == arr[i])
			{
				repeat = j;

				//function move repeated value to very end
				//and reduce num_used by 1
				move(arr,repeat, num_used);
			}
		}
	}
}

void move(char arr[], int repeat, int& num_used)
{
	//start from repeated location
	for(int i = repeat; i < num_used-1; i++)
	{
		//move back to very end
		arr[i] = arr[i+1];
	}
	num_used --;
}

void output(const char arr[], int& num_used)
{
	for(int i = 0; i < num_used; i ++)
	{
		cout << "Arr[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;
}