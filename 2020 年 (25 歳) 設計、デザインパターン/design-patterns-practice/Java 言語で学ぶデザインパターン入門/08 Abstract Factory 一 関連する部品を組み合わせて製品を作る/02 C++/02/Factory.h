#pragma once

#include "Link.h"
#include "Page.h"
#include "Tray.h"

#include <functional>
#include <map>
#include <memory>



class Factory
{
public:
    explicit Factory();
    virtual ~Factory();

public:
    // 生成したインスタンスが戻り値
    static Factory* getFactory(const std::string&);

    virtual Link* createLink(const std::string&, const std::string&) = 0;
    virtual Tray* createTray(const std::string&) = 0;
    virtual Page* createPage(const std::string&, const std::string&) = 0;

};
