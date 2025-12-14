<?php

namespace FizzBuzz\Spec;

use PHPUnit\Framework\TestCase;



class CyclicNumberRuleTest extends TestCase
{
    public function testReplace(): void
    {
        $rule = new CyclicNumberRule(3, "Fizz");


        
        $this->assertEquals("", $rule->replace(1));
        $this->assertEquals("Fizz", $rule->replace(3));
        $this->assertEquals("Fizz", $rule->replace(6));
    }
}
