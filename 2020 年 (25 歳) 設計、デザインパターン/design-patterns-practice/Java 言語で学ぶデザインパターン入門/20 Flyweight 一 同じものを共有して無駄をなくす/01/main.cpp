#include "main.h"

#include <iostream>
#include <map>
#include <memory>



class Flyweight
{
public:
    virtual ~Flyweight() = default;

    virtual void operate() = 0;
};

class FlyweightA : public Flyweight
{
public:
    void operate() override
    {
        std::cout << "FlyweightA operate\n";
    }
};




class FlyweightFactory
{
private:
    std::map<std::string, std::shared_ptr<Flyweight>> flyweights;

public:
    std::shared_ptr<Flyweight> get_flyweight(const std::string& key)
    {
        if (flyweights.find(key) == flyweights.end())
        {
            flyweights[key] = std::make_shared<FlyweightA>();
        }

        return flyweights[key];
    }
};



int main()
{
    FlyweightFactory factory;



    // V‹K
    std::shared_ptr<Flyweight> flyweight1 = factory.get_flyweight("a");
    flyweight1->operate();

    // Šù‘¶
    std::shared_ptr<Flyweight> flyweight2 = factory.get_flyweight("a");
    flyweight2->operate();



    return 0;
}
