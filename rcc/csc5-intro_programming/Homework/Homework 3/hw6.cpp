/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 19, 2013.
* HW: 3
* Problem: 6
* I certify this is my own work and code
*/


#include <iostream>
using namespace std;
int main()
{

	int total_pos = 0, total_neg = 0;
	int cntpos = 0, cntneg = 0;
	int respond;

	cout << "Input 10 numbers. (either Postivie or Negative).\n";
	for(int i = 1; i <= 10; i ++)
	{
		cout << i << ":\t ";
		cin >> respond;

		if(respond <= 0)
		{
			total_neg += respond;
			cntneg ++;
		}
		else
		{
			total_pos = total_pos + respond;
			cntpos ++;
		}

	}
	cout << endl;
	cout << "Sum of all the positives : "
		 << total_pos << endl;
	if(cntpos == 0)
	{
		cout << "The average of all postive number is : 0" << endl;
	}
	else
	{
	cout << "The average of all postive number is : " 
		 << total_pos / static_cast<double>(cntpos) << endl;
	}

	cout << "sum of all the negatives : " << total_neg << endl;
	if(cntneg == 0)
	{
	cout << "The average of all negative number is : 0" << endl;
	}
	else
	{
	cout << "The average of all negative number is : "
		 << total_neg / static_cast<double>(cntneg) << endl;
	}
	
	double total = static_cast<double>(total_pos + total_neg);
	cout << "The sum of all numbers : "
		<< total_pos + total_neg << endl;
	cout << "The average of all numbers : "
		<< total / (cntpos + cntneg) << endl;


	return 0;
}