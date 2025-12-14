<?php

interface SomeInterface
{
    public function doSomething(): void;
}

final class SomeSingleton implements SomeInterface
{
    private static ?SomeSingleton $theInstance = null;

    private function __construct()
    {
        
    }

    public static function getInstance(): SomeSingleton
    {
        if(self::$theInstance === null)
        {
            self::$theInstance = new SomeSingleton();
        }

        return self::$theInstance;
    }

    public function doSomething(): void
    {
        echo "Doing something as a singleton!" . PHP_EOL;
    }
}



class App
{
    public static function main(): void
    {
        $singleton = SomeSingleton::getInstance();
        
        $singleton->doSomething();
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
