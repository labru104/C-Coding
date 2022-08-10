// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

#include "Faculty.h"
#include "genBST.h"
#include "TreeNode.h"
#include "IDGenerator.h"
#include "FacultyTree.h"
#include "theImp.h"
#include "Menu.h"
#include "StudentTree.h"

theImp::theImp()
{
}

theImp::~theImp()
{
}

void theImp::runProgram()
{
	Menu *themenu = new Menu();
	FacultyTree* facultyTree = new FacultyTree();
	StudentTree* studentTree = new StudentTree();
	int id;
	int x = 0;
	int input;
	while(x == 0)
	{
		cin.clear();
		themenu->ShowMenu();
		cin >> input;
		while(!cin||input < 1 || input > 14)
		{
			cout << "Error: bad input. Try again, enter an integer between 1 and 14" << endl;
			cin >> input;
		}
		cin.clear();
		if(input == 1)
		{
			TreeNode<Student> * theroot = studentTree -> getRoot();
			studentTree -> PrintAllStudents(theroot);
		}
		else if(input == 2)
		{
			TreeNode<Faculty> * theroot = facultyTree -> getRoot();
			facultyTree -> PrintAllFaculty(theroot);
		}
                else if(input == 3)
                {   
                        cout << "Enter the student ID who you would like to display" << endl;
                        cin >> id; 
                        while (!cin||input < 0)
                        {   
                                cout << "Bad input. Please try again, enter an integer between 1 and 14" << endl;
                                cin.clear();
				cin >> id;
                        }
                        studentTree -> PrintStudent(id);
                }

		else if(input == 4)
		{
                        cout << "Enter the faculty ID who you would like to display" << endl;
                        cin >> id; 
                        while (!cin||input < 0)
                        {       
                                cout << "Bad input. Please try again,";
                                cin.clear();
				cin >> id;
                        }
                        facultyTree -> PrintFaculty(id);
                }
		else if(input == 5)
		{
			cout << "Enter the id of the student's advisor" << endl;
		}
		else if(input == 7)
		{
			cin.clear();
			studentTree -> AddStudent();
		}
		else if(input == 8)
                {   
                        cout << "Enter the student ID who you would like to delete" << endl;
                        cin >> id;
                        while (!cin||input < 0)
                        {       
                                cout << "Bad input. Please try again." << endl;
                                cin.clear();
				cin >> id;
                        }
                        studentTree -> DeleteStudent(id);
                }

			
		else if(input == 9)
		{
			facultyTree -> AddFaculty();
		}
		else if(input == 10)
                {
                        cout << "Enter the faculty ID who you would like to delete" << endl;
                        cin >> id;
                        while (!cin||input < 0)
                        {
                                cout << "Bad input. Please try again." << endl;
                                cin.clear();
                        }
                        facultyTree -> DeleteFaculty(id);
                }
		else if(input == 11)
		{
			cout << "Enter the ID of the student" << endl;
		}
		else if(input == 12)
		{
			cout << "Enter the id of the faculty member" << endl;
		}
		else if(input == 13)
		{
			cout << "How many times would you like to roll back" << endl;
		}
		else if(input == 14)
		{
			x = 1;
		}
	}	
}
