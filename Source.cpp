#include <iostream>
#include <string>
#include <fstream>
#include "TN.h" //tree node class
#include "ResultList.h" //linked results list class
#include "Word.h" //word manipulating class
#include "Timer.h" //timer class
using namespace std;


void trie(TN&,string,ResultList&); //function for constructing Tree structure
int unique = 0; //counter for unique words

int main()
{
	TN root; //root node
	ResultList list; //result list
	ifstream in("Hamlet.txt", ios::in); //stream object for reading input file
	string input; //temporary holder variable while reading file
	int counter=0; //total word counter
	Timer t; //timer for calculating time

	if (!in) //if the file cannot be opened, exit
	{
		cout << "File cannot be opened";
		return 476;
	}
	
	t.start();
	while (in) //until the end of file
	{
		in >> input; //read a string

		Word temp(input); //send the string to word object
		temp.clean(); //clean the word from punctuation marks

		if (temp.word.length()>1)
		{
			trie(root, temp.word, list); //add new word to tree
			counter++; //increment total word counter
		}

	}
	t.stop();

	cout << "Completed parsing input file: " << t.time() << "ms" << endl;

	//list.viewResult(); //output intermediate frequenct results to file
	t.start();
	list.printDescending(); //output sorted frequency results
	t.stop();

	cout << "Completed sorting results: " << t.time() << "ms" << endl;
	cout << "Count:" << counter << endl;
	cout << "Unique:" << unique << endl;


	system("pause");
	return 674;
}

void trie(TN &root, string test, ResultList& list)
{
	TN* temp;

	if (root.child[test[0] - 97] == NULL) //start from first node according to the first letter of the word
	{
		root.child[test[0] - 97] = new TN();
	}

	temp = root.child[test[0] - 97]; 
	
	int i = 1;
	while (test[i] != NULL) //iterate until the end of word
	{
		//parse through the tree until the end of the word
		if (temp->child[test[i] - 97] == NULL)
		{
			temp->child[test[i] - 97] = new TN();
		}
		temp = temp->child[test[i] - 97];
		i++;
	}

	temp->word = test;
	temp->freq++;

	if (temp->freq < 2) //if the word is first found, add it to the results
	{
		list.addResult(temp);
		unique++;
	}
}