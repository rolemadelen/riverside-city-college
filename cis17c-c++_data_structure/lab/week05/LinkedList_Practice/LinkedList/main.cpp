#include <iostream>
using namespace std;

#include "LnkdLst.h"

int main(int argc, char **argv) {
	const int SIZE = 10;
	int n = SIZE;
	LnkdLst list(n--);

	while(n>0) list.push(n--);
	while(n++<SIZE) cout<<list.pop()<<endl;
	return 0;
}
