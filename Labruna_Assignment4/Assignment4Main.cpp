// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 4
// This is the main class, invoking methods to be used for the solution

#include "Registrar.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char*argv[])
{
	string thefname;
	if (argc > 1)
        {
                thefname = argv[1];
        }
        else
        {
                cerr << "No file name given. Exiting program." << endl;
                return 0;
        }
        Registrar theRegistrar(thefname);
        bool a = theRegistrar.GetInfo();
	theRegistrar.UseInfo();
        return 0;
}