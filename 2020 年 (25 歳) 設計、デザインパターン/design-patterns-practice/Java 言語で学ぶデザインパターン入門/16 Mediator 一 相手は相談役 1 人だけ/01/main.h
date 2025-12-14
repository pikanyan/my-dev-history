#pragma once

#include <QObject>
#include <QDebug>


/*
Qt を使うことで Mediator クラスは必須ではない
しかし、Mediator クラスが便利になるときもある


Mediator が存在するなら Mediator パターン
Mediator が存在しないなら Observer パターン
*/

class Colleague : public QObject
{
    Q_OBJECT

public:
    void send(const QString& message)
    {
        emit messageSent(message);
    }

signals:
    void messageSent(const QString& message);

public slots:
    virtual void receive(const QString& message) = 0;
};

class ColleagueA : public Colleague
{
    Q_OBJECT

public slots:
    void receive(const QString& message) override
    {
        qDebug() << "ColleagueA : " << message;
    }
};

class ColleagueB : public Colleague
{
    Q_OBJECT

public slots:
    void receive(const QString& message) override
    {
        qDebug() << "ColleagueB : " << message;
    }
};
