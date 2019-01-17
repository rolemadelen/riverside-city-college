/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #7
* I certify this is my own work and code.
*/

//Using the function from number 6, create a program
//that allows the user to continually enter data into a vector.
//If the number is already inside the vector,
//inform the user that the value cannot be inserted
//because it is already being used.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//determine if number is
//already contained inside the vector.
//parameter: vector and user value
//return type is bool
bool isContain(vector<int>& v, int val)
{
	int check = -1;

	for(int i = 0; i < v.size(); i++)
	{
		//if number exist, check != -1
		if(v[i] == val)
		{
			check ++;
		}
	}

	if(check != -1)
		return true;
	else
		return false;
}

void getNum(vector<int>& v)
{
	int num;
	cout << "Enter a number to add in vector. 0 to quit." << endl;
	cin >> num;

	if(num == 0)
		exit(1);
	if(isContain(v,num) == true)
	{
		cout << "CANNOT BE ADD, NUMBER ALREADY EXIST." << endl;
	}
	else
	{
		cout << "Number added." << endl;
		v.push_back(num);
	}
}

void output(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << "Vector[" << i << "]: "
			<< v[i] << endl;
	}
}
int main()
{
	srand(time(NULL));

	vector<int> v;
	while(true)
	{
		//function that gets number
		getNum(v);
		output(v);
	}


	return 0;
}