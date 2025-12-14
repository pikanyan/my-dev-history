#include "Factory.h"


#include "TableFactory.h"
#include "ListFactory.h"



Factory::Factory()
{
    std::cout << __FUNCTION__ << std::endl;
}

Factory::~Factory()
{
    std::cout << __FUNCTION__ << std::endl;
}



// listfactory.ListFactory のようにクラス名を指定して、インスタンスを作成
Factory* Factory::getFactory(const std::string& classname)
{
    // reflection で下記を簡略化可能
    if (classname == "TableFactory")
    {
        return new TableFactory();
    }
    else if (classname == "ListFactory")
    {
        return new ListFactory();
    }
    else
    {
        std::cerr << "Class " << classname << " not found\n";

        return nullptr;
    }

    /*
    auto it = getRegistry().find(classname);

    if (it != getRegistry().end())
    {
        return it->second();
    }
    else
    {
        

        return nullptr;
    }
    */
}



