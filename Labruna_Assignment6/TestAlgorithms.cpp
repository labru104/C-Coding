// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 6
// The goal of this class is to test runtime of all sorting algorithms
// it prints them to standard out, and takes a file from the command line

#include "TestAlgorithms.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

AlgorithmTester::AlgorithmTester()
{
}

AlgorithmTester::~AlgorithmTester()
{

}

AlgorithmTester::AlgorithmTester(string filename)
{
	fname = filename;
	numcount = 0;
	
}
void AlgorithmTester::PrintArr(double* arr)
{
	int i;
	for(i = 0; i < numcount; i ++)
	{
		cout << arr[i] << endl;
	}
}

void AlgorithmTester::RunProgram()
{
	clock_t timeBeg;
	clock_t timeEnd;
	float thenum;
	GetFileInfo();
	timeBeg = clock();
	BubbleSort();
	timeEnd = clock();
	thenum = float(timeEnd - timeBeg)/CLOCKS_PER_SEC * 1000;
	cout << "It took " << thenum << " ms to sort the data with BubbleSort" << endl;
	timeBeg = clock();
	CocktailSort();
	timeEnd = clock();
	thenum = float(timeEnd - timeBeg)/CLOCKS_PER_SEC * 1000;
	cout << "It took " << thenum << " ms to sort the data with CocktailSort" << endl;
	timeBeg = clock();
	InsertionSort();
	timeEnd = clock();
	thenum = float(timeEnd - timeBeg)/CLOCKS_PER_SEC * 1000;
	cout << "It took " << thenum << " ms to sort the data with InsertionSort" << endl;
	timeBeg = clock();
	QuickSort(0, numcount - 1);
	timeEnd = clock();
	thenum = float(timeEnd - timeBeg)/CLOCKS_PER_SEC * 1000;
	cout << "It took " << thenum << "ms to sort the data with QuickSort" << endl;
}

void AlgorithmTester::GetFileInfo()
{
	ifstream numfile;
	string inputline;
	int lineon = 0;
	numfile.open(fname);
	if(numfile.is_open())
	{
		while(getline(numfile, inputline))
		{
			numcount++;
		}
	}
	else
	{
		cout << "File not found or File I/O error. Ending Program.";
		return;
	}
	numfile.close();
	numcount--;
	int i;
	int currValue = 0;
	bubbArr = new double[numcount];
	cocktailArr = new double[numcount];
	insertArr = new double[numcount];
	quickArr = new double[numcount];
	numfile.open(fname);
	int z = 0;
	if(numfile.is_open())
	{
		while(getline(numfile, inputline))
		{	if(int z = 0)
			{
				z++;
				//do nothing
			}
			else
			{		
				try
				{
					currValue = stod(inputline);
				}
				catch(exception e)
				{
					cerr << "Format error with text file. Ending program." << endl;
				}
				bubbArr[lineon] = currValue;
				cocktailArr[lineon] = currValue;
				insertArr[lineon] = currValue;
				quickArr[lineon] = currValue;
				lineon++;
			}
		}
	}
}

void AlgorithmTester::swap(double* d1, double* d2)
{
	int t = *d1;
	*d1 = *d2;
	*d2 = t;
}
void AlgorithmTester::BubbleSort()
{
	int i;
	int j;
	for(i = 0; i < numcount; i++)
	{
		for(j = 0; j < numcount - i - 1; j++)
		{
			if(bubbArr[j] > bubbArr[j + 1])
			{
				swap(&bubbArr[j], &bubbArr[j+1]);
			}
		}
	}
}

void AlgorithmTester::CocktailSort()
{
	bool didswap = true;
	int beg = 0;
	int lastnum = numcount - 1;
	while(didswap)
	{
		didswap = false;
		for(int i = beg; i < lastnum; ++i)
		{
			if(cocktailArr[i] > cocktailArr[i + 1])
			{
				swap(&cocktailArr[i], &cocktailArr[i + 1]);
				didswap = true;
			}
		}
		if(!didswap)
		{
			break;
		}
		didswap = false;
		--lastnum;
		for(int i = lastnum - 1; i >= beg; --i)
		{
			if(cocktailArr[i] > cocktailArr[i + 1])
			{
				swap(&cocktailArr[i], &cocktailArr[i + 1]);
				didswap = true;
			}
		}
		++beg;
	}
}

void AlgorithmTester::InsertionSort()
{
	int i;
	int key;
	int j;
	for(i = 1; i < numcount; i++)
	{
		key = insertArr[i];
		j = i - 1;
		while(j >= 0 && insertArr[j] > key)
		{
			insertArr[j + 1] = insertArr[j];
			j = j - 1;
		}
		insertArr[j + 1] = key;
	}
}

void AlgorithmTester::QuickSort(int low, int high)
{
	if(low < high)
	{
		int p = Partition(low, high);
		QuickSort(low, p - 1);
		QuickSort(p + 1, high);
	}
}

int AlgorithmTester::Partition(int low, int high)
{
	double pivot = quickArr[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++)
	{
		if(quickArr[j] <= pivot)
		{
			i++;
			swap(&quickArr[i], &quickArr[j]);
		}
	}
	swap(&quickArr[i + 1], &quickArr[high]);
	return(i + 1);
}


