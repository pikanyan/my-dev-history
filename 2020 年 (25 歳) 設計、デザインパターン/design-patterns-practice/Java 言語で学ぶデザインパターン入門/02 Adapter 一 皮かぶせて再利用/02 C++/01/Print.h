#pragma once

class Print
{
public:
    explicit Print();
    virtual ~Print();

    virtual void printWeak() = 0;
    virtual void printStrong() = 0;
};
