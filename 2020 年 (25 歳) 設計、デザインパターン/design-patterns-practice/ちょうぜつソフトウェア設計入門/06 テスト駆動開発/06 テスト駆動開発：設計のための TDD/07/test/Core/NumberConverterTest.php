<?php

namespace FizzBuzz\Core;

use PHPUnit\Framework\TestCase;



class NumberConverterTest extends TestCase
{
    public function testConvertWithEmptyRules(): void
    {
        $fizzBuzz = new NumberConverter
        (
            [

            ]
        );

        $this->assertEquals("", $fizzBuzz->convert(1));
    }

    public function testConvertWithSingleRule(): void
    {
        $fizzBuzz = new NumberConverter
        (
            [
                $this->createMockRule
                (
                    1,
                    "",
                    true,
                    "Replaced"
                )
            ]
        );



        $this->assertEquals("Replaced", $fizzBuzz->convert(1));
    }

    public function testConvertCompositingRuleResults()
    {
        $fizzBuzz = new NumberConverter
        (
            [
                $this->createMockRule
                (
                    1,
                    "",
                    true,
                    "Fizz"
                ),

                $this->createMockRule
                (
                    1,
                    "Fizz",
                    true,
                    "FizzBuzz"
                ),
            ]
        );



        $this->assertEquals("FizzBuzz", $fizzBuzz->convert(1));
    }

    public function testConvertSkippingUnmatchedRules(): void
    {
        $fizzBuzz = new NumberConverter
        (
            [
                $this->createMockRule
                (
                    1,
                    "",
                    false,
                    "Fizz"
                ),

                $this->createMockRule
                (
                    1,
                    "",
                    false,
                    "Buzz"
                ),

                $this->createMockRule
                (
                    1,
                    "",
                    true,
                    "1"
                )
            ]
        );



        $this->assertEquals("1", $fizzBuzz->convert(1));
    }

    private function createMockRule(int $expectedNumber, string $expectedCarry, bool $matchResult, string $replacement): ReplaceRuleInterface
    {
        $rule = $this->createMock(ReplaceRuleInterface::class);



        $rule
        ->expects($this->any())
        ->method('apply')
        ->with($expectedCarry, $expectedNumber)
        ->willReturn($replacement);

        $rule
        ->expects($this->atLeastOnce())
        ->method('match')
        ->with($expectedCarry, $expectedNumber)
        ->willReturn($matchResult);


        
        return $rule;
    }
}
