<?php

class BookShelfIterator implements Iterator
{
    private array $elements_;
    private int $position_;



    public function __construct(array $elements_)
    {
        $this->elements_ = $elements_;
        $this->position_ = 0;
    }



    public function current(): mixed
    {
        return $this->elements_[$this->position_];
    }

    public function key(): int
    {
        return $this->position_;
    }

    public function next(): void
    {
        ++$this->position_;
    }

    public function rewind(): void
    {
        $this->position_ = 0;
    }

    public function valid(): bool
    {
        return isset
        (
            $this->elements_[$this->position_]
        );
    }
}



class BookShelf implements IteratorAggregate
{
    private array $elements_;



    public function __construct(array $elements_)
    {
        $this->elements_ = $elements_;
    }

    public function getIterator(): Iterator
    {
        return new BookShelfIterator($this->elements_);
    }
}



function showAll(Iterator $iterator)
{
    foreach($iterator as $element)
    {
        echo $element . PHP_EOL;
    }
}



class App
{
    public static function main(): void
    {
        $elements = ["Apple", "Banana", "Cherry"];
        
        $bookShelf = new BookShelf($elements);



        showAll($bookShelf->getIterator());
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
