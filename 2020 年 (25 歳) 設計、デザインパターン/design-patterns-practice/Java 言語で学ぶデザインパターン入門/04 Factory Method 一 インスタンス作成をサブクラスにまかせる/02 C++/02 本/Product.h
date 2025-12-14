#pragma once

#include <string>



class Product
{
protected:
	const std::string owner_;

public:
	explicit Product(const std::string&);
	virtual ~Product();

	virtual void use() = 0;
};
