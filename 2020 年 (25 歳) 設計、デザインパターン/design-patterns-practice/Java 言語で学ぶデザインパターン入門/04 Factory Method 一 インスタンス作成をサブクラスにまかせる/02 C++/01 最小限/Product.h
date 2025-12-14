#pragma once

class Product
{
public:
	explicit Product();
	virtual ~Product();

	virtual void use() = 0;
};
