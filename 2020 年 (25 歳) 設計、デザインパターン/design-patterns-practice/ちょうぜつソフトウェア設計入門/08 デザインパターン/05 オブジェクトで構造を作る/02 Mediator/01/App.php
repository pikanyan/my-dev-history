<?php

// Package

interface TaskExecutorInterface
{
    public function doTask();
}

// 依存しない
// 単方向
class ObjectA
{
    protected TaskExecutorInterface $executor;

    public function someActivity()
    {
        $this->executor->doTask();
    }

    public function finishTheWork()
    {

    }
}

// 依存する
// 単方向
class ObjectB implements TaskExecutorInterface
{
    protected ObjectA $a;

    public function doTask()
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
