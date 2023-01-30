#include "Word.h"
#include <iostream>
#include <string>

Word::Word()
{
	//default constructor, null string value
	word = "";
}

Word::Word(string s)
{
	//assing parameter's value to word
	word = s;
}

void Word::clean()
{
	for (int i = 0; i < word.length(); i++)
	{
		//if there is a punctuation mark in the word, exchange it with *
		if ((word[i] <65) || (word[i] > 90 && word[i]<97) || (word[i]>122))
		{
			word[i] = '*';
		}
		else if (word[i]>64 && word[i]<91)
		{
			//if the character is upper case, lower it
			word[i] = word[i] + 32;
		}
	}

	//if there is * at the beginning of the word
	if (word[0] == '*')
	{
		word.erase(word.begin());
		if (word.size() == 0)
		{
			return;
		}
	}

	//erase * until there is none at the end
	while (word[word.length() - 1] == '*')
	{
		word.erase(word.begin() + word.length() - 1);
		if (word.size() == 0)
		{
			return;
		}
	}

	//clean apostrophe and it's addition
	if (word.length()>2 && word[word.length() - 2] == '*')
	{
		word.erase(word.begin() + word.length() - 1);
		word.erase(word.begin() + word.length() - 1);
		if (word.size() == 0)
		{
			return;
		}
	}

	//if the word is hybrid, concatenate
	if (hybrid())
	{
		conc();
	}
}

bool Word::hybrid()
{
	//if there is a * in the middle of the word, return true
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == '*')
		{
			return true;
		}
	}
	return false;
}

void Word::conc()
{
	//clean the * in the hybrid word
	int i = 0;
	while (i<word.length())
	{
		if (word[i] == '*')
		{
			word.erase(word.begin() + i);
			i = 0;
		}
		else
		{
			i++;
		}		
	}
}
