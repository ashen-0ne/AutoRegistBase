#ifndef CLASSFACTORY_H
#define CLASSFACTORY_H

#include <string>
#include <map>

#include "Singleton.h"

typedef void *(* create_method)();   

class ClassFactory
{
    friend class Singleton<ClassFactory>;
public:
    // reflect class
    bool register_class(const std::string & className, create_method method);
    void * create_class(const std::string & className);

private:
    ClassFactory() {}
    ~ClassFactory() {}

private:
    std::map<std::string, create_method> m_classMap;
};


#define REGISTER_CLASS(classname,class) \
    Singleton<ClassFactory>::getInstance()->register_class(classname,[](){return (void *)(new class);}); 

#endif

