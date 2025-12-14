<?php

// 利用される
// Proxy 追加時に変更されない
class MailerInterface
{
    public function send(Mail $mail): void
    {

    }
}

// 利用する
// Proxy 追加時に変更されない
class JobWorker
{
    public function __construct
    (
        protected MailerInterface $mailer
    )
    {
        
    }

    public function process(): void
    {
        // 前処理

        $reportMail = new Mail();

        $this->mailer->send($reportMail);

        // 後処理
    }
}



// 仲介する
class LoggingMailProxy implements MailerInterface
{
    public function __construct
    (
        protected MailerInterface $target,
        protected LoggerInterface $logger
    )
    {
        
    }

    public function send(Mail $mail): void
    {
        $this->logger->info("Before send " . $mail->address);

        $this->target->send($mail);

        $this->logger->info("After send " . $mail->addcslashes);
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
