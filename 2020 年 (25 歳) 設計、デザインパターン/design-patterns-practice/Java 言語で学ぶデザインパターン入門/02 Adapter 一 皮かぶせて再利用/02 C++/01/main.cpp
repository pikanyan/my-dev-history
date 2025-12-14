#include "main.h"
#include "Print.h"
#include "PrintBanner.h"

#include <iostream>
#include <memory>



int main()
{
	std::unique_ptr<Print> p = std::make_unique<PrintBanner>("Hello");



	std::cout << std::endl;



	p->printWeak();
	p->printStrong();



	std::cout << std::endl;



	return 0;
}
