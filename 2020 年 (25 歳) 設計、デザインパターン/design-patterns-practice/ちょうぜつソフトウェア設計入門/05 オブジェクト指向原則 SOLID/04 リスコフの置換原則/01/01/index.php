<?php
    
class TaskDisplay
{
    public function show(): string
    {
        return "{$this->total} 件中 {$this->remains} 件が完了しました";
    }
}

class PercentileTaskDisplay extends TaskDisplay
{
    public function show(): string
    {
        $percent = (int) (100.0 * $this->remains / $this->total);



        return persent::show() . " ($percent %)";
    }
}
