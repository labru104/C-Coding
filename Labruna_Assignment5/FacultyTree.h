// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is the faculty tree header class, defining all functions to be implemented in facultree.cpp

#include <cstdlib>
#include <string>
#ifndef FACULTYTREE_H
#define FACULTYTREE_H
#include "genBST.h"
#include "Faculty.h"
#include "IDGenerator.h"
class FacultyTree
{
	public:
		FacultyTree();
		Faculty* FindFaculty(int);
		void PrintAllFaculty(TreeNode<Faculty>*);
		void PrintFaculty(int);
		void AddFaculty();
		void DeleteAdvisee(int);
		void AddAdvisee(int);
		bool DeleteFaculty(int);
		TreeNode<Faculty>* getRoot();
	private:
		genBST<Faculty>* allFaculty;
		IDGenerator* facultygen;	
};

#endif


