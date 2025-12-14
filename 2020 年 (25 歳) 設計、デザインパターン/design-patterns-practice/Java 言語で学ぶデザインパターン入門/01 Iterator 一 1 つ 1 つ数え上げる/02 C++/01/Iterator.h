#pragma once

#include "Aggregate.h"



class Iterator
{
private:
	const Aggregate& aggregate_;
	int index_;

public:
	explicit Iterator(const Aggregate&);
	virtual ~Iterator();

	bool hasNow() const;
	const Element& now() const;
	void nextNow();
};
