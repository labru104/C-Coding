// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include <cstdlib>
#include <iostream>
#include <string>
#include "Student.h"


using namespace std;

Student::Student()
{
}

Student::Student(int theid, double thegpa, string nam, string lev, string maj, int adv)
{
	GPA = thegpa;
	name = nam;
	level = lev;
	major = maj;
	advisor = adv;
	ID = theid;
}

int Student::getID()
{
	return ID;
}

void Student::setID(int theid)
{
	ID = theid;
}

double Student::getGPA()
{
	return GPA;
}

void Student::setGPA(double thegpa)
{
	GPA = thegpa;
}

void Student::setAdvisor(int adv)
{
	advisor = adv;
}

int Student::getAdvisor()
{
	return advisor;
}

void Student::printInfo()
{
	cout << "ID#: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Major: " << major << endl;
	cout << "Advisor ID: " << advisor << endl;
}
