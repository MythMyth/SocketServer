#ifndef __CLIENT__
#define __CLIENT__

#include "../PThread/MyPThread.h"

class Client : public MyPThread {
    public:
    Client();
    void run();
};

#endif