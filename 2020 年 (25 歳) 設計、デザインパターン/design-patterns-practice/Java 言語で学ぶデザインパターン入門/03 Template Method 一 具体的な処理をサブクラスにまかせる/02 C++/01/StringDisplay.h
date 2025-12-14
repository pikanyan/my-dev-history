#pragma once

#include "AbstractDisplay.h"

#include <string>



class StringDisplay : public AbstractDisplay
{
private:
	const std::string str_;

public:
	explicit StringDisplay(const std::string&);
	virtual ~StringDisplay();

protected:
	void open();
	void print();
	void close();

private:
	void printLine();
};
