#include <iostream>
#include <fstream>
#include "ResultList.h"
#include "Result.h"
using namespace std;

ResultList::ResultList()
{
	//default constructor
	first = NULL;
	last = NULL;
}

void ResultList::addResult(TN* res)
{
	if (first == NULL) //if the list is empty
	{
		first = new Result(res);
		last = first;
		first->next = last;
		last->next = NULL;
		last->prev = NULL;
	}
	else //if there is an existing result
	{
		last->next = new Result(res);
		last->next->prev = last;
		last = last->next;
		last->next = NULL;
	}
}

void ResultList::viewResult()
{
	Result point(*first);
	ofstream out("HamCokelek.txt", ios::out); //output file for intermediate results

	while (true) //write results to file until the end of the list
	{
		out << "Result:" << point.result->word << " freq:" << point.result->freq << endl;
		point = *point.next;

		if (point.next == NULL)
		{
			break;
		}
	}
}

bool ResultList::empty()
{
	if (first->next == NULL && last->next == NULL) //if the list is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ResultList::printDescending()
{
	Result point;
	Result max;
	ofstream out("Sorted.txt", ios::out); //output file for results descending in frequency values

	out << "Word-----------freq" << endl;

	while (!empty()) //until the list is empty, remove result
	{
		point = *first;
		max = point;
		while (point.next != NULL) //until the entire list is compared
		{
			if (point.next->result->freq>max.result->freq)
			{
				max = *point.next;
				point = *point.next;
			}
			else
			{
				point = *point.next;
			}
		}

		
		out << max.result->word; //output the remaining max result
		for (int i = 0; i < 35-max.result->word.length(); i++) //arrange spacings
		{
			out << " ";
		}
		out << max.result->freq << endl;

		if (max.prev == NULL) //if the result is at the beginning of the list
		{
			first = max.next;
			first->prev = NULL;
			
		}
		else //if the result is at the other parts of the list
		{
			max.prev->next = max.next;
			max.next->prev = max.prev;
		}
	}

}