#include "Book.h"

#include <iostream>



Book::Book(const std::string& name) :
	Element(name)
{
	std::cout << __FUNCTION__ << std::endl;
}

Book::~Book()
{
	std::cout << __FUNCTION__ << std::endl;
}
