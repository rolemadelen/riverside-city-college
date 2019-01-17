/* 
	Author: Jiwon Yoo
	Date: April 2, 2016
	Specification file for the Prority Queue class 
*/

#ifndef PQUEUE_H
#define PQUEUE_H

// System Libraries
#include <cstdlib>	//NULL

// User Libraries
#include "Node.h"

class PQueue {
	private:
		Node *head;
	public:
		// Constructor
		PQueue( int );
	
		// Destrucor
		~PQueue();
	
		// Member Functions
		void push_front(int);
		int pop_front();
		bool find(int);
		void remove(int);
		void print();
};

#endif
