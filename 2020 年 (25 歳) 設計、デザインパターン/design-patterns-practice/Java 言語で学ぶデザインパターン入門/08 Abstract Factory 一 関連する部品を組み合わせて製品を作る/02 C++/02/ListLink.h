#pragma once

#include "Link.h"

#include <sstream>



class ListLink : public Link
{
public:
    ListLink(const std::string&, const std::string&);

    std::string makeHTML() override;
};
