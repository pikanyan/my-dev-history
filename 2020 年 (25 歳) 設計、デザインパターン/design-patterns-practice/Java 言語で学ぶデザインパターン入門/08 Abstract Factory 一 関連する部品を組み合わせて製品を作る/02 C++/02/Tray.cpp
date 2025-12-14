#include "Tray.h"

#include <iostream>



Tray::Tray(const std::string& caption) : 
    Item(caption)
{
    std::cout << __FUNCTION__ << std::endl;
}

Tray::~Tray()
{
    std::cout << __FUNCTION__ << std::endl;

    for (auto item : tray_)
    {
        // ŠÇ—‚µ‚Ä‚¢‚éƒŠƒ\[ƒX‰ð•ú
        // delete item;
    }
}

void Tray::add(Item* item)
{
    tray_.push_back(item);
}
