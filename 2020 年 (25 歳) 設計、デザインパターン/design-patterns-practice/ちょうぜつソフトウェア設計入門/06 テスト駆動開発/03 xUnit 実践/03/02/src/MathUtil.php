<?php

namespace FizzBuzz;

use FizzBuzz\Math;



class MathUtil
{
    public function __construct
    (
        protected Math $math
    )
    {

    }

    public function saturate(int $value, int $minValue, int $maxValue): int
    {
        $temp = $this->math->max($value, $minValue);
        $temp = $this->math->min($temp, $maxValue);

        return $temp;
    }
}
