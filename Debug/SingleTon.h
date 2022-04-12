#ifndef __SINGLETON__
#define __SINGLETON__
#include <mutex>

template <class A>
class Singleton {
    public:
    static A* GetInstance() {
        m_mutex.lock();
        if(instance == NULL) {
            instance = new A();
        }
        m_mutex.unlock();
        return instance;
    }
    private:
    static A *instance;
    std::mutex m_mutex;

};

#endif