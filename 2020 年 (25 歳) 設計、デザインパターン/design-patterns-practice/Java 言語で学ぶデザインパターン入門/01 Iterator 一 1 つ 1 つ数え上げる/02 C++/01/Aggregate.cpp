#include "Aggregate.h"

#include <iostream>



Aggregate::Aggregate()
{
	std::cout << __FUNCTION__ << std::endl;
}

Aggregate::~Aggregate()
{
	std::cout << __FUNCTION__ << std::endl;
}

int Aggregate::size() const
{
	return elements_.size();
}

void Aggregate::append(std::unique_ptr<Element> element)
{
	elements_.push_back(std::move(element));
}

const Element& Aggregate::element(int index) const
{
	if (index < 0 || elements_.size() <= index)
		throw std::out_of_range("Index out of range");

	return *elements_[index].get();
}
