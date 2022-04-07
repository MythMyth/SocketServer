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

using namespace std;
class Client;
class ClientListener : public MyPThread {
public:
    ClientListener(int server_fd, struct sockaddr_in *address);
    void run();
    void ClientEnd(int client_id);
private: 
    struct sockaddr_in *m_address;
    int m_server_fd;
    map<int, Client*> connected;
};

#endif