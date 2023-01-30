/*

Class for manipulating input words

*/
#pragma once
#include <string>
using namespace std;

class Word
{
public:
	string word; //content

	Word(); //Default constructor
	Word(string); //Constructor with string parameter

	void clean(); //function for cleaning punctuating marks
	bool hybrid(); //function for returning word's status, whether it is composed of multiple words or not
	void conc(); //function for concatenating hybrid words
};