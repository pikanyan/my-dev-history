<?php

interface LoggerInterface
{
    public function log(string $message);
}

class PetShop
{
    public function __construct
    (
        protected LoggerInterface $logger
    )
    {
        
    }

    public function paycheck()
    {
        $this->logger->log("begin");

        // transaction

        $this->logger->log("end");
    }
}

class NullLogger implements LoggerInterface
{
    public function log(string $message)
    {
        // Do nothing.
    }
}



$shop = new PetShop(new NullLogger());

$shop->paycheck();
