#include "main.h"

#include <QCoreApplication>



int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);



    ColleagueA colleagueA;
    ColleagueB colleagueB;

    QObject::connect(&colleagueA, &Colleague::messageSent, &colleagueB, &Colleague::receive);
    QObject::connect(&colleagueB, &Colleague::messageSent, &colleagueA, &Colleague::receive);



    colleagueA.send("Hello from A");
    colleagueB.send("Hello from B");



    return application.exec();
}
