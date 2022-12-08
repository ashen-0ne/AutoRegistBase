#include "ClassFactory.h"

bool ClassFactory::register_class(const std::string & className, create_method method)
{
    m_classMap[className] = method;
    return true;
}

void * ClassFactory::create_class(const std::string & className)
{
    auto it = m_classMap.find(className);
    if(it == m_classMap.end())
    {
        return NULL;
    }
    else
    {
        return it->second();
    }
}
