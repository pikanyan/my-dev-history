<?php

// SubpackageA

interface MediatorInterfaceA
{
    // 2
    public function notifyActivityDone();
}

class ObjectA
{
    protected MediatorInterfaceA $mediator;

    // 1
    public function someActivity()
    {
        $this->mediator->notifyActivityDone();
    }

    // 5
    public function finishTheWork()
    {

    }
}



// SubpackageB

interface MediatorInterfaceB
{
    // 4
    public function notifyTaskCompletion();
}

class ObjectB
{
    protected MediatorInterfaceB $mediator;

    // 3
    public function doTask()
    {
        $this->mediator->notifyTaskCompletion();
    }
}



class Mediator implements MediatorInterfaceA, MediatorInterfaceB
{
    protected ObjectA $a;
    protected ObjectB $b;

    // 2
    public function notifyActivityDone()
    {
        $this->b->doTask();
    }

    // 4
    public function notifyTaskCompletion()
    {
        $this->a->finishTheWork();
    }
}



class App
{
    public static function main(): void
    {
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();
