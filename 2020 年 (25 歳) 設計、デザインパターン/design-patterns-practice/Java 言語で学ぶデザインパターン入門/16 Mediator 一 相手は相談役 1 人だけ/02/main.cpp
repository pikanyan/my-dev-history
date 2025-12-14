#include "main.h"

#include <iostream>
#include <memory>
#include <vector>



class Mediator;

// 部分クラス
class Colleague
{
protected:
    std::shared_ptr<Mediator> mediator_;

public:
    void set_mediator(std::shared_ptr<Mediator> mediator)
    {
        this->mediator_ = mediator;
    }

    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
};

// 仲介クラス
class Mediator :
    public std::enable_shared_from_this<Mediator>
{
protected:
    std::vector<std::shared_ptr<Colleague>> colleagues_;

public:
    void add_colleague(std::shared_ptr<Colleague> colleague)
    {
        this->colleagues_.push_back(colleague);

        colleague->set_mediator(shared_from_this());
    }

    virtual void send(const std::string& message, const Colleague* colleagueSender) = 0;
};



class ConcreteColleague :
    public Colleague,
    public std::enable_shared_from_this<ConcreteColleague>
{
public:
    void send(const std::string& message)
    {
        std::cout << "ConcreteColleague : " << message << "\n";

        this->mediator_->send(message, this);
    }

    void receive(const std::string& message)
    {
        std::cout << "ConcreteColleague : " << message << "\n";
    }
};

class ConcreteMediator :
    public Mediator
{
public:
    void send(const std::string& message, const Colleague* colleagueSender) override
    {
        for (const auto& colleague : colleagues_)
        {
            if (colleague.get() != colleagueSender)
            {
                std::cout << "ConcreteMediator : " << message << "\n";

                colleague->receive(message);
            }
        }
    }
};



int main()
{
    std::shared_ptr<Mediator> mediator = std::make_shared<ConcreteMediator>();
    std::shared_ptr<Colleague> colleagueA = std::make_shared<ConcreteColleague>();
    std::shared_ptr<Colleague> colleagueB = std::make_shared<ConcreteColleague>();



    mediator->add_colleague(colleagueA);
    mediator->add_colleague(colleagueB);



    colleagueA->send("Hello");



    return 0;
}
