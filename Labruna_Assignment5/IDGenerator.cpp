// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 5

#include<cstdlib>
#include<string>
#include<cmath>
#include "GenDoublyLinkedList.h"
#include "IDGenerator.h"

using namespace std;

IDGenerator::IDGenerator()
{
	studList = new DoublyLinkedList<int>();
	facList = new DoublyLinkedList<int>();
}

int IDGenerator::createStudID()
{
	int x = 0;
	while(x == 0)
	{
		int theID = rand() % 500000 + 1;
		int*currID = &theID;
		if(studList->contains(currID) == false)
		{	
			studList -> insertFront(currID);
			return theID;
		}
			
	}
	return 0;	
	
}

int IDGenerator::createFacID()
{
        int x = 0;
        while(x == 0)
        {
                int theID = rand() % 500001 + 1;
		int* currID = &theID;
		currID += 50000;
                if(facList->contains(currID) == false)
                {       
                        facList -> insertFront(currID);
                        return theID;
                }
        
        }
	return 0;

}

