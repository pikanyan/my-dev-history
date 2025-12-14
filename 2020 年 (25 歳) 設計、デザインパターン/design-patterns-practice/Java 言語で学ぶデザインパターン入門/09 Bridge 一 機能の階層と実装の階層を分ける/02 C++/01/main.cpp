#include "main.h"

#include <iostream>
#include <memory>



class Implementor
{
public:
    virtual ~Implementor() = default;

    virtual void operate() const = 0;
};

class ImplementorA : public Implementor
{
public:
    void operate() const override
    {
        std::cout << "ImplementorA : operate" << std::endl;
    }
};

class ImplementorB : public Implementor
{
public:
    void operate() const override
    {
        std::cout << "ImplementorB : operate" << std::endl;
    }
};



class Abstraction
{
protected:
    std::unique_ptr<Implementor> implementor_;

public:
    explicit Abstraction(std::unique_ptr<Implementor> implementor) :
        implementor_(std::move(implementor))
    {
    }

    virtual ~Abstraction() = default;

    virtual void operate()
    {
        implementor_->operate();
    }
};

class AbstractionA : public Abstraction
{
public:
    using Abstraction::Abstraction;

    void operate() override
    {
        std::cout << "AbstractionA : ";

        Abstraction::operate();
    }
};



int main()
{
    std::unique_ptr<AbstractionA> abstraction1 = std::make_unique<AbstractionA>(std::make_unique<ImplementorA>());
    abstraction1->operate();

    std::unique_ptr<AbstractionA> abstraction2 = std::make_unique<AbstractionA>(std::make_unique<ImplementorB>());
    abstraction2->operate();



    return 0;
}



/*
Abstraction
機能クラス
目的、何をするかに相当する
変化の頻度が小さい
再利用可能性が大きい
同じ機能クラスでも異なる実装クラスで動作できる



AbstractImplementor
実装クラス
手段、どうするかに相当する
変化の頻度が大きい
再利用可能性が小さい
同じ実装クラスでも異なる実装クラスで動作できる
*/
