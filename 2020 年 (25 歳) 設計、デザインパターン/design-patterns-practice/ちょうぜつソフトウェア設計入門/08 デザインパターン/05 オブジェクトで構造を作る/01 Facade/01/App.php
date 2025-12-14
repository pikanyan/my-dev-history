<?php

// 利用側
// 安定
interface FacadeInterface
{
    public function  simpleAction();
}

function useFacade(FacadeInterface $facade)
{
    $facade->simpleAction();
}



// 実装側
// 不安定
class Facade implements FacadeInterface
{
    protected FeatureA $a;
    protected FeatureB $b;
    protected FeatureC $c;

    public function simpleAction()
    {
        $this->a->complexProcessA();
        $this->b->complexProcessB();
        $this->c->complexProcessC();
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
