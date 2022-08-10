// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include<cstdlib>
#include<string>
#include<cmath>

#include "GenDoublyLinkedList.h"

#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IDGenerator
{
	public:
		IDGenerator();
		int createStudID();
		int createFacID();
	private:
		DoublyLinkedList<int>* studList;
		DoublyLinkedList<int>* facList;
		

};
#endif


