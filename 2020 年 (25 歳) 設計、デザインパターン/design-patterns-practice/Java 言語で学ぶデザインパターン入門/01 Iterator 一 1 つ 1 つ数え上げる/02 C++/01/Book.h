#pragma once

#include "Element.h"



class Book : public Element
{
public:
	explicit Book(const std::string&);
	virtual ~Book();
};
