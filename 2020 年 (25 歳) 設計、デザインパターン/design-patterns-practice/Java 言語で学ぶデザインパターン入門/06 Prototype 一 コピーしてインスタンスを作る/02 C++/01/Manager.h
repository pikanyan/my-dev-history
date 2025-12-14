#pragma once

#include "Product.h"

#include <map>
#include <memory>
#include <string>



class Manager
{
private:
    std::map<std::string, std::unique_ptr<Product>> showcase_;

public:
    std::unique_ptr<Product> create_product(const std::string&);
    void register_product(const std::string&, std::unique_ptr<Product>);
};
