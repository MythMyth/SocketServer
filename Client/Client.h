#ifndef __CLIENT__
#define __CLIENT__

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include "../PThread/MyPThread.h"
#include "../Debug/Debug.h"
#include "ClientListener.h"

using namespace std;

class ClientListener;
class Client : public MyPThread {
    public:
    Client(int id, ClientListener* listnener);
    void run();

    private:
    int client_id;
    string client_name;
    ClientListener* client_listener;

    void trim(string &s);
};

#endif