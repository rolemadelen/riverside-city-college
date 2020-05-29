/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #6
* I certify this is my own work and code.
*/

//Write a function that determines if a number is
//already contained inside the vector.
//Create a driver that tests if the function works properly.

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
	int check = 0;

	cout << "FUNCTION CALL.\n";
	cout<< "=============================\n"
		<< "if check == -1 : number DNE.\n"
		<< "if check != -1 : number exist.\n";
	cout << "check : " << check << endl;
	if(check != -1)
		return true;
	else
		return false;
}

void getNum(vector<int>& v)
{
	int num;
	cout << "\nEnter a number to add in vector. 0 to quit." << endl;
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
	}


	return 0;
}