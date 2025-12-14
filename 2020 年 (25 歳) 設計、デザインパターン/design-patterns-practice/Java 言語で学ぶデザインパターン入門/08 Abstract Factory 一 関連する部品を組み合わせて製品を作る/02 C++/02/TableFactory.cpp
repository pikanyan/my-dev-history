#include "TableFactory.h"

TableFactory::TableFactory()
{
    std::cout << __FUNCTION__ << std::endl;
}

TableFactory::~TableFactory()
{
    std::cout << __FUNCTION__ << std::endl;
}

Link* TableFactory::createLink(const std::string& caption, const std::string& url)
{
    return new TableLink(caption, url);
}

Tray* TableFactory::createTray(const std::string& caption)
{
    return new TableTray(caption);
}

Page* TableFactory::createPage(const std::string& title, const std::string& author)
{
    return new TablePage(title, author);
}
