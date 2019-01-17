// System Libraries
#include <stdio.h>
#include <stdlib.h>	// srand
#include <time.h>	// time()

// Function Prototypes
int max( int *, int, int );
int max2( int *, int );
int *fillAry( int );

// Execution begins here
int main(int argc, char **argv) {
	// Initialize the random number seed
	unsigned seed = time(0);
	srand(seed);

	// Fill a dynamic array
	int size = 16000000;
	int *a = fillAry(size);
	int factFor = 100;
	int factRec = 10;

	// Time the functions
	int beg = time(0);
	for(int i=1;i<=factRec;++i) max(a,0,size);
	int end = time(0);
	
	// Output the time for the Recursion
	//printf("N=%d\tRecursion time = %f seconds\n", size,(1.0f*(end-beg))/factRec);
	printf("N=%d\tRecursion time = %f seconds\n", size,(1.0f*(end-beg)));

	// Time the functions
	beg = time(0);
	for(int i=1;i<=factFor;++i) max2(a,size);
	end = time(0);
	
	// Output the time for the Loop
	//printf("N=%d\tLoop time Max function = %f seconds\n", size,(1.0f*(end-beg))/factFor);
	printf("N=%d\tLoop time Max function = %f seconds\n", size,(1.0f*(end-beg)));
	return 0;
}

int max(int *a, int beg, int end) {
	if(end-beg<=1)return a[beg];
	int half=(beg+end)/2;
	int m1=max(a,beg,half);
	int m2=max(a,half,end);
	return (m1>m2?m1:m2);
}

int max2(int *a, int end) {
	int maximum=a[0];
	for(int i=1;i<end;++i)
		if(maximum<a[i]) maximum=a[i];
	return maximum;
}

int *fillAry( int size ) {
	// dynamically allocate memory
	int *array = (int *)malloc( sizeof(int)*size );
	for(int i=0;i<size;++i) {
		array[i]=rand();
	}	
	return array;
}
