/*
* Jiwon Yoo
* Professor Ung
* Lab 9 part 2 - #2
*/

//Create a program that asks the user to enter a number.
//For each number received, add it to a vector called numbers.
//Allow the user to continually add numbers until the user enters -1.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers;
	cout << "Enter a list of pos. and neg. numbers.\n"
		<<"When you're done, place -1 at the end.\n: ";

	int num = 0;

	//get input until user inputs -1
	while(num != -1)
	{
		//get num
		cin >> num;
		//add it to vector 'numbers'
		numbers.push_back(num);
		cout << num << " added.\n";
	}

	cout << "\nElements in vector: \n";
	for(int i = 0; i < numbers.size(); i ++)
	{
		cout << "vector [" << i << "]: " << numbers[i] << endl;
	}
}