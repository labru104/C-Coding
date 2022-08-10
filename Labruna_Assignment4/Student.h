// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4


#include <cstdlib>
#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	public:	
		Student();
		Student(int, int);
		void setWaitTime(int);
		int getWaitTime();
		int getTimeCame();
		int getVisitLength();
	private:
		int timeCame;
		int waitTime;
		int visitLength;
};

#endif

