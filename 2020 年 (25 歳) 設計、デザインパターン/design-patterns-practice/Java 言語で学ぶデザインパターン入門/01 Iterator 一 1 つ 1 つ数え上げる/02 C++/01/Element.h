#pragma once

#include <string>



class Element
{
private:
	const std::string name_;

public:
	explicit Element(const std::string&);
	virtual ~Element();

	const std::string& name() const;
};
