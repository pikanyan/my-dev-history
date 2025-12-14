#pragma once

#include "Element.h"

#include <memory>
#include <vector>



class Iterator;



class Aggregate
{
private:
	std::vector<std::unique_ptr<Element>> elements_;

public:
	explicit Aggregate();
	virtual ~Aggregate();

	virtual std::unique_ptr<Iterator> iterator() const = 0;

	int size() const;

	void append(std::unique_ptr<Element>);
	const Element& element(int) const;
};
