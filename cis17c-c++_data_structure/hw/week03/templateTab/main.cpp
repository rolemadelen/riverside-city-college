// System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

// User Libraries
#include "PlusTab.h"

// Function Prototypes
template <class T>
void print(Table<T> &);

// Execution begins here
int main(int argc, char **argv) {
	// Seed the random numberG
	unsigned seed = time(0);
	srand(seed);
	
	// Declare Variables
	int r,c;

	// Prompt the user for a row and col
	cout << "Enter a row and col size: ";
	cin >> r >> c;

	// Create a PlusTab Object
	PlusTab<float> obj(r,c);
	PlusTab<int> obj2(r,c);

	// output the results
	print(obj);
	print(obj2);

	return 0;
}

template <class T>
void print(Table<T> &obj) {
	cout << endl;
	for(int i=0; i<obj.getRowSz(); ++i) {
		for(int j=0;j<obj.getColSz();++j) {
			cout << fixed << showpoint << setprecision(1) << obj.getData(i,j) << ' ';
		}
		cout << endl;
	}
	
}
