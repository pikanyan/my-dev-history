#include "main.h"

#include <iostream>
#include <memory>



// –½—ß
class Command
{
public:
    virtual ~Command() = default;

    virtual void execute() = 0;
};

class CommandA : public Command
{
public:
    void execute() override
    {
        std::cout << "CommandA : execute\n";
    }
};



// ŽÀs
class Invoker
{
private:
    std::shared_ptr<Command> command_;

public:
    void set_command(std::shared_ptr<Command> command)
    {
        command_ = command;
    }

    void invoke()
    {
        if (command_)
            command_->execute();
    }
};



int main()
{
    std::shared_ptr<Invoker> invoker = std::make_shared<Invoker>();
    std::shared_ptr<CommandA> command = std::make_shared<CommandA>();



    invoker->set_command(command);
    invoker->invoke();



    return 0;
}
