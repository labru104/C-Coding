// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4


#include <cstdlib>
#include <iostream>

#include "Student.h"

using namespace std;

Student::Student()
{
}

Student::Student(int tCame, int vLength)
{
	timeCame = tCame;
	visitLength = vLength;
	waitTime = 0;
}

void Student::setWaitTime(int wTime)
{
	waitTime = wTime;
}

int Student::getWaitTime()
{
	return waitTime;
}

int Student::getTimeCame()
{
	return timeCame;
}

int Student::getVisitLength()
{
	return visitLength;
}