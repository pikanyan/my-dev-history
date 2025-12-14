#include "Item.h"

#include <iostream>



Item::Item(const std::string& caption) : 
	caption_(caption)
{
	std::cout << __FUNCTION__ << std::endl;
}

Item::~Item()
{
	std::cout << __FUNCTION__ << std::endl;
}
