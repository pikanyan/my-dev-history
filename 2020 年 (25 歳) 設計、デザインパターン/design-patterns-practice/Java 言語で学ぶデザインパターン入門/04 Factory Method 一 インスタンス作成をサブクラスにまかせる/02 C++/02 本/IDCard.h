#pragma once

#include "Product.h"

#include <string>



class IDCard : public Product
{
public:
	explicit IDCard(const std::string&);
	virtual ~IDCard();

	void use() override;
};
