<?php

class SpeedMeter
{
    protected float $speed;
    protected SpeedMeterState $currentState;



    public function __construct()
    {
        $this->speed = 0.0;
        $this->currentState = SafeState::getInstance();
    }

    public function setSpeed(float $speed): void
    {
        $this->speed = $speed;
        $this->currentState = $this->currentState->nextState($this->speed);
    }

    public function display(): string
    {
        $color = $this->currentState->getColor();

        return sprintf("%.2fkm/h %s", $this->speed, $color);
    }
}



abstract class SpeedMeterState
{
    abstract public function nextState(float $speed): SpeedMeterState;
    abstract public function getColor(): string;
}

class SafeState extends SpeedMeterState
{
    use SingletonTrait;



    public function nextState(float $speed): SpeedMeterState
    {
        return $speed > 100.0 ? DangerState::getInstance() : $this;
    }

    public function getColor(): string
    {
        return "green";
    }
}

class DangerState extends SpeedMeterState
{
    use SingletonTrait;



    public function nextState(float $speed): SpeedMeterState
    {
        return $speed <= 80.0 ? SafeState::getInstance() : $this;
    }

    public function getColor(): string
    {
        return "red";
    }
}



trait SingletonTrait
{
    private static ?self $theInstance = null;


    
    private function __construct()
    {

    }

    public static function getInstance(): self
    {
        if(!self::$theInstance)
        {
            self::$theInstance = new self();
        }

        return self::$theInstance;
    }
}



$speedMeter = new SpeedMeter();
echo $speedMeter->display() . "\n"; // 0.00km/h green

$speedMeter->setSpeed(90.0);
echo $speedMeter->display() . "\n"; // 90.00km/h green

$speedMeter->setSpeed(101.0);
echo $speedMeter->display() . "\n"; // 101.00km/h red

$speedMeter->setSpeed(90.0);
echo $speedMeter->display() . "\n"; // 90.00km/h red

$speedMeter->setSpeed(80.0);
echo $speedMeter->display() . "\n"; // 80.00km/h green
