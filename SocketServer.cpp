#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    std::cout << "Start server\n";
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) {
        std::cout << "Socket failed\n";
        return 1;
    }
    
    return 0;
}