// System Libraries
#include <iostream>
using namespace std;

// Function Prototypes
int max(int *a, int beg, int end);
int max(int *a, int end);

// Execution begins here
int main(int argc, char **argv) {
	int a1[] = {5,4,3,2,1};
	int a2[] = {2,3,5,4,1};
	int a3[] = {1,2,3,4,5};
	
	cout << "\nMax value in the array = " << max(a1,0,sizeof(a1)/sizeof(int)) << endl;
	cout << "\nMax value in the array = " << max(a2,0,sizeof(a2)/sizeof(int)) << endl;
	cout << "\nMax value in the array = " << max(a3,0,sizeof(a3)/sizeof(int)) << endl;
	cout << "\nMax value in the array = " << max(a1,sizeof(a1)/sizeof(int)) << endl;
	cout << "\nMax value in the array = " << max(a2,sizeof(a2)/sizeof(int)) << endl;
	cout << "\nMax value in the array = " << max(a3,sizeof(a3)/sizeof(int)) << endl;
	return 0;
}

int max(int *a, int beg, int end) {
	if(end-beg<=1)return a[beg];
	int half=(beg+end)/2;
	int m1=max(a,beg,half);
	int m2=max(a,half,end);
	return (m1>m2?m1:m2);
}

int max(int *a, int end) {
	int maximum=a[0];
	for(int i=1;i<end;++i)
		if(maximum<a[i]) maximum=a[i];
	return maximum;
}
