/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 19, 2013.
* HW: 3
* Problem: 5
* I certify this is my own work and code
*/


#include <iostream>
using namespace std;
int main()
{

	int total_pos = 0, total_neg = 0;
	int respond;
	for(int i = 1; i <= 10; i ++)
	{
		cout << i << ": ";
		cin >> respond;

		if(respond <= 0)
		{
			total_neg += respond;
		}
		else
		{
			total_pos = total_pos + respond;
		}

	}

	cout << "sum of all the positives : " << total_pos << endl;
	cout << "sum of all the negatives : " << total_neg << endl;

	return 0;
}