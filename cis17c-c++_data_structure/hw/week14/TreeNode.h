/*
	Author: Jiwon Yoo
	Date: May 24, 2016
	Specification file for the TreeNode Structure
*/

#ifndef TREENODE_H
#define TREENODE_H
using namespace std;
struct TreeNode {
	int *data;
	TreeNode **child;
	TreeNode *parent;
};

#endif
