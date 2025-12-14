#pragma once

#include "Factory.h"
#include "ListLink.h"
#include "ListTray.h"
#include "ListPage.h"



class ListFactory : public Factory
{
public:
    Link* createLink(const std::string&, const std::string&) override;
    Tray* createTray(const std::string&) override;
    Page* createPage(const std::string&, const std::string&) override;
};
