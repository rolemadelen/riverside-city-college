/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 19, 2013.
* HW: 3
* Problem: 7
* I certify this is my own work and code
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{

	int total_pos = 0, total_neg = 0;
	int random;
	double cntpos = 0, cntneg = 0;

	srand(time(NULL));
	for(int i = 1; i <= 10; i ++)
	{
		random = (rand()%200-100);
		cout << random << endl;

		if(random > 0)
		{
			total_pos += random;
			cntpos ++;
		}
		else
		{
			total_neg += random;
			cntneg ++;
		}
	}
	cout << endl;
	cout << "Sum of all the positive numbers : " 
		 << setw(5) << total_pos << endl;
	cout << "Sum of all the negative numbers : " 
		 << setw(5) << total_neg << endl << endl;
	cout << "The average of all the positives : " 
		 << setw(6) << fixed << setprecision(2)
		 << total_pos / cntpos << endl;
	cout << "The average of all the negatives : " 
		 << setw(6) << total_neg / cntneg << endl << endl;
	
	double total = static_cast<double>(total_pos + total_neg);
	cout << "The sum of all numbers : "
		<< total_pos + total_neg << endl;
	cout << "The average of all numbers : "
		<< total / (cntpos + cntneg) << endl << endl;



	return 0;
}