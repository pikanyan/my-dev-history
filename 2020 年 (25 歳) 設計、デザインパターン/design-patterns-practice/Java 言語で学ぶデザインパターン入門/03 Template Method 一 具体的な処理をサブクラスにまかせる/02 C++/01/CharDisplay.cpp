#include "CharDisplay.h"

#include <iostream>



CharDisplay::CharDisplay(const char ch) :
	ch_(ch)
{
	std::cout << __FUNCTION__ << std::endl;
}

CharDisplay::~CharDisplay()
{
	std::cout << __FUNCTION__ << std::endl;
}

void CharDisplay::open()
{
	std::cout << "<<";
}

void CharDisplay::print()
{
	std::cout << ch_;
}

void CharDisplay::close()
{
	std::cout << ">>" << std::endl;
}
