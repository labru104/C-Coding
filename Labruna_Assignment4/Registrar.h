// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4

#include <cstdlib>
#include <string>
#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "GenDLLQueue.h"
#include "Student.h"
#include "Window.h"

class Registrar
{
	public:
		Registrar();
		Registrar(std::string);
		~Registrar();
		bool GetInfo();
		bool UseInfo();
		bool addFirstEmpty(Student*);
		bool allWindowsEmpty();
	private:
		std::string filename;
		GenDLLQueue<Student>* studFinished;
		GenDLLQueue<Student>* studWaiting;
		GenDLLQueue<Student>* allStudents;
		Window* theWindows;
		int numWindows;
};

#endif

