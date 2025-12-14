<?php

abstract class Pet
{
    abstract public function reaction();
}

class PetshopCustomer
{
    public function touch(Pet $pet)
    {
        $pet->reaction();
    }
}



class ParameterizedPet extends Pet
{
    public function __construct
    (
        protected string $voice
    )
    {
        
    }

    public function reaction()
    {
        echo $this->voice;
    }
}



$customer = new PetshopCustomer();
$customer->touch(new ParameterizedPet("ワン"));
$customer->touch(new ParameterizedPet("ニャン"));
