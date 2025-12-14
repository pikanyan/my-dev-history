<?php

abstract class Node
{
    protected Branch $parent;
}

class Branch extends Node
{
    protected array $subnodes;
}

class Leaf extends Node
{

}



// App
class App
{
    public static function main(): void
    {
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
