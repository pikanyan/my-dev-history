#pragma once

#include "Tray.h"

#include <sstream>



class ListTray : public Tray
{
public:
    ListTray(const std::string&);

    std::string makeHTML() override;
};
