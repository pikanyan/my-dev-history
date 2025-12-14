#include "Iterator.h"

#include <iostream>



Iterator::Iterator(const Aggregate& aggregate) :
	aggregate_(aggregate),
	index_(0)
{
	std::cout << __FUNCTION__ << std::endl;
}

Iterator::~Iterator()
{
	std::cout << __FUNCTION__ << std::endl;
}

bool Iterator::hasNow() const
{
	return index_ < aggregate_.size();
}

const Element& Iterator::now() const
{
	if (aggregate_.size() <= index_)
		throw std::out_of_range("No more elements");

	return aggregate_.element(index_);
}

void Iterator::nextNow()
{
	if (aggregate_.size() <= index_)
		throw std::out_of_range("No more elements");

	index_++;
}
