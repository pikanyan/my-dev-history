#include "main.h"
#include "CharDisplay.h"
#include "StringDisplay.h"

#include <iostream>



int main()
{
    CharDisplay d1('H');
    StringDisplay d2("Hello, World");
    StringDisplay d3("‚±‚ñ‚É‚¿‚Í");

    std::cout << std::endl;

    d1.display();
    d2.display();
    d3.display();

    std::cout << std::endl;



	return 0;
}
