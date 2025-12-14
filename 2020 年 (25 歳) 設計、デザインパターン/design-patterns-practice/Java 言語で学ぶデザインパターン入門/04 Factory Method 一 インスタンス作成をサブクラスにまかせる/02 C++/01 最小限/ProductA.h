#pragma once

#include "Product.h"



class ProductA : public Product
{
public:
	explicit ProductA();
	virtual ~ProductA();

	void use() override;
};
