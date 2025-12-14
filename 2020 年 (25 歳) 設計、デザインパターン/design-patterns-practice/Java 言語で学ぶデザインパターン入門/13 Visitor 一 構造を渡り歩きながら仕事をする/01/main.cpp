#include "main.h"

#include <iostream>
#include <memory>



class ElementA;
class ElementB;

// データ操作
class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit_elementA(std::shared_ptr<ElementA>) = 0;
    virtual void visit_elementB(std::shared_ptr<ElementB>) = 0;
};



// データ構造
class Element
{
public:
    virtual ~Element() = default;

    virtual void accept(Visitor* visitor) = 0;
};

class ElementA :
    public Element,
    public std::enable_shared_from_this<ElementA>
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visit_elementA(shared_from_this());
    }

    void operateA() const
    {
        std::cout << "operate A" << std::endl;
    }
};

class ElementB :
    public Element,
    public std::enable_shared_from_this<ElementB>
{
public:
    void accept(Visitor* visitor) override
    {
        visitor->visit_elementB(shared_from_this());
    }

    void operateB() const
    {
        std::cout << "operate B" << std::endl;
    }
};



class VisitorA : public Visitor
{
public:
    void visit_elementA(std::shared_ptr<ElementA> element) override
    {
        std::cout << "VisitorA is operating on ElementA : ";

        element->operateA();
    }

    void visit_elementB(std::shared_ptr<ElementB> element) override
    {
        std::cout << "VisitorA is operating on ElementB : ";

        element->operateB();
    }
};

class VisitorB : public Visitor
{
public:
    void visit_elementA(std::shared_ptr<ElementA> element) override
    {
        std::cout << "VisitorB is NOT operating on Element A" << std::endl;
    }

    void visit_elementB(std::shared_ptr<ElementB> element) override
    {
        std::cout << "VisitorB changes the operation on ElementB" << std::endl;
    }
};



int main()
{
    std::shared_ptr<Visitor> visitorA = std::make_shared<VisitorA>();
    std::shared_ptr<Visitor> visitorB = std::make_shared<VisitorB>();
    std::shared_ptr<Element> elementA = std::make_shared<ElementA>();
    std::shared_ptr<Element> elementB = std::make_shared<ElementB>();

    

    elementA->accept(visitorA.get());
    elementB->accept(visitorA.get());

    std::cout << std::endl;

    elementA->accept(visitorB.get());
    elementB->accept(visitorB.get());



    return 0;
}



/*
elementA->operateA();
データ構造が operateA() を直接的に呼ぶ
データ操作と合併する

elementA->accept(visitor.get());
データ構造が operateA() を間接的に呼ぶ
データ操作と分離する
*/
