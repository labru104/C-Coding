// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>
#include <iostream>
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
	public:
		Student();
		Student(int, double,  string, string, string, int);
		int getID();
		void setID(int);
		double getGPA();
		void setGPA(double);
		void printInfo();
		int getAdvisor();
		void setAdvisor(int);
	private:
		double GPA;
		string name;
		string level;
		string major;
		int advisor;
		int ID;
};

#endif


