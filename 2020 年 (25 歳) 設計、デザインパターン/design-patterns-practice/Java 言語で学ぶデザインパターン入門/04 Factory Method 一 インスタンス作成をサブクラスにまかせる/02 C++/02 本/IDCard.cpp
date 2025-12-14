#include "IDCard.h"

#include <iostream>



IDCard::IDCard(const std::string& owner) :
	Product(owner)
{
	std::cout << __FUNCTION__ << std::endl;

	std::cout << owner << " のカードを作ります。" << std::endl;
}

IDCard::~IDCard()
{
	std::cout << __FUNCTION__ << std::endl;
}

void IDCard::use()
{
	std::cout << owner_ << " のカードを使います。" << std::endl;
}
