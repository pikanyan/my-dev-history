#pragma once

#include "Link.h"



class TableLink : public Link
{
public:
    explicit TableLink(const std::string&, const std::string&);
    virtual ~TableLink();

    std::string makeHTML() override;
};
