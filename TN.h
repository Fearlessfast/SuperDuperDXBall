/*

Class for Tree Node class

*/
#pragma once
#include <string>
using namespace std;

#define MAX_CHARS 26

class TN
{
public:
	string word; //word information
	int freq; //frequency of the word
	TN* child[MAX_CHARS]; //child nodes of the tree node
	int id; //id for the node, for research purposes

	TN(); //default constructor
	
	TN& operator=(TN*); //assingment operator overloading
};