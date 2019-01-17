/*
* Jiwon Yoo
* Professor Ung
* Lab 9 part 2 - #4
*/

//Create a function that does number 2. You should
//output the vector before and outhput the function.

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void getVector(vector<int> &v)
{
	int numbers;
	cout << "Enter a list of neg. or pos. numbers.\n"
		<<"When you're done place -1 at the end.\n";
	cin >> numbers;
	while(numbers != -1)
	{
		v.push_back(numbers);
		cout << numbers << " added.\n";
		cin >> numbers;
	}
}

void output(vector<int> &v)
{
	cout << "==============================\n";
	cout << "Current size of a vector : " << v.size() << endl << endl;
	
	for(int i = 0; i < v.size(); i ++)
	{
		cout <<  setw(3) << v[i] << " ";
		if(i != 0 && i % 5 == 0 )
			cout << endl;
	}
	
	cout << "\n============================\n";
}
int main()
{
	vector<int> v;	
	output(v);
	getVector(v);
	output(v);
}