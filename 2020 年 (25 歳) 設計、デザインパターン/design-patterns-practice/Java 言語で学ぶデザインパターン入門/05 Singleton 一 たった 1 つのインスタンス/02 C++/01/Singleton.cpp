#include "Singleton.h"

#include <iostream>



Singleton::Singleton()
{
    std::cout << __FUNCTION__ << std::endl;
}

Singleton::~Singleton()
{
    std::cout << __FUNCTION__ << std::endl;
}

Singleton& Singleton::instance()
{
    static Singleton singleton;

    return singleton;
}
