#include "singleton.h"

int main(int argc, char** argv)
{
    qDebug()<<"---------------------------------------------------------------------";
    Singleton::resetInstance(100,
                             "My Singleton Class");
    qDebug()<<"---------------------------------------------------------------------";

    qDebug()<<Singleton::getX();

    Singleton::setX(23);

    qDebug()<<Singleton::getX();

    qDebug()<<Singleton::getArg().data();


    qDebug()<<"---------------------------------------------------------------------";
    Singleton::resetInstance(250,
                             "My Singleton Class part 2");
    qDebug()<<"---------------------------------------------------------------------";

    qDebug()<<Singleton::getX();

    Singleton::setX(44);
    qDebug()<<Singleton::getX();

    qDebug()<<Singleton::getArg().data();


    qDebug()<<"---------------------------------------------------------------------";
    Singleton::releaseInstance();
    qDebug()<<"---------------------------------------------------------------------";
    return 0;
}
