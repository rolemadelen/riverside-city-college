//Jiwon Yoo
//2013, September 3. Week 2
// Lab Worksheet problem 02
//Problem 2 my expectation what the outputs will be :
//      a: 5 b: 10
//      a: 10 b: 5

#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b =10;
	int temp = 0;
    
    cout << "a: " << a << " " << "b: " << b << endl;
    
    //a = b;   5 = 10
   // b = a;   10 = 10
	
	temp = a; //temp = 5;
	a = b;    // 5 = 10;
	b = temp; //= b(10) = 5;
    
    cout << "a: " << a << " " << "b: " << b << endl; 
    
    return 0;
}