#include "BookShelfIterator.h"

#include <iostream>



BookShelfIterator::BookShelfIterator(const Aggregate& aggregate) :
	Iterator(aggregate)
{
	std::cout << __FUNCTION__ << std::endl;
}

BookShelfIterator::~BookShelfIterator()
{
	std::cout << __FUNCTION__ << std::endl;
}
