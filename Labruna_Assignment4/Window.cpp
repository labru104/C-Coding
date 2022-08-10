// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4


#include <cstdlib>
#include <iostream>

using namespace std;

#include "Window.h"

Window::Window()
{
	timeVisited = 0;
	idleTime = 0;
	currStudent = NULL;
}

void Window::resetTimeVisited()
{
	timeVisited = 0;
}

void Window::addTimeVisited()
{
	timeVisited++;
}
void Window::addIdleTime()
{
	idleTime++;
}

void Window::addStudent(Student* stud)
{
	currStudent = stud;
}

Student* Window::removeStudent()
{
	Student *ret = currStudent;
	currStudent = NULL;
	return ret;
}

int Window::getStudTime()
{
	if(currStudent == NULL)
	{
		return -1;
	}
	else
	{
		return currStudent->getTimeCame();
	}
}

bool Window::isTimeUp()
{
	if(currStudent->getVisitLength() == timeVisited)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Window::isFull()
{
	return(currStudent != NULL);
}
