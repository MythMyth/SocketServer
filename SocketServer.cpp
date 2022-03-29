#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#define PORT 8080
using namespace std;

int main() {
    int server_fd, new_socket, valread;
    int opt = 1;
    char buffer[1024] = {0};
    // Creating socket fd
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) {
        std::cout << "Socket failed\n";
        return 1;
    }
    // Set socket option
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        cout << "Set socket option failed\n";
        return 1;
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    //Bind socket to port
    if( bind(server_fd, (struct sockaddr*)&address, addrlen) < 0) {
        cout << "Bind error \n";
        return 1;
    }

    if(listen(server_fd, 5) < 0) {
        cout << "Listen error \n";
        return 1;
    }

    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if(new_socket < 0) {
        cout << "Socket accept failed \n";
        return 1;
    }
    while(1) {
        valread = read( new_socket , buffer, 1024);
        printf("%s\n",buffer );
    }
    char* hello = "Hello\n";
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}