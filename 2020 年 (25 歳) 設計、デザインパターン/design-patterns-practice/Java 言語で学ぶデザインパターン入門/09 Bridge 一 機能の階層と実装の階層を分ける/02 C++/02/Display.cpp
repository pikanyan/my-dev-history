#include "Display.h"



Display::Display(DisplayImpl* impl) : 
	impl(impl)
{
}

Display::~Display()
{
	if (impl)
	{
		delete impl;
	}
}

void Display::open()
{
	impl->rawOpen();
}

void Display::print()
{
	impl->rawPrint();
}

void Display::close()
{
	impl->rawClose();
}
