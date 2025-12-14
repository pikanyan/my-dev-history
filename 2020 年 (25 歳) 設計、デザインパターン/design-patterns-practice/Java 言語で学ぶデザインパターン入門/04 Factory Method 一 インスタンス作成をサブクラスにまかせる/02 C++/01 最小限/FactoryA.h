#pragma once

#include "Factory.h"

class Product;



class FactoryA : public Factory
{
public:
	explicit FactoryA();
	virtual ~FactoryA();

	std::unique_ptr<Product> create() override;
};
