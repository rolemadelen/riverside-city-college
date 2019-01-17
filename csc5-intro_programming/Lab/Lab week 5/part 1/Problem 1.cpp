/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 1 - problem 1
*/

// Write a program to compute the interest due,
// total amount due, and the minimum payment for
// a revolving credit account. The program accepts
// the account balance as input, then adds on the
// interest to get the total amount due. The rate
// schedules are the following: The interest is
// 1.5 percent on the first $1000, and 1 percent
// on any amount over that. The minimum payment is
// the total amount due if that is $10 or less; otherwise,
// it is $10 or 10 percent of the total amount owed,
// whichever is larger. Your program should include a
// loop that lets the user repeat this calculation
// until the user says she or he is done.

#include <iostream>
using namespace std;

int main()
{
	const double INTEREST_UNDER_1000 = 0.015;
	const double INTEREST_OVER_1000 = 0.01;
	
	double accBalance, totalAmount, minPay, interest;
	cout << "To quit, enter negative number.\n\n";
	while(true)
	{
		cout << "Enter the account balance : $";
		cin >> accBalance;
		
		if(accBalance < 0)
		{
			cout << "That's it!\n";
			return 0;
		}
		
		// interest is 1.5% on the first $1000.
		if(accBalance <= 1000)
		{
			interest = accBalance * INTEREST_UNDER_1000;
			totalAmount = accBalance + interest;
			
			// if total amount due <= $10
			if(totalAmount <= 10)
			{
				// minPay = total amount due;
				minPay = 10;
			}
			else
			{
				// otherwise it is $10 or 10% of total amount
				//whichever is larger.
				if((totalAmount * 0.1) > 10)
				{
					minPay = totalAmount * 0.1;
				}
				else
				{
					minPay = 10;
				}
			}
		}
		else
		{
			double overInterst, underInterest;
			
			// 1% on any amount over $1000.
			overInterst = (accBalance / 1000) * INTEREST_OVER_1000;
			
			// if its over 1000, automatically
			//accBalnce + (1000*15% interst)
			underInterest = 1000 * INTEREST_UNDER_1000;
			
			//total amount due = accbalance + interest;
			interest = overInterst + underInterest;
			totalAmount = accBalance + interest;
			if(totalAmount <= 10)
			{
				// minPay = total amount due;
				minPay = totalAmount;
			}
			else
			{
				// otherwise it is $10 or 10% of total amount
				//whichever is larger.
				if(totalAmount > 10)
				{
					minPay = totalAmount;
				}
				else
				{
					minPay = 10;
				}
			}
		}
		cout << "Interest due : $" << interest << endl;
		cout << "Total amount due : $" << totalAmount << endl;
		cout << "Minimum payment : $" << minPay << endl;
	}
}
