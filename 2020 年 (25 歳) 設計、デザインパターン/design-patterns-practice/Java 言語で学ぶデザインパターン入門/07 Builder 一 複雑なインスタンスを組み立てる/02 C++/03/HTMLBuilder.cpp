#include "HTMLBuilder.h"



void HTMLBuilder::makeTitle(const std::string& title)
{
    filename = title + ".html";
    writer.open(filename);

    if (!writer.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    writer << "<html><head><title>" << title << "</title></head><body>\n";
}

void HTMLBuilder::makeString(const std::string& str)
{
    writer << "<p>" << str << "</p>\n";
}

void HTMLBuilder::makeItems(const std::vector<std::string>& items)
{
    writer << "<ul>\n";

    for (const auto& item : items)
    {
        writer << "<li>" << item << "</li>\n";
    }

    writer << "</ul>\n";
}

void HTMLBuilder::close()
{
    writer << "</body></html>\n";

    if (writer.is_open())
        writer.close();
}

std::string HTMLBuilder::getResult() const
{
    return filename;
}
