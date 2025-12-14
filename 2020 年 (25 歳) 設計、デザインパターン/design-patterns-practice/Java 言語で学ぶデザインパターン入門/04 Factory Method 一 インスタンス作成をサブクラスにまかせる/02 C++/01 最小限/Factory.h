#pragma once

#include <memory>

class Product;



class Factory
{
public:
	explicit Factory();
	virtual ~Factory();

	virtual std::unique_ptr<Product> create() = 0;
};
