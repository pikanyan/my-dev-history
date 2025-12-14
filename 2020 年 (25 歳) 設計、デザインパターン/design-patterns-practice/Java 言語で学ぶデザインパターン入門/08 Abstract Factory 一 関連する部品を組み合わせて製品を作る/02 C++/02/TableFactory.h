#pragma once

#include "Factory.h"
#include "TableLink.h"
#include "TableTray.h"
#include "TablePage.h"



class TableFactory : public Factory
{
public:
    explicit TableFactory();
    virtual ~TableFactory();

public:
    Link* createLink(const std::string&, const std::string&) override;
    Tray* createTray(const std::string&) override;
    Page* createPage(const std::string&, const std::string&) override;
};
