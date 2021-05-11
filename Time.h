#pragma once
#include <string>
#include <random>
#include "UniversalObjectOutput.h"

using std::string;

//
//	This class serves as structure for time and can return it as simple string.
//
class Time : public UniversalObjectOutput
{
private:
	int second;												// contains number of seconds
	int minute;												// contains number of minutes
	int hour;												// contains number of hours
public:
	Time();													// constructs time randomly
	Time(int second, int minute, int year);					// constructs certain time with given details
	string ReturnAsString();								// returns time as string
};