// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>
#include <string>
#ifndef STUDENTTREE_H
#define STUDENTTREE_H

#include "genBST.h"
#include "Student.h"
#include "IDGenerator.h"
class StudentTree
{
	public:
		StudentTree();
		Student* FindStudent(int);
		void PrintAllStudents(TreeNode<Student>*);
		void PrintStudent(int);
		void AddStudent();
		bool DeleteStudent(int);
		TreeNode<Student>* getRoot();
	private:
		genBST<Student>* allStudents;
		IDGenerator* studgen;	
};

#endif

