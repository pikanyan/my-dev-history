<?php

// ’ŠÛ‚ð‰¼’u‚«‚·‚é
interface USBDeviceInterface
{
    public function connect(InternalBus $bus): void;
}

// ’ŠÛ‚ð‘O’ñ‚Éæ‚ÉŠ®¬‚³‚¹‚é
class USBPort
{
    private InternalBus $internalBus;

    public function plug(USBDeviceInterface $device): void
    {
        $device->connect($this->internalBus);
    }
}

// Œã‚Å’Ç‰Á‚·‚é
class USBKeyboard implements USBDeviceInterface
{
    public function connect(InternalBus $bus): void
    {
        
    }
}
