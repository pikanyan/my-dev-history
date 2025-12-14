#pragma once

#include "Aggregate.h"
#include "BookShelfIterator.h"

#include <memory>



class BookShelf : public Aggregate
{
public:
	explicit BookShelf();
	virtual ~BookShelf();

	std::unique_ptr<Iterator> iterator() const override;
};
