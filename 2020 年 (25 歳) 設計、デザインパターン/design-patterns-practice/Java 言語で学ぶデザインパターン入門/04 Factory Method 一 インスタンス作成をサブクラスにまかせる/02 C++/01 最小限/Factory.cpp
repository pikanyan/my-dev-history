#include "Factory.h"
#include "Product.h"

#include <iostream>



Factory::Factory()
{
	std::cout << __FUNCTION__ << std::endl;
}

Factory:: ~Factory()
{
	std::cout << __FUNCTION__ << std::endl;
}
