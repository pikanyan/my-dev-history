#pragma once

#include "Product.h"

#include <iostream>
#include <memory>
#include <string>



class UnderlinePen : public Product
{
private:
	char ulchar_;

public:
	UnderlinePen(char);
    ~UnderlinePen();

	void use(const std::string&) override;
	std::unique_ptr<Product> clone() override;
};
