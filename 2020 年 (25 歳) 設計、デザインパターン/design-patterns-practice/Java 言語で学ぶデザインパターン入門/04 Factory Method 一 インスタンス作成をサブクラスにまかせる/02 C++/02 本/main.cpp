#include "main.h"
#include "IDCardFactory.h"
#include "IDCard.h"

#include <iostream>



int main()
{
    auto idCardFactory = std::make_unique<IDCardFactory>();

    std::cout << std::endl;

    auto card0 = idCardFactory->create("‚Ò‚©‚É‚á‚ñ");
    auto card1 = idCardFactory->create("Œäâ”ü‹Õ");
    auto card2 = idCardFactory->create("ƒ‚ƒ‚");

    std::cout << std::endl;

    card0->use();
    card1->use();
    card2->use();

    std::cout << std::endl;



	return 0;
}
