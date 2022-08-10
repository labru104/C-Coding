#include <string>
#include <iostream>
#include <cstdlib>
#include "FacultyTree.h"
#include "IDGenerator.h"

using namespace std;

FacultyTree::FacultyTree()
{
	allFaculty = new genBST<Faculty>();
	facultygen = new IDGenerator();
}

Faculty* FacultyTree::FindFaculty(int thekey)
{
	Faculty* ans;
	if(allFaculty->contains(thekey))
	{
		ans = allFaculty -> find(thekey);
		return ans;
	}
	else
	{
		cout << "Faculty not in database." << endl;
		return NULL;
	}
}

void FacultyTree::PrintFaculty(int id)
{
	Faculty * currfac = FindFaculty(id);
	if(currfac == NULL)
	{
		cout << "Faculty coud not be printed" << endl;
		return;
	}
	currfac -> PrintInfo();
}

bool FacultyTree::DeleteFaculty(int id)
{
	bool didDelete = allFaculty -> deleteNode(id);
	return didDelete;
}
void FacultyTree::PrintAllFaculty(TreeNode<Faculty> * node)
{
	if(node == NULL)
	{
		return;
	}
	PrintAllFaculty(node -> left);
	Faculty* currFac = node -> data;
	currFac -> PrintInfo();
	PrintAllFaculty(node -> right);
}

void FacultyTree::AddFaculty()
{
	string studGP;
	string studadv;
	double studGPA;
	string facname;
	string faclevel;
	string department;
	string strm;
	string b;
	int studadvisor;
	cout << "Add Faculty: " <<endl;
	while(getline(cin, strm))
	{
		b = strm;
		break;
	}
	cout << "Enter the name of the Faculty" << endl;
	while(getline(cin, strm))
        {
                facname += strm;
		break;
        }

	cout << "Enter the level of the Faculty" << endl;
	while(getline(cin, strm))
        {
                faclevel += strm;
		break;
        }

	cout << "Enter the department of the Faculty" << endl; 
	while(getline(cin, strm))
	{
		department += strm;
		break;
	}
	int facID = facultygen -> createFacID();
	Faculty*thefaculty = new Faculty(facID,  facname, faclevel, department);
	TreeNode<Faculty> * thenode = new TreeNode<Faculty>(thefaculty, facID);
	allFaculty -> insert(thenode);
}

TreeNode<Faculty>* FacultyTree::getRoot()
{
	return allFaculty -> root;
}

//void AddAdvisee(int oldfacid, int newfacid, int studid)
//{
//	if(allFaculty -> contains(oldfacid) && allFaculty -> contains(newfacid) 
//	{
		
