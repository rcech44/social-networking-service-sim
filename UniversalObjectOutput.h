#pragma once
#include <string>

using std::string;

//
//	This class serves as pure abstract class that returns universal info about child classes.
//
class UniversalObjectOutput
{
public:
	UniversalObjectOutput();					// empty constructor
	virtual string ReturnAsString();			// returns basic info of the object
};