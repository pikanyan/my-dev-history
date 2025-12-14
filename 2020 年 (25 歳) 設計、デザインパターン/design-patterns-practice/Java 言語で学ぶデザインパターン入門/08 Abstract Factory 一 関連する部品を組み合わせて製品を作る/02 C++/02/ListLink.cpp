#include "ListLink.h"



ListLink::ListLink(const std::string& caption, const std::string& url) :
    Link(caption, url)
{
}

std::string ListLink::makeHTML()
{
    std::stringstream buffer;

    buffer << "<li>";
    buffer << "<a href=\"";
    buffer << url_;
    buffer << "\">";
    buffer << caption_;
    buffer << "</a>";
    buffer << "</li>\n";

    return buffer.str();
}
