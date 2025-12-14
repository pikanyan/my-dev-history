#pragma once

class AbstractDisplay
{
public:
	explicit AbstractDisplay();
	virtual ~AbstractDisplay();

	void display();

protected:
	virtual void open() = 0;
	virtual void print() = 0;
	virtual void close() = 0;
};
