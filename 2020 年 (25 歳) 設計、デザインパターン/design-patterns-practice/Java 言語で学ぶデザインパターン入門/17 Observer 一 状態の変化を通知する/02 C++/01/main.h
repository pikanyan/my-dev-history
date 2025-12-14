#pragma once

#include <QObject>
#include <QDebug>



// 観察者
class Observer : public QObject
{
    Q_OBJECT

public slots:
    virtual void update(int value) = 0;
};

class ObserverA : public Observer
{
    Q_OBJECT

public slots:
    void update(int value) override
    {
        qDebug() << "ObserverA : " << value;
    }
};



// 被観察者
class Subject : public QObject
{
    Q_OBJECT

private:
    int value_;

public:
    Subject() :
        value_(0)
    {
    }

signals:
    void changed_value(int value);

public slots:
    void set_value(int value)
    {
        if (value_ != value)
        {
            value_ = value;

            emit changed_value(value);
        }
    }
};



/*
Mediator パターン
Colleague が Colleague に伝える
Mediator は不要

Observer パターン
Subject が Observer に伝える
Observer クラスは必要
*/
