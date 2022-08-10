// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4
// This is my registrar class, the main function used to make the solution

#include "Registrar.h"
#include "Student.h"
#include "Window.h"
#include "GenDLLQueue.h"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Registrar::Registrar()
{
}

Registrar::Registrar(string fname)
{
	filename = fname;
	allStudents = new GenDLLQueue<Student>();
	studFinished = new GenDLLQueue<Student>();
	studWaiting = new GenDLLQueue<Student>();
	numWindows = 0;
		
}

Registrar::~Registrar()
{
}

bool Registrar::GetInfo()
{
	string inputline;
	int theIterations = 0;
	int progHandler = 0;
	int studCounted = 0;
	int theTime = 0;
	int visitLength = 0;
	int numStudents = 0;
	int numstuditerator = 0;
	ifstream inputfile;
	inputfile.open(filename);
	if(inputfile.is_open())
	{
		while(getline(inputfile, inputline))
		{
			if(progHandler == 0)
			{
				numWindows = stoi(inputline);
				progHandler = 1;
			}
			else
			{
				if(numWindows <= 0)
				{
					cerr << "Error with input file. Ending program." << endl;
					return false;
				}
				else
				{
					if(progHandler == 1)
					{
						theTime = stoi(inputline);
						cout << "the Time: "<< theTime << endl;
						if(theTime <= 0)
						{
							cerr << "Error with input file. Ending program." << endl;
							return false;
						}
						progHandler = 2;
					}
					else if(progHandler == 2)
					{
						numStudents = stoi(inputline);
						
						if(numWindows <= 0)
						{
							cerr << "Error with input file. Ending program." << endl;
							return false;
						}
						progHandler = 3;
					}
					else if(progHandler == 3)
					{
						
						visitLength = stoi(inputline);
						cout << "visit Length: " << visitLength << endl;
						if(visitLength <= 0)
						{
							cerr << "Error with input file. Ending program." << endl;
							return false;
						}

						Student* currStudent = new Student(theTime, visitLength);
						allStudents -> enqueue(currStudent);
						++studCounted;
						if(studCounted >= numStudents)
						{
							studCounted = 0;
							progHandler = 1;
						}
					}
				}
			}
		}
	}
	else
	{
		cerr << "File not found error" << endl;
		return false;
	}
	return true;
}
				
bool Registrar::UseInfo()
{
	theWindows = new Window[numWindows];
	for(int i = 0; i < numWindows; i++)
	{
		theWindows[i] = Window();
	}
	int studInWindows = 0;
	int timeWaited = 0;
	int currTime = (allStudents -> peek() -> getTimeCame());
	while(allStudents->isEmpty() == false)
	{
		while(allStudents -> peek() -> getTimeCame() == currTime)
		{
			timeWaited = 0;
			cout << "filling windows" << endl;
			if(studInWindows > numWindows)
			{
				
				addFirstEmpty(allStudents -> dequeue());
			}
			else
			{
				studWaiting -> enqueue(allStudents -> dequeue());
			}
		}
		for(int i = 0; i < numWindows; i++)
		{
			if(theWindows[i].isFull())
			{
				theWindows[i].addTimeVisited();
				if(theWindows[i].isTimeUp())
				{
					studFinished -> enqueue(theWindows[i].removeStudent());
				}
				else
				{
					theWindows[i].addTimeVisited();
				}
			}
			else if(studWaiting -> isEmpty() == false)
			{
				studWaiting -> peek() -> setWaitTime(timeWaited);
				theWindows[i].addStudent(studWaiting -> dequeue());
			}			
			else
			{
				theWindows[i].addIdleTime();
			}
		}
		if(studWaiting -> isEmpty() == false)
		{
			timeWaited++;
		}
		if(allWindowsEmpty() && studWaiting -> isEmpty() && allStudents -> isEmpty())
		{	
			return true;
		}
		if(allWindowsEmpty())
		{
			currTime = allStudents -> peek() -> getTimeCame();
		}
	}
	return true;
	
}

//eventually add an if statement to check if the list of studwaiting is empty, if it is then make it so if that is empty and all the windows are, then we start from the top again and update currtime
//after we make sure the queue is updated well have another abstract method called run a minute where we do exactly that
		
	
					
bool Registrar::addFirstEmpty(Student* stud)
{
	for(int i = 0; i < numWindows; i++)
	{
		if(theWindows[i].isFull() == false)
		{
			theWindows[i].addStudent(stud);
			return true;
		}
	}
	return false;
}

bool Registrar::allWindowsEmpty()
{
	for(int i = 0; i < numWindows; i++)
	{
		if(theWindows[i].isFull())
		{
			return false;
		}
	}
	return true;
}
