#pragma once

class Singleton
{
private:
    explicit Singleton();

    virtual ~Singleton();

public:
    static Singleton& instance();
};
