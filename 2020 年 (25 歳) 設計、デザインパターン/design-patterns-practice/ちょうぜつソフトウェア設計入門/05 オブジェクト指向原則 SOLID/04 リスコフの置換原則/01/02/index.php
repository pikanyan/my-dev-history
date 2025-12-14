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
        if($this->total != 0)
        {
            $percent = (int) (100.0 * $this->remains / $this->total);
        }
        else
        {
            $percent = 100;
        }



        return persent::show() . " ($percent %)";
    }
}
