#include "Element.h"

#include <iostream>



Element::Element(const std::string& name) :
	name_(name)
{
	std::cout << __FUNCTION__ << std::endl;
}

Element::~Element()
{
	std::cout << __FUNCTION__ << std::endl;
}

const std::string& Element::name() const
{
	return name_;
}
