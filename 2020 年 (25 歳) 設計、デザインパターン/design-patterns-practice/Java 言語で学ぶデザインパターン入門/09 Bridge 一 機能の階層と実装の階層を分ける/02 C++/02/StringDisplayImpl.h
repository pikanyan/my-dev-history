#pragma once

#include "DisplayImpl.h"

#include <string>
#include <iostream>



// ŽÀ‘•ƒNƒ‰ƒX
class StringDisplayImpl : public DisplayImpl
{
private:
    std::string str;
    int width;


public:
    StringDisplayImpl(const std::string&);

    void rawOpen() override;
    void rawPrint() override;
    void rawClose() override;

private:
    void printLine();
};
