// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is the faculty class, implementing all functions defined in faculty.h

#include <cstdlib>
#include <iostream>
#include <string>
#include "Faculty.h"
#include "StudentTree.h"
using namespace std;


Faculty::Faculty()
{
}

Faculty::Faculty(int theid, string nam, string lev, string dept) 
{
	ID = theid;
	name = nam;
	level = lev;
	department = dept;
	advisees = new DoublyLinkedList<int>();
}

void Faculty::PrintInfo()
{
	cout << "ID#: " << ID  << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Advisee IDs: " << endl;
	advisees -> printList();
}


void Faculty::addAdvisee(int studid)
{
	advisees -> insertFront(&studid);
}

//void Faculty::deleteAdvisee(int theid)
//{
//	advisees -> find(theid)
//}
void Faculty::PrintAdvisees()
{

}
