/*
	Author: Jiwon Yoo
	Date: May 24, 2016
	Implementation file for the m-ary class 
*/

#include <iostream>
using namespace std;

// User Libraries
#include "MAry.h"

//////////////////////////////////////////////////////////////////////
//												CONSTRUCTOR
//////////////////////////////////////////////////////////////////////
MAry::MAry( int m ) {
	nChild = m;
	root = new TreeNode();
	root->data = NULL;
	root->child = new TreeNode *[m];	
	root->parent = root;
}

//////////////////////////////////////////////////////////////////////
//                         insert
//	Input   -> data: int
//  output  -> void
//	purpose -> insert a data to the tree 
//////////////////////////////////////////////////////////////////////
void MAry::insert( int _data ) {
	if( root->data==NULL ) { 
		root->data = new int(_data); 
		return;
	}

	TreeNode *temp = nilNode(root);
	for(int i=0;i<nChild;++i) {
		if( temp->child[i]==NULL ) {
			temp->child[i] = new TreeNode();
			temp->child[i]->data = new int (_data);
			temp->child[i]->parent = temp;
	  	cout << "parent : " << *(temp->data) << ' ';
	  	cout << "child : " << *(temp->child[i]->data) << endl;
			break;
		} 
	}
}

//////////////////////////////////////////////////////////////////////
//                      nilNode -> empty node
//	Input   -> obj: TreeNode *
//  output  -> temp: TreeNode *
//	purpose -> if a node is full, create and return a new node
//////////////////////////////////////////////////////////////////////
TreeNode* MAry::nilNode( TreeNode *obj ) {
	if( obj->child[nChild-1]==NULL ) return obj;
	obj = obj->parent;
	int cnt=0;
	for(int i=0;i<nChild;++i) {
		if( obj->child[i]->child==NULL ) {
			obj->child[i]->child = new TreeNode*[nChild];
			obj->child[i]->parent = obj;
		}
		if( !(isFull(obj->child[i])) ) {obj = obj->child[i];break;}
		else if(i==nChild-1) {
			i=-1; 
			obj = root->child[0+(cnt++)];
			if(cnt==nChild) cnt=0;
		}
	}
	nilNode( obj );
}

//////////////////////////////////////////////////////////////////////
//                            isFull
//////////////////////////////////////////////////////////////////////
bool MAry::isFull( TreeNode *obj ) {
	for(int i=0;i<nChild;++i){
		if( obj->child[i]==NULL ) return false;
	}
	return true;
}
