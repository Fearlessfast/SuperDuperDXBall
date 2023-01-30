#include <iostream>
#include "TN.h"
using namespace std;

int ID = 0;

TN::TN()
{
	word = "";
	freq = 0;
	id = ID++;
	
	for (int i = 0; i < MAX_CHARS; i++)
	{
		child[i] = NULL;
	}
}

TN& TN::operator=(TN* t)
{	
	word = t->word;	
	freq = t->freq;	
	id = t->id;

	for (int i = 0; i < 26; i++)
	{
		child[i] = t->child[i];
	}
	
	return *this;
}


