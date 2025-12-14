<?php

class Point
{
    public function __construct
    (
        public int $x,
        public int $y
    )
    {
        
    }
}

interface DrawingInterface
{
    public function startAt(Point $p): void;
    public function lineTo(Point $p): void;
}



class DecorativeDrawing implements DrawingInterface
{
    public function __construct
    (
        protected DrawingInterface $target
    )
    {

    }

    public function startAt(Point $p): void
    {
        // そのまま委譲
        $this->target->startAt($p);
    }

    public function lineTo(Point $p): void
    {
        // そのまま委譲
        $this->target->lineTo($p);
    }

    public function rectangle(Point $topLeft, Point $bottomRight): void
    {
        $topRight = new Point($bottomRight->x, $topLeft->y);
        $bottomLeft = new Point($topLeft->x, $bottomRight->x);

        $this->startAt($topLeft);

        $this->lineTo($topRight);
        $this->lineTo($bottomRight);
        $this->lineTo($bottomLeft);
        $this->lineTo($topLeft);
    }

    public function triangle(Point $p0, Point $p1, Point $p2): void
    {
        $this->startAt($p0);

        $this->lineTo($p1);
        $this->lineTo($p2);
        $this->lineTo($p0);
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
