#include "Person.h"
#include "Generators.h"
#include "Date.h"

Person::Person()
{
    this->personID = NumberGenerator(0, INT32_MAX);
    this->name = TextGenerator("names.txt");
    this->address = TextGenerator("addresses.txt");
    this->date_of_birth = Date();
}

Person::Person(string name, string address, Date date)
{
    this->personID = NumberGenerator(0, INT32_MAX);
    this->name = name;
    this->address = address;
    this->date_of_birth = date;
}

int Person::GetID()
{
    return this->personID;
}

string Person::GetName()
{
    return this->name;
}

string Person::GetDate()
{
    return this->date_of_birth.ReturnAsString();
}
