#pragma once

#include <memory>
#include <string>

class Product;



class Factory
{
public:
	explicit Factory();
	virtual ~Factory();

	virtual std::unique_ptr<Product> create(const std::string&) = 0;
};
