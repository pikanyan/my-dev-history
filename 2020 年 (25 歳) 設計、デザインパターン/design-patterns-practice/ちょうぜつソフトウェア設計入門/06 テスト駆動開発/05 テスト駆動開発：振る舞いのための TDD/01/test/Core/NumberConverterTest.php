<?php

namespace FizzBuzz\Core;

use PHPUnit\Framework\TestCase;



class NumberConverterTest extends TestCase
{
    public function testConvert(): void
    {
        $fizzBuzz = new NumberConverter();

        
        
        $this->assertEquals("1", $fizzBuzz->convert(1));    // 追加
    }
}
