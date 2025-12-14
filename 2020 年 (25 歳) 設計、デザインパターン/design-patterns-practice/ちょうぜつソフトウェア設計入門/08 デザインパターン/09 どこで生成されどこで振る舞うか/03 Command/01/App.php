<?php

// namespace Common;

interface CommandInterface
{
    public function invoke(): void;
}



// namespace UI;

class SelectionItem
{
    public function __construct
    (
        public string $label,
        public CommandInterface $command
    )
    {
        
    }
}

class SelectionUI
{
    protected array $selectionItems = [];



    public function registerCommand(string $label, CommandInterface $command): void
    {
        $this->selectionItems[] = new SelectionItem($label, $command);
    }



    public function help(): string
    {
        $indexedItemList = [];



        foreach($this->selectionItems as $i => $item)
        {
            $indexedItemList[] = sprintf("%d: %s", $i + 1, $item->label);
        }



        return implode("\n", $indexedItemList);
    }



    public function select(int $number): void
    {
        $command = $this->selectionItems[$number - 1]->command;

        $command->invoke();
    }
}



// namespace UseCase;

class PetShop
{
    public function buyPet(Pet $pet): void
    {
        echo "Buying a " . get_class($pet) . PHP_EOL;
    }



    public function cancel(): void
    {
        echo "Purchase canceled." . PHP_EOL;
    }
}

abstract class Pet
{

}

class Cat extends Pet
{

}

class Dog extends Pet
{

}



// namespace UseCase\Command;

class BuyPetCommand implements CommandInterface
{
    public function __construct
    (
        protected PetShop $shop,
        protected Pet $pet
    )
    {

    }

    public function invoke(): void
    {
        $this->shop->buyPet($this->pet);
    }
}

class CancelBuyingCommand implements CommandInterface
{
    public function __construct
    (
        protected PetShop $shop
    )
    {

    }

    public function invoke(): void
    {
        $this->shop->cancel();
    }
}



function createPetSelectionUI(PetShop $shop): SelectionUI
{
    $ui = new SelectionUI();



    $ui->registerCommand("猫をください", new BuyPetCommand($shop, new Cat()));
    $ui->registerCommand("犬をください", new BuyPetCommand($shop, new Dog()));
    $ui->registerCommand("やっぱりやめます", new CancelBuyingCommand($shop));



    return $ui;
}



$shop = new PetShop();

$ui = createPetSelectionUI($shop);

echo $ui->help() . "\n";
// 1: 猫をください
// 2: 犬をください
// 3: やっぱりやめます



$userInput = (int)fgets(STDIN);

$ui->select($userInput);
// 選んだ項目の command が実行される
