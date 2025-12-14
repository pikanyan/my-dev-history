<?php

class Logger
{
    public function log($message)
    {
        echo $message . "\n";
    }
}

class App
{
    protected $logger;

    public function __construct()
    {
        $this->logger = new Logger();
    }

    public function getLogger()
    {
        return $this->logger;
    }
}



$app = new App();



class PetShop
{
    public function __construct
    (
        protected App $app,
        protected bool $withoutLogging = false
    )
    {
        
    }

    public function paycheck()
    {
        if(!$this->withoutLogging)
        {
            $this->app->getLogger()->log("begin");
        }

        // transaction

        if(!$this->withoutLogging)
        {
            $this->app->getLogger()->log("end");
        }
    }
}



$shop = new PetShop($app, true);

$shop->paycheck();
