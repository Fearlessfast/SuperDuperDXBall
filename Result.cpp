#include "Result.h"

Result::Result()
{
	//assing null values to variables
	result = NULL;
	next = NULL;
	prev = NULL;
}

Result::Result(TN* res)
{
	//assing node's values to variables
	result = res;
	next = NULL;
	prev = NULL;
}
