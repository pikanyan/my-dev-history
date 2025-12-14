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
                    "Replaced"
                )
            ]
        );

        $this->assertEquals("Replaced", $fizzBuzz->convert(1));
    }

    public function testConvertWithFizzBuzzRules(): void
    {
        $fizzBuzz = new NumberConverter
        (
            [
                $this->createMockRule
                (
                    1,
                    "Fizz"
                ),

                $this->createMockRule
                (
                    1,
                    "Buzz"
                )
            ]
        );

        $this->assertEquals("FizzBuzz", $fizzBuzz->convert(1));
    }

    public function testConvertWithUnmatchedFizzBuzzRulesAndConstantRule(): void
    {
        $fizzBuzz = new NumberConverter
        (
            [
                $this->createMockRule
                (
                    1,
                    ""
                ),

                $this->createMockRule
                (
                    1,
                    ""
                ),

                $this->createMockRule
                (
                    1,
                    "1"
                ),
            ]
        );

        $this->assertEquals("1", $fizzBuzz->convert(1));
    }

    private function createMockRule(int $expectedNumber, string $replacement): ReplaceRuleInterface
    {
        $rule = $this->createMock(ReplaceRuleInterface::class);

        $rule
        ->expects($this->atLeastOnce())
        ->method('replace')
        ->with($expectedNumber)
        ->willReturn($replacement);

        return $rule;
    }
}
