/*
* Jiwon Yoo
* Student ID : 2485776
* October 11, 2013
* Homework : 6
* Problem : 5
* I certify this is my own work and code!
*/


#include <iostream>
#include <string>
using namespace std;

// Purpose of this fuction is to
// swap two numbers.
// return type is void.
// paramter : two reference values
void swap(int &num, int &num2);

int main()
{
	int x = 3;
	int y = 4;

	cout << "Before SWAP x = " << x << " y = " << y << endl;
	swap(x,y);
	cout << "After SWAP x = " << x << " y = " << y << endl;



	return 0;
}

void swap(int &num, int &num2)
{
	int temp;
	temp = num;
	num = num2;
	num2 = temp;
	cout << "---------------------------\n";
	cout << "INSIDE THE FUNTION.\n";
	cout << "---------------------------\n";
}
