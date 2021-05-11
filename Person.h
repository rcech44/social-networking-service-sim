#pragma once
#include <string>
#include "Date.h"

using std::string;

//
//	This class holds information about person and can return multiple info
//
class Person
{
protected:
	int personID;												// unique ID of person
	string name;												// name of the person
	string address;												// address of the person
	Date date_of_birth;											// date of birth
public:
	Person();													// constructs Person with random values
	Person(string name, string address, Date date);				// constructs Person with given details
	int GetID();												// returns ID of the person
	string GetName();											// returns name of the person
	string GetDate();											// returns date of birth of the person
};