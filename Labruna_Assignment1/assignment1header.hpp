// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 1
// The goal of this class is to head this assignment by declaring all functions
// and variables necessary for a proper Object-oriented solution.


#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef ASSIGNMENT1HEADER_HPP
#define ASSIGNMENT1HEADER_HPP


//Necessary constructor and destructor, functions and variables included with self-explanatory names, more info on functions in implementation file

class DNAFunctions
{
	public:
		DNAFunctions();
		~DNAFunctions();
		void FileReader(string );
		void PerformCalculations(string);
		void DNAWriter(bool);
		double gaussgenerator();
		void setsum(double );
		double getsum();
		void setmean(double );
		double getmean();
                void setvar(double );
                double getvar();
                void setstdev(double );
                double getstdev();
		
	
	private:
		double proba;
		double probc;
		double probt;
		double probg;
		double sum;
		double mean;
		double variance;
		double stdev;
		double nuccount;
		double a;
		double c;
		double t;
		double g;
		double aa;
		double ac;
		double at;
		double ag;
		double ca;
		double cc;
		double ct;
		double cg;
		double tc;
		double ta;
		double tt;
		double tg;
		double gt;
		double gc;
		double ga;
		double gg;
                double probaa;
                double probac;
                double probat;
                double probag;
                double probca;
                double probcc;
                double probct;
                double probcg;
                double probtc;
                double probta;
                double probtt;
                double probtg;
                double probgt;
                double probgc;
                double probga;
                double probgg;
		double linecount;
		double lettercount;
		double bigramcount;

};

#endif


