#include "ProductA.h"

#include <iostream>



ProductA::ProductA()
{
	std::cout << __FUNCTION__ << std::endl;
}

ProductA::~ProductA()
{
	std::cout << __FUNCTION__ << std::endl;
}

void ProductA::use()
{
	std::cout << "Product A is being used." << std::endl;
}
