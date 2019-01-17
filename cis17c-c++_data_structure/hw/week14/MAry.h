/* 
	Author: Jiwon Yoo
	Date: May 24, 2016
	Specification file for the m-ary class 
*/

#ifndef MARY_H
#define MARY_H

// System Library
#include <cstdlib>	// NULL

// User Library
#include "TreeNode.h"

class MAry {
	private:
		TreeNode *root;
		int nChild;

		TreeNode* nilNode( TreeNode * );
		bool isFull( TreeNode * );
	public:
		MAry(int);	// Constructor
		//~MAry();		// Destructor
	
		void insert(int); // Member functions
};

#endif
