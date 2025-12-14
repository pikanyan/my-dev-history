#include "main.h"

#include <iostream>
#include <memory>



class Singleton
{
private:
    Singleton()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

public:
    ~Singleton()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

public:
    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;

    static Singleton& get_instance()
    {
        static Singleton instance;

        return instance;
    }
};



int main()
{
    Singleton& instanceA = Singleton::get_instance();
    Singleton& instanceB = Singleton::get_instance();



    return 0;
}



// copy constructor
// Singleton(const Singleton&) = delete;

// copy ‘ã“ü‰‰ŽZŽq
// Singleton& operator=(const Singleton&) = delete;
