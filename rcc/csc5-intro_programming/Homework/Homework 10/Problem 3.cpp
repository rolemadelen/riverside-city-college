/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW10 - Problem 3
* I certify this is my own work and code.
*/

//Instead of getting a size from the user,
//retrieve values from the user until the user
//does not want to enter any more values.
//Store these values into a dynamic array.
//Finally, output the array, once the user has
//finished entering values.
//HINT: Keep track of the elements used.


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//store vector integers to array
//output all numbers
void output(int arr[], vector<int>& num)
{
	for(int i = 0; i < num.size(); i++)
	{
		arr[i] = num[i];
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int *p;
	int cnt = 0;
	int number = 0;
	vector<int> num;

	cout << "Enter a number and place -1 after you're done.\n";

	do
	{
		cnt ++;

		cin >> number;

		if(number != -1)
		{
			cnt++;
			num.push_back(number);
		}
		
	}while(number != -1);

	p = new int(cnt);

	output(p,num);
	
	delete[] p;
	return 0;
}