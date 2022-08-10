// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 3
// The goal of this class is to define the brace checker class.

#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef BRACECHECKER_H
#define BRACECHECKER_H

class BraceChecker
{
        public:
                BraceChecker();
                bool CheckFile(string);
};

#endif
