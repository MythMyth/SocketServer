#ifndef __CLIENT__
#define __CLIENT__

#include "MyPThread.h"
#include "../PThread/MyPThread.h"

class Client : public MyPThread {
    public:
    Client();
    void run();
};

#endif