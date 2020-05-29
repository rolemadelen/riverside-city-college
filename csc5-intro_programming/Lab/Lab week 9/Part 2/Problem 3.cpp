/*
* Jiwon Yoo
* Professor Ung
* Lab 9 part 2 - #3
*/

//Create a function that outputs any vector of integers.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void randVec(vector<int> &v)
{
	srand(time(NULL));
	int randNum = (rand() % 100) + 1;
	
	v.push_back(randNum);

	cout << "A rand. value stored in a vector: " << v[0] << endl;
}

void output(vector<int> &v)
{
	cout << "CURRENT VECTOR SIZE: " << v.size() << endl;
}
int main()
{
	vector<int> v;
	output(v);
	randVec(v);
	output(v);
}