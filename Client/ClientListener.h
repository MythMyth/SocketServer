#ifndef __CLIENTLISTENER__
#define __CLIENTLISTENER__

#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <iostream>
#include<map>
#include<string>
#include "Client.h"
#include "../PThread/MyPThread.h"
#include "../Socket/MSocket.h"

using namespace std;
class Client;
class ClientListener : public MyPThread {
public:
    ClientListener();
    void run();
    void ClientEnd(int client_id);
private: 
    struct sockaddr_in *address;
    int server_fd;
    map<int, Client*> connected;
};

#endif