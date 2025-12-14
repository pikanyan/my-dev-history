#include "TableTray.h"

#include <iostream>



TableTray::TableTray(const std::string& caption) :
    Tray(caption)
{
    std::cout << __FUNCTION__ << std::endl;
}

TableTray::~TableTray()
{
    std::cout << __FUNCTION__ << std::endl;
}

std::string TableTray::makeHTML()
{
    std::stringstream buffer;

    buffer
        << "<td>"
        << "<table width=\"100%\" border=\"1\"><tr>"
        << "<td bgcolor=\"#cccccc\" align=\"center\" colspan=\"" << tray_.size()
        << "\"><b>" << caption_ << "</b></td></tr><tr>";



    for (const auto& item : tray_)
        buffer << item->makeHTML();


    buffer << "</tr></table></td>";



    return buffer.str();
}
