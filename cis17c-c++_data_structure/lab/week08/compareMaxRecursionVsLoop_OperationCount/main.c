// System Libraries
#include <stdio.h>
#include <stdlib.h>	// srand
#include <time.h>	// time()

// Global Constants -- only excepitons
int cforlt,cforeq,cforinc, cforret, cfortot;
int creceq, crecle, crecsub, crecadd, crecdiv, creciff, crecfnc,crectot,crecret;
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
	int size = 8000;
	int *a = fillAry(size);

	// Call Function For Loop
	max2(a,size);
	printf("for-loop less than  = %d\n", cforlt);
	printf("for-loop equalities = %d\n", cforeq);
	printf("for-loop increment  = %d\n", cforinc);
	printf("for-loop return     = %d\n", cforret);
	cfortot = cforlt+cforeq+cforinc+cforret;
	printf("for-loop  total     = %d\n\n", cfortot);

	// Call Function Recursive
	max(a,0,size);
	printf("recursive less than equal to = %d\n", crecle);
	printf("recursive equalities         = %d\n", creceq);
	printf("recursive subtraction        = %d\n", crecsub);
	printf("recursive addition           = %d\n", crecadd);
	printf("recursive division           = %d\n", crecdiv);
	printf("recursive function           = %d\n", crecfnc);
	printf("recursive ternary            = %d\n", creciff);
	printf("recursive return             = %d\n", crecret);
	crectot = crecle+creceq+crecsub+crecadd+crecdiv+crecfnc+creciff+crecret;
	printf("recursive  total             = %d\n", crectot);
	free(a);

	return 0;
}

int max(int *a, int beg, int end) {
	++crecle; ++crecsub;
	if(end-beg<=1)return a[beg];
	++crecadd; ++crecdiv; ++creceq;
	int half=(beg+end)/2;
	crecfnc+=2;
	int m1=max(a,beg,half);
	int m2=max(a,half,end);
	++creciff; ++crecret;
	return (m1>m2?m1:m2);
}

int max2(int *a, int end) {
	++cforeq;
	int maximum=a[0];
	++cforeq;
	for(int i=1;i<end;++i) {
		++cforlt; ++cforinc;
		++cforlt;
		if(maximum<a[i]) maximum=a[i];
	}
	++cforret;
	return maximum;
}

int *fillAry( int size ) {
	int *array = (int *)malloc( sizeof(int)*size );
	for(int i=0;i<size;++i) {
		array[i]=rand();
	}	
	return array;
}
