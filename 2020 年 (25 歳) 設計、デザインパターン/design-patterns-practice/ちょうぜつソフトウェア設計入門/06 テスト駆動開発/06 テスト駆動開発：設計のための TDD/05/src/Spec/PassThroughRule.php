<?php

namespace FizzBuzz\Spec;

use FizzBuzz\Core\ReplaceRuleInterface;



class PassThroughRule implements ReplaceRuleInterface
{
    public function replace(int $n): string
    {
        return (string)$n;
    }
}
