#include "IDCardFactory.h"
#include "IDCard.h"

#include <iostream>



IDCardFactory::IDCardFactory()
{
	std::cout << __FUNCTION__ << std::endl;
}

IDCardFactory::~IDCardFactory()
{
	std::cout << __FUNCTION__ << std::endl;
}

std::unique_ptr<Product> IDCardFactory::create(const std::string& owner)
{
	std::cout << __FUNCTION__ << std::endl;

	return std::make_unique<IDCard>(owner);
}
