#include "singleton.h"

Singleton* Singleton::_singleton_instance = nullptr;

void Singleton::resetInstance(const double& initialX,
                              const char* _arg)
{
    delete Singleton::_singleton_instance;
    Singleton::_singleton_instance = new Singleton(initialX, _arg);
}

void Singleton::releaseInstance()
{
    delete Singleton::_singleton_instance;
    Singleton::_singleton_instance = nullptr;
}

bool Singleton::good()
{
    return (Singleton::_singleton_instance != nullptr);
}

const double& Singleton::getX()
{
    return Singleton::instance()->_get_x();
}

const std::string& Singleton::getArg()
{
    return Singleton::instance()->_get_arg();
}

void Singleton::setX(const double& newValue)
{
    Singleton::_singleton_instance->_set_x(newValue);
}

Singleton::Singleton(const double& initialX, const char* _arg):
    x(initialX),
    arg(_arg)
{
    qDebug()<<Q_FUNC_INFO;
}

Singleton::~Singleton()
{
    qDebug()<<Q_FUNC_INFO;
}

Singleton* Singleton::instance()
{
    if(!Singleton::good()){
        qWarning("Singleton::instance() is nullptr. Call Singleton::resetInstance()\n"
                 "before use any method of the class Singleton");

        Singleton::resetInstance();
    }
    return Singleton::_singleton_instance;

}

const double& Singleton::_get_x() const
{
    return x;
}

const std::string& Singleton::_get_arg() const
{
    return arg;
}

void Singleton::_set_x(const double& newValue)
{
    x = newValue;
}
