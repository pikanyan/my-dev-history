<?php

interface RunnableInterface
{
    public function run(): void;
}



$foo = "Foo";



// 無名 class による振る舞い
$runnableObject = new class($foo) implements RunnableInterface
{
    public function __construct
    (
        private string $value
    )
    {

    }

    public function run(): void
    {
        echo $this->value . "\n";
    }
};



$runnableObject->run();
