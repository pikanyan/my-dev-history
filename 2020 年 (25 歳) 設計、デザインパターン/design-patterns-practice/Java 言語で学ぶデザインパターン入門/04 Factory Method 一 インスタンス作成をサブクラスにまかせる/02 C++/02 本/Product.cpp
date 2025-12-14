#include "Product.h"

#include <iostream>



Product::Product(const std::string& owner) :
	owner_(owner)
{
	std::cout << __FUNCTION__ << std::endl;
}

Product::~Product()
{
	std::cout << __FUNCTION__ << std::endl;
}
