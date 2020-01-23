/*
	Author: Jiwon Yoo
	Purpose: Mark Sort
	Date : March 8, 2016
*/

// System Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void fillAry(int *, const int);
void print(int *, const int, const int);
void markSrt(int *, const int);

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
	printf("%s\n", "Before Sorted");
	print( ip, i_size, i_perLn );

	// sorts the array
	markSrt( ip, i_size );

	// Display the array
	printf("%s\n", "After Sorted");
	print( ip, i_size, i_perLn );

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
void markSrt(int *arr, const int size) {
	int i,j;
	i=j=0;
	
	for( i=0;i<size-1 ;++i) 
		for( j=i+1;j<size;++j )
			if( arr[i]>arr[j] ) {
				arr[i] ^= arr[j];
				arr[j] = arr[i]^arr[j];
				arr[i] ^= arr[j];
			}

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
