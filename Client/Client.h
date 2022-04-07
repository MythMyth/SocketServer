#ifndef __CLIENT__
#define __CLIENT__

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include "../PThread/MyPThread.h"
#include "ClientListener.h"

class ClientListener;
class Client : public MyPThread {
    public:
    Client(int id, ClientListener* listnener);
    void run();

    private:
    int client_id;
    ClientListener* client_listener;
};

#endif