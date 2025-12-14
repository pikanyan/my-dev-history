#include "UnderlinePen.h"



UnderlinePen::UnderlinePen(char ulchar) :
	ulchar_(ulchar)
{

}

UnderlinePen::~UnderlinePen()
{

}

void UnderlinePen::use(const std::string& str)
{
    int length = str.length();

    std::cout << "\"" << str << "\"" << std::endl;



    std::cout << " ";

    for (int i = 0; i < length; i++)
    {
        std::cout << ulchar_;
    }

    std::cout << std::endl;
}

std::unique_ptr<Product> UnderlinePen::clone()
{
    return std::make_unique<UnderlinePen>(*this);
}
