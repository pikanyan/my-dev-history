<?php

use FizzBuzz\Math;
use FizzBuzz\MathUtil;
use PHPUnit\Framework\TestCase;



class MathUtilTest extends TestCase
{
    public function testSaturate(): void
    {
        $mathStub = $this->createMock(Math::class);
        $mathUtil = new MathUtil($mathStub);

        $mathStub->method('max')->willReturn(2);
        $mathStub->method('min')->willReturn(2);

        $result = $mathUtil->saturate(2, 1, 3);
        $this->assertEquals(2, $result);
    }
}
