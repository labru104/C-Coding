// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5
// This is my list class, defining all functions outlined in my virtual class

#include <iostream>
#include <cstdlib>

using namespace std;

#include "AbstractList.h"

#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H

	
template <typename T>
class DoublyLinkedList : List<T>
{
	class ListNode
	{
		public:
			T* data;
			ListNode* next;
			ListNode* prev;
			ListNode()
			{
				next = NULL;
				prev = NULL;
			}
			ListNode(T* dat)
			{
				data = dat;
				next = NULL;
				prev = NULL;
			}
	};
	
	private:
		ListNode*front;
		ListNode*back;
		unsigned int size;
	public:
		DoublyLinkedList()
		{
			front = NULL;
			back = NULL;
			size = 0;
		}

				
		
		~DoublyLinkedList()
		{
			while(front!= NULL)
			{
				removeFront();
			}
		}
		virtual void insertFront(T* dat)
		{
		
			ListNode * node = new ListNode(dat);
			if(isEmpty())
			{
				back = node;
			}
			else
			{
				front -> prev = node;
				node -> next = front;
			}
			front = node;
			size++;
		}

		virtual void insertBack(T* dat)
		{
			ListNode* node = new ListNode(dat);
			if(isEmpty())
			{
				front = node;
			}
			else
			{
				back -> next = node;
				node -> prev = back;
			}	
			back = node;
			size++;

		}
		virtual T* removeFront()
		{
			T* thedata;
			if(isEmpty())
			{
				return NULL;
			}
			else if(front == back)
			{
				thedata = front -> data;
				ListNode* todel = front;
				todel -> next = NULL;
				todel -> prev = NULL;
				front = NULL;
				delete todel;
			}
			else
			{
				thedata = front -> data;
				front->next->prev = NULL;
				ListNode* todel = front;
				front = todel -> next;
				todel -> next = NULL;
				delete todel;
			}
			size--;
			return thedata;
		}

		virtual T* removeBack()
		{
				T* thedata;
			if(isEmpty())
			{
				return NULL;
			}
			else if(back -> prev == NULL)
			{
				thedata = back -> data;
				ListNode* todel = back;
				back = NULL;
				front = NULL;
				delete todel;

			}
			else
			{
				thedata = back -> data;
				back -> prev -> next = NULL;
				ListNode* todel = back;
				back = todel -> prev;
				delete todel;
			}
			size--;
			return thedata;
		}

		virtual int find(T* dat)
		{
			int idx = -1;
			ListNode *curr = front;
			while(curr != NULL)
			{
				++idx;
				if(curr -> data == dat)
				{
					break;
				}
				else
				{
					curr = curr -> next;
				}
			}
			if(curr == NULL)
			{
				idx = -1;
			}
			return idx;
		}

		virtual T* deletePos(int pos)
		{
			if(pos > size)
			{
				return NULL;
			}
			int idx = 0;
			ListNode *curr = front;
			ListNode *prev = front;
			ListNode *next = front;

			//traverse list and update pointers accordingly

			while(idx != pos)
			{
		
				prev = curr;
				curr = curr -> next;	
				next = curr -> next;
			}
			prev -> next = curr -> next;
			next -> prev = curr -> prev;
			T* thedata = curr -> data;
			ListNode* todel = curr;
			todel -> next = NULL;
			todel -> prev = NULL;
			size--;
			delete todel;
			return thedata;
		}

		virtual bool contains(T* dat)
		{
			ListNode* curr = front;
			while(curr != NULL)
			{
				if(curr -> data == dat)
				{
					return true;
				}
				else
				{
					curr = curr -> next;
				}
			}
		return false;
		}
			
		virtual unsigned int getSize()
		{
			return size;
		}
		virtual bool isEmpty()
		{
			return(size == 0);
		}
		virtual int removeAt(T* dat)
		{
			{
				int pos = find(dat);
				deletePos(pos);
				return pos;
			}
		}


		virtual T* peekBack()
		{
			return back -> data;
		}
		virtual void printList()
		{
			if(front == NULL)
			{
				cout << "List Empty" << endl;
				return;
			}
			else
			{
				ListNode * curr = front;
				while(curr != NULL)
				{
					cout << curr -> data << endl;
				}
			}
		}
	
};

#endif

