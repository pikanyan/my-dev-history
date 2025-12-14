#include "main.h"

#include <iostream>
#include <memory>
#include <vector>


// 共通クラス
class Component
{
public:
    virtual ~Component() = default;

    virtual void operate() const = 0;
};

// 全体クラス
class Composite : public Component
{
private:
    std::vector<std::shared_ptr<Component>> children_;

public:
    void add(std::shared_ptr<Component> component)
    {
        children_.push_back(component);
    }

    void operate() const override
    {
        for (const auto& child : children_)
        {
            child->operate();
        }
    }
};

// 部分クラス
class Leaf : public Component
{
public:
    void operate() const override
    {
        std::cout << "Leaf operate" << std::endl;
    }
};



int main()
{
    std::shared_ptr<Composite> composite1 = std::make_shared<Composite>();
    std::shared_ptr<Composite> composite2 = std::make_shared<Composite>();



    composite1->add(std::make_shared<Leaf>());
    composite1->add(std::make_shared<Leaf>());

    composite2->add(std::make_shared<Leaf>());
    composite2->add(composite1);



    composite1->operate();

    std::cout << std::endl;

    composite2->operate();



    return 0;
}
