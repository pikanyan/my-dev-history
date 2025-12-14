<?php

// namespace Buyer;

abstract class Pet
{
    abstract public function getType(): string;
}

interface PetShopInterface
{
    public function createPet(string $type): Pet;
}

class PetBuyer
{
    public function buyPet(PetShopInterface $petShop, string $type): void
    {
        $pet = $petShop->createPet($type);

        buy($pet);
    }
}



// namespace Shop;

class Cat extends Pet
{
    public function getType(): string
    {
        return 'Cat';
    }
}

class Dog extends Pet
{
    public function getType(): string
    {
        return 'Dog';
    }
}

class CatAndDogOnlyPetShop implements PetShopInterface
{
    public function createPet(string $type): Pet
    {
        $pet = match($type)
        {
            'cat' => new Cat(),
            'dog' => new Dog(),
            default => throw new InvalidArgumentException("Unknown pet type: " . $type)
        };

        return $pet;
    }
}



function buy(Pet $pet)
{
    echo "Buying a " . $pet->getType() . PHP_EOL;
}



class App
{
    public static function main(): void
    {
        $petShop = new CatAndDogOnlyPetShop();

        $petBuyer = new PetBuyer();



        $petBuyer->buyPet($petShop, 'cat');

        $petBuyer->buyPet($petShop, 'dog');
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
