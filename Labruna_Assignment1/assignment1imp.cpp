// Nicholas LaBruna
// 002273241
// labru104@mail.chapman.edu
// CPSC 350-02
// Assignment 1
// The goal of this class is to implement all functions required for proper main functionality. 
// The methods are organized and commented.
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include "Assignment1Header.hpp"
using namespace std;

//initializing all variables declared in the main function in this constructor

DNAFunctions::DNAFunctions()
{
	sum = 0;
	mean = 0;
	variance = 0;
	stdev = 0;
	proba = 0;
	probc = 0;
	probt = 0;
	probg = 0;
	a = 0;
	c = 0;
	t = 0;
	g = 0;
	aa = 0;
	ac = 0;
	at = 0;
	ag = 0;
	ca = 0;
	cc = 0;
	ct = 0;
	cg = 0;
	tc = 0;
	ta = 0;
	tt = 0;
	tg = 0;
	gt = 0;
	gc = 0;
	ga = 0;
	gg = 0;
        probaa = 0;
        probac = 0;
        probat = 0;
        probag = 0;
        probca = 0;
        probcc = 0;
        probct = 0;
        probcg = 0;
        probtc = 0;
        probta = 0;
        probtt = 0;
        probtg = 0;
        probgt = 0;
        probgc = 0;
        probga = 0;
        probgg = 0;
	linecount = 0;
	lettercount = 0;
	bigramcount = 0;
}

//necessary destructor

DNAFunctions::~DNAFunctions()
{
}

//this functions takes in the file name as an argument and takes in all of the necessary information to perform the calculations required. It counts bigrams and nucleotides and computes the sum and mean.

void DNAFunctions::FileReader(string fname)
{       
        string dnainput;
        ifstream inputdnafile;
	char charchecker;
	char oldchar;
        inputdnafile.open(fname);
        if(inputdnafile.is_open())
        {
                while(getline(inputdnafile, dnainput))
                {
			linecount++;
			lettercount += dnainput.length();
			for(int i = 0; i < dnainput.length(); ++i)
			{				
				charchecker = dnainput.at(i);
				charchecker  = tolower(charchecker);
				if(i > 1)
				{
					oldchar = dnainput.at(i-1);
					oldchar = tolower(oldchar);
					if(oldchar == 'a' && charchecker == 'a')
					{
						aa++;
						bigramcount++;
					}
                                        else if(oldchar == 'a' && charchecker == 'c')
                                        {
                                                ac++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'a' && charchecker == 't')
                                        {
                                                at++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'a' && charchecker == 'g')
                                        {
                                                ag++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'c' && charchecker == 'a')
                                        {
                                                ca++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'c' && charchecker == 'c')
                                        {
                                                cc++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'c' && charchecker == 't')
                                        {
                                                ct++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'c' && charchecker == 'g')
                                        {
                                                cg++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 't' && charchecker == 'c')
                                        {
                                                tc++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 't' && charchecker == 'a')
                                        {
                                                ta++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 't' && charchecker == 't')
                                        {
                                                tt++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 't' && charchecker == 'g')
                                        {
                                                tg++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'g' && charchecker == 't')
                                        {
                                                gt++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'g' && charchecker == 'c')
                                        {
                                                gc++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'g' && charchecker == 'a')
                                        {
                                                ga++;
                                                bigramcount++;
                                        }
                                        else if(oldchar == 'g' && charchecker == 'g')
                                        {
                                                gg++;
                                                bigramcount++;
                                        }
				}
						
				switch(charchecker)
				{
					case 'a':
						a++;
						break;
					case 'c':
						c++;
						break;
					case 't':
						t++;
						break;
					case 'g':
						g++;
						break;
					default:
						break;
				}
			}
		}
		sum = lettercount;
		mean = lettercount/linecount;
        }
        else
        {
                cerr << "Unable to open dna file given in command line. Exiting program." << endl;
		
        }
        inputdnafile.close();
}


// This function performs the sum, mean, variance, standard deviation and probabiliy calculations. It uses numbers taken in from the DNAReader file. 

void DNAFunctions::PerformCalculations(string fname)
{
        sum = lettercount;
        mean = lettercount/linecount;

	ifstream inputdnafile;
	inputdnafile.open(fname);
	string dnainput;
	double thenum = 0;
        double varsum = 0;
        double base = 0;
	if(inputdnafile.is_open())
	{
		while(getline(inputdnafile, dnainput))
		{
			base = (dnainput.length() - mean);
			thenum = pow(base, 2); 
			varsum += thenum;
		}    
		    
		variance = (varsum/linecount);
		stdev = sqrt(variance);

		proba = a/lettercount;
		probc = c/lettercount;
		probt = t/lettercount;
		probg = g/lettercount;

		probaa = aa/bigramcount;
		probac = ac/bigramcount;
		probat = at/bigramcount;
		probag = ag/bigramcount;
		probca = ca/bigramcount;
		probcc = cc/bigramcount;
		probct = ct/bigramcount;
		probcg = cg/bigramcount;
		probtc = tc/bigramcount;
		probta = ta/bigramcount;
		probtt = tt/bigramcount;
		probtg = tg/bigramcount;
		probgt = gt/bigramcount;
		probgc = gc/bigramcount;
		probga = ga/bigramcount;
		probgg = gg/bigramcount;

        }   
        else
        {   
                cerr << "Unable to open dna file given in command line. Exiting program." << endl;
    
        }   
        inputdnafile.close();
}
	
//This function writes to the DNA file using the probability calculated in the DNAReader profile. The boolean decides whether it appends or truncates, and 

void DNAFunctions::DNAWriter(bool a)
{
	ofstream newdnafile;
	if(a == true)
	{
		newdnafile.open("nicklabruna.out", ofstream::out | ofstream::app);
	}
	else
	{
		newdnafile.open("nicklabruna.out");
	}
	if(newdnafile.is_open())
	{
		newdnafile << "Nick Labruna \n 002273241 \n labru104@mail.chapman.edu \n CPSC 350-02 \n \n";
		newdnafile << "Sum : " << sum << "\n" <<  "Mean: " << mean << "\n";
		newdnafile << "Variance: " << variance << "\n" << "Standard Deviation: " << stdev << "\n";

		newdnafile << "Relative frequency of a: " << proba  << "\n" <<  "Relative frequency of c: " << probc << "\n";
		newdnafile << "Relative frequency of t: " << probt << "\n" << "Relative frequency of g: " << probg << "\n \n";

		newdnafile << "Relative bigram frequency of aa: "<< probaa << "\n" <<  "Relative bigram frequency ac: " << probac << "\n";
		newdnafile << "Relative bigram frequency of at: "<< probat << "\n" <<  "Relative bigram frequency ag: " << probag << "\n";
		newdnafile << "Relative bigram frequency of ca: "<< probca << "\n" <<  "Relative bigram frequency cc: " << probcc << "\n";
		newdnafile << "Relative bigram frequency of ct: "<< probct << "\n" <<  "Relative bigram frequency cg: " << probcg << "\n";
		newdnafile << "Relative bigram frequency of tc: "<< probtc << "\n" <<  "Relative bigram frequency ta: " << probta << "\n";
		newdnafile << "Relative bigram frequency of tt: "<< probtt << "\n" <<  "Relative bigram frequency tg: " << probtg << "\n";
		newdnafile << "Relative bigram frequency of gt: "<< probgt << "\n" <<  "Relative bigram frequency gc: " << probgc << "\n";
		newdnafile << "Relative bigram frequency of ga: "<< probga << "\n" <<  "Relative bigram frequency gg: " << probgg << "\n \n";
		
		//Making it so I can use the crand function between 1 and 100 by converting relative frequency to a percentage

		int afunc = (proba * 100.0 + 0.5);
		int cfunc = ((probc * 100 + 0.5) + afunc);
		int tfunc = ((probt * 100 + 0.5) + cfunc);
		int gfunc = ((probg * 100 + 0.5) + tfunc);
		for(int i = 0; i < 1000; ++i)
		{
			int linelength = gaussgenerator() + 0.5;
			
			for(int j = 0; j < linelength; ++j)
			{
				int randnum = (rand() % 100);
				if(randnum <= afunc)
				{
					newdnafile << "A";
				}
				else if(randnum <= cfunc && randnum > afunc)
				{
					newdnafile << "C";
				}
				else if(randnum <= tfunc && randnum > cfunc)
				{
					newdnafile << "T";
				}
				else if(randnum <= gfunc && randnum > tfunc)
				{
					newdnafile << "G";
				}
				else
				{
					cout << "error" << endl;
				}
			}
			newdnafile << "\n";
			
		}		

		 
	}
	else
	{
		cerr << "Fatal error: Unable to write to file. Exiting program." << endl;
	}
	newdnafile.close();
	
}


//this method generates a random number using the gaussian distribution specified in the assignment instructions
double DNAFunctions::gaussgenerator()
{
//initializing local variables
	double rand2 = 0.0;
	int rand2_cached = 0;
		if (!rand2_cached)
	        {
			double var1, var2, r;
			do
			{
			    var1 = 2.0*rand()/RAND_MAX - 1;
			    var2 = 2.0*rand()/RAND_MAX - 1;

			    r = var1*var1 + var2*var2;
			}
			//perform the gaussian distribution and return the result
			while (r > 1.0 || r == 0.0);
			{
				double d = sqrt(-2.0*log(r)/r);
				double n1 = var1*d;
		    		rand2 = var2*d;
		    		double thenum = n1 * stdev + mean;
		    		rand2_cached = 1;
		    		return thenum;
			}
	        }
	    else
	    {
		rand2_cached = 0;
		return rand2*stdev + mean;
	    }
		
}

//getters and setters for important variables

void DNAFunctions::setsum(double su)
{
	sum = su;
}

double DNAFunctions::getsum()
{
	return sum;
}

void DNAFunctions::setmean(double mea)
{
	mean = mea;
}

double DNAFunctions::getmean()
{
	return mean;
}

void DNAFunctions::setvar(double var)
{
	variance = var;
}

double DNAFunctions::getvar()
{
	return variance;
}

void DNAFunctions::setstdev(double std)
{
	stdev = std;
}

double DNAFunctions::getstdev()
{
	return stdev;
} 
