#pragma once

#include "Item.h"
#include "Page.h"

#include <sstream>



class ListPage : public Page
{
public:
    ListPage(const std::string&, const std::string&);

    std::string makeHTML() override;
};
