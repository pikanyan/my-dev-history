#pragma once

#include "Item.h"

#include <vector>



// 複数の Link, Tray を集めて一纏めにしたものを表すクラス
// 抽象的な部品
// Link, Tray のリストを表現する為に, Item 型にする
class Tray : public Item
{
protected:
	std::vector<Item*> tray_;

public:
    explicit Tray(const std::string&);
    virtual ~Tray();

    void add(Item*);
};
