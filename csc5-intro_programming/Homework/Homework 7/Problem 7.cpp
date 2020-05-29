/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 4, 2013.
* Professor Ung
* HW7 - problem 7
* I certify this is my own work and code!!
*/

//Write a program that inserts 10 random integers in a vector.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//get 10 random integers and store in a vector.
//paramter : vector<int> 
//pseudo-returns.
void inVec(vector<int> &v)
{
	//seed
	srand(time(NULL));

	//store a randValue in num.
	int num;

	v.resize(0);
	//insert rand value in v[0] to v[9]
	for(int i = 0; i < 10; i++)
	{
		num = (rand() % 100) + 1;
		v.push_back(num);
	}
}

void output(vector<int> &v)
{
	for(int i = 0; i < v.size(); i ++)
	{
		cout << "Vector [" << i << "] :" << v[i] << endl;
	}
}
int main()
{
	vector<int> v(10);
	
	cout << "This program will insert ten random\n"
		<< "integers in a vector.\n";
		
	cout << "CURRENT VECTOR.\n";
	output(v);

	//empty the vector and add 10 numbers;
	inVec(v);

	cout << "AFTER VECTOR.\n";
	output(v);
}