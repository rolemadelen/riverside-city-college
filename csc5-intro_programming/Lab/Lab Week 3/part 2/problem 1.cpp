
/*
 *Jiwon Yoo
 *Sept 12, 2013.
 * CSC5 - C++ programming
 * Lab3 Worksheet part2
 * problem 1 
 */

// write a program that will read in an amount of a purchase and 
// the amount given as payment (in dollars and cents, essentially as
// a floating point value). Tell the user if they have not given
// enough money to make the purchase. If they have given enough 
// money, compute and nicely output the user's change and how that 
// change is to be given(dollars, quarters, dimes, nickels, and pennies).
// For example, if the user owes %5.37 and gives $10, then they should get
// back $4.63 as 4 dollars, 2 quarters, 1 dime, 0 nickels, and 3 pennies.
// while it would be correct change to give the customer 463 pennies, use
// the largest number of the highest amounts first.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //declare variable money, payment
    double spend, payment;
    double holder;
    int remainder;
    int dollars, quarters, dime, nickels, pennies;
    
    // get how much the user owes
    cout << "Enter the amount of a purchase : $";
    cin >> spend;
    
    // get payment
    cout << "Enter the amount that you're gonna pay : $";
    cin >> payment;
    
    //while payment is not >= money
    while(payment < spend)
    {
        //output not enough money to pay and keep asking
        cout << "You have not given enough money to make your purchase.\n\a";
        cout << "Enter the amount again : $";
        cin >> payment;
    }
    
    //output the user's change
    
    holder = (payment - spend)* 100; //gives 462 not 463 why?
    remainder = static_cast<int>(holder);
    
    dollars = remainder / 100; 
    quarters = (remainder % 100) / 25;
    dime = ((remainder % 100) - (quarters * 25)) / 10;
    nickels = ((remainder % 100) - (quarters * 25) - (dime * 10)) / 5;
    pennies = (remainder % 10);
            
	cout << fixed << showpoint << setprecision(2);
    cout << "You paid $" << payment << " to pay $" << spend << ".\n\n";
    cout << "Your change is $" << remainder / 100.0 << endl
         << dollars << " dollar(s), " << quarters << " quarter(s), "
         << dime << " dime(s)," << nickels << " nickels, and " 
         << pennies << " pennies.\n";
    
    return 0;
}
