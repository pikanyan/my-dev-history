<?php

namespace FizzBuzz\Core;



class NumberConverter
{
    public function convert(int $n): string
    {
        /*
        if($n == 3)
        {
            return "Fizz";
        }
        else if ($n == 5)
        {
            return "Buzz";
        }
        else
        {
            return (string)$n;
        }
        */

        if($n % 3 == 0)
        {
            return "Fizz";
        }
        else if ($n % 5 == 0)
        {
            return "Buzz";
        }
        else
        {
            return (string)$n;
        }
    }
}
