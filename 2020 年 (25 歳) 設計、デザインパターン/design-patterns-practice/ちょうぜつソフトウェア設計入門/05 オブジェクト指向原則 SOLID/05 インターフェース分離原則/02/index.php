<?php

// íäè€ device ÇÃëÄçÏ
interface KeyboardInterface
{
    public function typeKey(string $code): void;
}

interface PointerDeviceInterface
{
    public function moveCursor(float $direction, float $distance): void;
}

class PCOperator
{
    public function __construct
    (
        protected KeyBoardInterface $keyboard,
        protected PointerDeviceInterface $pointerDevice
    )
    {
        
    }

    public function inputText(array $codes): void
    {
        foreach($codes as $code)
        {
            $this->keyboard->typeKey($code);
        }
    }

    public function pointAt(int $x, int $y): void
    {
        // $x Ç∆ $y Ç©ÇÁ
        // $direction Ç∆ $distance ÇçlÇ¶ÇÈ
        $this->pointerDevice->moveCursor($direction, $distance);
    }
}



// íäè€ device ÇÃê⁄ë±
interface USBDeviceInterface
{
    public function connect(InternalBus $bus): void;
}

class USBPort
{
    private InternalBus $internalBus;

    public function plug(USBDeviceInterface $device): void
    {
        $device->connect($this->internalBus);
    }
}



// ãÔè€ device ÇÃé¿ëï

// ïWèÄ device
class BuiltinKeyboard implements KeyboardInterface
{
    public function typeKey(string $code): void
    {
        
    }
}

class BuiltinTrackpad implements PointerDeviceInterface
{
    public function moveCursor(float $direction, float $distance): void
    {
        
    }
}

// ägí£ device
class USBKeyboard implements KeyboardInterface, USBDeviceInterface
{
    public function connect(InternalBus $bus): void
    {
        
    }

    public function typeKey(string $code): void
    {
        
    }
}

class USBMouse implements PointerDeviceInterface, USBDeviceInterface
{
    public function connect(InternalBus $bus): void
    {

    }

    public function moveCursor(float $direction, float $distance): void
    {
        
    }
}
