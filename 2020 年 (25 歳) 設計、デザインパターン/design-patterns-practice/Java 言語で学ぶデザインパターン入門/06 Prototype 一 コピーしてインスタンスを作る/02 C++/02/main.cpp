#include "main.h"

#include <iostream>
#include <memory>



class AbstractPrototype
{
public:
    virtual std::unique_ptr<AbstractPrototype> clone() const = 0;

    virtual void print_value() const = 0;
};

class ConcretePrototype : public AbstractPrototype
{
private:
    int value_;

public:
    explicit ConcretePrototype(int value) :
        value_(value)
    {
    }

    explicit ConcretePrototype(const ConcretePrototype& clone) :
        value_(clone.value_)
    {
    }

    std::unique_ptr<AbstractPrototype> clone() const override
    {
        return std::make_unique<ConcretePrototype>(*this);
    }

    void print_value() const
    {
        std::cout << value_ << std::endl;
    }
};



int main()
{
    std::unique_ptr<AbstractPrototype> original = std::make_unique<ConcretePrototype>(10);
    std::unique_ptr<AbstractPrototype> copy = original->clone();

    original->print_value();
    copy->print_value();



    return 0;
}



// 基底クラスが print_value() を持つ
// down cast をせずに copy->print_value(); を実行できる

// 派生クラスが print_value() を持つ
// down cast をせずに copy->print_value(); を実行できない



// 基底クラスが clone() = 0 を持つ
// 派生クラスが clone() を実装する必要がある
// down cast を避ける為に、基底クラスが print_value() = 0 を持つ必要がある
// std::unique_ptr<AbstractPrototype> copy = original->clone(); のように派生型を知らずに clone() を実行できる

// 基底クラスが clone() = 0 を持たない
// 派生クラスが clone() を実装する必要がない
// down cast を避ける為に、基底クラスが print_value() = 0 を持つ必要がある
// std::unique_ptr<AbstractPrototype> copy = original->clone(); のように派生型を知らずに clone() を実行できない
