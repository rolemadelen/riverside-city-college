/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #4
* I certify this is my own work and code.
*/

//Repeat number 3, but perform error checking on the number
//provided by the user. The error checking should return
//a message if the value was not found in the vector.

#include <iostream>
#include <vector>

using namespace std;

/*
* output function outputs vector integer;
*
* parmaeter : vector;
*
* pseudo-returns.
*/
void output(vector<int>& v);

/*
* remove function removes a number from a 
* number given by the user. (Not a location).
*
* Parameter : vector and number to remove
*
* pseudo-returns.
*/
void remove(vector<int>& v, int del);

/*
* errCheck function performs error checking on
* the number provide by the user. It outputs a 
* message whether a value exist or not.
*
* parameter is user value and vector
*
* pseudo-returns
*/
void errCheck(vector<int>& v, int& userVal);

int main()
{
	using namespace std;

	vector<int> v(6);
	v[0] = 1;
	v[1] = 3;
	v[2] = 6;
	v[3] = 2;
	v[4] = 6;
	v[5] = 4;

	//number that user wants to remove
	int a_del;

	//output vector
	output(v);

	cout << "Which number do you want to remove? ";
	cin >> a_del;
	
	errCheck(v,a_del);

	//call function remove
	remove(v, a_del);

	//output results
	output(v);

	return 0;
}

void output(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << "Vector[" << i << "]: "
			<< v[i] << endl;
	}
}

void remove(vector<int>& v, int del)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == del)
		{
			for(int j = i; j < v.size()-1; j++)
			{
				v[j] = v[j+1];
			}
			v.pop_back();
			//if there is two or more same numbers,
			//call function again to delete all
			remove(v,del);
		}
	}
}

void errCheck(vector<int>& v, int& userVal)
{
	int check = -1;

	while(true)
	{
		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] == userVal)
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