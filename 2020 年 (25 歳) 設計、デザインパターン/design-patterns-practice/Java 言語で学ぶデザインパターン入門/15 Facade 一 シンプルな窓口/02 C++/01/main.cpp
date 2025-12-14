#include "main.h"

#include <iostream>
#include <memory>



// •¡G‚È‘€ì
class SubSystemA
{
public:
    std::string operate() const
    {
        return "SubSystem A : Ready!\n";
    }
};

class SubSystemB
{
public:
    std::string operate() const
    {
        return "SubSystem B : Go!\n";
    }
};



// ’Pƒ‚È‘€ì
class Facade
{
protected:
    std::shared_ptr<SubSystemA> subSystemA_;
    std::shared_ptr<SubSystemB> subSystemB_;

public:
    Facade
    (
        std::shared_ptr<SubSystemA> subSystemA = nullptr,
        std::shared_ptr<SubSystemB> subSystemB = nullptr
    ) :
        subSystemA_(subSystemA),
        subSystemB_(subSystemB)
    {
    }

    virtual ~Facade() = default;

    std::string operate() const
    {
        std::string result = "Facade initializes SubSystems : \n";

        result += this->subSystemA_->operate();
        result += this->subSystemB_->operate();

        return result;
    }
};



int main()
{
    std::shared_ptr<SubSystemA> subSystemA = std::make_shared<SubSystemA>();
    std::shared_ptr<SubSystemB> subSystemB = std::make_shared<SubSystemB>();
    std::shared_ptr<Facade> facade = std::make_shared<Facade>(subSystemA, subSystemB);



    std::cout << facade->operate();



    return 0;
}
