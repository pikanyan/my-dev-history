#pragma once

#include <memory>
#include <string>



class Product
{
public:
    explicit Product();
    virtual ~Product();

    virtual void use(const std::string&) = 0;
    virtual std::unique_ptr<Product> clone() = 0;
};
