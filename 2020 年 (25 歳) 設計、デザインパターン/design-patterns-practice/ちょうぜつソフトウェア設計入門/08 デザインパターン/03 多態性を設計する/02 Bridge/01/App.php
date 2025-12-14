<?php

interface PrizeItemInterface
{
    public function getMaterial(): Material;
    public function getShape(): Shape;
}

class PrizeItem implements PrizeItemInterface
{
    public function __construct
    (
        protected PrizeMaterial $material,
        protected PrizeShape $shape
    )
    {

    }

    public function getMaterial(): Material
    {
        return $this->material->get();
    }

    public function getShape(): Shape
    {
        return $this->shape->get();
    }
}



abstract class PrizeMaterial
{
    abstract public function get(): Material;
}

abstract class PrizeShape
{
    abstract public function get(): Shape;
}



class PrizeMaterialGold extends PrizeMaterial
{
    public function get(): Material
    {
        return new Material("Gold");
    }
}

class PrizeMaterialSilver extends PrizeMaterial
{
    public function get(): Material
    {
        return new Material("Silver");
    }
}

class PrizeMaterialBronze extends PrizeMaterial
{
    public function get(): Material
    {
        return new Material("Bronze");
    }
}

class PrizeShapeMedal extends PrizeShape
{
    public function get(): Shape
    {
        return new Shape("Medal");
    }
}

class PrizeShapeCup extends PrizeShape
{
    public function get(): Shape
    {
        return new Shape("Cup");
    }
}



class Material
{
    public function __construct
    (
        private string $type
    )
    {

    }

    public function getType(): string
    {
        return $this->type;
    }
}

class Shape
{
    public function __construct
    (
        private string $type
    )
    {
        
    }

    public function getType(): string
    {
        return $this->type;
    }
}



class App
{
    public static function main(): void
    {
        $goldMedal = new PrizeItem
        (
            new PrizeMaterialGold(),
            new PrizeShapeMedal()
        );

        $silverCup = new PrizeItem
        (
            new PrizeMaterialSilver(),
            new PrizeShapeCup()
        );



        echo "Prize: " . $goldMedal->getMaterial()->getType() . " " . $goldMedal->getShape()->getType() . PHP_EOL;

        echo "Prize: " . $silverCup->getMaterial()->getType() . " " . $silverCup->getShape()->getType() . PHP_EOL;
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
