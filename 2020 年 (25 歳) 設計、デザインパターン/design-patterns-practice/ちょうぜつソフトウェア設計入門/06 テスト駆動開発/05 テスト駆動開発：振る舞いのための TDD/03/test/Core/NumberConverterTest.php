<?php

namespace FizzBuzz\Core;

use PHPUnit\Framework\TestCase;



class NumberConverterTest extends TestCase
{
    public function testConvert(): void
    {
        $fizzBuzz = new NumberConverter();

        

        $this->assertEquals("1", $fizzBuzz->convert(1));
        $this->assertEquals("2", $fizzBuzz->convert(2));
        $this->assertEquals("Fizz", $fizzBuzz->convert(3)); // 追加
    }
}
