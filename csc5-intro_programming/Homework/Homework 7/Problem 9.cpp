/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 5, 2013.
* Professor Ung
* HW7 - problem 9
* I certify this is my own work and code!!
*/

//Write a program that finds the largest integer
//from a vector of integers. Create a vector contains
//20 random integer values. Then, create a function
//that finds, and returns the maximum value.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//purpose of this function is to store
//20 random values in vector.
//parameter: integer vector that is reference
//pseudo-returns.
void rand20(vector<int> &v)
{
	//seed new randNum
	srand(time(NULL));

	int randNum;
	
	//iterate 20 times
	for(int i = 0; i < 20; i ++)
	{
		//store random 1-1000 numbers
		randNum = rand() % 1000 + 1;
		//store to vector v
		v.push_back(randNum);
	}
}

//purpose of this function is to find
//the largest value inside vector.
//paramter: integer vector that is referenced
//pseudo-returns.
int largest(vector<int> &v)
{
	int num = v[1];

	for(int i = 0; i < v.size(); i ++)
	{
		if(num < v[i])
		{
			num = v[i];
		}
	}
	return num;
}
int main()
{
	vector<int> v;
	int large = 0;

	//Current size of a vector
	cout << "===========================\n";
	cout << "BEFORE STORING ANY VALUE.\n"
		<< "Vector size: " << v.size() << endl;

	//store rand 20 value to vector.
	rand20(v);

	//size of a vector after calling a function
	cout << "AFTER STROING VALUES.\n"
		<<"Vector size: " << v.size() << endl;
	cout << "==========================\n";

	//find largest number.
	large = largest(v);

	//output largest number in vector.
	cout << "Largetst number in vector: " << large << endl;
}