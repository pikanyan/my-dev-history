#include "TableLink.h"

#include <iostream>



TableLink::TableLink(const std::string& caption, const std::string& url) :
    Link(caption, url)
{
    std::cout << __FUNCTION__ << std::endl;
}

TableLink::~TableLink()
{
    std::cout << __FUNCTION__ << std::endl;
}


std::string TableLink::makeHTML()
{
    return "<td><a href=\"" + url_ + "\">" + caption_ + "</a></td>\n";
}
