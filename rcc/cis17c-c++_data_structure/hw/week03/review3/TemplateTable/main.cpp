/*
    Author: Jiwon Yoo
    File: main.cpp
    March 6, 2016, ( BEGIN: 12:22 PM  
                     END :  12:44 PM)
    Purpose:  Templated aggregates
*/

//User Libraries
#include <iostream>
#include <cstdlib>	//srand
#include <ctime>	// time
#include <iomanip>	// setw
using namespace std;

//User Libraries
#include "Table.h"

//Global Constants

//Function Prototype
template<class T>
void prntRow(T *,int);

template<class T>
void prntTab(const Table<T> &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
	unsigned seed = time(0);
	srand(seed);
   
   //Declare Variables
   int rows=3,cols=4;
   
   //Test out the Row with integers and floats
   RowAry<int> a(3);RowAry<float> b(4);
   cout<<"Test the Integer Row "<<endl;
   prntRow(&a,3);
   cout<<"Test the Float Row "<<endl;
   prntRow(&b,4);
   
   //Test out the Table with a float
   Table<float> tab1(rows,cols);
   Table<float> tab2(tab1);
   Table<float> tab3=tab1+tab2;
   
   cout<<"Float Table 3 size is [row,col] = Table 1 + Table 2 ["
           <<rows<<","<<cols<<"]\n";
//	prntTab(tab1);
//	prntTab(tab2);
	prntTab(tab3);
   
   //Exit Stage Right
   return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : T *obj, int num
// PURPOSE   : Print rows displaying num characters per line 
//////////////////////////////////////////////////////////////////////
template<class T>
void prntRow(T *a,int perLine){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : const Table 
// PURPOSE   : Print Tables (row,col)
//////////////////////////////////////////////////////////////////////
template<class T>
void prntTab(const Table<T> &a){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int row=0;row<a.getRowSz();row++){
        for(int col=0;col<a.getColSz();col++){
            cout<<setw(8)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}
