#include "FactoryA.h"
#include "ProductA.h"

#include <iostream>



FactoryA::FactoryA()
{
	std::cout << __FUNCTION__ << std::endl;
}

FactoryA:: ~FactoryA()
{
	std::cout << __FUNCTION__ << std::endl;
}

std::unique_ptr<Product> FactoryA::create()
{
	return std::make_unique<ProductA>();
}
