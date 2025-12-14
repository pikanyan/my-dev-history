#include "ListFactory.h"


Link* ListFactory::createLink(const std::string& caption, const std::string& url)
{
    return new ListLink(caption, url);
}

Tray* ListFactory::createTray(const std::string& caption)
{
    return new ListTray(caption);
}

Page* ListFactory::createPage(const std::string& title, const std::string& author)
{
    return new ListPage(title, author);
}
