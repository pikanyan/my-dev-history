#include "TextBuilder.h"



void TextBuilder::makeTitle(const std::string& title)
{
    buffer << "====================\n";
    buffer << "w" << title << "x\n";
    buffer << "\n";
}

void TextBuilder::makeString(const std::string& str)
{
    buffer << "¡" << str << "\n\n";
}

void TextBuilder::makeItems(const std::vector<std::string>& items)
{
    for (const auto& item : items)
    {
        buffer << "  E" << item << "\n";
    }

    buffer << "\n";
}

void TextBuilder::close()
{
    buffer << "====================\n";
}

std::string TextBuilder::getResult() const
{
    return buffer.str();
}