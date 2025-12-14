#pragma once

#include "Page.h"
#include <sstream>



class TablePage : public Page
{
public:
    TablePage(const std::string&, const std::string&);
    std::string makeHTML() override;
};
