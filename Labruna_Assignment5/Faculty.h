// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is the faculty header class, defining all functions to be implemented in faculty.cpp

#include <cstdlib>
#include <iostream>
#include <string>



#include "GenDoublyLinkedList.h"

#ifndef FACULTY_H
#define FACULTY_H

class Faculty
{
	public: 
		Faculty();
		Faculty(int, string, string, string);
		void PrintInfo();
		void PrintAdvisees();
		void addAdvisee(int);
		//void removeAdvisee(int);
	private:
		string name;
		string level;
		string department;
		DoublyLinkedList<int>* advisees;
		int ID;
};

#endif


