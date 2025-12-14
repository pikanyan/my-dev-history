#include "main.h"
#include "Singleton.h"

#include <iostream>



int main()
{
    Singleton& obj1 = Singleton::instance();
    Singleton& obj2 = Singleton::instance();



    if (&obj1 == &obj2)
        std::cout << "obj1 と obj2 は同じインスタンスである" << std::endl;
    else
        std::cout << "obj1 と obj2 は同じインスタンスでない" << std::endl;



	return 0;
}
