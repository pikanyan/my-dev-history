<?php

use FizzBuzz\Math;
use PHPUnit\Framework\TestCase;



class MathTest extends TestCase
{
    public function testMin(): void
    {
        $math = new Math();

        $this->assertEquals(0, $math->min(0, 1));
        $this->assertEquals(0, $math->min(1, 0));

        $this->assertEquals(-1, $math->min(0, -1));
        $this->assertEquals(-1, $math->min(-1, 0));

        $this->assertEquals(0, $math->min(0, 0));

        $this->assertEquals(0, $math->min(0, PHP_INT_MAX));
        $this->assertEquals(0, $math->min(PHP_INT_MAX, 0));

        $this->assertEquals(PHP_INT_MIN, $math->min(0, PHP_INT_MIN));
        $this->assertEquals(PHP_INT_MIN, $math->min(PHP_INT_MIN, 0));
    }

    public function testMax(): void
    {
        $math = new Math();

        $this->assertEquals(1, $math->max(0, 1));
        $this->assertEquals(1, $math->max(1, 0));

        $this->assertEquals(0, $math->max(0, -1));
        $this->assertEquals(0, $math->max(-1, 0));

        $this->assertEquals(0, $math->max(0, 0));

        $this->assertEquals(0, $math->max(0, PHP_INT_MIN));
        $this->assertEquals(0, $math->max(PHP_INT_MIN, 0));

        $this->assertEquals(PHP_INT_MAX, $math->max(0, PHP_INT_MAX));
        $this->assertEquals(PHP_INT_MAX, $math->max(PHP_INT_MAX, 0));
    }
}
