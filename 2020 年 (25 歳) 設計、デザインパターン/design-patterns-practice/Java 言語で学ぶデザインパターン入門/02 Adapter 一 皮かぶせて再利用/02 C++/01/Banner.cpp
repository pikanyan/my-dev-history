#include "Banner.h"

#include <iostream>



Banner::Banner(const std::string& str) :
	str_(str)
{
	std::cout << __FUNCTION__ << std::endl;
}

Banner::~Banner()
{
	std::cout << __FUNCTION__ << std::endl;
}

void Banner::show_withParen() const
{
	std::cout << "(" << str_ << ")" << std::endl;
}

void Banner::show_withAster() const
{
	std::cout << "*" << str_ << "*" << std::endl;
}
