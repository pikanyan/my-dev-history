#include "StringDisplayImpl.h"

StringDisplayImpl::StringDisplayImpl(const std::string& string) :
    str(string), width(string.length())
{
}

void  StringDisplayImpl::rawOpen()
{
    printLine();
}

void  StringDisplayImpl::rawPrint()
{
    // In C++, you need to explicitly flush the buffer using `std::endl` or `std::flush`.
    // Otherwise, the output might not be immediately visible on the console.
    std::cout << "|" << str << "|\n";
}

void  StringDisplayImpl::rawClose()
{
    printLine();
}

void StringDisplayImpl::printLine()
{
    std::cout << "+";

    for (int i = 0; i < width; ++i)
    {
        std::cout << "-";
    }

    std::cout << "+\n";
}
