#include "StringDisplay.h"

#include <iostream>



StringDisplay::StringDisplay(const std::string& str) :
	str_(str)
{
	std::cout << __FUNCTION__ << std::endl;
}

StringDisplay::~StringDisplay()
{
	std::cout << __FUNCTION__ << std::endl;
}

void StringDisplay::open()
{
	printLine();
}

void StringDisplay::print()
{
	std::cout << "|" << str_ << "|" << std::endl;
}

void StringDisplay::close()
{
	printLine();
}

void StringDisplay::printLine()
{
	std::cout << "+";

	for (int i = 0; i < str_.length(); i++)
		std::cout << "-";

	std::cout << "+" << std::endl;
}
