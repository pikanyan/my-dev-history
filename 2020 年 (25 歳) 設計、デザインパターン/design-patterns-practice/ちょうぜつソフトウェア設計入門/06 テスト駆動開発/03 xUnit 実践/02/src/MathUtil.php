<?php

namespace FizzBuzz;

use FizzBuzz\Math;



class MathUtil
{
    public function saturate(int $value, int $minValue, int $maxValue): int
    {
        $math = new Math();

        $temp = $math->max($value, $minValue);
        $temp = $math->min($temp, $maxValue);

        return $temp;
    }
}
