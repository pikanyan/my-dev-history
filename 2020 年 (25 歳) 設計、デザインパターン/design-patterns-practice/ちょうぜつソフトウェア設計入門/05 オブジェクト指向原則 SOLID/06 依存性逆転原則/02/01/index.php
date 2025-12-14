<?php

class USBKeyboard
{
    public function connect(InternalBus $bus): void
    {
        
    }
}

class USBPort
{
    private InternalBus $internalBus;

    public function plugKeyboard(USBKeyboard $keyboard): void
    {
        // USBPort ‚ª USBKeyboard ‚ğŒÄ‚Ño‚·
        $keyboard->connect($this->internalBus);
    }
}
