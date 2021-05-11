#pragma once
#include <string>
#include <random>
#include "UniversalObjectOutput.h"

using std::string;

//
//	This class serves as structure for date and can return it as simple string.
//
class Date : public UniversalObjectOutput
{
private:
	int day;										// contains day number
	int month;										// contains month number
	int year;										// contains year number
public:
	Date();											// constructs random date
	Date(int day, int month, int year);				// constructs date with given details
	string ReturnAsString();						// returns date as string
};