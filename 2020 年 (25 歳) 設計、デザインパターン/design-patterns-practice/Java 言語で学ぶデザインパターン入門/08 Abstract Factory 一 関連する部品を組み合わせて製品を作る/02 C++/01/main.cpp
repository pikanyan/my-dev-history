#include "main.h"

#include <iostream>
#include <memory>


/*
Abstract Factory ‚Ì–{¿‚Í
ˆÙ‚È‚ée‚Ì Product ‚Å‚È‚¯‚ê‚Î‚È‚ç‚È‚¢

“¯í‚Ìe‚Ìê‡
•¡”‚Ì Factory Method ‚ğ‚Â Factory ‚Ì‚æ‚¤‚Å‚ ‚é
*/

class Product
{
protected:
    std::string name_;

public:
    explicit Product(const std::string& name) :
        name_(name)
    {
    }

    virtual ~Product() = default;

    std::string get_name() const
    {
        return name_;
    }
};

class ProductA : public Product
{
public:
    using Product::Product;
};

class ProductB : public Product
{
public:
    using Product::Product;
};



template<typename T>
class Factory
{
public:
    virtual ~Factory() = default;

    std::unique_ptr<Product> create_product(const std::string& name) const
    {
        return std::make_unique<T>(name);
    }
};



int main()
{
    Factory<ProductA> factory1;
    Factory<ProductB> factory2;



    std::unique_ptr<Product> productA1 = factory1.create_product("ConcreteProduct A1");
    std::unique_ptr<Product> productA2 = factory1.create_product("ConcreteProduct A2");

    std::unique_ptr<Product> productB1 = factory2.create_product("ConcreteProduct B1");
    std::unique_ptr<Product> productB2 = factory2.create_product("ConcreteProduct B2");



    std::cout << productA1->get_name() << ", " << productA2->get_name() << std::endl;
    std::cout << productB1->get_name() << ", " << productB2->get_name() << std::endl;



    return 0;
}
