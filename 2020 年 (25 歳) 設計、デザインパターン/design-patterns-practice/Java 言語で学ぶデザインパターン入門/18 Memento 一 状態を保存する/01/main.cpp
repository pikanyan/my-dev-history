#include "main.h"

#include <iostream>
#include <memory>



// ‹L‰¯
class Memento
{
private:
    int state_;

public:
    Memento(int state) :
        state_(state)
    {
    }

    friend class Originator;
};



// ”­ˆÄ
class Originator
{
private:
    int state_;

public:
    Originator(int state) :
        state_(state)
    {
        std::cout << "Originator : " << state_ << "\n";
    }

    std::shared_ptr<Memento> create_memento()
    {
        return std::make_shared<Memento>(state_);
    }

    void set_memento(const std::shared_ptr<Memento>& memento)
    {
        this->state_ = memento->state_;

        std::cout << "Originator : " << state_ << "\n";
    }

    void set_state(int state)
    {
        this->state_ = state;

        std::cout << "Originator : " << state_ << "\n";
    }
};



int main()
{
    std::shared_ptr<Originator> originator = std::make_shared<Originator>(100);
    std::shared_ptr<Memento> memento1 = originator->create_memento();



    originator->set_state(200);
    std::shared_ptr<Memento> memento2 = originator->create_memento();



    originator->set_memento(memento1);



    return 0;
}
