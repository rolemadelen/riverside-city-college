/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 2 - problem 1
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	double x= 0;
	double s;
	
	cout << "n : ";
	cin >> n;

	s = 1.0 / (1 + n * n);
	while(s > 0.01)
	{
		s = 1.0 / (1 + n * n);
		n ++;
		x = x + s;
		cout << s << endl;
	}
	
	return 0;
}