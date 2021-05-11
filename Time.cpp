#include "Time.h"
#include <iostream>
#include <sstream>

Time::Time()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution_0_59(0, 59);
    std::uniform_int_distribution<int> distribution_0_23(0, 23);
    this->second = distribution_0_59(generator);
    this->minute = distribution_0_59(generator);
    this->hour = distribution_0_23(generator);
}

Time::Time(int second, int minute, int hour)
{
    this->second = second;
    this->minute = minute;
    this->hour = hour;
}

string Time::ReturnAsString()
{
    std::stringstream text;
    text << this->hour << ":" << this->minute << ":" << this->second;
    return text.str();
}
