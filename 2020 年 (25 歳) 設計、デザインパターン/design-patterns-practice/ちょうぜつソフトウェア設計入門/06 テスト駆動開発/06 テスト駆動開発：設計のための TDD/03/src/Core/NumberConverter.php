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
        /*
        if(empty($this->rules))
        {
            return "";
        }
        else
        {
            return $this->rules[0]->replace($n);
        }
        */

        $result = "";

        foreach($this->rules as $rule)
        {
            $result .= $rule->replace($n);
        }

        return $result;
    }
}
