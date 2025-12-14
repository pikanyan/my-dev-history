#pragma once

#include "Iterator.h"



class BookShelfIterator : public Iterator
{
public:
	explicit BookShelfIterator(const Aggregate&);
	virtual ~BookShelfIterator();
};
