// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>
#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::ShowMenu()
{
	cout << "This is the Chapman Database. There are many options to choose from, and all of the data entered in here will be stored locally on your computer." << endl;
	cout << "These are your options: " << endl;
	cout << "1. Print all students and their corresponding information." << endl;
	cout << "2. Print all faculty and their corresponding information." << endl;
	cout << "3. Search for and display a student's information." << endl;
	cout << "4. Search for and display faculty infortmation." << endl;
	cout << "5. Find the name and information of a student's advisor." << endl;
	cout << "6. Find the names and information of all of a faculty member's advisees" << endl;
	cout << "7. Add a new student to the database." << endl;
	cout << "8. Delete a student from the database." << endl;
	cout << "9. Add a new faculty member to the database." << endl;
	cout << "10. Delete a faculty member from the databade." << endl;
	cout << "11. Change a student's advisor." << endl;
	cout << "12. Remove an advisee from a faculty member given the ids." << endl;
	cout << "13. Rollback: Undo your most recent action that changed the structure of the database." << endl;
	cout << "14. Exit" << endl; 
	cout << "Type in the integer corresponding to what you would like to do." << endl;
}
