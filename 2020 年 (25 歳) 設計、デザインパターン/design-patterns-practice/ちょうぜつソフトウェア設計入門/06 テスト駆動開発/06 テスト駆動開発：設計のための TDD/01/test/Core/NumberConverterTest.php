<?php

namespace FizzBuzz\Core;

use PHPUnit\Framework\TestCase;



class NumberConverterTest extends TestCase
{
    public function testConvertWithEmptyRules(): void
    {
        $fizzBuzz = new NumberConverter([]);



        $this->assertEquals("", $fizzBuzz->convert(1)); // 追加
    }
}
