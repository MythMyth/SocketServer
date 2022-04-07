#include "MSocket.h"

#define PORT 8080

MSocket::MSocket() {

}

int MSocket::ListenForConnect() {
    int opt = 1;
    char buffer[1024] = {0};
    // Creating socket fd
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) {
        std::cout << "Socket failed\n";
        return -1;
    }
    // Set socket option
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        cout << "Set socket option failed\n";
        return -1;
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    //Bind socket to port
    if( bind(server_fd, (struct sockaddr*)&address, addrlen) < 0) {
        cout << "Bind error \n";
        return -1;
    }
    if(listen(server_fd, 5) < 0) {
        cout << "Listen error \n";
        return -1;
    }
    int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    return new_socket;
}
