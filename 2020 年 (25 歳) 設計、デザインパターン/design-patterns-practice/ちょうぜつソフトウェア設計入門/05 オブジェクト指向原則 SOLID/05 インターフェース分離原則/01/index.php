<?php

// インターフェース分離 DB 抽象
interface DataInputInterface
{
    public function write(string $key, mixed $data): void;
}

interface DataOutputInterface
{
    public function read(string $key): mixed;
}

interface DatabaseDriverInterface extends DataInputInterface, DataOutputInterface
{
    
}



// インターフェース分離 DB ベンダー
class VendorDatabaseDriver implements DatabaseDriverInterface
{
    public function write(string $key, mixed $data): void
    {
        // キーにデータを保存
    }

    public function read(string $key): mixed
    {
        // return キーで取得したデータ
    }
}



// 分離されたインターフェースを使うアプリケーション
class CommandExecuter
{
    public function __construct
    (
        // DatabaseDriverInterface ではなく
        protected DataInputInterface $input
    )
    {
        
    }

    public function exec(...$args): void
    {
        $this->input->write(...$args);
    }
}

class QueryService
{
    public function __construct
    (
        // DatabaseDriverInterface ではなく
        protected DataOutputInterface $output
    )
    {
        
    }

    public function query(...$args): mixed
    {
        return $this->output->read(...$args);
    }
}
