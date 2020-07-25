#ifndef SINGLETON_H
#define SINGLETON_H

#include <QDebug>
#include <string>

class Singleton
{
public:

    static void resetInstance(const double& initialX = 0,
                              const char* _arg = "\0 ");
    static void releaseInstance();
    static bool good();

    static const double& getX();
    static const std::string& getArg();
    static void setX(const double& newValue);

private:

    Singleton(const double& initialX,
              const char* _arg);
    Singleton(const Singleton& that) = delete;
    Singleton(Singleton&& that) = delete;
    ~Singleton();

    static Singleton* instance();

    static Singleton* _singleton_instance;

    const double& _get_x()const;
    const std::string& _get_arg()const;

    void _set_x(const double& newValue);

    double x;
    std::string arg;
};
#endif
