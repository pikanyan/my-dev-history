#pragma once

#include "AbstractDisplay.h"



class CharDisplay : public AbstractDisplay
{
private:
	const char ch_;

public:
	explicit CharDisplay(char);
	virtual ~CharDisplay();

protected:
	void open() override;
	void print() override;
	void close() override;
};
