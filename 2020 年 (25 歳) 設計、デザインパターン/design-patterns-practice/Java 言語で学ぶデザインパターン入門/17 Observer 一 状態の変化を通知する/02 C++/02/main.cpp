#include "main.h"

#include <iostream>
#include <memory>
#include <vector>



// 観察者
class Observer
{
public:
    virtual void update(int value) = 0;
};

class ObserverA : public Observer
{
public:
    void update(int value) override
    {
        std::cout << "ObserverA : " << value << "\n";
    }
};



// 被観察者
class Subject
{
private:
    std::vector<std::shared_ptr<Observer>> observers;

    int value;

public:
    Subject() :
        value(0)
    {
    }

    void attach(std::shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void set_value(int value)
    {
        this->value = value;

        notify();
    }

private:
    void notify()
    {
        for (const auto& observer : observers)
            observer->update(value);
    }
};



int main()
{
    std::shared_ptr<Subject> subject = std::make_shared<Subject>();
    std::shared_ptr<ObserverA> observerA = std::make_shared<ObserverA>();

    subject->attach(observerA);



    subject->set_value(123);



    return 0;
}
