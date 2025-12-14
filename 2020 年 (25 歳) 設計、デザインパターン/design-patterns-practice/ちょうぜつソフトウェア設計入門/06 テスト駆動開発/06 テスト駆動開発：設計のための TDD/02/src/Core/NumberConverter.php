<?php

namespace FizzBuzz\Core;



class NumberConverter
{
    public function __construct
    (
        protected array $rules
    )
    {

    }

    public function convert(int $n): string
    {
        // return "";

        if(empty($this->rules))
        {
            return "";
        }
        else
        {
            return $this->rules[0]->replace($n);
        }
    }
}
