#pragma once

#include "Builder.h"

#include <vector>



class Director
{
private:
	Builder* builder;

public:
	Director(Builder* builder);

	void construct();
};
