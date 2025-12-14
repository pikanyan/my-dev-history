<?php

namespace FizzBuzz;

use FizzBuzz\App\FizzBuzzSequencePrinter;



class App
{
    public static function main(): void
    {
        $printer = new FizzBuzzSequencePrinter();

        $printer->printRange(1, 100);
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
