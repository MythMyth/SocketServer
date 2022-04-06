#ifdef __MYPTHREAD__
#define __MYPTHREAD__

#include<pthread.h>
#include<iostream>

class MyPThread {
    public:
    MyPThread();
    virtual void run() {std::cout << "Default\n";}
    void start();
    void join();
    private:
    pthread_t m_thread;
    pthread_attr_t thread_attr;
    static void* thread_run(void* t_obj);
};

#endif