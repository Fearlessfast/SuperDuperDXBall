/*

Class for storing the frequency result for single word

*/
#pragma once
#include "TN.h"

class Result
{
public:
	Result* next; //pointer to next result
	Result* prev; //pointer to previous result
	TN* result; //Tree node storing the word and frequency

	Result(); //default constructor
	Result(TN*); //constuctor with TreeNode parameter

};