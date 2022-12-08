#ifndef SINGLETON_H
#define SINGLETON_H

template<class T>
class Singleton
{
public:
    static T * getInstance()
    {
        if(!s_instance)
        {
            s_instance = new T();
        }
        return s_instance;
    }

private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton<T> &) {}
    Singleton<T> & operator = (const Singleton<T> &) {}

private:
    static T * s_instance;
};

template<class T>
T * Singleton<T>::s_instance = NULL;

#endif