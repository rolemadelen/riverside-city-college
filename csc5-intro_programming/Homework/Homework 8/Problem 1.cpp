/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #1
* I certify this is my own work and code.
*/

//Write a function that will delete a number from
//a vector from a given location. The function
//should have a vector and the location as parameters.

#include <iostream>
#include <vector> //to use vector

using namespace std;

/*
* Purpose of this function is to delete a number from
* a vector from a given location. 
* 
* Parameter : vector and a location
* 
* Pseudo-returns.
*/
void deleteLoc(vector<int>& v, int loc);

/*
* Purpose of this function is to output 
* vector integers.
*
* Parmater is vector
*
* Pseudo-returns.
*/
void output(vector<int>& v);

int main()
{
	vector<int> v(4);
	int loc;
	
	v[0] = 3;
	v[1] = 5;
	v[2] = 0;
	v[3] = 10;
	

	//output initial vector
	cout << "BEFORE FUNCTION CALL." << endl;
	output(v);
	
	//get location of a number to delete
	cout << "Enter a location (0 ~ 3) of a"
		<< " number to delete." << endl;
	cin >> loc;

	//error check: prevent bound error
	while(loc > 3)
	{
		cout << "Enter a location (0~3)." << endl;
		cin >> loc;
	}

	//call function deleteLoc
	deleteLoc(v, loc);

	//output vector after func() call.
	cout << "AFTER FUNCTION CALL." << endl;
	output(v);
}
void output(vector<int>& v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << "v[" << i << "]: "
			<<  v[i] << endl;
	}
}

void deleteLoc(vector<int>& v, int loc)
{
	for(int i = loc; i < v.size()-1; i++)
	{
			v[i] = v[i+1];
	}
	v.pop_back();
}