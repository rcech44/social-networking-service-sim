#include "Date.h"
#include <iostream>
#include <sstream>

Date::Date()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution_1_31(1, 31);
    std::uniform_int_distribution<int> distribution_1_12(1, 12);
    std::uniform_int_distribution<int> distribution_1950_2020(1950, 2020);
    this->day = distribution_1_31(generator);
    this->month = distribution_1_12(generator);
    this->year = distribution_1950_2020(generator);
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

string Date::ReturnAsString()
{
    std::stringstream text;
    text << this->day << "." << this->month << "." << this->year;
    return text.str();
}
