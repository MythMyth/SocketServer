#include "MyPThread.h"

MyPThread::MyPThread() {

}

void* MyPThread::thread_run(void* t_obj) {
    MyPThread *p_obj = (MyPThread*) t_obj;
    p_obj->run();
    return 0;
}

void MyPThread::start() {
    
    pthread_create(&m_thread, &thread_attr, &MyPThread::thread_run, this);
}

void MyPThread::join() {
    pthread_join(m_thread, NULL);
}