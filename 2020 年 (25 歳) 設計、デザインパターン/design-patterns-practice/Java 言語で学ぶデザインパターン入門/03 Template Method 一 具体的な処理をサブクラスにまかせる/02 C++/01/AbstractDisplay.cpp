#include "AbstractDisplay.h"

#include <iostream>



AbstractDisplay::AbstractDisplay()
{
	std::cout << __FUNCTION__ << std::endl;
}

AbstractDisplay::~AbstractDisplay()
{
	std::cout << __FUNCTION__ << std::endl;
}

void AbstractDisplay::display()
{
	open();

	for (int i = 0; i < 5; i++)
		print();

	close();
}
