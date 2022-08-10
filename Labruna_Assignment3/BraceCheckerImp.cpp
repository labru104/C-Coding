// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 3
// The goal of this class is to use the generic stack to implement the delimiter program. 
// The function which does this is commented on below.


#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include "GenStack.h"
#include "BraceChecker.h"
using namespace std;

template class GenStack<char>;

//empty constructor
BraceChecker::BraceChecker()
{

}

//main function to check a file's braces, uses switch case to identify delimiters then for each case either adds to stack, prints out an error, or pops the stack. The works to assignment expectations.

bool BraceChecker::CheckFile(string fname)
{
        GenStack<char> theStack(100);
        string currentstring;
	int linecount = 0;
        ifstream filetocheck;
        filetocheck.open(fname);
        if(filetocheck.is_open())
        {
                while(getline(filetocheck, currentstring))
                {
                        ++linecount;
                        char braceChecker[currentstring.length() + 1]; 
                        strcpy(braceChecker, currentstring.c_str());
                        int j = currentstring.size();
                        for(int i = 0; i < j; i++)
                        {
                                switch(braceChecker[i])
                                {   
                                        case '[':
                                                theStack.push(braceChecker[i]);
                                                break;
                                        case '(':
                                                theStack.push(braceChecker[i]);
                                                break;
                                        case '{':
                                                theStack.push(braceChecker[i]);
						break;
                                        case ']':
						if(theStack.isEmpty())
						{
							cout << "Error: got ]  at line " << linecount << " with no previous [" <<  endl;
							return false;
						}
                                                else if(theStack.peek() == '[')
                                                {   
                                                        theStack.pop();
							break;
                                                }
						else if(theStack.peek() == '(' )
						{
							cout << "Line " << linecount << ": expected ')', found ']'." << endl;
							return false;
						}
						else if(theStack.peek() == '{' ) 
						{
							cout << "Line " << linecount << ": expected '}', found ']'." << endl;
							return false;
						}  
                                                else
                                                {   
                                                        cout << "Error:  " << braceChecker[i] <<  " at line " << linecount << " unnacounted for" <<  endl;
                                                        return false;
                                                }   
                                        case ')':
                                                if(theStack.isEmpty())
                                                {       
                                        	        cout << "Error: got )  at line " << linecount << " with no previous (" <<  endl;
							return false;
                                                }

                                                else if(theStack.peek() == '(')
                                                {   
                                                        theStack.pop();
							break;
                                                }
                                                else if(theStack.peek() == '[' )
                                                {
                                                        cout << "Line " << linecount << ": expected ']', found ')'." << endl;
                                                        return false;
                                                }
                                                else if(theStack.peek() == '{' ) 
                                                {
                                                        cout << "Line " << linecount << ": expected '}', found ')'." << endl;
                                                        return false;
                                                }

                                                else
                                                {
                                                        cout << "Error:  " << braceChecker[i] <<  " at line " << linecount << " unnacounted for" <<  endl;
                                                        return false;   
                                                }   

                                        case '}':
						if(theStack.isEmpty())
						{
							cout << "Error: got }  at line " << linecount << " with no previous {" <<  endl;
							return false;
						}
							
                                                else if(theStack.peek() == '{')
                                                {   
                                                        theStack.pop();
							break;
                                                }   
                                                else if(theStack.peek() == '[' )
                                                {
                                                        cout << "Line " << linecount << ": expected ']', found '}'." << endl;
                                                        return false;
                                                }
                                                else if(theStack.peek() == '(' )
                                                {
                                                        cout << "Line " << linecount << ": expected ')', found '}'." << endl;
                                                        return false;
                                                }
                                                else
                                                {
                                                        cout << "Error:  " << braceChecker[i] <<  " at line " << linecount << " unnacounted for" <<  endl;
                                                        return false;
                                                }   

					default:
						break;   


                                }   
                        }   
                }
                if(theStack.isEmpty() == false)
                {   
                          cout << "Reached end of file, missing " << theStack.peek() << endl;
                          return false;
                }    
                else
                {   
                          cout << "File has balanced delimiters" << endl;
                          return true;
                }   
   
        }   
        else
        {   
                cerr << "File not found error. Exiting program." << endl;
                return false;
        }   
        return false;   
}
