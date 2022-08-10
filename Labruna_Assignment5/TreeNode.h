// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>

#ifndef TREENODE_H
#define TREENODE_H

template <typename T>
class TreeNode
{   
	public:
		TreeNode *left;
		TreeNode *right;
		int key;
		T* data;

		TreeNode()
		{   
			right = NULL;
			left = NULL;
		}   
		TreeNode(T* thedata, int thekey)
		{   
			right = NULL;
			left = NULL;
			data = thedata;
			key = thekey;
		}   
		~TreeNode()
		{   
			delete right;
			delete left;
			delete data;
		}   
};  

#endif
