<?php

interface ExpressionInterface
{
    public function setVariables(array $vars): void;
    public function evaluate(): float;
}

class Expressoin implements ExpressionInterface
{
    protected ?array $vars = null;
    protected ?CalculationStrategyInterface $calculationStrategy = null;



    public function setVariables(array $vars): void
    {
        if(!$this->calculationStrategy->validate($vars))
        {
            throw new InvalidArgumentException();
        }

        $this->vars = $vars;
    }



    public function evaluate(): float
    {
        if($this->vars === null || $this->calculationStrategy === null)
        {
            throw new LogicException();
        }

        return $this->calculationStrategy->calculate($this->vars);
    }



    public function setCalculationStrategy(CalculationStrategyInterface $strategy): void
    {
        $this->calculationStrategy = $strategy;
    }
}



interface CalculationStrategyInterface
{
    public function validate(array $vars): bool;

    public function calculate(array $vars): float;
}

class PlusCalculationStrategy implements CalculationStrategyInterface
{
    public function validate(array $vars): bool
    {
        return count($vars) === 2;
    }

    public function calculate(array $vars): float
    {
        return $vars[0] + $vars[1];
    }
}



$expression = new Expressoin();

$expression->setCalculationStrategy(new PlusCalculationStrategy());

$expression->setVariables([1.1, 2.2]);

echo $expression->evaluate(); // 3.3
