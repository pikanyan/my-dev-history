#include "main.h"

#include <iostream>
#include <memory>



class Subject
{
public:
    virtual ~Subject() = default;

    virtual void request() = 0;
};

class SubjectA : public Subject
{
public:
    void request() override
    {
        std::cout << "SubjectA : Handling request\n";
    }
};



// “¯ˆê interface
class Proxy : public Subject
{
private:
    std::shared_ptr<SubjectA> subjectA_;

public:
    void request() override
    {
        // ’x‰„‰Šú‰»
        if (!subjectA_)
            subjectA_ = std::make_shared<SubjectA>();

        subjectA_->request();
    }
};



int main()
{
    std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>();

    proxy->request();



    return 0;
}
