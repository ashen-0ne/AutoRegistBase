#ifndef AUTOREGISTBASE_H
#define AUTOREGISTBASE_H

#include <string>
#include "ReflectRegister.h"

template<class T>
std::string type_name()
{
    std::string name, prefix, suffix;

    name = __PRETTY_FUNCTION__;
    prefix = "std::__cxx11::string type_name() [with T = ";
    suffix = "; std::__cxx11::string = std::__cxx11::basic_string<char>]";

    int name_size = name.size() - (prefix.size() + suffix.size());
    name = name.substr(prefix.size(),name_size);
    return name;
}


#define REGISTER_CLASS(classname)


template<class T>
void* create_func()
{
    return (void *)(new T);
}

template<class T>
class AutoRegistBase
{
    friend T;
public:
    static bool regist();
    static bool registered;
};


template<class T>
bool AutoRegistBase<T>::regist()
{
    ReflectRegister::getInstance()->RegisterClass(type_name<T>(),create_func<T>);
}

template<class T>
bool AutoRegistBase<T>::registered = AutoRegistBase<T>::regist();

#endif