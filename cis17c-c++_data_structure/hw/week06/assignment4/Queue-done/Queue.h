/* 
	Author: Jiwon Yoo
	Date: March 29, 2016
	Specification file for the Queue(FIFO) class 
*/

#ifndef QUEUE_H
#define QUEUE_H

// System Libraries
#include <cstdlib>	//NULL

// User Libraries
#include "Node.h"

class Queue {
	private:
		Node *head;
	public:
		// Constructor
		Queue( int );
	
		// Destrucor
		~Queue();
	
		// Member Functions
		void push_front(int);
		int pop_front();
};

#endif
