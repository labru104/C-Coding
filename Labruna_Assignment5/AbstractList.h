// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is the virtual list class, defining all functions to be implemented in the list

#include <cstdlib>

#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

template <class T>
class List
{
	public:
		virtual void insertFront(T* dat) = 0;
		virtual void insertBack(T* dat) = 0;
		virtual T* removeFront() = 0;
		virtual T* removeBack() = 0;
		virtual bool contains(T* dat) = 0;
		virtual bool isEmpty() = 0;
		virtual int removeAt(T* dat) = 0;
		virtual T* deletePos(int val) = 0;
		virtual int find(T* data) = 0;
		virtual unsigned int getSize() = 0;
		virtual T* peekBack() = 0;
		virtual void printList() = 0;
};

#endif


