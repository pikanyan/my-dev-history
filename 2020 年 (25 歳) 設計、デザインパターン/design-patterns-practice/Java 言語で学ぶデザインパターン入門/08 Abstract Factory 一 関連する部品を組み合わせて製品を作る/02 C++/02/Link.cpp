#include "Link.h"

#include <iostream>



Link::Link(const std::string& caption, const std::string& url) :
	Item(caption), 
	url_(url)
{
	std::cout << __FUNCTION__ << std::endl;
}

Link::~Link()
{
	std::cout << __FUNCTION__ << std::endl;
}
