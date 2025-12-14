<?php

function saturate(int $value, int $minValue, int $maxValue): int
{
    $temp = max($value, $minValue)
    
    return min($temp, $maxValue);
}
