// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is the bst Template class, imnplementing all functions in a bst

#include <iostream>
#include <cstdlib>
#include "TreeNode.h"


#ifndef GENBST_H
#define GENBST_H

using namespace std;
	
template <typename T>
class genBST
{
		private:
			unsigned int size;
		public:
			TreeNode<T>* root;
			genBST()
			{
				root = NULL;
				size = 0;
			}
			~genBST()
			{
				//delete root;
			}
			TreeNode<T>* findMin()
			{
				TreeNode<T> *curr = root;
				if(root == NULL)
				{
					return NULL;
				}
				while(curr->left != NULL)
				{
					curr = curr -> left;
				}
				return curr;
			}
			TreeNode<T>* findMinNode(TreeNode<T> *node)
			{
				TreeNode<T> *curr = node;
				if(node == NULL)
				{
					return NULL;
				}
				while(curr -> left != NULL)
				{
					curr = curr -> left;
				}
				return curr;
			}		
			TreeNode<T>* findMax()
			{
				TreeNode<T> *curr = root;
				if(root == NULL)
				{
					return NULL;
				}
				while(curr->right != NULL)
				{
					curr = curr->right;
				}
				return curr;
			}
			void inOrderPrint(TreeNode<T>* node)
			{
				if(node == NULL)
				{
					return;
				}
				inOrderPrint(node->left);
				cout << node->key << endl;
				inOrderPrint(node->right);
			}
			void insert(TreeNode<T>* node)
			{
				if(root == NULL)
				{
					root = node;
					size++;
					return;
				}
				else
				{
					TreeNode<T> * curr = root;
					TreeNode<T> * parent = NULL;
					int x = 0;
					while(x == 0)
					{
						parent = curr;
						if(node -> key == curr -> key)
						{
							cerr << "Error. Duplicate key value. Data was not inserted." << endl;
							size++;
							x = 1;
						}
						else if(node -> key < curr -> key)
						{
							curr = curr -> left;
							if(curr == NULL)
							{
								parent -> left = node;
								size++;
								x = 1;
							}
						}
						else
						{
							curr = curr -> right;
							if(curr == NULL)
							{
								parent -> right = node;
								size++;
								x = 1;
							}
						}
					}
				}
			}
			bool contains(int thekey)
			{
				if(root == NULL)
				{
					return false;
				}
				else
				{
					TreeNode<T>*curr = root;
					while(curr -> key != thekey)
					{
						if(thekey < curr -> key)
						{
							curr = curr -> left;
						}
						else
						{
							curr = curr -> right;
						}
						if(curr == NULL)
						{
							return false;
						}
					}
				}
				return true;
			}

			T* find(int thekey)
			{
				if(root == NULL)
				{
					return NULL;
				}
				else if(root -> key == thekey)
				{
					return root -> data;
				}
				else
				{
					TreeNode<T>* curr = root;
					while(curr -> key != thekey )
					{
						if(thekey < curr -> key)
						{
							if(curr -> left == NULL)
							{
								return NULL;
							}
							curr = curr -> left;
						}
						else
						{
							if(curr -> right == NULL)
							{
								return NULL;
							}
							curr = curr -> right;
						}
						if(curr -> key == thekey)
						{
							return curr -> data;
						}
					}
				}
				return NULL;
			}
			
			TreeNode<T>* getSuccessor(TreeNode<T>* d)
			{
				if(root == NULL)
				{
					return NULL;
				}
				if(d -> right != NULL)
				{
					return findMinNode(d->right);
				}
					
				TreeNode<T> *sp = d;
				TreeNode<T> *succ = d;
				TreeNode<T> *curr = d -> right;
				while(curr != NULL)
				{
					sp = succ;
					succ = curr;
					curr = curr -> left;
				}
				if(succ != curr -> right)
				{
					sp -> left = succ -> right;
					succ -> right = d -> right;
				}
				return succ;
			}
				
			bool deleteNode(int thekey)
			{
				if(root == NULL)
				{
					return false;
				}
				
				TreeNode<T> * par = root;
				TreeNode<T> * curr = root;
				bool isLeft;
				while(curr -> key != thekey)
				{
					par = curr;
					if(thekey < curr -> key)
					{
						isLeft = true;
						curr = curr -> left;
					}
					else
					{
						isLeft = false;
						curr = curr -> right;
					}
					if(curr == NULL)
					{
						return false;
					}
				}
				
				if(curr -> left == NULL && curr -> right == NULL)
				{
					if(isLeft == true)
					{
						par -> left = NULL;
					}
                                        else if(curr == root)
                                        {
                                                root = NULL;
                                        }

					else
					{
						par -> right = NULL;
					}
				}
				//one left child
				else if(curr -> right == NULL)
				{
					if(isLeft)
					{
						par -> left = curr -> left;
					}
					else if(curr == root)
					{
						root = curr -> left;
					}
					else
					{
						par -> right = curr -> right;
					}
				}
				else if(curr -> left == NULL)
				{
					if(curr == root)
					{
						root = curr -> right;
					}
					else if(isLeft)
					{
						par -> left = curr -> right;
					}
					else
					{
						par -> right = curr -> right;	
					}
				}
				else
				{	
					TreeNode<T> *successorparent = curr;
					TreeNode<T> *successor = curr;
					TreeNode<T> *current = curr -> right;
					while(current != NULL)
					{      
						successorparent = successor;
						successor = current;
						current = current -> left;
					}
					if(successor != curr -> right)
					{      
						successorparent -> left = successor -> right;
						successor -> right = curr -> right;
						successor -> left = curr -> left;
					}
					
					if(curr == root)
					{
						cout << "in here" << endl;
						root = successor;
					}
					else if(isLeft)
					{
						par -> left = successor;
					}
					else
					{
						par -> right = successor;
					}
					successor -> left = curr -> left;
				}
				size--;
				return true;
			}
			TreeNode<T>* getParent(TreeNode<T>* child)
			{
				TreeNode<T>* par = root;
				TreeNode<T>* curr = root;
				while(child->key != curr -> key)
				{
					if(child -> key < root -> key)
					{	if(curr -> left == NULL)
						{
							return NULL;
						}	
						par = curr;
						curr = curr -> left;
					}
					else
					{
						if(curr -> right == NULL)
						{
							return NULL;
						}
						par = curr;
						curr = curr -> right;
					}	
				}
				return par;
			}	
			bool isEmpty()
			{
				return(size == 0);
			}
			unsigned int getSize()
			{
				return size;
			}				
};

#endif

