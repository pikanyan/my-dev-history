<?php

interface ExpressionInterface
{
    public function setVariables(array $vars): void;
    public function evaluate(): float;
}

// Template Method による実現
abstract class AbstractExpression implements ExpressionInterface
{
    protected ?array $vars = null;



    public function setVariables(array $vars): void
    {
        if(!$this->validate($vars))
        {
            throw new InvalidArgumentException();
        }

        $this->vars = $vars;
    }


    
    public function evaluate(): float
    {
        if($this->vars === null)
        {
            throw new LogicException();
        }

        return $this->calculate();
    }



    abstract protected function validate(array $vars): bool;

    // 引数が不要
    abstract protected function calculate(): float;
}



class PlusExpression extends AbstractExpression
{
    protected function validate(array $vars): bool
    {
        return count($vars) === 2;
    }

    // 引数が不要
    protected function calculate(): float
    {
        return $this->vars[0] + $this->vars[1];
    }
}



$expression = new PlusExpression();

$expression->setVariables([1.1, 2.2]);

echo $expression->evaluate();   // 3.3
