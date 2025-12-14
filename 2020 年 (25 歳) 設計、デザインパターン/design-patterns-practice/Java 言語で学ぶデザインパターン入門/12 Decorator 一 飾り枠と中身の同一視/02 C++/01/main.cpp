#include "main.h"

#include <iostream>
#include <memory>
#include <vector>



class Component
{
public:
    virtual ~Component() = default;

    virtual void operate() const = 0;
};

// 修飾後のクラス
// 抽象クラス
class Decorator : public Component
{
protected:
    std::shared_ptr<Component> component_;

public:
    Decorator(std::shared_ptr<Component> component) : 
        component_(component)
    {
    }

    virtual void operate() const override
    {
        component_->operate();
    }
};

// 修飾後のクラス
// 具体クラス
class ConcreteDecorator : public Decorator
{
public:
    ConcreteDecorator(std::shared_ptr<Component> component) :
        Decorator(component)
    {
    }

    void operate() const override
    {
        std::cout << "ConcreteDecorator pre-operate" << std::endl;

        Decorator::operate();

        std::cout << "ConcreteDecorator post-operate" << std::endl;
    }
};

// 修飾前のクラス
class ConcreteComponent : public Component
{
public:
    void operate() const override
    {
        std::cout << "ConcreteComponent operate" << std::endl;
    }
};



int main()
{
    std::shared_ptr<Component> concreteComponent = std::make_shared<ConcreteComponent>();
    std::shared_ptr<Component> concreteDecorator = std::make_shared<ConcreteDecorator>(concreteComponent);



    concreteDecorator->operate();



    return 0;
}
