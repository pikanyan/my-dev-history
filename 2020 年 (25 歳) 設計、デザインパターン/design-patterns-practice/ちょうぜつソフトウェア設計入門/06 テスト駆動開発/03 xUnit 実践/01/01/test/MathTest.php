<?php

use FizzBuzz\Math;
use PHPUnit\Framework\TestCase;



class MathTest extends TestCase
{
    public function testMinMax(): void
    {
        $math = new Math();

        $this->assertEquals(1, $math->min(1, 2));
        $this->assertEquals(2, $math->max(1, 2));
    }
}
