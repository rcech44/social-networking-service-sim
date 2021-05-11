#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <random>

using std::string;

string TextGenerator(const char* text);
int NumberGenerator(int from, int to);

//
//	Text generator which returns random line of text file
//
inline string TextGenerator(const char* text)
{
	std::ifstream file(text);

	if (!file.is_open())
	{
		exit(-1);
	}

	string line;
	std::getline(file, line);
	int numberOfLines = std::stoi(line);		// na zacatku souboru je pocet radku
	int selectedRandomLine = NumberGenerator(1, numberOfLines);

	for (int i = 0; i < selectedRandomLine; i++)
	{
		std::getline(file, line);
	}

	return line;
}

//
//	Random number generator that returns integer from given boundary
//
inline int NumberGenerator(int from, int to)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}