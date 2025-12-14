#include "main.h"

#include <iostream>
#include <memory>



// ó‘Ô
class State
{
public:
    virtual ~State() = default;

    virtual void handle() = 0;
};

class StateA : public State
{
public:
    void handle() override
    {
        std::cout << "Handling in State A\n";
    }
};

class StateB : public State
{
public:
    void handle() override
    {
        std::cout << "Handling in State B\n";
    }
};



// •Û
class Context
{
private:
    std::shared_ptr<State> state_;

public:
    Context(std::shared_ptr<State> state) :
        state_(state)
    {
    }

    void set_state(std::shared_ptr<State> state)
    {
        this->state_ = state;
    }

    void request()
    {
        this->state_->handle();
    }
};



int main()
{
    std::shared_ptr<StateA> stateA = std::make_shared<StateA>();
    std::shared_ptr<StateB> stateB = std::make_shared<StateB>();



    Context context(stateA);
    context.request();

    context.set_state(stateB);
    context.request();



    return 0;
}
