// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 3
// The goal of this class is to ensure a file name was given from the command line then 
// make an instance of the brace checker class to perform the specifications of the assignment

#include <iostream>
#include <cstdlib>
#include "BraceChecker.h"
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
        string filetocheck;
        if (argc > 1)
        {
                filetocheck = argv[1];
        }
        else
        {
                cerr << "No file given. Exiting program." << endl;
                return 0;
        }
        BraceChecker theChecker;
        theChecker.CheckFile(filetocheck);
        return 0;
}
