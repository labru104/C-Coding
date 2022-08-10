// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 1 
// The goal of this class is to demonstrate the gas pump implementation file

#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include "Assignment1Header.hpp"
using namespace std;

//main takes in string argument from command line, could not take one directly from command line or would have had to use an array
//main makes an object of type DNAFunctions and uses it to perform all functions specified in assignment instructions, functions are explained in more detail in implementation file
int main(int argc, char **argv) 
{
	srand(time(NULL));
	string filename;
	cout << "Enter the name of the file of DNA strings: " << endl;
	cin >> filename;
	DNAFunctions theDNA;
	theDNA.FileReader(filename);
	theDNA.PerformCalculations(filename);
	theDNA.DNAWriter(false);
	int x = 1;
	while(x == 1)
	{
		cout << "Would you like to process another file? Enter 1 to process and 0 or any other integer to exit" << endl;
		cin >> x;
		if(x == 1)
		{
			DNAFunctions theDNA;
			cout << "Enter the name of the file: ";
			cin >> filename;
			theDNA.FileReader(filename);
			theDNA.PerformCalculations(filename);
			theDNA.DNAWriter(true);
		}	
		else
		{
			break;
		}	
	}	
}
