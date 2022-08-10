// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 6
// This is the main of the program, the goal of this file is to instantiate
// an instance of algorithm tester and run the program

#include <iostream>
#include <cstdlib>
#include <string>
#include "TestAlgorithms.h"
using namespace std;


int main(int argc, char *argv[])
{
        string numFile;
        if (argc > 1)
        {
                numFile = argv[1];
        }
        else
        {
                cerr << "No file given. Exiting program." << endl;
                return 0;
        }
        AlgorithmTester theTester(numFile);
        theTester.RunProgram();
        return 0;
}
