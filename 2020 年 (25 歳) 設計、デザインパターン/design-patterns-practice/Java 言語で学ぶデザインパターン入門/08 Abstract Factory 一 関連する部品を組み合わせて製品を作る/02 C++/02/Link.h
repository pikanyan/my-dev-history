#pragma once

#include "Item.h"

#include <string>



// HTML のハイパーリンクという部品を抽象的に表現した、抽象的な部分に相当するクラス
// makeHTML を実装していないので、抽象クラス
class Link : public Item
{
protected:
	std::string url_;

public:
	explicit Link(const std::string&, const std::string&);
	virtual ~Link();
};
