#pragma once

#include "Factory.h"

class Product;



class IDCardFactory : public Factory
{
public:
	explicit IDCardFactory();
	virtual ~IDCardFactory();

	std::unique_ptr<Product> create(const std::string&) override;
};
