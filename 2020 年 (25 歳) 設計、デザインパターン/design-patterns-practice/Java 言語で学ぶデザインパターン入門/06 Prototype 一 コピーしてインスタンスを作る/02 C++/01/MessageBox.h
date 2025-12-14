#pragma once

#include "Product.h"

#include <iostream>
#include <memory>
#include <string>



class MessageBox : public Product
{
private:
    char decochar_;

public:
    MessageBox(char);

    void use(const std::string&) override;
    std::unique_ptr<Product> clone() override;
};
