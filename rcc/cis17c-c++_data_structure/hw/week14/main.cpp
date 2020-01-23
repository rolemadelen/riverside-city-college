// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "MAry.h"

// Execution begins here
int main(int argc, char **argv) {
	int m=3;
	MAry *obj = new MAry(m);

	obj->insert(1);

	for(int i=2,j=1;i<=30;++i,++j) {
		obj->insert(i);
		if(j%m==0) cout<<endl;
	}

	delete [] obj;
	return 0;
}
