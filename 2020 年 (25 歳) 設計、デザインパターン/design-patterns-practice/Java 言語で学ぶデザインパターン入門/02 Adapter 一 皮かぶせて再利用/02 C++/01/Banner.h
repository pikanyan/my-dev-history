#pragma once

#include <string>



class Banner
{
private:
	const std::string str_;

public:
	explicit Banner(const std::string&);
	virtual ~Banner();

	void show_withParen() const;
	void show_withAster() const;
};
