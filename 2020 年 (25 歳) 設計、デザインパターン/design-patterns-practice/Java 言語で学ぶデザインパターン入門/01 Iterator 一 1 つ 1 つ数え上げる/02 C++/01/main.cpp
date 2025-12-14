#include "main.h"
#include "Book.h"
#include "BookShelf.h"

#include <iostream>
#include <memory>



int main()
{
	std::unique_ptr<Aggregate> bookShelf;
	std::unique_ptr<Element> book;
	std::unique_ptr<Iterator> bookShelfIterator;



	bookShelf = std::make_unique<BookShelf>();

	book = std::make_unique<Book>("Around the World in 80 Days");
	bookShelf->append(std::move(book));

	book = std::make_unique<Book>("Bible");
	bookShelf->append(std::move(book));

	book = std::make_unique<Book>("Cinderella");
	bookShelf->append(std::move(book));

	book = std::make_unique<Book>("Daddy-Long-Legs");
	bookShelf->append(std::move(book));

	bookShelfIterator = std::move(bookShelf->iterator());



	std::cout << std::endl;



	while (bookShelfIterator->hasNow())
	{
		const Element& book = bookShelfIterator->now();

		std::cout << book.name() << std::endl;

		bookShelfIterator->nextNow();
	}



	std::cout << std::endl;



	return 0;
}
