/*
* Jiwon Yoo
* Professor Ung
* Lab 9 part 2 - #1
*/

//Write a program that creates a vector
//of ints and stores the values 3, 6, and 8 inside it.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//declare int type vector 'v'
	vector<int> v;

	//add or push_back three values: 3, 6, and 8
	v.push_back(3);
	v.push_back(6);
	v.push_back(8);

	//check if three values are stored in vector.
	for(int i = 0; i < v.size(); i ++)
		cout << v[i] << endl;
	return 0;
}