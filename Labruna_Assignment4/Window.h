// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4


#include <cstdlib>
#include <iostream>
#include "Student.h"


#ifndef WINDOW_H
#define WINDOW_H

class Window
{
	public:	
		Window();
		void resetTimeVisited();
		void addTimeVisited();
		void addIdleTime();
		bool isTimeUp();
		bool isFull();
		void addStudent(Student*);
		Student* removeStudent();
		int getStudTime();
	private:
		Student* currStudent;
		int idleTime;
		int timeVisited;
};

#endif

