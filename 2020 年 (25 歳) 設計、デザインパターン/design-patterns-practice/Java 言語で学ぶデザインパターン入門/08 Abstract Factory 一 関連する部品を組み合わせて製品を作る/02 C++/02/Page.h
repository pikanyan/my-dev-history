#pragma once

#include "Item.h"

#include <iostream>
#include <fstream>
#include <vector>



class Page
{
protected:
    std::string title;
    std::string author;

    std::vector<Item*> content;

public:
    Page(const std::string&, const std::string&);
    virtual ~Page();


    void add(Item*);
    void output();

    virtual std::string makeHTML() = 0;
};
