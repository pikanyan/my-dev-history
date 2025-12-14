<?php

interface ObservableInterface
{
    public function addObserver(string $eventKey, callable $observer): void;
}



class DataStore implements ObservableInterface
{
    const EVENT_SAVE = 'save';
    const EVENT_LOAD = 'load';

    protected array $observersMap = [];



    public function addObserver(string $eventKey, callable $observer): void
    {
        $this->observersMap[$eventKey][] = $observer;
    }



    protected function notify(string $eventKey, mixed $data): void
    {
        $observers = $this->observersMap[$eventKey];

        foreach($observers as $observer)
        {
            $observer($data);
        }
    }


    
    public function save(mixed $data): void
    {
        // data を保存
        echo "Saving data: " . json_encode($data) . "\n";

        // observer に通知
        $this->notify(self::EVENT_SAVE, $data);
    }

    public function load(): mixed
    {
        // data を作成
        $data = ['key' => 'value'];
        echo "Loading data...\n";

        // observer に通知
        $this->notify(self::EVENT_LOAD, $data);



        return $data;
    }
}



interface LoggerInterface
{
    public function info(string $message): void;
}

class Logger implements LoggerInterface
{
    public function info(string $message): void
    {
        echo "[INFO]: " . $message . "\n";
    }
}



class LoggingObserver
{
    public function __construct
    (
        protected LoggerInterface $logger
    )
    {
        
    }

    public function watch(ObservableInterface $target, string $eventKey): void
    {
        $target->addObserver
        (
            $eventKey,

            function($data) use($eventKey)
            {
                $this->logger->info($eventKey . ": " . json_encode($data));
            }
        );
    }
}



$logger = new Logger();
$observer = new LoggingObserver($logger);

$dataStore = new DataStore();
$observer->watch($dataStore, Datastore::EVENT_SAVE);
$observer->watch($dataStore, Datastore::EVENT_LOAD);

// 保存
$data = ['name' => 'John', 'age' => 30];
// $dataStore->save($data);

// 読み込み
// $dataStore->load();
