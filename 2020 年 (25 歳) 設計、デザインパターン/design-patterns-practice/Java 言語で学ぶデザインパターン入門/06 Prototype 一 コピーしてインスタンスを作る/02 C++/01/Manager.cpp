#include "Manager.h"



std::unique_ptr<Product> Manager::create_product(const std::string& protoname)
{
    auto it = showcase_.find(protoname);

    if (it != showcase_.end())
        return it->second->clone();

    return nullptr;
}

void Manager::register_product(const std::string& name, std::unique_ptr<Product> proto)
{
    showcase_[name] = std::move(proto);
}
