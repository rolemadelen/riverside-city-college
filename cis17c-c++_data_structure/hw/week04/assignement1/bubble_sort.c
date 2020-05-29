/*
	Author: Jiwon Yoo
	Purpose: Bubble Sort Algorithm 
			 Best = O(n)  ---  Worst = O(n^2)
	Date : March 16, 2016
*/

// System Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void fillAry(int *, const int);
void print(int *, const int, const int);
void bblSrt(int *, const int);

// Execution begins here
int main() {
	// seed rand numbers
	unsigned seed = time(0);
	srand( seed );

	// Declare Variables
	int *ip;
	int i_size, i_perLn;
	i_size=i_perLn=0;

	// Prompt the user for the input
	printf("Enter the size of an array: ");
	scanf("%d",&i_size);
	printf("Display how many numbers per line: ");
	scanf("%d", &i_perLn);

	// Allocate memory
	ip = (int *)malloc( sizeof(int)*i_size );

	// fill array with random values
	fillAry( ip, i_size );
	
	// Display the array
//	printf("%s\n", "Before Sorted");
//	print( ip, i_size, i_perLn );

	// sorts the array
	bblSrt( ip, i_size );

	// Display the array
//	printf("%s\n", "After Sorted");
//	print( ip, i_size, i_perLn );

	// Deallocate the memory
	free(ip);

	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN	 	 : void
// PRECONDITION  : filled array
// POSTCONDITION : array is sorted
// PARAMETER	 : int *, const int size
//////////////////////////////////////////////////////////////////////
void bblSrt(int *arr, const int size) {
	int ceq, clt, cinc, cswap, csrt;
	ceq=clt=cinc=cswap=csrt=0;

	++ceq;	// i=0
	++ceq;	// sorted=0
	for( int i=0,sorted=0;i<size-1 && !sorted ;++i) { 
		sorted=1;
		++ceq;	// sorted=1
		++clt;	// i<size-1
		++cinc;	// ++i
		++ceq;	// j=0
		for( int j=0;j<size-1-i;++j ) {
			++cinc;	// ++j
			++clt;	// j<size-1
			if( arr[j]>arr[j+1] ) {
				arr[j] ^= arr[j+1];
				arr[j+1] = arr[j]^arr[j+1];
				arr[j] ^= arr[j+1];
				sorted=0;
				++cswap;	// swap
				++ceq;		// sorted=0
			}
			++clt;	// arr[j]>arr[j+1]
		}
	}
    printf("Size of the sorted array = %d\n",size);
    printf("How many equalities  = %d\n", ceq);
    printf("How many increments  = %d\n", cinc);
    printf("How many comparisons = %d\n", clt);
    printf("How many swaps       = %d\n", cswap);

	return;
}

//////////////////////////////////////////////////////////////////////
// RETURN	 	 : void
// PRECONDITION  : initialized array
// POSTCONDITION : array is filled with random values 
// PARAMETER	 : int *, const int size
//////////////////////////////////////////////////////////////////////
void fillAry(int *arr, const int size) {
	int i;
	for( i=0;i<size;++i )
		*(arr+i) = rand()%size+1;
	return;
}

//////////////////////////////////////////////////////////////////////
// RETURN	 	 : void
// PRECONDITION  : array must contain some values
// POSTCONDITION : displayed all elements in the array
// PARAMETER	 : int *, const int size, const int perLine
//////////////////////////////////////////////////////////////////////
void print(int *arr, const int size, const int perLine) {
	int i;
	for( i=0;i<size;++i ) {
		printf("%3d ",*(arr+i));
		if( (i+1)%perLine==0 ) printf("\n");
	}
	printf("\n");
	return;
}
