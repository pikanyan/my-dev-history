#include "main.h"

#include <QCoreApplication>



int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);



    Subject subject;
    ObserverA observerA;

    QObject::connect(&subject, &Subject::changed_value, &observerA, &Observer::update);



    subject.set_value(123);
    subject.set_value(456);



    return application.exec();
}
