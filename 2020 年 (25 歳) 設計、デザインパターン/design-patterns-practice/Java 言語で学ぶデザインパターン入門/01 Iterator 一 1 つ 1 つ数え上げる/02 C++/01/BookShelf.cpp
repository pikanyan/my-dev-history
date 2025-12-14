#include "BookShelf.h"

#include <iostream>



BookShelf::BookShelf()
{
	std::cout << __FUNCTION__ << std::endl;
}

BookShelf::~BookShelf()
{
	std::cout << __FUNCTION__ << std::endl;
}

std::unique_ptr<Iterator> BookShelf::iterator() const
{
	return std::make_unique<BookShelfIterator>(*this);
}
