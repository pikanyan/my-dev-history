#include "main.h"

#include <iostream>
#include <memory>



class ProductA
{
protected:
    std::string _part1;
    std::string _part2;

public:
    virtual ~ProductA() = default;

    void part1(const std::string& part1)
    {
        _part1 = part1;
    }

    void part2(const std::string& part2)
    {
        _part2 = part2;
    }

    std::string part1() const
    {
        return _part1;
    }

    std::string part2() const
    {
        return _part2;
    }
};

class ProductA1 : public ProductA
{
};

class ProductA2 : public ProductA
{
};



class BuilderA
{
protected:
    std::unique_ptr<ProductA> _product;

public:
    virtual ~BuilderA() = default;
    
    virtual void reset() = 0;
    virtual void build_part1() = 0;
    virtual void build_part2() = 0;
    virtual std::unique_ptr<ProductA> product()
    {
        return std::move(_product);
    }
};

class BuilderA1 : public BuilderA
{
public:
    void reset() override
    {
        _product = std::make_unique<ProductA1>();
    }

    void build_part1() override
    {
        _product->part1("A1 : Part1");
    }

    void build_part2() override
    {
        _product->part2("A1 : Part2");
    }
};

class BuilderA2 : public BuilderA
{
public:
    void reset() override
    {
        _product = std::make_unique<ProductA2>();
    }

    void build_part1() override
    {
        _product->part1("A2 : Part1");
    }

    void build_part2() override
    {
        _product->part2("A2 : Part2");
    }
};



class DirectorX
{
protected:
    std::shared_ptr<BuilderA> _builder;

public:
    void set_builder(std::shared_ptr<BuilderA> builder)
    {
        _builder = builder;
    }

    virtual void construct() = 0;
};

class DirectorA1 : public DirectorX
{
public:
    void construct() override
    {
        _builder->reset();
        _builder->build_part1();
        _builder->build_part2();
    }
};

class DirectorA2 : public DirectorX
{
public:
    void construct() override
    {
        _builder->reset();
        _builder->build_part2();
        _builder->build_part1();
    }
};



int main()
{
    DirectorA1 directorA1;
    DirectorA2 directorA2;
    std::shared_ptr<BuilderA> builderA1 = std::make_shared<BuilderA1>();
    std::shared_ptr<BuilderA> builderA2 = std::make_shared<BuilderA2>();



    directorA1.set_builder(builderA1);
    directorA2.set_builder(builderA2);
    


    directorA1.construct();
    std::unique_ptr<ProductA> productA1 = builderA1->product();

    directorA2.construct();
    std::unique_ptr<ProductA> productA2 = builderA2->product();



    std::cout << productA1->part1() << std::endl;
    std::cout << productA1->part2() << std::endl;

    std::cout << std::endl;

    std::cout << productA2->part1() << std::endl;
    std::cout << productA2->part2() << std::endl;



    return 0;
}



/*
Factory Method
ProductA, ProductA1, ProductA2
FactoryA, FactoryA1, FactoryA2
‰ºˆÊŒÝŠ·



Builder
ProductA, ProductA1, ProductA2
BuilderA, BuilderA1, BuilderA2
DirectorX, DirectorX1, DirectorX2
ãˆÊŒÝŠ·
*/
