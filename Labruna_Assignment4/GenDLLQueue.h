// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4
// This is my generic queue class using the doubly linked list. Methods are self explanatory

#include <iostream>
#include <cstdlib>
#include "GenDoublyLinkedList.h"

#ifndef GENDLLQUEUE_H
#define GENDLLQUEUE_H

template <typename T>
class GenDLLQueue 
{
        public:
		GenDLLQueue()
		{
			theQueue = new DoublyLinkedList<T>();
			front = 0;
		}
		~GenDLLQueue()
		{
		}
		void enqueue(T* dat)
		{
			theQueue -> insertFront(dat);
		}
		T* dequeue()
		{
			return (theQueue -> removeBack());
		}
		T* peek()
		{
			return(theQueue -> peekBack());
		}
		bool isEmpty()
		{
			return(theQueue -> getSize() == 0);
		}
		int getSize()
		{
			return (theQueue -> getSize());
		}
	private:
		DoublyLinkedList<T>*theQueue;
		int front;

};

#endif

