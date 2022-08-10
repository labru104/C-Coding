// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 6
// The goal of this class is to head the algorithm tester class, which tests
// four different sorting algorithms

#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef ALGORITHMTESTER_H
#define ALGORITHMTESTER_H

class AlgorithmTester
{
        public:
                AlgorithmTester();
		~AlgorithmTester();
		AlgorithmTester(string);
		void RunProgram();
	private:
		string fname;
		int numcount;
		double* bubbArr;
		double* cocktailArr;
		double* insertArr;
		double* quickArr;
		void GetFileInfo();
		void swap(double*, double*);
		void BubbleSort();
		void CocktailSort();
		void InsertionSort();
		void QuickSort(int, int);
		int Partition(int, int);
		void PrintArr(double*);
};

#endif


