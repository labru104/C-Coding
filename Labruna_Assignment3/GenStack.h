// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 3
// The goal of this class is to declare and define all functions required for a properly functioning generic stack. Error checking is implemented.
// The methods are organized and commented.


#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef GENSTACK_H
#define GENSTACK_H

//defining all functions that will be used in class with the generic type T

template<class T>
class GenStack
{
        public:
                GenStack(); // default constructor
                GenStack(int maxSize); // overloaded constructor
                ~GenStack();
                void push(T);
                T pop();
                T peek();
                bool isFull();
                bool isEmpty();
                T *myArray;
        private:
                int numElements;
                int size;
                int top;

};

#endif

//Empty constructor
template <class T>
GenStack<T>::GenStack()
{
        size = 0;
        top = -1;
}

//Overloaded Constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{
        myArray = new T[maxSize];
        size = maxSize;
        top = -1;
}

//destructor
template <class T>
GenStack<T>::~GenStack()
{
        delete [] myArray;
}

//push function with error checking implemented
template <class T>
void GenStack<T>::push(T elem)
{
        if(isFull())
        {
                
        }
        else
        {
                myArray[++top] = elem;
        }
}

//pop function with error checking implemented
template <class T>
T GenStack<T>::pop()
{
        if(isEmpty())
        {
                cerr << "Error: Stack is empty. Exiting program." << endl;
                exit (EXIT_FAILURE);
        }
        else
        {
                return myArray[top--];
        }
}

//peek function with error checking implemented
template <class T>
T GenStack<T>::peek()
{
        if(isEmpty())
        {
                cerr << "Error: Stack is empty. Exiting program." << endl;
                exit (EXIT_FAILURE);
        }
        else
        {
                return myArray[top];
        }
}

//Check if full
template <class T>
bool GenStack<T>::isFull()
{
        return(size - 1 == top);
}

//Check if empty
template <class T>
bool GenStack<T>::isEmpty()
{
        return(top == - 1);
}

