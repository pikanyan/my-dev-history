#include "TablePage.h"



TablePage::TablePage(const std::string& title, const std::string& author) : 
    Page(title, author)
{
}

std::string TablePage::makeHTML()
{
    std::stringstream buffer;

    buffer << "<html><head><title>" << title << "</title></head>\n"
        << "<body>\n<h1>" << title << "</h1>\n"
        << "<table width=\"80%\" border=\"3\">\n";



    for (const auto& item : content)
        buffer << "<tr>" + item->makeHTML() + "</tr>";



    buffer << "</table>\n<hr><address>"
        << author
        << " </address></body></html>\n";



    return buffer.str();
}
