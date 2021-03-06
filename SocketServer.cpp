#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include "Client/ClientListener.h"
#include "Debug/Debug.h"
using namespace std;

#define PORT 8080

int main(int argc, char* argv[]) {
    Debug *d = Debug::GetInstance();
    if(argc > 1) {
        LogLevel level = (LogLevel)atoi(argv[1]);
        d->SetDebugLevel(level);
    }

    int server_fd, new_socket, valread;
    int opt = 1;
    char buffer[1024] = {0};
    // Creating socket fd
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) {
        d->Log(LOG_LEVEL_HIGH, "Socket failed");
        return 1;
    }
    // Set socket option
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        d->Log(LOG_LEVEL_HIGH, "Set socket option failed");
        return 1;
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    //Bind socket to port
    if( bind(server_fd, (struct sockaddr*)&address, addrlen) < 0) {
        d->Log(LOG_LEVEL_HIGH, "Bind error");
        return 1;
    }
    d->Log(LOG_LEVEL_HIGH, "Socket binded");
    if(listen(server_fd, 5) < 0) {
        d->Log(LOG_LEVEL_HIGH, "Listen error");
        return 1;
    }
    ClientListener *listener = new ClientListener(server_fd, &address);
    listener->start();
    listener->join();
    return 0;
}