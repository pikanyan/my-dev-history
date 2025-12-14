#pragma once

#include <string>



// Link と Tray を同一視する為のクラス
class Item
{
protected:
	std::string caption_;

public:
	// 見出し
	explicit Item(const std::string&);
	virtual ~Item();

	// HTML の文字列が戻り値
	virtual std::string makeHTML() = 0;
};
