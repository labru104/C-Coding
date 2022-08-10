// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <string>
#include <iostream>
#include <cstdlib>
#include "StudentTree.h"

using namespace std;

StudentTree::StudentTree()
{
	allStudents = new genBST<Student>();
	studgen = new IDGenerator();
}

Student* StudentTree::FindStudent(int thekey)
{
	Student* ans;
	if(allStudents->contains(thekey))
	{
		ans = allStudents -> find(thekey);
		return ans;
	}
	else
	{
		cout << "Student not in database." << endl;
		return NULL;
	}
}

void StudentTree::PrintStudent(int id)
{
	Student * currstud = FindStudent(id);
	if(currstud == NULL)
	{
		cout << "Student coud not be printed" << endl;
		return;
	}
	currstud -> printInfo();
}

bool StudentTree::DeleteStudent(int id)
{
	bool didDelete = allStudents -> deleteNode(id);
	return didDelete;
}
void StudentTree::PrintAllStudents(TreeNode<Student> * node)
{
	if(node == NULL)
	{
		return;
	}
	PrintAllStudents(node -> left);
	Student* currStud = node -> data;
	currStud -> printInfo();
	PrintAllStudents(node -> right);
}

void StudentTree::AddStudent()
{
	string studGP;
	string studadv;
	double studGPA;
	string studname;
	string studlevel;
	string studmaj;
	string strm;
	string b;
	int studadvisor;
	        cout << "Add Student: " <<endl;
        while(getline(cin, strm))
        {   
                b = strm;
                break;
        }   

	cout << "Enter the name of the Student" << endl;
	while(getline(cin, strm))
        {
                studname += strm;
		break;
        }

	cout << "Enter the level of the Student" << endl;
	while(getline(cin, strm))
        {
                studlevel += strm;
		break;
        }
	cout << "Enter the GPA of the Student" << endl;
	while(getline(cin, strm))
        {
                studGP += strm;
		break;
        }

	studGPA = stod(studGP);
	if(studGPA == 0)
	{
		cerr << "GPA given was invalid or 0. Failed to add Student." << endl;
		return;
	}
	cout << "Enter the major of the Student" << endl; 
	while(getline(cin, strm))
	{
		studmaj += strm;
		break;
	}
	cout << "Enter the ID of the advisor of the Student" << endl;
	while(getline(cin, strm))
        {
                studadv += strm;
		break;
        }
	studadvisor = stoi(studadv);
	if(studadvisor > 50000 != true || studadvisor < 100000 != true)
	{
		cout << "Bad advisor ID given. Aborting student add." << endl;
		return;
	}
	int studID = studgen -> createStudID();
	Student*thestudent = new Student(studID, studGPA, studname, studlevel, studmaj, studadvisor);
	TreeNode<Student> * thenode = new TreeNode<Student>(thestudent, studID);
	allStudents -> insert(thenode);
}

TreeNode<Student>* StudentTree::getRoot()
{
	return allStudents -> root;
}
