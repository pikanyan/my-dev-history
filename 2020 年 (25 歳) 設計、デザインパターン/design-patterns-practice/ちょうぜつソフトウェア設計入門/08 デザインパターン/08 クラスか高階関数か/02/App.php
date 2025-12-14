<?php


$foo = "Foo";



// closer による振る舞い
$functionObject = function () use ($foo)
{
    echo $foo . "\n";
};



$functionObject();
