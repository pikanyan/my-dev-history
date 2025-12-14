#include "main.h"
#include "FactoryA.h"
#include "ProductA.h"

#include <iostream>



int main()
{
	std::unique_ptr<Factory> factory = std::make_unique<FactoryA>();
	std::unique_ptr<Product> product = factory->create();

	std::cout << std::endl;

	if (product)
		product->use();

	std::cout << std::endl;



	return 0;
}
