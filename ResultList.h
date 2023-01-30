/*

Class for Linked list which holds the results

*/
#pragma once
#include "Result.h"

class ResultList
{
public:
	Result* last; //pointer to the last result in the list
	Result* first; //pointer to the first result in the list

	ResultList(); //default constructor

	void addResult(TN*); //function to add new result to list
	void viewResult(); //function to display results
	bool empty(); //function to return list's empty status
	void printDescending(); //function to print results to output file
};