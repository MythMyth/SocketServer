#ifndef __MSOCKET__
#define __MSOCKET__
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

using namespace std;

class MSocket {
    public:
    static int port;
    MSocket();
    int ListenForConnect();
    private:
    int server_fd;
};

#endif