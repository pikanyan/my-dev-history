<?php

class Body
{
    public function __construct()
    {

    }
}

class Engine
{
    public function start()
    {
        echo "エンジンが始動しました\n";
    }
}

class Wheel
{
    public function adjust()
    {
        echo "ホイールが調整されました\n";
    }
}

class Car
{
    public function __construct
    (
        protected $body,
        protected $engine,
        protected $wheels
    )
    {
        
    }

    public function startEngine()
    {
        $this->engine->start();
    }

    public function adjustHandle()
    {
        $this->wheels[0]->adjust();
        $this->wheels[1]->adjust();
        $this->wheels[2]->adjust();
        $this->wheels[3]->adjust();
    }
}



$body = new Body();
$engine = new Engine();
$wheels =
[
    new Wheel(),
    new Wheel(),
    new Wheel(),
    new Wheel(),
];



$car = new Car($body, $engine, $wheels);
$car->startEngine();
$car->adjustHandle();
